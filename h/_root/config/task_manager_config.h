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
/*@@task_manager_config.h
 * ***********************************************************************************************
 * File:   task_manager_config.h
 * Author: M91406
 * 
 * Summary:
 * User configuration file for basic task scheduler parameters
 * 
 * Description:
 * Users can specify which timer drives the task scheduler and at which frequency. further
 * some fine tuning options are available to account for runtime influences of compiler 
 * optimizations on CPU meter and task time quota monitoring.
 * 
 * History:
 * 07/28/2017	File created
 * ***********************************************************************************************/

#ifndef ROOT_TASK_MANAGER_CONFIGURATION_H
#define	ROOT_TASK_MANAGER_CONFIGURATION_H

#ifdef	__cplusplus
extern "C" {
#endif

/* ***********************************************************************************************
 * DEFAULT INCLUDES
 * ***********************************************************************************************/

#include <stdint.h>
#include <math.h>
#include "p33SMPS_devices.h"
    
/* ***********************************************************************************************
 * PROJECT SPECIFIC INCLUDES
 * ***********************************************************************************************/

/* ***********************************************************************************************
 * DECLARATIONS
 * ***********************************************************************************************/
#define TASK_MGR_TIMER_INDEX                1
#define TASK_MGR_PERIOD                     7010
#define TASK_MGR_TIMER_COUNTER_REGISTER     TMR1
#define TASK_MGR_TIMER_PERIOD_REGISTER      PR1
#define TASK_MGR_TIMER_ISR_FLAG_REGISTER    IFS0

#if defined (_P33SMPS_WACA_) || defined (_P33SMPS_WACS_)
  #define TASK_MGR_TIMER_ISR_FLAG_BIT_MASK        0b0000000000000010
#elif defined (_P33SMPS_TLAL_) || defined (_P33SMPS_TLAH_) || defined (_P33SMPS_TLAY_)
  #define TASK_MGR_TIMER_ISR_FLAG_BIT_MASK        0b0000000000001000
#elif defined (_P33SMPS_YGAR_) || defined (_P33SMPS_UEAG_) || defined (_P33SMPS_UEAA_)
  #define TASK_MGR_TIMER_ISR_FLAG_BIT_MASK        0b0000000000001000
#else
    
#endif
    
#define TASK_MGR_CPU_LOAD_NOMBLK            24      // Number of cycles for one TxIF-wait while loop iteration at code optimization #0
//#define TASK_MGR_CPU_LOAD_NOMBLK            18      // Number of cycles for one TxIF-wait while loop iteration at code optimization #1
//#define TASK_MGR_CPU_LOAD_NOMBLK            21      // Number of cycles for one TxIF-wait while loop iteration at code optimization #2
//#define TASK_MGR_CPU_LOAD_NOMBLK            21      // Number of cycles for one TxIF-wait while loop iteration at code optimization #3
#define TASK_MGR_CPU_LOAD_FACTOR            (uint16_t)(((float)(1000.000)/(float)(TASK_MGR_PERIOD))*pow(2, 16))
#define TASK_MGR_ISR_PRIORITY               1       // Timer ISR priority
#define TASK_MGR_ISR_STATE                  0       // Timer ISR state (0=disabled, 1=enabled)
    
 /* ***********************************************************************************************
 * PROTOTYPES
 * ***********************************************************************************************/

    
#ifdef	__cplusplus
}
#endif

#endif	/* ROOT_TASK_MANAGER_CONFIGURATION_H */

// EOF
