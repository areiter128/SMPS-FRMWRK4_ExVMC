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
/* @@fdrv_FaultHandler.c
 * ****************************************************************************
 * File:   fdrv_FaultHandler.c
 * Author: M91406
 *
 * Description:
 * This source file provides multiple functions to set up and monitor user-
 * defined fault objects as well as routines handling default fault cases.
 * 
 * History:
 * Created on June 22, 2018, 01:14 PM
 ******************************************************************************/

#include "xc.h"
#include <stdint.h>
#include "fdrv_FaultHandler.h"

/* private function prototypes */
inline uint16_t CheckFaultCondition(FAULT_OBJECT_t* fltobj);
inline uint16_t ExecFaultHandler(FAULT_OBJECT_t* fltobj);

/*@@fault_object_list_pointer
 * ***********************************************************************************************
 * Description:
 * The fault_object_list_pointer variable is used by the exec_FaultCheckSequential() function.
 * Instead of checking all fault objects at once, this routine checks one fault object  
 * declared in fault_object_list[] at a time. After the last item was checked, the 
 * fault_object_list_pointer is automatically reset and starts from fault_object_list[0].
 * ***********************************************************************************************/
volatile uint16_t fault_object_list_pointer = 0;

/*@@CheckFaultCondition
 * ***********************************************************************************************
 * Parameters:
 *      FAULT_OBJECT_t* fltobj: Pointer to fault object fltobj of type FAULT_OBJECT_t, holding
 *          all the information about fault conditions, fault class, and further user-defined
 *          settings.
 * 
 * Return:
 *      type: uint16_t
 *      0: Failure
 *      1: Success
 * 
 * Description:
 * The fault_object_list_pointer variable is used by the exec_FaultCheckSequential() function.
 * Instead of checking all fault objects at once, this routine checks one fault object  
 * declared in fault_object_list[] at a time. After the last item was checked, the 
 * fault_object_list_pointer is automatically reset and starts from fault_object_list[0].
 * ***********************************************************************************************/
inline uint16_t CheckFaultCondition(FAULT_OBJECT_t* fltobj)
{
    volatile uint16_t fres = 0, compare_value = 0;
    
    // if the fault object is not initialized, exit here
    if(!fltobj->object == NULL) { return(1); }
    
    // if the fault check of this object is disabled, exit here
    if(!fltobj->status.flags.fltchken){ return(1); }

    // derive value to monitor
    compare_value = ((*fltobj->object) & (fltobj->object_bit_mask));
    
    // Check the given fault object on threshold violations
    if(fltobj->criteria.fault_ratio == (FAULT_LEVEL_RATIO_GREATER_THAN))
    {
        // if the fault level is defined to be greater than a given threshold...
        // (=> checking for maximum thresholds))
        
        if(compare_value > fltobj->criteria.trip_level)
        { // if the upper threshold is exceeded, increase error counter
            fltobj->status.flags.fltstat |= 1; // set "fault present" bit
            fltobj->criteria.counter++; // increment fault counter
        }
        else if(compare_value < fltobj->criteria.reset_level)
        { // if the value is below the lower limit of the hysteresis of the threshold, 
          // reset error counter
            fltobj->status.flags.fltstat &= 0; // reset "fault present" bit
            fltobj->criteria.counter = 0; // reset fault counter
        }
        else
        {
          // if the value hovers within the hysteresis of the threshold => do nothing
            Nop();
        }
    }
    else if (fltobj->criteria.fault_ratio == (FAULT_LEVEL_RATIO_LESS_THAN))
    {
        // if the fault level is defined to be less than a given threshold 
        // (=> checking for minimum thresholds))
        
        
        if(compare_value < fltobj->criteria.trip_level)
        { // if the lower threshold is exceeded, increase error counter
            fltobj->status.flags.fltstat |= 1; // set "fault present" bit
            fltobj->criteria.counter++; // increment fault counter
        }
        else if(compare_value > fltobj->criteria.reset_level)
        { // if the value is above the upper limit of the hysteresis of the threshold, 
          // reset error counter
            fltobj->criteria.counter = 0; // reset fault counter
        }
        else
        {
          // if the value hovers within the hysteresis of the threshold => do nothing
            Nop();
        }
    }
    else
    { // Uups -> something went horribly wrong => exit
        Nop();
        return(0);
    }
    
    // check if fault filter counter limited have been exceeded
    if(fltobj->criteria.counter >= fltobj->criteria.trip_cnt_threshold)
    {
        // Call fault handler passing on the recent fault object
        fltobj->status.flags.fltactive |= 1; // set "fault active" bit
        fres = ExecFaultHandler(fltobj); // call fault handler routine
    }
    else
    {
        fltobj->status.flags.fltstat &= 0; // reset "fault present" bit
        fltobj->status.flags.fltactive &= 0; // set "fault active" bit
    }
    
    return(fres);
}

/*@@CheckCPUResetRootCause
 * ***********************************************************************************************
 * Parameters: (none)
 *      
 * Return:
 *      type: uint16_t
 *      0: Failure
 *      1: Success
 * 
 * Description:
 * This routine analyzes the traplog object and CPU RESET register RCON for the latest events.
 * The register status is triaged in critical, warning and notification-level reset causes.
 * If a critical condition was detected, this functions returns 
 * 
 *     0 = Failure (critical-level reset condition)
 *     1 = Success (notification-level reset condition)
 *     2 = Warning (warning-level reset condition)
 * ***********************************************************************************************/
