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
/* @@p33SMPS_oscillator.h
 * ***************************************************************************
 *
 * File:   p33SMPS_oscillator.h
 * Author: M91406
 *
 * Created on October 27, 2017, 11:24 AM
 * ***************************************************************************/

#ifndef MCAL_P33_SMPS_OSCILLATOR_H
#define MCAL_P33_SMPS_OSCILLATOR_H

#include <stdint.h>
#include "p33SMPS_devices.h"

/* ***************************************************************************************
 *	BASIC DEFINES
 * **************************************************************************************/

typedef enum
{
    OSC_FRC	    = 0b000,	// Fast RC Oscillator, no PLL (=7.37MHz)
    OSC_FRCPLL	= 0b001,	// Fast RC Oscillator with PLL (=7.37MHz x PLL)
    OSC_PRI		= 0b010,	// Primary Oscillator (EC, XT, HS), no PLL
    OSC_PRIPLL	= 0b011,	// Primary Oscillator (EC, XT, HS) with PLL
    OSC_LPRC	= 0b101,	// Low Power Oscillator for Idle/Sleep Mode (= 32.768 Hz)
    OSC_BFRC 	= 0b110,	// Backup Fast RC Oscillator
    OSC_FRCDIVN	= 0b111		// Fast RC Oscillator with variable Divider (=7.37MHz / n)
}OSC_OSCILLATOR_TYPE_e;

typedef enum
{
    OSC_FRCDIVN_1   = 0b000,	// Fast RC Oscillator Clock Divider Setting 1:1
    OSC_FRCDIVN_2   = 0b001,	// Fast RC Oscillator Clock Divider Setting 1:2
    OSC_FRCDIVN_4   = 0b010,	// Fast RC Oscillator Clock Divider Setting 1:4
    OSC_FRCDIVN_8   = 0b011,	// Fast RC Oscillator Clock Divider Setting 1:8
    OSC_FRCDIVN_16  = 0b100,	// Fast RC Oscillator Clock Divider Setting 1:16
    OSC_FRCDIVN_32  = 0b101,	// Fast RC Oscillator Clock Divider Setting 1:32
    OSC_FRCDIVN_64  = 0b110,	// Fast RC Oscillator Clock Divider Setting 1:64
    OSC_FRCDIVN_256 = 0b111	// Fast RC Oscillator Clock Divider Setting 1:256
}OSC_FRCDIVN_e;

typedef enum
{
    OSC_DOZE_DIV_1    = 0b000,	// FCY Clock Divider Setting 1:1
    OSC_DOZE_DIV_2    = 0b001,	// FCY Clock Divider Setting 1:2
    OSC_DOZE_DIV_4    = 0b010,	// FCY Clock Divider Setting 1:4
    OSC_DOZE_DIV_8    = 0b011,	// FCY Clock Divider Setting 1:8
    OSC_DOZE_DIV_16   = 0b100,	// FCY Clock Divider Setting 1:16
    OSC_DOZE_DIV_32   = 0b101,	// FCY Clock Divider Setting 1:32
    OSC_DOZE_DIV_64   = 0b110,	// FCY Clock Divider Setting 1:64
    OSC_DOZE_DIV_1128 = 0b111 	// FCY Clock Divider Setting 1:128
}OSC_DOZE_DIV_e;

#if defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) 

