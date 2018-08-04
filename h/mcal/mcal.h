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
/*@@mcal.h
 * ***********************************************************************************************
 * File:   mcal.h
 * Author: M91406
 * 
 * Summary:
 * Microcontroller Abstraction Layer header file
 * 
 * Description:
 * This header is used to publish generic peripheral drivers of the MCAL layer. A file, which 
 * needs to access routines of any generic peripheral driver should include this header.
 * 
 * History:
 * 07/28/2017	File created
 * ***********************************************************************************************/

#ifndef MICROCONTROLLER_ABSTRACTION_LAYER_H
#define	MICROCONTROLLER_ABSTRACTION_LAYER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdint.h>

/* ***********************************************************************************************
 * INCLUDES
 * ***********************************************************************************************/
/* generic drivers */
#include "p33SMPS_devices.h"

#ifdef __00124_R02_EP806__
// dsPIC33EP128GS806 Digital Power Plug-In Module, Version 0.2
  #include "00124_R02_EP806_pinmap.h"
#endif
#ifdef __00124_R10_EP806__
// dsPIC33EP128GS806 Digital Power Plug-In Module, Version 1.0
  #include "00124_R10_EP806_pinmap.h"
#endif
#ifdef __00124_R11_EP806__
// dsPIC33EP128GS806 Digital Power Plug-In Module, Version 1.1
  #include "00124_R11_EP806_pinmap.h"
#endif
/*
#ifdef __00133_R30_MP506__
// dsPIC33CH128MP506 Digital Power Plug-In Module, Version 3.0
  #include "00133_R30_MP506_pinmap.h"
#endif
#ifdef __00146_R10_MP506__
// dsPIC33EP128GS806 Digital Power Plug-In Module, Version 0.2
  #include "00124_R02_EP806_pinmap.h"
#endif
*/

    
#include "p33GS_irq.h"
#include "p33SMPS_dsp.h"
#include "p33SMPS_gpio.h"
#include "p33SMPS_oscillator.h"
#include "p33SMPS_pmd.h"
#include "p33SMPS_swdt.h"
#include "p33SMPS_timer.h"

/* specific drivers */
#include "p33GS_hsadc.h"
#include "p33GS_hspwm.h"
    
/* user configuration headers */
#include "devcfg_oscillator.h"
#include "devcfg_clock.h"
#include "devcfg_hspwm.h"
#include "devcfg_hsadc.h"

    
/* ***********************************************************************************************
 * GENERIC DEFINES
 * ***********************************************************************************************/
 
 
/* ***********************************************************************************************
 * MACRO DEFINITIONS
 * ***********************************************************************************************/
    
#define WDT_RESET		asm volatile ("CLRWDT\n")
#define PWRSAV_IDLE		asm volatile ("PWRSAV #1\n")
#define PWRSAV_SLEEP	asm volatile ("PWRSAV #0\n")
#define CPU_RESET		asm volatile ("RESET\n")
//#define ALTWREG_SWAP(x)    asm volatile ( "PUSH.W W0 \n CTXTSWP #" + x + "POP.W W0 \n")
    
/* ***********************************************************************************************
 * PROTOTYPES
 * ***********************************************************************************************/


#endif	/* MICROCONTROLLER_ABSTRACTION_LAYER_H */

// EOF
