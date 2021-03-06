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
/* @@p33MP_gpio.c
 * ***************************************************************************
 *
 * File:   p33MP_gpio.c
 * Author: M91406
 *
 * Created on October 27, 2017, 11:24 AM
 * ***************************************************************************/
/* @@p33SMPS_pmd.h
 * ***************************************************************************
 *
 * File:   p33SMPS_pmd.h
 * Author: M91406
 *
 * Created on October 25, 2017, 4:18 PM
 * 
 * Revision:
 * 
 * ***************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _MCAL_P33_SMPS_PDM_H_
#define	_MCAL_P33_SMPS_PDM_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

typedef enum
{
    PMD_POWER_ON = 0, 
    PMD_POWER_OFF = 1
}pmd_enable_setting_e;

extern uint16_t pmd_reset(pmd_enable_setting_e power_on_state);

#endif	/* MCAL_P33_SMPS_PDM_H */

