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
/*@@task_DebugLED.h
 * ***************************************************************************
 * File:   task_DebugLED.h
 * Author: M91406
 * 
 * Summary:
 * Header of debug LED task
 * 
 * Description:
 * This header is used to register a global data structure allowing to edit
 * parameters of the task. It is also used to publish global function calls.
 * 
 * History:
 * 07/28/2017	File created
 * ***************************************************************************/

#ifndef APL_TASK_ON_BOARD_LED_H
#define	APL_TASK_ON_BOARD_LED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

/* ***********************************************************************************************
 * DECLARATIONS
 * ***********************************************************************************************/
/*
// Generic definition of a 16-bit with port register
typedef struct tagLATDBITS {
  uint16_t LATx0:1;
  uint16_t LATx1:1;
  uint16_t LATx2:1;
  uint16_t LATx3:1;
  uint16_t LATx4:1;
  uint16_t LATx5:1;
  uint16_t LATx6:1;
  uint16_t LATx7:1;
  uint16_t LATx8:1;
  uint16_t LATx9:1;
  uint16_t LATx10:1;
  uint16_t LATx11:1;
  uint16_t LATx12:1;
  uint16_t LATx13:1;
  uint16_t LATx14:1;
  uint16_t LATx15:1;
} __attribute__((packed))LATxbits;
*/
    
typedef struct
{
    volatile uint16_t pin_status;           // pin status (on/off) driving command
    volatile uint16_t delay_counter;        // used for locally increment LED delay counter
    volatile uint16_t delay_counter_max;    // LED toggle threshold
    volatile uint16_t enable;               // Enable/Disable flag 
    volatile uint16_t status;               // used to globally publish the switch button status
}TASK_ON_BOARD_LED_CONFIG_t;

extern volatile TASK_ON_BOARD_LED_CONFIG_t taskOnBoardLED_config;

#define LED_DELAY_COUNTER_DEFAULT   500
#define LED_DELAY_COUNTER_FAULT     100

/* ***********************************************************************************************
 * PROTOTYPES
 * ***********************************************************************************************/
extern volatile uint16_t init_TaskOnBoardLED(void);
extern volatile uint16_t task_OnBoardLED(void);
extern volatile uint16_t dispose_TaskOnBoardLED(void);

#endif	/* APL_TASK_ON_BOARD_LED_H */

// EOF
