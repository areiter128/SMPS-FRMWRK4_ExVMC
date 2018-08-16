/*LICENSE ********************************************************************
 * Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 * ***************************************************************************/
/* @@task_FaultHandler.c
 * ****************************************************************************
 * File:   task_FaultHandler.c
 * Author: M91406
 *
 * Description:
 * This source file provides multiple functions to set up and monitor user-
 * defined fault objects as well as routines to handle specific fault cases.
 * 
 * History:
 * Created on June 22, 2018, 01:14 PM
 ******************************************************************************/

#include "xc.h"
#include <stdint.h>

#include "apl.h"
#include "task_FaultHandler.h"

/*@@User-Defined Fault Objects
 * ***********************************************************************************************
 * Description:
 * The following prototype declarations represent user-defined fault objects. Every fault object
 * used to monitor values of variables or registers throughout the firmware needs to be declared 
 * here.
 *
 * Please note:
 * All fault objects must be added to the list of fault objects fault_object_list[] in file 
 * task_FaultHandler.c. 
 * After having added a fault object to the fault_object_list[], add a friendly label to the
 * fault_object_index_e enumeration.
 * ***********************************************************************************************/

// Fault objects for firmware modules and task manager flow control
FAULT_OBJECT_t fltobj_CPULoadOverrun;
FAULT_OBJECT_t fltobj_TaskExecutionFailure;
FAULT_OBJECT_t fltobj_TaskTimeQuotaViolation;

// Declaration of user defined fault objects
FAULT_OBJECT_t fltobj_SoftStartFailure;
#if (INCLUDE_SOFT_SHUT_DOWN == 1)
FAULT_OBJECT_t fltobj_SoftShutDownFailure;
#endif

FAULT_OBJECT_t fltobj_UnderVoltageLockOut;
FAULT_OBJECT_t fltobj_OverVoltageLockOut;
FAULT_OBJECT_t fltobj_OverVoltageProtection;
FAULT_OBJECT_t fltobj_OverCurrentProtection;
FAULT_OBJECT_t fltobj_OverTemperatureWarning;
FAULT_OBJECT_t fltobj_OverTemperatureProtection;

/*@@User-Defined Fault Objects Initialization
 * ***********************************************************************************************
 * Description:
 * The following prototype declarations represent user-defined initialization routines of each
 * defined fault object. Every fault object used to monitor values of variables or registers 
 * throughout the firmware needs to be initialized by a separate initialization routine.
 * ***********************************************************************************************/

inline uint16_t init_CPULoadOverrunFaultObject(void);
inline uint16_t init_TaskExecutionFaultObject(void);
inline uint16_t init_TaskTimeQuotaViolationFaultObject(void);

inline uint16_t init_SoftStartFailureFaultObject(void);
#if (INCLUDE_SOFT_SHUT_DOWN == 1)
inline uint16_t init_SoftShutDownFailureFaultObject(void);
#endif
inline uint16_t init_InputUnderVoltageFaultObject(void);
inline uint16_t init_InputOverVoltageFaultObject(void);

/*@@fault_object_list[]
 * ***********************************************************************************************
 * Description:
 * The fault_object_list[] array is a list of all fault objects defined for this project. It
 * is a list of pointers to DEFAULT_FAULT_OBJECT_t data structures defining fault settings,
 * status information, fault classes and user fault actions.
 * ***********************************************************************************************/

FAULT_OBJECT_t *fault_object_list[] = {
    
    // fault objects for firmware modules and task manager flow
    &fltobj_CPULoadOverrun,    // The CPU meter indicated an overrun condition (no free process time left))
    &fltobj_TaskExecutionFailure,   // a task returned an error code ("no success")
    &fltobj_TaskTimeQuotaViolation, // a time execution took longer than specified
    
    // user defined fault objects
    &fltobj_SoftStartFailure, 
    #if (INCLUDE_SOFT_SHUT_DOWN == 1)
    &fltobj_SoftShutDownFailure,
    #endif
    
    &fltobj_UnderVoltageLockOut,
    &fltobj_OverVoltageLockOut

/*
    &fltobj_OverVoltageProtection,
    &fltobj_OverCurrentProtection,
    &fltobj_OverTemperatureWarning,
    &fltobj_OverTemperatureProtection
*/
};
uint16_t fltobj_list_size = (sizeof(fault_object_list)/sizeof(fault_object_list[0]));

