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
/* @@tasks.c
 *****************************************************************************
 * File:   tasks.c
 *
 * Summary:
 * Defines lists of tasks which will be called by the scheduler
 *
 * Description:	
 * 
 * In this header file prototypes of external functions are added and combined
 * in arrays. These arrays (task lists) will be used by the task manager executing 
 * all tasks in a list in their order of appearance.
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


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

/* ***********************************************************************************************
 * INCLUDE OF HEADERS ALSO CONTAINING GLOBALLY AVAILABLE FUNCTION CALLS
 * ***********************************************************************************************/
  
#include "tasks.h"

/*@@Task Table
 *  *****************************************************************************************************
 * Task Table lists all tasks which will be called by the task manager
 * *****************************************************************************************************
 * This is the list which defines ALL available tasks as enumerated items of an array.
 * These enumerations will be combined freely in so called Task Flow Lists which will then be called
 * by the manager's function calls from the main loop
 * *****************************************************************************************************/

uint16_t (*Task_Table[])(void) = {
    
    // OS-level initialization
    task_Idle,              // simple task doing nothing 
    
    // Chip level initialization
    init_gpio,              // task initializing all used GPIOs in accordance to their application specific function
    init_irq,               // task initializing the interrupt controller
    init_dsp,               // task initializing all digital signal controller

    // cross-function modules
    init_FaultObjects, // call fault object initialization
    
    // board level initialization
    init_TaskOnBoardLED,    // task initializing the on-board LED control pin and debug LED data structure
    init_TaskSwitchButton,  // task initializing the expander board switch button
    init_TaskLEDRed,        // task initializing the red expander board LED
    init_TaskLEDGreen,      // task initializing the green expander board LED
    task_OnBoardLED,        // task toggling the on-board LED
    task_SwitchButton,      // task reading the expander board switch button status
    task_LEDRed,            // task operating the red expander board LED
    task_LEDRed_ForceOn,    // task forcing the red expander board LED into ON state
    task_LEDRed_ForceOff,   // task forcing the red expander board LED into OFF state
    task_LEDRed_ForceToggle, // task forcing the red expander board LED to toggle state
    task_LEDGreen,          // task operating the green expander board LED
    task_LEDGreen_ForceOn,    // task forcing the green expander board LED into ON state
    task_LEDGreen_ForceOff,   // task forcing the green expander board LED into OFF state
    task_LEDGreen_ForceToggle, // task forcing the green expander board LED to toggle state
    
    // System function / Special function initialization
    init_hsadc,             // task initializing the high-speed ADC module
    exec_launch_hsadc,      // task launching the pre-configured high-speed ADC module
    init_hspwm,             // task initializing the high-speed PWM module
    exec_launch_hspwm,      // task launching the pre-configured high-speed PWM module
    init_soft_start,  // task initializing the soft-start configuration object
    exec_soft_start,  // task soft-starting the converter

    init_VMC_Controller     // task initializing the voltage mode controller object
        
};


//task_id_no TaskIdFlags;

/*@@Task Flow Lists
 *  *****************************************************************************************************
 * Task Flow Lists 
 * *****************************************************************************************************
 * These lists are used to establish any order of the registered tasks to be executed.
 * As the task manager is running on a fixed tick rate, more critical tasks might be called
 * multiple times while less critical ones might only be called once.
 * *****************************************************************************************************/

uint16_t task_list_boot[] = {
    TASK_INIT_GPIO, // Step #0
    TASK_INIT_IRQ, // Step #1
    TASK_INIT_DSP, // Step #2
    TASK_INIT_ON_BOARD_LED, // Step #3
    TASK_INIT_SWITCH, // Step #4
    TASK_INIT_LED_RED, // Step #5
    TASK_INIT_LED_GREEN // Step #6
};
uint16_t task_list_boot_size = (sizeof(task_list_boot)/sizeof(task_list_boot[0]));

uint16_t task_list_device_startup[] = {
    TASK_IDLE, // Step #0
    TASK_INIT_FAULT_OBJECTS, // Step #1
    TASK_LED_GREEN_ON, // Step #2
    TASK_INIT_CNPNZ_VMC, // Step #3
    TASK_INIT_HSADC, // Step #4
    TASK_INIT_HSPWM, // Step #5
    TASK_INIT_SOFT_START, // Step #6
    TASK_LAUNCH_HSPWM, // Step #7
    TASK_LAUNCH_HSADC // Step #8
};
uint16_t task_list_device_startup_size = (sizeof(task_list_device_startup)/sizeof(task_list_device_startup[0]));

uint16_t task_list_system_startup[] = {
    TASK_IDLE, // Step #0
    TASK_LED_RED_ON, // Step #2
    TASK_EXEC_SOFT_START // Step #3
};
uint16_t task_list_system_startup_size = (sizeof(task_list_system_startup)/sizeof(task_list_system_startup[0]));

uint16_t task_list_normal[] = {
    TASK_IDLE, // Step #0
    TASK_ON_BOARD_LED, // Step #1
    TASK_READ_SWITCH, // Step #2
    TASK_LED_RED, // Step #3
    TASK_LED_GREEN // Step #4
};
uint16_t task_list_normal_size = (sizeof(task_list_normal)/sizeof(task_list_normal[0]));

uint16_t task_list_fault[] = {
    TASK_IDLE, // Step #0
    TASK_ON_BOARD_LED, // Step #1
    TASK_READ_SWITCH, // Step #2
    TASK_LED_RED, // Step #3
    TASK_LED_GREEN // Step #4
};
uint16_t task_list_fault_size = (sizeof(task_list_fault)/sizeof(task_list_fault[0]));

uint16_t task_list_standby[] = {
    TASK_IDLE, // Step #0
    TASK_ON_BOARD_LED, // Step #1
    TASK_READ_SWITCH, // Step #2
    TASK_LED_RED, // Step #3
    TASK_LED_GREEN // Step #4
};
uint16_t task_list_standby_size = (sizeof(task_list_standby)/sizeof(task_list_standby[0]));

// EOF