inline uint16_t CheckCPUResetRootCause(void)
{
    volatile uint16_t fres = 0;
    
    // TODO: return value needs to be properly defined and made accessible and fault handling 
    // routines need to be installed
    
    traplog.rcon_reg.reg_block = RCON; // Copy contents of CPU RESET register into monitoring buffer
    
    if (traplog.rcon_reg.reg_block & FLT_CPU_RESET_CLASS_CRITICAL) {
        /* TODO: handle exceptions after restart */
        Nop();    
        Nop();   
        
        fres = 0;
    }
    else if (traplog.rcon_reg.reg_block & FLT_CPU_RESET_CLASS_WARNING) {
        /* TODO: handle exceptions after restart */
        Nop();    
        Nop();    

        fres = 2;
    }
    else {
        /* TODO: handle exceptions after restart */
        Nop();    
        Nop();    

        fres = 1;
    }

    return(fres);
}

/*@@ExecFaultHandler
 * ***********************************************************************************************
 * Parameters: 
 *      FAULT_OBJECT_t* fltobj: Pointer to fault object fltobj of type FAULT_OBJECT_t, holding
 *          all the information about fault conditions, fault class, and further user-defined
 *          settings.
 * 
 * Return:
 *      type: uint16_t
 *      0: Failure
 *      1: Success
 * 
 * Description:
 * This routine executes pre-defined standard actions when a fault of FAULT_OBJECT_CLASS_e has 
 * been detected. 
 * 
 *      - FLT_CLASS_CATASTROPHIC:
 *          * the global fault flag will be set
 *          * the scheduler will be set in OP_MODE_FAULT
 *          * the main loop will be ended to enforce a warm CPU restart
 * 
 *      - FLT_CLASS_CRITICAL:
 *          * the global fault flag will be set
 *          * the scheduler will be set in OP_MODE_FAULT
 * 
 *      - FLT_CLASS_WARNING:
 *          * the global warning flag will be set
 * 
 *      - FLT_CLASS_NOTICE:
 *          * the global notify flag will be set
 * 
 *      - FLT_CLASS_USER_ACTION:
 *          * the global notify flag will be set
 *          * a user defined function will be called (of form uint16_t xxxx(void) only)
 * 
 * ***********************************************************************************************/
inline uint16_t ExecFaultHandler(FAULT_OBJECT_t* fltobj)
{
    volatile uint16_t fres = 0, log_id = 0;
    
    if(fltobj->classes.class & FLT_CLASS_CATASTROPHIC)
    {
        // if fault is of class CATASTROPHIC, force main loop to reset CPU
        application.fault_status.flags.global_fault = 1;  // setting global fault bit
        task_mgr.op_mode.mode = OP_MODE_FAULT; // force main scheduler into fault mode
        log_id = fltobj->id;
        run_main_loop = 0;
        return(1);
    }
    else
    {
        // if fault is of any other class than CATASTROPHIC, perform response. 
        // Multiple responses are supported when the multiple fault classes are specified
        // by ORing multiple FAULT CLASSES into fltobj.classes

        if(fltobj->classes.class & FLT_CLASS_CRITICAL)
        {
            // if fault is of class CRITICAL, set error flag and force schedule in standby mode
            application.fault_status.flags.global_fault = 1;  // set global fault bit
            task_mgr.op_mode.mode = OP_MODE_FAULT; // force main scheduler into fault mode
        }

        if(fltobj->classes.class & FLT_CLASS_WARNING)
        {
            // if fault is of class CRITICAL, set error flag and force schedule in standby mode
            application.fault_status.flags.global_warning = 1;  // set global warning bit 
                                                          // and don't take further action
        }

        if(fltobj->classes.class & FLT_CLASS_NOTICE)
        {
            // if fault is of class CRITICAL, set error flag and force schedule in standby mode
            application.fault_status.flags.global_notice = 1;  // setting global notify bit
                                                         // and don't take further action
        }

        if(fltobj->classes.class & FLT_CLASS_USER_ACTION)
        {
            // if fault object is a USER_CLASS, fault response is handled in an external function
            application.fault_status.flags.global_usrflt = 1;
            log_id = fltobj->id;
            fres = fltobj->user_action(); // Call/execute user defined function of type uint16_t xxxx(void) only
        }

    }
    return(fres);
}

/*@@exec_FaultCheckAll
 * ***********************************************************************************************
 * Parameters: 
 *      (none)
 * 
 * Return:
 *      type: uint16_t
 *      0: Failure
 *      1: Success
 * 
 * Description:
 * This routine checks all fault objects listed in *fault_object_list[] in one execution cycle.
 * any fault action triggered will be executed immediately after every individual fault object 
 * check.
 * ***********************************************************************************************/
uint16_t exec_FaultCheckAll(void)
{
    volatile uint16_t i = 0, fres = 0;
    
    // scan all fault objects for active fault flags
    for (i=0; i<fltobj_list_size; i++)
    {
        fres &= CheckFaultCondition(fault_object_list[i]);
    }

    return(fres);

}

/*@@exec_FaultCheckSequential
 * ***********************************************************************************************
 * Parameters: 
 *      (none)
 * 
 * Return:
 *      type: uint16_t
 *      0: Failure
 *      1: Success
 * 
 * Description:
 * This routine checks one fault object listed in *fault_object_list[] sequentially, one at a time
 * and only one per function call. With every call the fault_object_list_pointer is incremented for
 * the next function call. 
 * Any fault action triggered by any of the fault objects, will be executed immediately after every 
 * individual fault object check.
 * ***********************************************************************************************/
uint16_t exec_FaultCheckSequential(void)
{
    volatile uint16_t fres = 0;
    
    // check next fault object
    fres = CheckFaultCondition(fault_object_list[fault_object_list_pointer]);

    // check fault_object_list_pointer overrun
    if(fault_object_list_pointer++ >= fltobj_list_size) fault_object_list_pointer = 0;
    
    return(fres);

}
/*************************************************************************************************/
