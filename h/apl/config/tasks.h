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
/*@@tasks.h
 *****************************************************************************
 * File:   tasks.h
 *
 * Summary:
 * Globally defines the task list and operating modes
 *
 * Description:	
 * -
 *
 * References:
 * -
 *
 * See also:
 * task_manager.c
 * task_manager.h
 * 
 * Revision history: 
 * 07/27/16     Initial version
 * Author: M91406
 * Comments:
 *****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _APPLICATION_LAYER_TASK_FLOW_LISTS_H_
#define	_APPLICATION_LAYER_TASK_FLOW_LISTS_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <math.h>

/* ***********************************************************************************************
 * INCLUDE OF HEADERS ALSO CONTAINING GLOBALLY AVAILABLE FUNCTION CALLS
 * ***********************************************************************************************/
#include "apl.h"

/* *****************************************************************************************************
 * Prototypes of external function used in task lists
 * *****************************************************************************************************
 * Functions which should be used in task flow lists can be prototyped here. The functions can
 * come from any source and are usually located in external C-files.
 * 
 * Limitations:
 *   - function has to be of the type int xxx (void)
 *   - The function must return an integer value
 *   - The function cannot take specific parameters
 *   - Specific parameters have to be derived from global or private data structures
 *
 * *****************************************************************************************************/

// All User Tasks are defined here
/*
extern uint16_t init_gpio(void);         // Initialize GPIOs
extern uint16_t init_oscillator(void);   // Initialize main oscillator
extern uint16_t init_system_timer(void);        // Initialize timer
extern uint16_t launch_system_timer(void);      // Start timer
 */
/* Prototypes of additional initialization task functions */

/*@@Task Table
 * *****************************************************************************************************
 * Task Table lists all tasks which will be called by the task manager
 * *****************************************************************************************************
 * This is the list which defines ALL available tasks as enumerated items of an array.
 * These enumerations will be combined freely in so called Task Flow Lists which will then be called
 * by the manager's function calls from the main loop
 * *****************************************************************************************************/

extern volatile uint16_t(*Task_Table[])(void);

/*@@task_id_no_e
 * *****************************************************************************************************
 * The task_id_no_e enum is for easy addressing task-items from Task_Table using readable 
 * defines instead of indices. 
 * *****************************************************************************************************/
typedef enum {
    
    // OS-level initialization
    TASK_IDLE, // Default task not performing any action but occupying a task time frame
        
    // Chip level initialization
    TASK_INIT_GPIO, // Task initializing the chip GPIOs
    TASK_INIT_IRQ, // Task initializing the interrupt controller
    TASK_INIT_DSP, // Task initializing the digital signal controller
        
    // cross-function modules
    TASK_INIT_FAULT_OBJECTS, // Task initializing default and user defined fault objects

    // board level initialization
    TASK_INIT_ON_BOARD_LED, // Task initializing the on-board debug LED
    TASK_INIT_SWITCH, // Task initializing the expander board switch button
    TASK_INIT_LED_RED, // Task initializing the red expander board debug LED
    TASK_INIT_LED_GREEN, // Task initializing the green expander board debug LED
    TASK_ON_BOARD_LED, // Task controlling the on-board debug LED
    TASK_READ_SWITCH, // Task reading expander board switch button status
    TASK_LED_RED, // Task initializing the red expander board debug LED
    TASK_LED_RED_ON, // task forcing the red expander board LED into ON state
    TASK_LED_RED_OFF, // task forcing the red expander board LED into OFF state
    TASK_LED_RED_TOGGLE, // task forcing the red expander board LED to toggle state
    TASK_LED_GREEN, // Task initializing the green expander board debug LED
    TASK_LED_GREEN_ON, // task forcing the green expander board LED into ON state
    TASK_LED_GREEN_OFF, // task forcing the green expander board LED into OFF state
    TASK_LED_GREEN_TOGGLE, // task forcing the green expander board LED to toggle state

    // System function / Special function initialization
    TASK_INIT_UART, // Task initializing the debugging UART interface
    TASK_EXEC_UART, // Task executing the debugging UART communication
    TASK_INIT_HSADC, // Task initializing the high speed ADC module
    TASK_LAUNCH_HSADC, // Task launching the pre-configured high speed ADC module
    TASK_INIT_HSACMP, // Task initializing the high speed analog comparator module
    TASK_LAUNCH_HSACMP, // Task launching the pre-configured high speed analog comparator module
    TASK_INIT_HSPWM, // Task initializing the high speed PWM module
    TASK_LAUNCH_HSPWM, // Task launching the pre-configured high speed PWM module
    TASK_INIT_SOFT_START, // Task initializing the soft-start procedure
    TASK_EXEC_SOFT_START, // Task soft-starting the power converter

    #if (INCLUDE_SOFT_SHUT_DOWN == 1)
    TASK_INIT_SOFT_SHUT_DOWN, // Task initializing the soft-shut down procedure
    TASK_EXEC_SOFT_SHUT_DOWN, // Task soft-shutting down the power converter
    #endif
        
    TASK_INIT_CNPNZ_VMC // task initializing the voltage mode controller object

} task_id_no_e;

/*@@Task Flow Lists
 *  *****************************************************************************************************
 * Task Flow Lists 
 * *****************************************************************************************************
 * These lists are used to establish any order of the registered tasks to be executed.
 * As the task manager is running on a fixed tick rate, more critical tasks might be called
 * multiple times while less critical ones might only be called once.
 * *****************************************************************************************************/

extern volatile uint16_t task_list_boot[];
extern volatile uint16_t task_list_boot_size;

extern volatile uint16_t task_list_device_startup[];
extern volatile uint16_t task_list_device_startup_size;

extern volatile uint16_t task_list_system_startup[];
extern volatile uint16_t task_list_system_startup_size;

#if (INCLUDE_SOFT_SHUT_DOWN == 1)
extern volatile uint16_t task_list_system_shut_down[];
extern volatile uint16_t task_list_system_shut_down_size;
#endif

extern volatile uint16_t task_list_normal[];
extern volatile uint16_t task_list_normal_size;

extern volatile uint16_t task_list_fault[];
extern volatile uint16_t task_list_fault_size;

extern volatile uint16_t task_list_standby[];
extern volatile uint16_t task_list_standby_size;

#endif	/* _APPLICATION_LAYER_TASK_FLOW_LISTS_H_ */