typedef enum
{
    OSC_PLLDIV_N1_2  = 0b00000,     // PLL Input Clock Divider Setting 1:2
    OSC_PLLDIV_N1_3  = 0b00001,     // PLL Input Clock Divider Setting 1:3
    OSC_PLLDIV_N1_4  = 0b00010,     // PLL Input Clock Divider Setting 1:4
    OSC_PLLDIV_N1_5  = 0b00011,     // PLL Input Clock Divider Setting 1:5
    OSC_PLLDIV_N1_6  = 0b00100,     // PLL Input Clock Divider Setting 1:6
    OSC_PLLDIV_N1_7  = 0b00101,     // PLL Input Clock Divider Setting 1:7
    OSC_PLLDIV_N1_8  = 0b00110,     // PLL Input Clock Divider Setting 1:8
    OSC_PLLDIV_N1_9  = 0b00111,     // PLL Input Clock Divider Setting 1:9
    OSC_PLLDIV_N1_10 = 0b01000, 	// PLL Input Clock Divider Setting 1:10
    OSC_PLLDIV_N1_11 = 0b01001, 	// PLL Input Clock Divider Setting 1:11
    OSC_PLLDIV_N1_12 = 0b01010, 	// PLL Input Clock Divider Setting 1:12
    OSC_PLLDIV_N1_13 = 0b01011, 	// PLL Input Clock Divider Setting 1:13
    OSC_PLLDIV_N1_14 = 0b01100, 	// PLL Input Clock Divider Setting 1:14
    OSC_PLLDIV_N1_15 = 0b01101, 	// PLL Input Clock Divider Setting 1:15
    OSC_PLLDIV_N1_16 = 0b01110, 	// PLL Input Clock Divider Setting 1:16
    OSC_PLLDIV_N1_17 = 0b01111, 	// PLL Input Clock Divider Setting 1:17
    OSC_PLLDIV_N1_18 = 0b10000, 	// PLL Input Clock Divider Setting 1:18
    OSC_PLLDIV_N1_19 = 0b10001, 	// PLL Input Clock Divider Setting 1:19
    OSC_PLLDIV_N1_20 = 0b10010, 	// PLL Input Clock Divider Setting 1:20
    OSC_PLLDIV_N1_21 = 0b10011, 	// PLL Input Clock Divider Setting 1:21
    OSC_PLLDIV_N1_22 = 0b10100, 	// PLL Input Clock Divider Setting 1:22
    OSC_PLLDIV_N1_23 = 0b10101, 	// PLL Input Clock Divider Setting 1:23
    OSC_PLLDIV_N1_24 = 0b10110, 	// PLL Input Clock Divider Setting 1:24
    OSC_PLLDIV_N1_25 = 0b10111, 	// PLL Input Clock Divider Setting 1:25
    OSC_PLLDIV_N1_26 = 0b11000, 	// PLL Input Clock Divider Setting 1:26
    OSC_PLLDIV_N1_27 = 0b11001, 	// PLL Input Clock Divider Setting 1:27
    OSC_PLLDIV_N1_28 = 0b11010, 	// PLL Input Clock Divider Setting 1:28
    OSC_PLLDIV_N1_29 = 0b11011, 	// PLL Input Clock Divider Setting 1:29
    OSC_PLLDIV_N1_30 = 0b11100, 	// PLL Input Clock Divider Setting 1:30
    OSC_PLLDIV_N1_31 = 0b11101, 	// PLL Input Clock Divider Setting 1:31
    OSC_PLLDIV_N1_32 = 0b11110, 	// PLL Input Clock Divider Setting 1:32
    OSC_PLLDIV_N1_33 = 0b11111, 	// PLL Input Clock Divider Setting 1:33
}OSC_PLL_PREDIV_N1_e;

typedef enum
{
    OSC_PLLDIV_N2_2 = 0b00,	// PLL Output Clock Divider Setting 1:2
    OSC_PLLDIV_N2_4 = 0b01,	// PLL Output Clock Divider Setting 1:4
    OSC_PLLDIV_N2_8 = 0b11,	// PLL Output Clock Divider Setting 1:8
}OSC_PLL_POSTDIV1_N2_e;

#elif defined (__P33SMPS_CH2__) || defined (__P33SMPS_CH5__) 


typedef enum
{
    OSC_PLLDIV_N1_1 = 0b0001,	// PLL Input Clock Divider Setting 1:1
    OSC_PLLDIV_N1_2 = 0b0010,	// PLL Input Clock Divider Setting 1:2
    OSC_PLLDIV_N1_3 = 0b0011,	// PLL Input Clock Divider Setting 1:3
    OSC_PLLDIV_N1_4 = 0b0100,	// PLL Input Clock Divider Setting 1:4
    OSC_PLLDIV_N1_5 = 0b0101,	// PLL Input Clock Divider Setting 1:5
    OSC_PLLDIV_N1_6 = 0b0110,	// PLL Input Clock Divider Setting 1:6
    OSC_PLLDIV_N1_7 = 0b0111,	// PLL Input Clock Divider Setting 1:7
    OSC_PLLDIV_N1_8 = 0b1000 	// PLL Input Clock Divider Setting 1:8
}OSC_PLL_PREDIV_N1_e;

typedef enum
{
    OSC_PLLDIV_N2_1 = 0b001,	// PLL Output Clock Divider Setting 1:1
    OSC_PLLDIV_N2_2 = 0b010,	// PLL Output Clock Divider Setting 1:2
    OSC_PLLDIV_N2_3 = 0b011,	// PLL Output Clock Divider Setting 1:3
    OSC_PLLDIV_N2_4 = 0b100,	// PLL Output Clock Divider Setting 1:4
    OSC_PLLDIV_N2_5 = 0b101,	// PLL Output Clock Divider Setting 1:5
    OSC_PLLDIV_N2_6 = 0b110,	// PLL Output Clock Divider Setting 1:6
    OSC_PLLDIV_N2_7 = 0b111 	// PLL Output Clock Divider Setting 1:7
}OSC_PLL_POSTDIV1_N2_e;

