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
/* @@task_manager.h
 *****************************************************************************
 * File:   task_manager.h
 *
 * Summary:
 * Task manager header file
 *
 * Description:	
 * -
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

#ifndef _ROOT_TASK_MANAGER_H_
#define	_ROOT_TASK_MANAGER_H_
    
#include <stdint.h>
#include "fdrv_FaultHandler.h"

/* Data structures */

typedef enum {
    OP_MODE_BOOT           = 0b0000000000000001, // Operation mode during device start-up and peripheral configuration
    OP_MODE_DEVICE_STARTUP = 0b0000000000000010, // On-chip peripherals start-up period (self-check, soft-start, etc.)
    OP_MODE_SYSTEM_STARTUP = 0b0000000000000100, // Power converter start-up period (self-check, soft-start, etc.)
    OP_MODE_NORMAL         = 0b0000000000001000, // Normal operation mode
    OP_MODE_FAULT          = 0b0000000000010000, // Fault mode will be entered when a critical fault condition has been detected
    OP_MODE_STANDBY        = 0b0000000000100000  // During standby mode the converter is disabled
} SYSTEM_OPERATION_MODE_e;

typedef struct {
    volatile uint16_t boot; // Operation mode during device start-up and peripheral configuration
    volatile uint16_t device_startup; // On-chip peripherals start-up period (self-check, soft-start, etc.)
    volatile uint16_t system_startup; // Power converter start-up period (self-check, soft-start, etc.)
    volatile uint16_t normal; // Normal operation mode
    volatile uint16_t fault; // Fault mode will be entered when a critical fault condition has been detected
    volatile uint16_t standby; // During standby mode the converter is disabled
} SYSTEM_OPERATION_MODE_FLAGS_BIT_FIELD_t;

typedef union 
{
	volatile SYSTEM_OPERATION_MODE_e mode;
	volatile SYSTEM_OPERATION_MODE_FLAGS_BIT_FIELD_t flags;
}system_operation_mode_t;


typedef struct {

    volatile uint32_t ticks; // Counter for CPU load measurement
    volatile uint16_t load; // CPU load result
    volatile uint16_t load_max_buffer; // CPU load maximum is tracked and logged
    volatile uint16_t loop_nomblk; // Number of cycles required for one CPU load counter tick
    volatile uint32_t load_factor; // CPU_TICKS result has to be multiplied with this number to get CPU_LOAD in [10x %] => percentage with 1 digit accuracy, e.g. 124 = 12.4%
} cpu_load_settings_t;

typedef struct {

    /* System operation mode (selects the active task flow list) */
    volatile system_operation_mode_t op_mode; // ID of current operating mode
    volatile uint16_t error_code;   // in case an execution error occurred, this code contains task ID
                                    // and list ID which caused the error 
    
    /* Active task list properties */
    volatile uint16_t exec_task_id; // Main task ID from task id definition list
    volatile uint16_t exec_task_retval; // last return code of most recently executed task
    volatile uint16_t *task_list; // Pointer to the task flow list (lookup table of task flow combinations)
    volatile uint16_t task_list_ubound; // Number of tasks in the current list (1-n))
    volatile uint16_t task_list_tick_index; // Recent task tick counter

    /* Settings for task scheduler timer */
    volatile uint16_t task_timer_index; // specifies the timer used for the task manager (e.g. 1 for Timer1)
    volatile uint16_t *reg_task_timer_period; // Pointer to Timer period register (e.g. PR1)
    volatile uint16_t *reg_task_timer_counter; // Pointer to Timer counter register (e.g. TMR1))
    volatile uint16_t *reg_task_timer_irq_flag; // Pointer to Timer interrupt flag register (e.g. IFS0)
    volatile uint16_t task_timer_irq_flag_mask; // Bit-Mask for filtering on dedicated interrupt flag bit

    /* Generic timer settings and buffer variables */
    volatile uint16_t task_period; // Global task execution period
    volatile uint16_t task_time_buffer; // Buffer of task time meter result
    volatile uint16_t task_time; // Execution time meter result of last called task
    volatile uint16_t task_time_max_buffer; // Task time meter maximum is tracked and logged

    /* CPU Load Meter variables */
    volatile cpu_load_settings_t cpu_load;
    
} task_manager_settings_t;

// Public Task Manager data structure declaration
extern volatile task_manager_settings_t task_mgr; // Declare a data structure holding the settings of the task manager


// Public Task Manager Function Prototypes
extern inline uint16_t init_TaskManager(void);
extern inline uint16_t task_manager_tick(void);
extern inline uint16_t task_CheckOperationModeStatus(void);


#endif	/* _ROOT_TASK_MANAGER_H_ */