/*@@init_FaultObjects
 * ***********************************************************************************************
 * Description:
 * The fault_object_list[] array is a list of all fault objects defined for this project. It
 * is a list of pointers to FAULT_OBJECT_t data structures defining fault settings,
 * status information, fault classes and user fault actions.
 * ***********************************************************************************************/

volatile uint16_t init_FaultObjects(void)
{
    volatile uint16_t fres = 0;

    fres = init_CPULoadOverrunFaultObject();
    fres &= init_TaskExecutionFaultObject();
    fres &= init_TaskTimeQuotaViolationFaultObject();
    
    fres &= init_SoftStartFailureFaultObject();
    #if (INCLUDE_SOFT_SHUT_DOWN == 1)
    fres &= init_SoftShutDownFailureFaultObject();
    #endif
    
    fres &= init_InputUnderVoltageFaultObject();
    fres &= init_InputOverVoltageFaultObject();

    // Set global fault flags (need to be cleared during operation)
    application.fault_status.flags.global_fault = 1;
    application.fault_status.flags.global_warning = 1;
    application.fault_status.flags.global_notice = 1;
    
    return(fres);
    
}

/*@@init_CPULoadOverrunFaultObject
 * ***********************************************************************************************
 * Description:
 * The fltobj_CPULoadOverrun is initialized here. This fault detects conditions where the CPU
 * meter of the main scheduler detects an overrun condition, where there is no free process
 * time left.
 * ***********************************************************************************************/

inline uint16_t init_CPULoadOverrunFaultObject(void)
{
    // Configuring the CPU Load Overrun fault object

    // specify the target value/register to be monitored
    fltobj_CPULoadOverrun.object = &task_mgr.cpu_load.load_max_buffer; // monitoring the CPU meter result
    fltobj_CPULoadOverrun.object_bit_mask = FAULT_OBJECT_BIT_MASK_DEFAULT;
    fltobj_CPULoadOverrun.error_code = (uint32_t)FLTOBJ_CPU_LOAD_OVERRUN;
    fltobj_CPULoadOverrun.id = (uint16_t)FLTOBJ_CPU_LOAD_OVERRUN;
    
    /* TODO: identify and set generic CPU load warning/fault thresholds */
    // configuring the trip and reset levels as well as trip and reset event filter setting
    fltobj_CPULoadOverrun.criteria.counter = 0;      // Set/reset fault counter
    fltobj_CPULoadOverrun.criteria.fault_ratio = FAULT_LEVEL_LESS_THAN;
    fltobj_CPULoadOverrun.criteria.trip_level = 50;   // Set/reset trip level value
    fltobj_CPULoadOverrun.criteria.trip_cnt_threshold = 1; // Set/reset number of successive trips before triggering fault event
    fltobj_CPULoadOverrun.criteria.reset_level = 100;  // Set/reset fault release level value
    fltobj_CPULoadOverrun.criteria.reset_cnt_threshold = 1; // Set/reset number of successive resets before triggering fault release
    
    // specifying fault class, fault level and enable/disable status
    fltobj_CPULoadOverrun.classes.flags.notify = 0;   // Set =1 if this fault object triggers a fault condition notification
    fltobj_CPULoadOverrun.classes.flags.warning = 1;  // Set =1 if this fault object triggers a warning fault condition response
    fltobj_CPULoadOverrun.classes.flags.critical = 0; // Set =1 if this fault object triggers a critical fault condition response
    fltobj_CPULoadOverrun.classes.flags.catastrophic = 0; // Set =1 if this fault object triggers a catastrophic fault condition response

    fltobj_CPULoadOverrun.classes.flags.user_class = 0; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_CPULoadOverrun.user_fault_action = 0; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_CPULoadOverrun.user_fault_reset = 0; // Set =1 if this fault object triggers a user-defined fault condition response
        
    fltobj_CPULoadOverrun.status.flags.fltlvlhw = 0; // Set =1 if this fault condition is board-level fault condition
    fltobj_CPULoadOverrun.status.flags.fltlvlsw = 1; // Set =1 if this fault condition is software-level fault condition
    fltobj_CPULoadOverrun.status.flags.fltlvlsi = 1; // Set =1 if this fault condition is silicon-level fault condition
    fltobj_CPULoadOverrun.status.flags.fltlvlsys = 0; // Set =1 if this fault condition is system-level fault condition

    fltobj_CPULoadOverrun.status.flags.fltstat = 1; // Set/ret fault condition as present/active
    fltobj_CPULoadOverrun.status.flags.fltactive = 1; // Set/reset fault condition as present/active
    fltobj_CPULoadOverrun.status.flags.fltchken = 1; // Enable/disable fault check

    return(1);
    
}

