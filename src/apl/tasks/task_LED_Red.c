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
/*@@task_LED_Red.h
 * ***************************************************************************
 * File:   task_LED_Red.h
 * Author: M91406
 * 
 * Summary:
 * Source file of red LED expander board LED task
 * 
 * Description:
 * This source file is used to register a global data structure allowing to edit
 * parameters of the task. It is also used to publish global function calls.
 * 
 * The main task routine is operating the red LED of the expander board by 
 * applying the status setting in the data structure.
 * 
 * History:
 * 05/03/2018	File created
 * ***************************************************************************/


#include "xc.h"
#include "hal.h"
#include "task_Switch.h"
#include "task_LED_Red.h"

volatile FUNCTION_LED_CONFIG_t taskLEDRED_config;

volatile uint16_t task_LEDRed_ForceOn(void)
{
    LED_RD_WR = LED_ON;
    return(1);
}

volatile uint16_t task_LEDRed_ForceOff(void)
{
    LED_RD_WR = LED_OFF;
    return(1);
}

volatile uint16_t task_LEDRed_ForceToggle(void)
{
    LED_RD_WR ^= 1;
    return(1);
}

volatile uint16_t task_LEDRed(void)
{
    if(taskSWITCH_config.status == SWITCH_CLOSED) LED_RD_WR = LED_ON;
    else {LED_RD_WR = LED_OFF;}
    
    return(1);
}

volatile uint16_t init_TaskLEDRed(void)
{
    LED_RD_WR = LED_OFF;
    LED_RD_TRIS = 0;
    
    taskLEDRED_config.pin_status = LED_OFF;
    taskLEDRED_config.status = LED_OFF;
    taskLEDRED_config.enable = 1;
    
    return(1);
}


