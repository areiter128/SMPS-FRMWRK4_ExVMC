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
/* @@task_DebugLED.c
 *****************************************************************************
 * File:   task_DebugLED.c
 * Author: M91406
 *
 * Description:
 * This function driver file is used to toggle an on-board debugging LED. In
 * order to use this function, it needs to be configured by default settings
 * in task_DebugLED.h used to initialize a variable of the t_TASK_DEBUG_LED_CONFIG 
 * data structure. 
 * These parameters are:
 * 
 * - enable:        enables/disables the function without changing its configuration
 *                  When disabled, the debug LED is turned constantly off by the library.
 * - delay_counter: this is a private variable counting function calls until the 
 *                  debug LED state needs to be changed
 * - delay_counter_max: this is the threshold of function call ticks at which
 *                  the debug LED state is changed
 * 
 * 
 * History:
 * Created on July 27, 2016, 11:32 PM
 ******************************************************************************/


#include "xc.h"
#include <stdint.h>
#include "globals.h"
#include "task_OnPIM_LED.h"

/* Private Variable Declarations */

TASK_ON_BOARD_LED_CONFIG_t taskOnBoardLED_config;

/* Public Functions globalized by declarations in task_DebugLED.h */

uint16_t task_OnBoardLED(void) {

    uint16_t fres=0;
    
    // change blink-rate in case of an active fault operating mode
    if (task_mgr.op_mode.mode == OP_MODE_FAULT)
    { taskOnBoardLED_config.delay_counter_max = LED_DELAY_COUNTER_FAULT; }
    else
    { taskOnBoardLED_config.delay_counter_max = LED_DELAY_COUNTER_DEFAULT; }
    
    
    // If on-board debug LED function is enabled, toggle LED control output pin
    if (taskOnBoardLED_config.enable)
    {
        // The delay counter is reducing the toggle frequency to make it visible
        if(taskOnBoardLED_config.delay_counter++ > taskOnBoardLED_config.delay_counter_max)
        {
            DBGLED1_WR ^= 1;                    // Toggle on-board Debug LED
            taskOnBoardLED_config.delay_counter = 0;   // reset filter counter
        }
    }
    else
    {
        // if LED function is disabled, turn off LED
        DBGLED1_WR = LED_OFF;
    }
    
    // Check if LED control output pin state meets programmed state
    if(DBGLED1_WR == DBGLED1_RD) fres = 1;
    
    return(fres);
    
}


uint16_t init_TaskOnBoardLED(void) {
    
    DBGLED1_TRIS = LED_OUTPUT;
    DBGLED1_WR = LED_ON;
    
    taskOnBoardLED_config.delay_counter = 0;
    taskOnBoardLED_config.delay_counter_max = LED_DELAY_COUNTER_DEFAULT;
    taskOnBoardLED_config.enable = 1;
    
    return(taskOnBoardLED_config.enable);
    
}

uint16_t dispose_TaskOnBoardLED(void) {
    
    taskOnBoardLED_config.delay_counter = 0;
    taskOnBoardLED_config.delay_counter_max = 0;
    taskOnBoardLED_config.enable = 0;

    DBGLED1_WR = PINSTATE_HIGH;
    DBGLED1_TRIS = PINDIR_INPUT;
    
    return(DBGLED1_RD);
    
}

/* Private Functions */

// (none)

// EOF