/*@@init_TaskExecutionFaultObject
 * ***********************************************************************************************
 * Description:
 * The fltobj_TaskExecutionFailure is initialized here. This fault detects conditions where a 
 * user defined task called by the main scheduler returns a failure flag
 * ***********************************************************************************************/

inline uint16_t init_TaskExecutionFaultObject(void)
{
    // Configuring the Task Execution Failure fault object

    // specify the target value/register to be monitored
    fltobj_TaskExecutionFailure.object = &task_mgr.proc_code.segments.retval;
    fltobj_TaskExecutionFailure.object_bit_mask = FAULT_OBJECT_BIT_MASK_DEFAULT;
    fltobj_TaskExecutionFailure.error_code = (uint32_t)FLTOBJ_TASK_EXECUTION_FAILURE;
    fltobj_TaskExecutionFailure.id = (uint16_t)FLTOBJ_TASK_EXECUTION_FAILURE;
    
    // configuring the trip and reset levels as well as trip and reset event filter setting
    fltobj_TaskExecutionFailure.criteria.counter = 0;      // Set/reset fault counter
    fltobj_TaskExecutionFailure.criteria.fault_ratio = FAULT_LEVEL_NOT_EQUAL;
    fltobj_TaskExecutionFailure.criteria.trip_level = 1;   // Set/reset trip level value
    fltobj_TaskExecutionFailure.criteria.trip_cnt_threshold = 1; // Set/reset number of successive trips before triggering fault event
    fltobj_TaskExecutionFailure.criteria.reset_level = 0;  // Set/reset fault release level value
    fltobj_TaskExecutionFailure.criteria.reset_cnt_threshold = 1; // Set/reset number of successive resets before triggering fault release

    // specifying fault class, fault level and enable/disable status
    fltobj_TaskExecutionFailure.classes.flags.notify = 0;   // Set =1 if this fault object triggers a fault condition notification
    fltobj_TaskExecutionFailure.classes.flags.warning = 1;  // Set =1 if this fault object triggers a warning fault condition response
    fltobj_TaskExecutionFailure.classes.flags.critical = 0; // Set =1 if this fault object triggers a critical fault condition response
    fltobj_TaskExecutionFailure.classes.flags.catastrophic = 0; // Set =1 if this fault object triggers a catastrophic fault condition response

    fltobj_TaskExecutionFailure.classes.flags.user_class = 0; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_TaskExecutionFailure.user_fault_action = 0; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_TaskExecutionFailure.user_fault_reset = 0; // Set =1 if this fault object triggers a user-defined fault condition response
        
    fltobj_TaskExecutionFailure.status.flags.fltlvlhw = 0; // Set =1 if this fault condition is board-level fault condition
    fltobj_TaskExecutionFailure.status.flags.fltlvlsw = 1; // Set =1 if this fault condition is software-level fault condition
    fltobj_TaskExecutionFailure.status.flags.fltlvlsi = 0; // Set =1 if this fault condition is silicon-level fault condition
    fltobj_TaskExecutionFailure.status.flags.fltlvlsys = 0; // Set =1 if this fault condition is system-level fault condition

    fltobj_TaskExecutionFailure.status.flags.fltstat = 1; // Set/ret fault condition as present/active
    fltobj_TaskExecutionFailure.status.flags.fltactive = 1; // Set/reset fault condition as present/active
    fltobj_TaskExecutionFailure.status.flags.fltchken = 1; // Enable/disable fault check

    return(1);
    
}

/*@@init_TaskTimeQuotaViolationFaultObject
 * ***********************************************************************************************
 * Description:
 * The fltobj_TaskTimeQuotaViolation is initialized here. This fault detects conditions where a 
 * user defined task takes more time than defined in the user task time quota or exceeds the 
 * maximum time quota defined within the task manager data structure.
 * ***********************************************************************************************/

