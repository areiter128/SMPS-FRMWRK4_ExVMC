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
/* @@apl.c
 * ****************************************************************************
 * File:   apl.c
 * Author: M91406
 *
 * Created on October 23, 2017, 5:17 PM
 * ****************************************************************************/


#include "apl.h"
#include "hal.h"
#include "mcal.h"

#include "task_FaultHandler.h"

/*@@SYSTEM_Initialize()
 * ************************************************************************************************
 * Summary:
 * Initializes the essential peripheral blocks to boot the task scheduler
 * 
 * Parameters:
 * (none)
 * 
 * Returns:
 * 0 = FALSE
 * 1 = TRUE
 * 
 * Description:
 * Initializes the essential peripheral blocks like GPIO ports, oscillator and the PLL module,
 * basic timers, etc.
 * All other, application specific peripheral configurations are executed within the scheduler 
 * where they can be monitored and faults can be detected and handled. 
 * 
 * Please Note:
 * In case users would like to use MCC to generate code for device peripheral configurations, 
 * the function call SYSTEM_initialize() will directly call the MCC generated code modules instead
 * of the peripheral libraries used in this example.
 * 
 * ***********************************************************************************************/

uint16_t SYSTEM_Initialize(void){

    /* this routine can be used to replace the operation mode OP_MODE_BOOT */

    uint16_t fres=0;
    
    // Initialize Master core clock for 90 MIPS (max speed on dsPIC33CHxxxMPxxx)
    fres = init_SoftwareWatchDogTimer();
    fres &= init_oscillator();
    fres &= init_aux_oscillator();
    
    // Device reset
    fres &= gpio_reset();               // Sets all pins as digital inputs, disabling all open-drain settings
    fres &= pmd_reset(PMD_POWER_OFF);   // Turns off power and clocks to all peripheral modules
    
    // Setup Timer1 as base clock for the task scheduler
    fres &= init_system_timer();               // Initialize timer @ 10 kHz
    fres &= launch_system_timer();             // Enable Timer without interrupts

    
    return(fres);
    
}

/*@@OS_Initialize()
 * ************************************************************************************************
 * Summary:
 * Initializes the task scheduler.
 * 
 * Parameters:
 * (none)
 * 
 * Returns:
 * 0 = FALSE
 * 1 = TRUE
 * 
 * Description:
 * Initializes the task scheduler and sets it up for the boot phase during which the functional 
 * peripheral blocks will be initialized and the system reaches full functionality.
 * 
 * Please Note:
 * In case users would like to use MCC to generate code for device peripheral configurations, 
 * the function call SYSTEM_initialize() will directly call the MCC generated code modules instead
 * of the peripheral libraries used in this example. 
 * If you use MCC all peripheral modules will be configured by SYSTEM_Initialize(). We recommend,
 * however, to initialize all modules used in a disabled state and use individual tasks to enable
 * functions when they are needed, resp. when their startup timing and execution can be monitored 
 * by the scheduler.
 * 
 * ***********************************************************************************************/

uint16_t OS_Initialize(void) {

    uint16_t fres=0;

    fres = init_TaskManager();
    fres &= init_FaultObjects();
    
    return(fres);
    
}
