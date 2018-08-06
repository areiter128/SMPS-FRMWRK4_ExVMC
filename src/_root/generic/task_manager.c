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
/* @@task_manager.c
 *****************************************************************************
 * File:   task_manager.c
 *
 * Summary:
 * Task manager initialization, operation mode switch-over and task execution routines
 *
 * Description:	
 * This file holds all routines of the basic scheduler functions covering scheduler 
 * settings initialization, basic task execution with time measurement and the 
 * operation mode switch over routine. CPU meter and time quota fault detection
 * are located in the main loop.
 * 
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


#include <xc.h>
#include <stdint.h>

#include "task_manager_config.h"
#include "task_manager.h"
#include "tasks.h"


// Task Manager
volatile task_manager_settings_t task_mgr; // Declare a data structure holding the settings of the task manager
volatile system_operation_mode_t pre_op_mode; // Private flag variable pre-op-mode used by task_CheckOperationModeStatus to identify changes in op_mode

//------------------------------------------------------------------------------
// execute task manager scheduler
//------------------------------------------------------------------------------

uint16_t task_manager_tick(void) {

    volatile uint16_t fres = 0, tbuf = 0;

    // The task manager scheduler runs through the currently selected task flow list in n steps.
    // After the last item of each list the operation mode switch-over check is performed and the 
    // task tick index is reset to zero, which cases the first task of the list to be called at 
    // the next scheduler tick.

    // Indices 0 ... (n-1) are calling listed user tasks
    task_mgr.exec_task_id = task_mgr.task_list[task_mgr.task_list_tick_index]; // Pick next task from list

    // Determine error code for the upcoming task
    task_mgr.proc_code.segments.op_mode = (task_mgr.op_mode.mode);    // log operation mode
    task_mgr.proc_code.segments.task_id = (task_mgr.exec_task_id);   // log upcoming task-ID

    // Capture task start time for time quota monitoring
    task_mgr.task_time_buffer = *task_mgr.reg_task_timer_counter; // Capture timer counter before task execution

    // Execute next task on the list
    fres = Task_Table[task_mgr.exec_task_id](); // Execute currently selected task

    // Capture time to determine elapsed task executing time
    tbuf = *task_mgr.reg_task_timer_counter;
    
    // Copy return value into process code for fault analysis
    task_mgr.proc_code.segments.retval = fres;
    
    if(tbuf > task_mgr.task_time_buffer)
    // if timer period has not expired ...
    { 
        task_mgr.task_time = tbuf - task_mgr.task_time_buffer; // measure most recent task time
    }
    else
    // if timer has overrun try to capture the total elapsed time
    {
        tbuf = (*task_mgr.reg_task_timer_period - tbuf); // capture expired time until end of timer period
        task_mgr.task_time = (tbuf + task_mgr.task_time_buffer); // add elapsed time into the new period
    }

    // track maximum execution time
    if(task_mgr.task_time > task_mgr.task_time_maximum)
    {
        task_mgr.task_time_maximum = task_mgr.task_time; // override maximum time buffer value
    }
    
    return (fres);
}


//------------------------------------------------------------------------------
// Check operation mode status and switch op mode if needed
//------------------------------------------------------------------------------

uint16_t task_CheckOperationModeStatus(void) {

    // Short Fix if MCC Configuration is used
    if ((pre_op_mode.mode == OP_MODE_BOOT) && (task_mgr.op_mode.mode == OP_MODE_BOOT)) 
     // Boot-up task list is only run once
    {
        task_mgr.op_mode.mode = OP_MODE_DEVICE_STARTUP;
    } 
    else if ((pre_op_mode.mode == OP_MODE_DEVICE_STARTUP) && (task_mgr.op_mode.mode == OP_MODE_DEVICE_STARTUP)) 
    // device resources start-up task list is only run once
    { 
        task_mgr.op_mode.mode = OP_MODE_SYSTEM_STARTUP;
    }

    // Skip execution if operation mode has not changed
    if (pre_op_mode.mode != task_mgr.op_mode.mode) {

        // If a change was detected, set the task flow list and reset settings and flags
        switch (task_mgr.op_mode.mode) {
            case OP_MODE_BOOT:
                // Switch to initialization mode operation
                task_mgr.exec_task_id = TASK_IDLE; // Set task ID to DEFAULT (IDle Task))
                task_mgr.task_list_tick_index = 0; // Reset task list pointer
                task_mgr.task_time = 0; // Reset maximum task time meter result
                task_mgr.task_list = task_list_boot; // Set task flow list INIT
                task_mgr.task_list_ubound = (task_list_boot_size-1);
                break;

            case OP_MODE_DEVICE_STARTUP:
                // Switch to device startup mode operation (launching and enabling peripherals)
                task_mgr.exec_task_id = TASK_IDLE; // Set task ID to DEFAULT (IDle Task))
                task_mgr.task_list_tick_index = 0; // Reset task list pointer
                task_mgr.task_time = 0; // Reset maximum task time meter result
                task_mgr.task_list = task_list_device_startup; // Set task flow list DEVICE_STARTUP
                task_mgr.task_list_ubound = (task_list_device_startup_size-1);
                break;

            case OP_MODE_SYSTEM_STARTUP:
                // Switch to system startup mode operation (launching external systems / power sequencing / soft-start)
                task_mgr.exec_task_id = TASK_IDLE; // Set task ID to DEFAULT (IDle Task))
                task_mgr.task_list_tick_index = 0; // Reset task list pointer
                task_mgr.task_time = 0; // Reset maximum task time meter result
                task_mgr.task_list = task_list_system_startup; // Set task flow list SYSTEM_STARTUP
                task_mgr.task_list_ubound = (task_list_system_startup_size-1);
                break;

            case OP_MODE_NORMAL:
                // Switch to normal operation
                task_mgr.exec_task_id = TASK_IDLE; // Set task ID to DEFAULT (IDle Task))
                task_mgr.task_list_tick_index = 0; // Reset task list pointer
                task_mgr.task_time = 0; // Reset maximum task time meter result
                task_mgr.task_list = task_list_normal; // Set task flow list NORMAL
                task_mgr.task_list_ubound = (task_list_normal_size-1);
                break;

            case OP_MODE_FAULT:
                // Switch to fault mode operation
                task_mgr.exec_task_id = TASK_IDLE; // Set task ID to DEFAULT (IDle Task))
                task_mgr.task_list_tick_index = 0; // Reset task list pointer
                task_mgr.task_time = 0; // Reset maximum task time meter result
                task_mgr.task_list = task_list_fault; // Set task flow list FAULT
                task_mgr.task_list_ubound = (task_list_fault_size-1);
                break;

            default: // OP_MODE_STANDBY
                // Switch to standby mode operation 
                task_mgr.exec_task_id = TASK_IDLE; // Set task ID to DEFAULT (IDle Task))
                task_mgr.task_list_tick_index = 0; // Reset task list pointer
                task_mgr.task_time = 0; // Reset maximum task time meter result
                task_mgr.task_list = task_list_standby; // Set task flow list STANDBY
                task_mgr.task_list_ubound = (task_list_standby_size-1);
                break;

        }

        pre_op_mode.mode = task_mgr.op_mode.mode; // Sync OpMode Flags

    }

    return (1);
}


// ======================================================================================================
// Basic Task Manager Structure Initialization
// ==============================================================================================

uint16_t init_TaskManager(void) {

    uint16_t fres = 1;

    // initialize private flag variable pre-op-mode used by task_CheckOperationModeStatus to identify changes in op_mode
    pre_op_mode.mode = OP_MODE_BOOT;

    // Initialize basic Task Manager Status
    task_mgr.op_mode.mode = OP_MODE_BOOT; // Set operation mode to STANDBY
    task_mgr.proc_code.value = 0; // Reset process code
    task_mgr.exec_task_id = TASK_IDLE; // Set task ID to DEFAULT (IDle Task))
    task_mgr.task_list_tick_index = 0; // Reset task list pointer
    task_mgr.task_time = 0; // Reset maximum task time meter result
    task_mgr.task_list = task_list_boot; // Set task flow list INIT
    task_mgr.task_list_ubound = (task_list_boot_size-1);

    // Scheduler Timer Configuration

    task_mgr.task_timer_index = TASK_MGR_TIMER_INDEX; // Index of the timer peripheral used

    task_mgr.reg_task_timer_counter = &TASK_MGR_TIMER_COUNTER_REGISTER;
    task_mgr.reg_task_timer_period = &TASK_MGR_TIMER_PERIOD_REGISTER;
    task_mgr.task_time_quota = *task_mgr.reg_task_timer_period; // Global task execution period 

    task_mgr.reg_task_timer_irq_flag = &TASK_MGR_TIMER_ISR_FLAG_REGISTER;
    task_mgr.task_timer_irq_flag_mask = TASK_MGR_TIMER_ISR_FLAG_BIT_MASK;

    // CPU Load Monitor Configuration
    task_mgr.cpu_load.load = 0;
    task_mgr.cpu_load.load_max_buffer = 0;
    task_mgr.cpu_load.ticks = 0;
    task_mgr.cpu_load.loop_nomblk = TASK_MGR_CPU_LOAD_NOMBLK;
    task_mgr.cpu_load.load_factor = TASK_MGR_CPU_LOAD_FACTOR;


    return (fres);
}