inline uint16_t init_TaskTimeQuotaViolationFaultObject(void)
{
    // Configuring the Task Time Quota Violation fault object
    fltobj_TaskTimeQuotaViolation.object = &task_mgr.task_time_maximum;
    fltobj_TaskTimeQuotaViolation.object_bit_mask = FAULT_OBJECT_BIT_MASK_DEFAULT;
    fltobj_TaskTimeQuotaViolation.error_code = (uint32_t)FLTOBJ_TASK_TIME_QUOTA_VIOLATION;
    fltobj_TaskTimeQuotaViolation.id = (uint16_t)FLTOBJ_TASK_TIME_QUOTA_VIOLATION;


    // configuring the trip and reset levels as well as trip and reset event filter setting
    fltobj_TaskTimeQuotaViolation.criteria.counter = 0;      // Set/reset fault counter
    fltobj_TaskTimeQuotaViolation.criteria.fault_ratio = FAULT_LEVEL_GREATER_THAN;
    fltobj_TaskTimeQuotaViolation.criteria.trip_level = (task_mgr.task_time_quota - (task_mgr.task_time_quota >> 3));   // Set/reset trip level value
    fltobj_TaskTimeQuotaViolation.criteria.trip_cnt_threshold = 1; // Set/reset number of successive trips before triggering fault event
    fltobj_TaskTimeQuotaViolation.criteria.reset_level = (task_mgr.task_time_quota - (task_mgr.task_time_quota >> 2));  // Set/reset fault release level value
    fltobj_TaskTimeQuotaViolation.criteria.reset_cnt_threshold = 10; // Set/reset number of successive resets before triggering fault release
        
    // specifying fault class, fault level and enable/disable status
    fltobj_TaskTimeQuotaViolation.classes.flags.notify = 0;   // Set =1 if this fault object triggers a fault condition notification
    fltobj_TaskTimeQuotaViolation.classes.flags.warning = 1;  // Set =1 if this fault object triggers a warning fault condition response
    fltobj_TaskTimeQuotaViolation.classes.flags.critical = 0; // Set =1 if this fault object triggers a critical fault condition response
    fltobj_TaskTimeQuotaViolation.classes.flags.catastrophic = 0; // Set =1 if this fault object triggers a catastrophic fault condition response

    fltobj_TaskTimeQuotaViolation.classes.flags.user_class = 0; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_TaskTimeQuotaViolation.user_fault_action = 0; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_TaskTimeQuotaViolation.user_fault_reset = 0; // Set =1 if this fault object triggers a user-defined fault condition response
        
    fltobj_TaskTimeQuotaViolation.status.flags.fltlvlhw = 0; // Set =1 if this fault condition is board-level fault condition
    fltobj_TaskTimeQuotaViolation.status.flags.fltlvlsw = 1; // Set =1 if this fault condition is software-level fault condition
    fltobj_TaskTimeQuotaViolation.status.flags.fltlvlsi = 0; // Set =1 if this fault condition is silicon-level fault condition
    fltobj_TaskTimeQuotaViolation.status.flags.fltlvlsys = 0; // Set =1 if this fault condition is system-level fault condition

    fltobj_TaskTimeQuotaViolation.status.flags.fltstat = 1; // Set/ret fault condition as present/active
    fltobj_TaskTimeQuotaViolation.status.flags.fltactive = 1; // Set/reset fault condition as present/active
    fltobj_TaskTimeQuotaViolation.status.flags.fltchken = 1; // Enable/disable fault check

    return(1);
}


/*@@init_SoftStartFailureFaultObject
 * ***********************************************************************************************
 * Description:
 * The fltobj_SoftStartFailure is initialized here. This fault detects conditions occurring 
 * during a soft-start process of the power converter.
 * ***********************************************************************************************/

