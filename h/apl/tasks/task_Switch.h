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
 * Header of switch button task
 * 
 * Description:
 * This header is used to register a global data structure allowing to edit
 * parameters of the task. It is also used to publish global function calls.
 * the main task routine is polling on the switch button of the DSP expander
 * board. When a switch event has been triggered, a global switch event flag 
 * is set in the task_Switch data structure for other tasks to respond to.
 * 
 * History:
 * 05/03/2018	File created
 * ***************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APL_TASK_SWITCH_BUTTON_H
#define	APL_TASK_SWITCH_BUTTON_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

/* ***********************************************************************************************
 * DECLARATIONS
 * ***********************************************************************************************/

typedef struct
{
    volatile uint16_t enable;               // Enable/Disable flag 
    volatile uint16_t status;               // used globally publish the switch button status
}TASK_SWITCH_BUTTON_CONFIG_t;

extern TASK_SWITCH_BUTTON_CONFIG_t taskSWITCH_config;

#define SWITCH_DELAY_COUNTER_DEFAULT   500
#define SWITCH_DELAY_COUNTER_FAULT     2500

/* ***********************************************************************************************
 * PROTOTYPES
 * ***********************************************************************************************/
extern uint16_t init_TaskSwitchButton(void);
extern uint16_t task_SwitchButton(void);


#endif	/* APL_TASK_SWITCH_BUTTON_H */

