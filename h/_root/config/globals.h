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

/*@@globals.h
 * ***********************************************************************************************
 * File:   globals.h
 * Author: M91406
 * 
 * Summary:
 * Global variables are published here
 * 
 * Description:
 * Global variables, function prototypes and other declarations are published globally by referencing 
 * to external declarations in other project files. 
 * 
 * History:
 * 07/28/2017	File created
 * ***********************************************************************************************/

#ifndef PROJECT_GLOBAL_DECLARATIONS_H
#define	PROJECT_GLOBAL_DECLARATIONS_H


/* ***********************************************************************************************
 * DEFAULT INCLUDES
 * ***********************************************************************************************/

#include <stdint.h>
#include "traps.h"

#include "task_manager.h"

/* ***********************************************************************************************
 * PROJECT SPECIFIC INCLUDES
 * ***********************************************************************************************/

#include "apl.h"
#include "hal.h"
#include "mcal.h"
#include "sfl.h"

/* ***********************************************************************************************
 * DECLARATIONS
 * ***********************************************************************************************/

/*@@SPECIAL_FUNCTION_REGISTER_t
 *****************************************************************************
 * 
 * Summary:
 * Universal masking data structure to conveniently address generic 
 * Special Function Registers
 *
 * Description:	
 * This data structure is an empty frame which can be used as data mask
 * for local copies of or pointers to specific registers for operations
 * requiring single-bit manipulations 
 *
 * See also:
 * 
 *****************************************************************************/

 typedef struct
 {
     volatile uint16_t bit0:1;	// Bit #0:  generic bit placeholder bit #0
     volatile uint16_t bit1:1;	// Bit #1:  generic bit placeholder bit #1
     volatile uint16_t bit2:1;	// Bit #2:  generic bit placeholder bit #2
     volatile uint16_t bit3:1;	// Bit #3:  generic bit placeholder bit #3
     volatile uint16_t bit4:1;	// Bit #4:  generic bit placeholder bit #4
     volatile uint16_t bit5:1;	// Bit #5:  generic bit placeholder bit #5
     volatile uint16_t bit6:1;	// Bit #6:  generic bit placeholder bit #6
     volatile uint16_t bit7:1;	// Bit #7:  generic bit placeholder bit #7
     
     volatile uint16_t bit8:1;	// Bit #8:  generic bit placeholder bit #8
     volatile uint16_t bit9:1;	// Bit #9:  generic bit placeholder bit #9
     volatile uint16_t bit10:1;	// Bit #11:  generic bit placeholder bit #10
     volatile uint16_t bit11:1;	// Bit #11:  generic bit placeholder bit #11
     volatile uint16_t bit12:1;	// Bit #12:  generic bit placeholder bit #12
     volatile uint16_t bit13:1;	// Bit #13:  generic bit placeholder bit #13
     volatile uint16_t bit14:1;	// Bit #14:  generic bit placeholder bit #14
     volatile uint16_t bit15:1;	// Bit #15:  generic bit placeholder bit #15
 }__attribute__((packed)) SFR16b_FRAME_t;
 
 typedef union 
{
	volatile uint16_t reg_block;    // buffer for 16-bit word read/write operations
	volatile SFR16b_FRAME_t flags;  // data structure for single bit addressing operations
}SPECIAL_FUNCTION_REGISTER_t;

/*@@APPLICATION_STATUS_t
 *****************************************************************************
 * 
 * Summary:
 * Universal masking data structure to conveniently address generic 
 * Special Function Registers
 *
 * Description:	
 * This data structure is an empty frame which can be used as data mask
 * for local copies of or pointers to specific registers for operations
 * requiring single-bit manipulations 
 *
 * See also:
 * 
 *****************************************************************************/

typedef struct{

	volatile unsigned :1;	// Bit #0:  Reserved
	volatile unsigned :1;	// Bit #1:  Reserved
	volatile unsigned :1;	// Bit #2:  Reserved
	volatile unsigned :1;	// Bit #3:  Reserved
	volatile unsigned :1;	// Bit #4:  Reserved
	volatile unsigned :1;	// Bit #5:  Reserved
	volatile unsigned :1;	// Bit #6:  Reserved
	volatile unsigned :1;	// Bit #7:  Reserved
    
	volatile unsigned :1;	// Bit #8:  Reserved
	volatile unsigned :1;	// Bit #9:  Reserved
	volatile unsigned :1;	// Bit #10: Reserved
	volatile unsigned :1;	// Bit #11: Reserved
	volatile unsigned global_usrflt:1;	// Bit #12: flag bit indicating the presence of a user defined fault event
	volatile unsigned global_notice:1;	// Bit #13: flag bit indicating the presence of notify events
	volatile unsigned global_warning:1;	// Bit #14: flag bit indicating the presence of warning events
	volatile unsigned global_fault:1;	// Bit #15: flag bit indicating the presence of fault events
} APPLICATION_FAULT_STATUS_BIT_FIELD_t;