inline uint16_t init_SoftStartFailureFaultObject(void)
{
    // Configuring the Task Time Quota Violation fault object
    fltobj_SoftStartFailure.object = &soft_start.status.flags;
    fltobj_SoftStartFailure.object_bit_mask = SOFT_START_FAULT_COMMON_FLAG;
    fltobj_SoftStartFailure.error_code = (uint32_t)FLTOBJ_SOFT_START;
    fltobj_SoftStartFailure.id = (uint16_t)FLTOBJ_SOFT_START;

    // configuring the trip and reset levels as well as trip and reset event filter setting
    fltobj_SoftStartFailure.criteria.counter = 0;      // Set/reset fault counter
    fltobj_SoftStartFailure.criteria.fault_ratio = FAULT_LEVEL_EQUAL;
    fltobj_SoftStartFailure.criteria.trip_level = 1;   // Set/reset trip level value
    fltobj_SoftStartFailure.criteria.trip_cnt_threshold = 10; // Set/reset number of successive trips before triggering fault event
    fltobj_SoftStartFailure.criteria.reset_level = 0;  // Set/reset fault release level value
    fltobj_SoftStartFailure.criteria.reset_cnt_threshold = 3; // Set/reset number of successive resets before triggering fault release
        
    // specifying fault class, fault level and enable/disable status
    fltobj_SoftStartFailure.classes.flags.notify = 0;   // Set =1 if this fault object triggers a fault condition notification
    fltobj_SoftStartFailure.classes.flags.warning = 0;  // Set =1 if this fault object triggers a warning fault condition response
    fltobj_SoftStartFailure.classes.flags.critical = 1; // Set =1 if this fault object triggers a critical fault condition response
    fltobj_SoftStartFailure.classes.flags.catastrophic = 0; // Set =1 if this fault object triggers a catastrophic fault condition response

    fltobj_SoftStartFailure.classes.flags.user_class = 1; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_SoftStartFailure.user_fault_action = &cvrt_ShutDown; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_SoftStartFailure.user_fault_reset = 0; // Set =1 if this fault object triggers a user-defined fault condition response
        
    fltobj_SoftStartFailure.status.flags.fltlvlhw = 1; // Set =1 if this fault condition is board-level fault condition
    fltobj_SoftStartFailure.status.flags.fltlvlsw = 0; // Set =1 if this fault condition is software-level fault condition
    fltobj_SoftStartFailure.status.flags.fltlvlsi = 0; // Set =1 if this fault condition is silicon-level fault condition
    fltobj_SoftStartFailure.status.flags.fltlvlsys = 1; // Set =1 if this fault condition is system-level fault condition

    fltobj_SoftStartFailure.status.flags.fltstat = 1; // Set/ret fault condition as present/active
    fltobj_SoftStartFailure.status.flags.fltactive = 1; // Set/reset fault condition as present/active
    fltobj_SoftStartFailure.status.flags.fltchken = 0; // Enable/disable fault check
    
    return(1);
}

#if (INCLUDE_SOFT_SHUT_DOWN == 1)

/*@@init_SoftShutDownFailureFaultObject
 * ***********************************************************************************************
 * Description:
 * The fltobj_SoftShutDownFailure is initialized here. This fault detects conditions occurring 
 * during a soft-shut-down process of the power converter.
 * ***********************************************************************************************/

inline uint16_t init_SoftShutDownFailureFaultObject(void)
{
    // Configuring the Task Time Quota Violation fault object
    fltobj_SoftShutDownFailure.object = &soft_shutdwn.status.flags;
    fltobj_SoftShutDownFailure.object_bit_mask = SOFT_START_FAULT_COMMON_FLAG;
    fltobj_SoftShutDownFailure.error_code = (uint32_t)FLTOBJ_SOFT_SHUT_DOWN;
    fltobj_SoftShutDownFailure.id = (uint16_t)FLTOBJ_SOFT_SHUT_DOWN;

    // configuring the trip and reset levels as well as trip and reset event filter setting
    fltobj_SoftShutDownFailure.criteria.counter = 0;      // Set/reset fault counter
    fltobj_SoftShutDownFailure.criteria.fault_ratio = FAULT_LEVEL_EQUAL;
    fltobj_SoftShutDownFailure.criteria.trip_level = 1;   // Set/reset trip level value
    fltobj_SoftShutDownFailure.criteria.trip_cnt_threshold = 10; // Set/reset number of successive trips before triggering fault event
    fltobj_SoftShutDownFailure.criteria.reset_level = 0;  // Set/reset fault release level value
    fltobj_SoftShutDownFailure.criteria.reset_cnt_threshold = 3; // Set/reset number of successive resets before triggering fault release
        
    // specifying fault class, fault level and enable/disable status
    fltobj_SoftShutDownFailure.classes.flags.notify = 0;   // Set =1 if this fault object triggers a fault condition notification
    fltobj_SoftShutDownFailure.classes.flags.warning = 0;  // Set =1 if this fault object triggers a warning fault condition response
    fltobj_SoftShutDownFailure.classes.flags.critical = 1; // Set =1 if this fault object triggers a critical fault condition response
    fltobj_SoftShutDownFailure.classes.flags.catastrophic = 0; // Set =1 if this fault object triggers a catastrophic fault condition response

    fltobj_SoftShutDownFailure.classes.flags.user_class = 1; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_SoftShutDownFailure.user_fault_action = &cvrt_ShutDown; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_SoftShutDownFailure.user_fault_reset = 0; // Set =1 if this fault object triggers a user-defined fault condition response
        
    fltobj_SoftShutDownFailure.status.flags.fltlvlhw = 1; // Set =1 if this fault condition is board-level fault condition
    fltobj_SoftShutDownFailure.status.flags.fltlvlsw = 0; // Set =1 if this fault condition is software-level fault condition
    fltobj_SoftShutDownFailure.status.flags.fltlvlsi = 0; // Set =1 if this fault condition is silicon-level fault condition
    fltobj_SoftShutDownFailure.status.flags.fltlvlsys = 1; // Set =1 if this fault condition is system-level fault condition

    fltobj_SoftShutDownFailure.status.flags.fltstat = 0; // Set/ret fault condition as present/active
    fltobj_SoftShutDownFailure.status.flags.fltactive = 0; // Set/reset fault condition as present/active
    fltobj_SoftShutDownFailure.status.flags.fltchken = 0; // Enable/disable fault check
    
    return(1);
}

