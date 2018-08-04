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

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _HARDWARE_ABSTRACTION_LAYER_FAULT_HANDLER_H_
#define	_HARDWARE_ABSTRACTION_LAYER_FAULT_HANDLER_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

#include "globals.h"


/*@@fault_object_index
 * ***********************************************************************************************
 * Description:
 * The enumeration fault_object_index provides a list of friendly labels to access user-defined
 * fault objects in fault_object_list[] more comfortably. Labels also allow fast reordering of the
 * array items without further code edits
 * 
 * Please note:
 * The enumerated indices have to match the fault object indices in
 * fault_object[]. It is therefore vital that the enumeration labels are in the exact same order 
 * as the fault objects listed in fault_object_list[]! 
 * ***********************************************************************************************/

typedef enum {
    FLTOBJ_CPU_LOAD_OVERRUN = 0, // CPU load counter exceeds task period => not enough bandwidth
    FLTOBJ_TASK_EXECUTION_FAILURE = 1, // Fault object Task Execution Failure
    FLTOBJ_TASK_TIME_QUOTA_VIOLATION = 2, // Fault object Task Time Quota Violation
        
    FLTOBJ_SOFT_START = 3, // Fault object Soft-Start Failure

    FLTOBJ_UVLO = 4, // Fault object Under Voltage Lock-Out
    FLTOBJ_OVLO = 5, // Fault object Over Voltage Lock-Out
    FLTOBJ_OVP  = 6, // Fault object Output Over Voltage Protection
    FLTOBJ_OCP  = 7, // Fault object Over Current Protection
    FLTOBJ_OTW  = 8, // Fault object Over Temperature Warning
    FLTOBJ_OTP  = 9  // Fault object Over Temperature Protection
}fault_object_index_e;

typedef enum
{
    ERR_CPU_LOAD_OVERRUN = 0b0000000000000001, // CPU load counter exceeds task period => not enough bandwidth
    ERR_TASK_EXECUTION_FAILURE    = 0b0000000000000010, // Fault object Task Execution Failure
    ERR_TASK_TIME_QUOTA_VIOLATION = 0b0000000000000100, // Fault object Task Time Quota Violation

    ERR_UVLO = 0b0000000000001000, // Fault object Under Voltage Lock-Out
    ERR_OVLO = 0b0000000000010000, // Fault object Over Voltage Lock-Out
    ERR_OVP  = 0b0000000000100000, // Fault object Output Over Voltage Protection
    ERR_OCP  = 0b0000000001000000, // Fault object Over Current Protection
    ERR_OTW  = 0b0000000010000000, // Fault object Over Temperature Warning
    ERR_OTP  = 0b0000000100000000  // Fault object Over Temperature Protection
}FAULT_OBJECT_ERROR_CODE_e;

/* PROTOTYPES */
extern volatile uint16_t init_FaultObjects();

#endif	/* _HARDWARE_ABSTRACTION_LAYER_FAULT_HANDLER_H_ */

