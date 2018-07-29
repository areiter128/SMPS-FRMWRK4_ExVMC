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
 * Header of green LED expander board LED task
 * 
 * Description:
 * This header is used to register a global data structure allowing to edit
 * parameters of the task. It is also used to publish global function calls.
 * 
 * The main task routine is operating the green LED of the expander board by 
 * applying the status setting in the data structure.
 * 
 * History:
 * 05/03/2018	File created
 * ***************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APL_TASK_BOARD_LED_GREEN_H
#define	APL_TASK_BOARD_LED_GREEN_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "fdrv_FunctionLED.h"

/* ***********************************************************************************************
 * DECLARATIONS
 * ***********************************************************************************************/

extern FUNCTION_LED_CONFIG_t taskLEDGREEN_config;


/* ***********************************************************************************************
 * PROTOTYPES
 * ***********************************************************************************************/
extern uint16_t init_TaskLEDGreen(void);
extern uint16_t task_LEDGreen(void);
extern uint16_t task_LEDGreen_ForceOn(void);
extern uint16_t task_LEDGreen_ForceOff(void);
extern uint16_t task_LEDGreen_ForceToggle(void);


#endif	/* APL_TASK_BOARD_LED_GREEN_H */