#endif

/*@@init_InputUnderVoltageFaultObject
 * ***********************************************************************************************
 * Description:
 * The fltobj_UnderVoltageLockOut is initialized here. This fault detects conditions occurring 
 * at start-up or during normal operation of the power converter.
 * ***********************************************************************************************/

inline uint16_t init_InputUnderVoltageFaultObject(void)
{
    // Configuring the Task Time Quota Violation fault object
    fltobj_UnderVoltageLockOut.object = &VIN_FB_ADCBUF;
    fltobj_UnderVoltageLockOut.object_bit_mask = FAULT_OBJECT_BIT_MASK_DEFAULT;
    fltobj_UnderVoltageLockOut.error_code = (uint32_t)FLTOBJ_UVLO;
    fltobj_UnderVoltageLockOut.id = (uint16_t)FLTOBJ_UVLO;

    // configuring the trip and reset levels as well as trip and reset event filter setting
    fltobj_UnderVoltageLockOut.criteria.counter = 0;      // Set/reset fault counter
    fltobj_UnderVoltageLockOut.criteria.fault_ratio = FAULT_LEVEL_LESS_THAN;
    fltobj_UnderVoltageLockOut.criteria.trip_level = VIN_UVLO_TRIP;   // Set/reset trip level value
    fltobj_UnderVoltageLockOut.criteria.trip_cnt_threshold = 10; // Set/reset number of successive trips before triggering fault event
    fltobj_UnderVoltageLockOut.criteria.reset_level = VIN_UVLO_RELEASE;  // Set/reset fault release level value
    fltobj_UnderVoltageLockOut.criteria.reset_cnt_threshold = 10; // Set/reset number of successive resets before triggering fault release
        
    // specifying fault class, fault level and enable/disable status
    fltobj_UnderVoltageLockOut.classes.flags.notify = 0;   // Set =1 if this fault object triggers a fault condition notification
    fltobj_UnderVoltageLockOut.classes.flags.warning = 0;  // Set =1 if this fault object triggers a warning fault condition response
    fltobj_UnderVoltageLockOut.classes.flags.critical = 1; // Set =1 if this fault object triggers a critical fault condition response
    fltobj_UnderVoltageLockOut.classes.flags.catastrophic = 0; // Set =1 if this fault object triggers a catastrophic fault condition response

    fltobj_UnderVoltageLockOut.classes.flags.user_class = 1; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_UnderVoltageLockOut.user_fault_action = &cvrt_ShutDown;
    fltobj_UnderVoltageLockOut.user_fault_reset = 0; //&cvrt_StartUp;
    
    fltobj_UnderVoltageLockOut.status.flags.fltlvlhw = 0; // Set =1 if this fault condition is board-level fault condition
    fltobj_UnderVoltageLockOut.status.flags.fltlvlsw = 0; // Set =1 if this fault condition is software-level fault condition
    fltobj_UnderVoltageLockOut.status.flags.fltlvlsi = 0; // Set =1 if this fault condition is silicon-level fault condition
    fltobj_UnderVoltageLockOut.status.flags.fltlvlsys = 1; // Set =1 if this fault condition is system-level fault condition

    // This fault is initialized in a fault state to enforce that this fault condition has to be cleared
    // before the converter can run.
    
    fltobj_UnderVoltageLockOut.status.flags.fltstat = 1; // Set/ret fault condition as present/active
    fltobj_UnderVoltageLockOut.status.flags.fltactive = 1; // Set/reset fault condition as present/active
    fltobj_UnderVoltageLockOut.status.flags.fltchken = 1; // Enable/disable fault check
    
    return(1);
}


