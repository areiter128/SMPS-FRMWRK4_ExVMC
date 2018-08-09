/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
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
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _SFL_SOFT_START_DRIVER_H_
#define	_SFL_SOFT_START_DRIVER_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "globals.h"

typedef enum
{
    SOFT_START_STEP_INIT = 0,
    SOFT_START_STEP_POWER_ON_DELAY = 1,
    SOFT_START_STEP_RAMP_UP = 2,
    SOFT_START_STEP_POWER_GOOD_DELAY = 3,
    SOFT_START_STEP_COMPLETE = 4
}SOFT_START_STEP_e;

#define SOFT_START_FAULT_COMMON_FLAG    0x2000
#define SOFT_START_FAULT_IRQ_FLAG       0x0001
#define SOFT_START_FAULT_CTRL_FLAG      0x0002

typedef struct {
	volatile unsigned irq_flt:1; // Bit #0:  Reserved
	volatile unsigned ctrl_flt:1; // Bit #1:  Reserved
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
	volatile unsigned :1;	// Bit #12: Reserved
	volatile unsigned fault:1;	// Bit #13: Flag it indicating a fault condition (lower flag bits give more details)
	volatile unsigned active :1; // Bit #14: Flag bit indicating that soft-start process is active
	volatile unsigned enable  :1;	// Bit #15: Fault check enable/disable flag bit
}__attribute__((packed))SOFT_START_OBJECT_STATUS_BIT_FIELD_t;

typedef union 
{
	volatile uint16_t flags;
	volatile SOFT_START_OBJECT_STATUS_BIT_FIELD_t flag;
}SOFT_START_OBJECT_STATUS_t;

typedef struct
{
    volatile SOFT_START_OBJECT_STATUS_t status;
    volatile SOFT_START_STEP_e phase;
    volatile uint16_t counter;
    volatile uint16_t power_on_delay;
    volatile uint16_t ramp_up_period;
    volatile uint16_t power_good_delay;
    volatile uint16_t output_tracking_filter;
    volatile uint16_t ref_increment;
}SOFT_START_OBJECT_t;

/* soft-start object prototypes */
extern volatile SOFT_START_OBJECT_t soft_start;

/* soft-start function prototypes */
extern volatile uint16_t init_soft_start(void);
extern volatile uint16_t exec_soft_start(void);


#if (INCLUDE_SOFT_SHUT_DOWN == 1)


typedef enum
{
    SOFT_SHUT_DOWN_STEP_INIT = 0,
    SOFT_SHUT_DOWN_STEP_POWER_OFF_DELAY = 1,
    SOFT_SHUT_DOWN_STEP_RAMP_DOWN = 2,
    SOFT_SHUT_DOWN_STEP_COMPLETE = 3
}SOFT_SHUT_DOWN_STEP_e;

typedef struct
{
    volatile SOFT_START_OBJECT_STATUS_t status;
    volatile SOFT_SHUT_DOWN_STEP_e phase;
    volatile uint16_t counter;
    volatile uint16_t power_off_delay;
    volatile uint16_t ramp_down_period;
    volatile uint16_t output_tracking_filter;
    volatile uint16_t ref_decrement;
}SOFT_SHUT_DOWN_OBJECT_t;

/* soft-shut down object prototypes */

extern volatile SOFT_SHUT_DOWN_OBJECT_t soft_shutdwn;

/* soft-shut down function prototypes */

extern volatile uint16_t init_soft_shut_down(void);
extern volatile uint16_t exec_soft_shut_down(void);

#endif


#endif	/* _SFL_SOFT_START_DRIVER_H_ */

