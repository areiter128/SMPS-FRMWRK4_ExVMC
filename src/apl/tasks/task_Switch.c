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
/*@@task_Switch.h
 * ***************************************************************************
 * File:   task_Switch.h
 * Author: M91406
 * 
 * Summary:
 * Source file of switch button task
 * 
 * Description:
 * This source file is used to register a global data structure allowing to edit
 * parameters of the task. It is also used to publish global function calls.
 * the main task routine is polling on the switch button of the DSP expander
 * board. When a switch event has been triggered, a global switch event flag 
 * is set in the task_Switch data structure for other tasks to respond to.
 * 
 * History:
 * 05/03/2018	File created
 * ***************************************************************************/


#include "xc.h"
#include "task_Switch.h"
#include "hal.h"

volatile TASK_SWITCH_BUTTON_CONFIG_t taskSWITCH_config;

volatile uint16_t task_SwitchButton(void) 
{

    if(taskSWITCH_config.enable)
    {
        taskSWITCH_config.status = SWITCH_RD;   // Read the switch status
    }
    else
    {
        taskSWITCH_config.status = 0;           // Set the switch status to zero
    }

    return(1);
}

volatile uint16_t init_TaskSwitchButton(void)
{
    // Setting up the port pin
    SWITCH_WR = 1;
    SWITCH_TRIS = 1;
    
    taskSWITCH_config.status = SWITCH_RD;   // Read the switch status
    taskSWITCH_config.enable = 1;           // Enable the switch task
    
    return(1);
}