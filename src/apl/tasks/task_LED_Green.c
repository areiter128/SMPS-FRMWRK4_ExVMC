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
/*@@task_LED_Green.h
 * ***************************************************************************
 * File:   task_LED_Green.h
 * Author: M91406
 * 
 * Summary:
 * Source file of green LED expander board LED task
 * 
 * Description:
 * This source file is used to register a global data structure allowing to edit
 * parameters of the task. It is also used to publish global function calls.
 * 
 * The main task routine is operating the green LED of the expander board by 
 * applying the status setting in the data structure.
 * 
 * History:
 * 05/03/2018	File created
 * ***************************************************************************/


#include "xc.h"
#include "hal.h"
#include "task_Switch.h"
#include "task_LED_Green.h"


FUNCTION_LED_CONFIG_t taskLEDGREEN_config;


uint16_t task_LEDGreen_ForceOn(void)
{
    LED_GN_WR = LED_ON;
    taskLEDGREEN_config.pin_status = LED_GN_RD;     // Reading active pin status
    return(1);
}

uint16_t task_LEDGreen_ForceOff(void)
{
    LED_GN_WR = LED_OFF;
    taskLEDGREEN_config.pin_status = LED_GN_RD;     // Reading active pin status
    return(1);
}

uint16_t task_LEDGreen_ForceToggle(void)
{
    LED_GN_WR ^= 1;
    taskLEDGREEN_config.pin_status = LED_GN_RD;     // Reading active pin status
    return(1);
}

uint16_t task_LEDGreen(void)
{
    if(taskSWITCH_config.status == SWITCH_OPEN) { LED_GN_WR = LED_ON; }
    else { LED_GN_WR = LED_OFF; }
    
    taskLEDGREEN_config.pin_status = LED_GN_RD;     // Reading active pin status
    if(LED_GN_RD == LED_GN_WR)
    {
        taskLEDGREEN_config.status = taskLEDGREEN_config.enable;
    }
    else
    {
        taskLEDGREEN_config.status = LED_STATUS_FAILURE;
    }
    
    return(taskLEDGREEN_config.status);
}

uint16_t init_TaskLEDGreen(void)
{
    LED_GN_WR = LED_OFF;
    LED_GN_TRIS = 0;
    
    taskLEDGREEN_config.pin_status = LED_OFF;
    taskLEDGREEN_config.status = LED_OFF;
    taskLEDGREEN_config.enable = 1;
    
    return(1);
}