typedef enum
{
    OSC_PLLDIV_N3_1 = 0b001,	// PLL Output Clock Divider Setting 1:1
    OSC_PLLDIV_N3_2 = 0b010,	// PLL Output Clock Divider Setting 1:2
    OSC_PLLDIV_N3_3 = 0b011,	// PLL Output Clock Divider Setting 1:3
    OSC_PLLDIV_N3_4 = 0b100,	// PLL Output Clock Divider Setting 1:4
    OSC_PLLDIV_N3_5 = 0b101,	// PLL Output Clock Divider Setting 1:5
    OSC_PLLDIV_N3_6 = 0b110,	// PLL Output Clock Divider Setting 1:6
    OSC_PLLDIV_N3_7 = 0b111 	// PLL Output Clock Divider Setting 1:7
}OSC_PLL_POSTDIV2_N3_e;

typedef enum 
{
    OSC_PLL_VCODIV_1 = 0b11,    // PLL VCO Divider Setting 1:1
    OSC_PLL_VCODIV_2 = 0b10,    // PLL VCO Divider Setting 1:2
    OSC_PLL_VCODIV_3 = 0b01,    // PLL VCO Divider Setting 1:3
    OSC_PLL_VCODIV_4 = 0b00     // PLL VCO Divider Setting 1:4
}OSC_PLL_VCODIV_e;

#endif

typedef enum
{
    OSC_AUX_PREDIV_1   = 0b111,	// Auxiliary Clock Divider Setting 1:1
    OSC_AUX_PREDIV_2   = 0b110,	// Auxiliary Clock Divider Setting 1:2
    OSC_AUX_PREDIV_4   = 0b101,	// Auxiliary Clock Divider Setting 1:4
    OSC_AUX_PREDIV_8   = 0b100,	// Auxiliary Clock Divider Setting 1:8
    OSC_AUX_PREDIV_16  = 0b011,	// Auxiliary Clock Divider Setting 1:16
    OSC_AUX_PREDIV_32  = 0b010,	// Auxiliary Clock Divider Setting 1:32
    OSC_AUX_PREDIV_64  = 0b001,	// Auxiliary Clock Divider Setting 1:64
    OSC_AUX_PREDIV_256 = 0b000	// Auxiliary Clock Divider Setting 1:256
}OSC_AUX_PRE_DIV_N1_e;

typedef enum
{
    OSC_AUX_CLOCK_FRC = 1,	// Internal RC Oscillator is Source Clock for ACLK
    OSC_AUX_CLOCK_PRI = 2,	// Primary Oscillator is Source Clock for ACLK
    OSC_AUX_CLOCK_FVCO = 3  // FVCO (intermediate PLL frequency is auxiliary clock source)
}OSC_AUXPLL_SOURCE_e;

typedef enum
{
  OSC_AUXPLL_OFF	=	0,		// Disable Auxiliary PLL
  OSC_AUXPLL_ON		=	1		// Enable Auxiliary PLL
}OSC_AUXPLL_ENABLE_e;


typedef struct 
{
	volatile OSC_OSCILLATOR_TYPE_e osc_type;
    volatile OSC_PLL_PREDIV_N1_e N1;
    volatile uint8_t M;
    volatile OSC_PLL_POSTDIV1_N2_e N2;
    #if defined (__P33SMPS_CH2__) || defined (__P33SMPS_CH5__)
    volatile OSC_PLL_POSTDIV2_N3_e N3;
    volatile OSC_PLL_VCODIV_e VCODIV;
    #endif
    volatile int8_t frc_tune;
}OSC_CONFIG_t;

typedef struct 
{
	volatile OSC_AUXPLL_SOURCE_e clock_source;
    volatile OSC_AUX_PRE_DIV_N1_e divider;
    volatile OSC_AUXPLL_ENABLE_e enableAUXPLL;
}AUXOSC_CONFIG_t;


#if defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) || defined (__P33SMPS_CH2__) || \
    defined (__P33SMPS_CH5__) || defined (__P33SMPS_FJC__) || defined (__P33SMPS_FJA__) || defined (__P33SMPS_FJ__)
  #define FRCTUN_MIN      -32     // maximum tuning value
  #define FRCTUN_MAX      31      // minimum tuning value
#else
  #error === selected device not supported by peripheral driver libraries ===
#endif

#ifdef REFOCON
// Reference Clock

