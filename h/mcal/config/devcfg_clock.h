/*LICENSE *********************************************************************
 * 
 * Software License Agreement
 *
 * Copyright � 2016 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED ìAS ISî WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *****************************************************************************/
 

#ifndef _DEVICE_CONFIGURATION_CLOCK_H_
#define _DEVICE_CONFIGURATION_CLOCK_H_

#include <xc.h>
#include <stdint.h>

#include "p33SMPS_devices.h"
#include "devcfg_oscillator.h"

/*@@device_clock.h
 * *****************************************************************************
 * Summary:
 * Application specific oscillator settings and macros
 *
 * Description:
 * This file contains user-defines and macros to determine register settings
 * for various clock sources (e.g. system oscillator, PWM, ADC, timer, etc.)
 *
 * *****************************************************************************
 */
 
/*@@System Frequencies
 * ************************************************************************************************
 * Summary:
 * Set of values and macros for system frequency adaption
 *
 * Description:
 * Following several basic settings for the main oscillator are listed, to scale the system's
 * frequencies of Timer, PWM or ADC accordingly.
 * ***********************************************************************************************/

#if defined (_P33SMPS_YGAR_) || defined (_P33SMPS_UEAG_)
    /* YGAR and UEAG Devices */

    #define OSC_FRC_FREQ        7370000     // Frequency of the internal oscillator in [Hz]
    #define OSC_FRC_TUN         5           // <OSCTUN> FRC Oscillator Tuning Rregister value
    #define OSC_TUN_SCALER      0.00375     // Oscillator frequency step size of <OSCTUN>

#elif defined (_P33SMPS_UEAA_)
    /* UEAA Devices */

    #define OSC_FRC_FREQ        7370000     // Frequency of the internal oscillator in [Hz]
    #define OSC_FRC_TUN         19          // <OSCTUN> FRC Oscillator Tuning Rregister value
    #define OSC_TUN_SCALER      0.000938    // Oscillator frequency step size of <OSCTUN>

#elif defined (_P33SMPS_TLAL_) || defined (_P33SMPS_TLAH_) || defined (_P33SMPS_TLAY_)
    /* TLAL, TLAH and TLAY Devices */

    #define OSC_FRC_FREQ        7370000     // Frequency of the internal oscillator in [Hz]
    #define OSC_FRC_TUN         31          // <OSCTUN> FRC Oscillator Tuning Rregister value
    #define OSC_TUN_SCALER      0.00047     // Oscillator frequency step size of <OSCTUN>

#else

    #error === device cannot be recognized to select oscillator settings ===

#endif

#if (USE_EXTERNAL_OSC == 0)

//  #warning -- internal RC oscillator will be used --

//  #define OSC_FREQ			OSC_FRC_FREQ	// FRC-frequency in Hz

  #if (MCU_SPEED == MIPS40)

//	#warning === MCU speed set to 40 MIPS operation ===

	#define OSCPLL_N1		2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
	#define OSCPLL_M		43		// PLLDIV<8:0> PLL Feedback Divisor value M
	#define OSCPLL_N2		2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

  #elif (MCU_SPEED == MIPS50)

//	#warning === MCU speed set to 50 MIPS operation ===
  
	#define OSCPLL_N1		2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
	#define OSCPLL_M		53		// PLLDIV<8:0> PLL Feedback Divisor value M
	#define OSCPLL_N2		2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

  #elif (MCU_SPEED == MIPS60)

//	#warning === MCU speed set to 60 MIPS operation ===
  
	#define OSCPLL_N1		2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
	#define OSCPLL_M		64		// PLLDIV<8:0> PLL Feedback Divisor value M
	#define OSCPLL_N2		2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

  #elif (MCU_SPEED == MIPS70)

//	#warning === MCU speed set to 70 MIPS operation ===

	#define OSCPLL_N1		2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
	#define OSCPLL_M		74		// PLLDIV<8:0> PLL Feedback Divisor value M
	#define OSCPLL_N2		2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

  #else
  
	#error === MCU speed not selected ===
  
  #endif
  
  // FRC Output Frequency in Hz (incl. OSCTUN)
  #define OSCFREQUENCY		((unsigned long)((float)OSC_FRC_FREQ + (float)((float)OSC_FRC_TUN * (OSC_TUN_SCALER * (float)OSC_FRC_FREQ))))

#else

  #warning -- internal RC oscillator will be used --

  #define OSC_FREQ			EXT_OSC_FREQ	// External oscillator frequency in [Hz]
                                            // As defined by user in device_config.h

  #if ((MCU_SPEED == MIPS40) && (EXT_OSC_FREQ == 8000000))

//	#warning === MCU speed set to 40 MIPS operation ===

	#define OSCPLL_N1		2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
	#define OSCPLL_M		40		// PLLDIV<8:0> PLL Feedback Divisor value M
	#define OSCPLL_N2		2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

  #elif ((MCU_SPEED == MIPS50) && (EXT_OSC_FREQ == 8000000))
  
//	#warning === MCU speed set to 50 MIPS operation ===

	#define OSCPLL_N1		2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
	#define OSCPLL_M		50		// PLLDIV<8:0> PLL Feedback Divisor value M
	#define OSCPLL_N2		2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

  #elif ((MCU_SPEED == MIPS60) && (EXT_OSC_FREQ == 8000000))
  
//	#warning === MCU speed set to 60 MIPS operation ===

	#define OSCPLL_N1		2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
	#define OSCPLL_M		60		// PLLDIV<8:0> PLL Feedback Divisor value M
	#define OSCPLL_N2		2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

  #elif ((MCU_SPEED == MIPS70) && (EXT_OSC_FREQ == 8000000))
  
//	#warning === MCU speed set to 70 MIPS operation ===

	#define OSCPLL_N1		2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
	#define OSCPLL_M		70		// PLLDIV<8:0> PLL Feedback Divisor value M
	#define OSCPLL_N2		2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

  #else
  
	#error === MCU speed not selected or external oscillator frequency not defined ===
  
  #endif


  #define OSCFREQUENCY		OSC_FREQ

#endif
 
 
// FRC Output Frequency in Hertz (incl. OSCTUN)
#define AUXOSCFREQUENCY	((unsigned long)(OSC_FRC_FREQ + (OSC_FRC_TUN * (OSC_TUN_SCALER * OSC_FRC_FREQ))))

// PLL Output Frequency in Hertz (~100 MHz max.)
#define FOSC				((unsigned long)(((OSCFREQUENCY / OSCPLL_N1) * OSCPLL_M) / OSCPLL_N2))

// Operating Frequency in Hertz (~50 MHz max.)
#define FCY					((unsigned long)(FOSC / 2))

// Instruction Cycle in Seconds (~20 ns max.)
#define TCY					((float)(1.0/(float)(FCY)))

// PWM Counter Frequency in Hertz (~960 MHz max.)
#define F_ACLK				((unsigned long)(AUXOSCFREQUENCY * 16 * 8))

// PWM Resolution in Seconds (~1.042 ns max.)
#define T_ACLK				((float)(1.0/(float)(F_ACLK)))



#endif