typedef union 
{
	volatile uint16_t status; // buffer for 16-bit word read/write operations
	volatile APPLICATION_FAULT_STATUS_BIT_FIELD_t flags; // data structure for single bit addressing operations
}APPLICATION_FAULT_STATUS_FLAGS_t;

typedef struct
{
    APPLICATION_FAULT_STATUS_FLAGS_t fault_status;
}APPLICATION_STATUS_t;

extern APPLICATION_STATUS_t application;

/*@@run_main_loop
 * ***********************************************************************************************
 * Description:
 * [run_main_loop] is a global flag, which enables a CPU reset from any part of the firmware.
 * This is meant to be used as "main fuse" in case something is badly going out of control 
 * and the CPU has to be restarted in a deterministic way.
 * 
 * When [run_main_loop] is set to zero, the scheduler will complete the execution of the most 
 * recent task end exit the main while() loop, where a CPU_RESET instruction will reset the CPU,
 * effectively causing a system restart.
 * 
 * If an immediate restart is necessary, use the CPU_RESET macro directly.
 * 
 * See also:
 * CPU_RESET
 * ***********************************************************************************************/
extern uint16_t run_main_loop;

/*@@USE_TASK_EXECUTION_CLOCKOUT_PIN
 * ***********************************************************************************************
 * Description:
 * CPU load monitoring for code execution profile analysis is supported by two features:
 * 
 *    - MCU debug pin indicating task execution periods
 *    - CPU time counter logged in history array
 * 
 * To use the debug pin features and monitor task execution timing on an oscilloscope, a
 * MCU pin needs to be available and initialized as output. The related port-latch register
 * bit needs to declared as CLKOUT_WR (CLOCKOUT-WRITE).
 * 
 * e.g. #define CLKOUT_WR  LATAbits.LATA0 when port-pin RA0 is used as generic debugging output pin
 * 
 * Settings:
 * Set USE_TASK_EXECUTION_CLOCKOUT_PIN = 1 to enable the debug pin task time output feature.
 * Set USE_TASK_EXECUTION_CLOCKOUT_PIN = 0 to disable the debug pin task time output feature.
 *
 * If USE_TASK_EXECUTION_CLOCKOUT_PIN = 1 but no clock-output pin is defined, a build error will 
 * be triggered.
 * 
 * See also:
 * CLKOUT_WR
 * ***********************************************************************************************/
#define USE_TASK_EXECUTION_CLOCKOUT_PIN     1

#if __DEBUG
#define USE_TASK_MANAGER_TIMING_DEBUG_ARRAYS 1
#endif

/*@@USE_TASK_EXECUTION_CLOCKOUT_PIN
 * ***********************************************************************************************
 * Description:
 * CPU load monitoring for code execution profile analysis is supported by two features:
 * 
 *    - MCU debug pin indicating task execution periods
 *    - CPU time counter logged in history array
 * 
 * To use the debug pin features and monitor task execution timing on an oscilloscope, a
 * MCU pin needs to be available and initialized as output. The related port-latch register
 * bit needs to declared as CLKOUT_WR (CLOCKOUT-WRITE).
 * 
 * e.g. #define CLKOUT_WR  LATAbits.LATA0 when port-pin RA0 is used as generic debugging output pin
 * 
 * Settings:
 * Set USE_TASK_EXECUTION_CLOCKOUT_PIN = 1 to enable the debug pin task time output feature.
 * Set USE_TASK_EXECUTION_CLOCKOUT_PIN = 0 to disable the debug pin task time output feature.
 *
 * If USE_TASK_EXECUTION_CLOCKOUT_PIN = 1 but no clock-output pin is defined, a build error will 
 * be triggered.
 * 
 * See also:
 * CLKOUT_WR
 * ***********************************************************************************************/

// in debugging mode two generic arrays are available for CPU load measurements
#if __DEBUG
#define CPU_LOAD_DEBUG_BUFFER_LENGTH     128
extern uint16_t task_time_buffer[];
extern uint16_t cpu_time_buffer[];
#endif

 /* ***********************************************************************************************
 * PROTOTYPES
 * ***********************************************************************************************/

    

#endif	/* PROJECT_GLOBAL_DECLARATIONS_H */

// EOF
