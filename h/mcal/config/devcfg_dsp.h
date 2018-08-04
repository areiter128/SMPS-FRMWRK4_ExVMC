/* ****************************************************************************************************
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
 * *****************************************************************************************************
 * File:   devcfg_dsp.h
 * Author: M91406
 * Comments: User configuration of the digital signal controller
 * Revision history: v1.0, first release
 * *****************************************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _DEVICE_CONFIGURATION_DSP_H
#define	_DEVICE_CONFIGURATION_DSP_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

#include "mcal.h"

/* CORCON Settings */

// Variable Exception Processing Latency disabled
// Signed multiplications
// Early DO loop termination disabled
// Saturation enabled for accumulator A
// Saturation enabled for accumulator B
// Saturation enabled for writes to data space
// Accumulator saturation mode 1.31
// Unbiased (convergent) rounding enabled
// Fractional multiplier mode enabled

/*
#define DSP_CORCON_CFG     (REG_CORCON_VAR_FIXED | \	
                            REG_CORCON_US_SIGNED | \
                            REG_CORCON_EDT_OFF | \
                            REG_CORCON_SATA_ON | \
                            REG_CORCON_SATB_ON | \
                            REG_CORCON_SATDW_ON | \
                            REG_CORCON_ACCSAT_131 | \
                            REG_CORCON_RND_UNBIASED | \
                            REG_CORCON_IF_FRACTIONAL | \
                            REG_CORCON_SFA_ACTIVE \
                            )
*/

#endif	/* _DEVICE_CONFIGURATION_DSP_H */