/*@@init_InputOverVoltageFaultObject
 * ***********************************************************************************************
 * Description:
 * The fltobj_OverVoltageLockOut is initialized here. This fault detects conditions occurring 
 * at start-up or during normal operation of the power converter.
 * ***********************************************************************************************/

inline uint16_t init_InputOverVoltageFaultObject(void)
{
    // Configuring the Task Time Quota Violation fault object
    fltobj_OverVoltageLockOut.object = &VIN_FB_ADCBUF;
    fltobj_OverVoltageLockOut.object_bit_mask = FAULT_OBJECT_BIT_MASK_DEFAULT;
    fltobj_OverVoltageLockOut.error_code = (uint32_t)FLTOBJ_OVLO;
    fltobj_OverVoltageLockOut.id = (uint16_t)FLTOBJ_OVLO;

    // configuring the trip and reset levels as well as trip and reset event filter setting
    fltobj_OverVoltageLockOut.criteria.counter = 0;      // Set/reset fault counter
    fltobj_OverVoltageLockOut.criteria.fault_ratio = FAULT_LEVEL_GREATER_THAN;
    fltobj_OverVoltageLockOut.criteria.trip_level = VIN_OVLO_TRIP;   // Set/reset trip level value
    fltobj_OverVoltageLockOut.criteria.trip_cnt_threshold = 10; // Set/reset number of successive trips before triggering fault event
    fltobj_OverVoltageLockOut.criteria.reset_level = VIN_OVLO_RELEASE;  // Set/reset fault release level value
    fltobj_OverVoltageLockOut.criteria.reset_cnt_threshold = 10; // Set/reset number of successive resets before triggering fault release

    // specifying fault class, fault level and enable/disable status
    fltobj_OverVoltageLockOut.classes.flags.notify = 0;   // Set =1 if this fault object triggers a fault condition notification
    fltobj_OverVoltageLockOut.classes.flags.warning = 0;  // Set =1 if this fault object triggers a warning fault condition response
    fltobj_OverVoltageLockOut.classes.flags.critical = 1; // Set =1 if this fault object triggers a critical fault condition response
    fltobj_OverVoltageLockOut.classes.flags.catastrophic = 0; // Set =1 if this fault object triggers a catastrophic fault condition response

    fltobj_OverVoltageLockOut.classes.flags.user_class = 1; // Set =1 if this fault object triggers a user-defined fault condition response
    fltobj_OverVoltageLockOut.user_fault_action = &cvrt_ShutDown;
    fltobj_OverVoltageLockOut.user_fault_reset = 0; //&cvrt_StartUp;
    
    fltobj_OverVoltageLockOut.status.flags.fltlvlhw = 0; // Set =1 if this fault condition is board-level fault condition
    fltobj_OverVoltageLockOut.status.flags.fltlvlsw = 0; // Set =1 if this fault condition is software-level fault condition
    fltobj_OverVoltageLockOut.status.flags.fltlvlsi = 0; // Set =1 if this fault condition is silicon-level fault condition
    fltobj_OverVoltageLockOut.status.flags.fltlvlsys = 1; // Set =1 if this fault condition is system-level fault condition

    // This fault is initialized in a fault state to enforce that this fault condition has to be cleared
    // before the converter can run.
    
    fltobj_OverVoltageLockOut.status.flags.fltstat = 1; // Set/ret fault condition as present/active
    fltobj_OverVoltageLockOut.status.flags.fltactive = 1; // Set/reset fault condition as present/active
    fltobj_OverVoltageLockOut.status.flags.fltchken = 1; // Enable/disable fault check
    
    return(1);
}