typedef enum
{
    OSC_REFCLK_DIV_1     = 0b0000,	// Reference Clock Output Divider 1:1
    OSC_REFCLK_DIV_2     = 0b0001,	// Reference Clock Output Divider 1:2
    OSC_REFCLK_DIV_4     = 0b0010,	// Reference Clock Output Divider 1:4
    OSC_REFCLK_DIV_8     = 0b0011,	// Reference Clock Output Divider 1:8
    OSC_REFCLK_DIV_16    = 0b0100,	// Reference Clock Output Divider 1:16
    OSC_REFCLK_DIV_32    = 0b0101,	// Reference Clock Output Divider 1:32
    OSC_REFCLK_DIV_64    = 0b0110,	// Reference Clock Output Divider 1:64
    OSC_REFCLK_DIV_128   = 0b0111,	// Reference Clock Output Divider 1:128
    OSC_REFCLK_DIV_256   = 0b1000,	// Reference Clock Output Divider 1:256
    OSC_REFCLK_DIV_512   = 0b1001,	// Reference Clock Output Divider 1:512
    OSC_REFCLK_DIV_1024  = 0b1010,	// Reference Clock Output Divider 1:1024
    OSC_REFCLK_DIV_2048  = 0b1011,	// Reference Clock Output Divider 1:2048
    OSC_REFCLK_DIV_4096  = 0b1100,	// Reference Clock Output Divider 1:4096
    OSC_REFCLK_DIV_8192  = 0b1101,	// Reference Clock Output Divider 1:8192
    OSC_REFCLK_DIV_16384 = 0b1110,	// Reference Clock Output Divider 1:16384
    OSC_REFCLK_DIV_32768 = 0b1111	// Reference Clock Output Divider 1:32768
}OSC_REFCLK_DIVIDER_e;


typedef enum
{
    OSC_REFCLK_SRC_FOSC    = 0,	// System Clock is used as Reference Clock Source
    OSC_REFCLK_SRC_POSCCLK = 1	// External Crystal Oscillator is used as Reference Clock Source
}OSC_REFCLK_SOURCE_e;


typedef enum
{
    OSC_REFCLK_STOP_IN_SLEEP = 0,	// Reference Clock Output will stop in Sleep Mode
    OSC_REFCLK_RUN_IN_SLEEP  = 1		// Reference Clock Output will run in Sleep Mode
}OSC_REFCLK_SLEEP_CFG_e;


#endif

/* ***************************************************************************************
 *	ERROR CODES
 * **************************************************************************************/

typedef enum
{
  OSCERR_SUCCESS	=		0x0001,	// Clock initialization was successfully performed
  OSCERR_FAILURE	=		0x0000,	// Global Clock Error
                                    // (reserved)
  OSCERR_CSF		=		0x0002,	// Clock switch-over failed
  OSCERR_PLL_LCK	=		0x0008,	// Primary PLL does not lock in
  OSCERR_APLL_LCK	=		0x0010,	// Auxiliary PLL does not lock in
  OSCERR_CSD		=		0x0004,	// Clock switching is disabled but desired clock differs 
  									// from current clock
  OSCERR_FRCTUN		=		0x0020	// FRC tuning failed
}OSC_CFG_ERR_RESULT_t;


/* ***************************************************************************************
 *	Prototypes
 * **************************************************************************************/

// InitFOSC is used with all 40-MIPS 16-Bit controller families.
  extern int16_t init_FOSC(
  				OSC_CONFIG_t OscCfg, 		// Oscillator Type, e.g. OSC_PRIPLL
                OSC_FRCDIVN_e FrcDiv,       // FRC output divider value
  				int8_t FrcTune              // Tuning Register Value for tuning the internal RC Clock
            );									

#if defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJA__) || defined (__P33SMPS_FJC__) || \
    defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)
  
  extern uint16_t init_ACLK(
                AUXOSC_CONFIG_t aux_clock_config // Auxiliary PLL Input Clock, e.g. OSC_AUX_CLOCK_PRI
                                                 // Auxiliary PLL Post-Scaler Value
                                                 // Enable/Disable 16x Auxiliary PLL
  			);

  extern void init_RefClockOutput(
  				OSC_REFCLK_SOURCE_e RefClkSource,	// Reference Clock Output Source, e.g. OSC_REFCLK_SRC_FOSC
  				OSC_REFCLK_DIVIDER_e RefClkDivider, // Reference Clock Post-Scaler Value
  				OSC_REFCLK_SLEEP_CFG_e RunInSleep	// Enable/Disable RefClock in Sleep Mode
  			);
  
#elif defined (__P33SMPS_CH2__) || defined (__P33SMPS_CH5__)
  
  
  
#else
  #error === selected device not supported by peripheral driver libraries ===
#endif
  


  
#endif  /* MCAL_P33_SMPS_OSCILLATOR_H */
