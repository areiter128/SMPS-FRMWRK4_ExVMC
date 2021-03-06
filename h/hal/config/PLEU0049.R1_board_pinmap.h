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
/*@@board_pinmap.h
 * ***************************************************************************
 * File:   PLEU0049.R1_board_pinmap.h
 * Author: M91406
 * 
 * Summary:
 * Global declarations of specific board pin names and peripherals
 * 
 * Description:
 * Global declarations are used to associate board signals, LEDs and other 
 * peripherals with device pins and special function registers.
 * 
 * History:
 * 07/28/2017	File created
 * ***************************************************************************/

#ifndef _HARDWARE_ABSTRACTION_LAYER_PLEU0029_R1_BOARD_PINMAP_H_
#define	_HARDWARE_ABSTRACTION_LAYER_PLEU0029_R1_BOARD_PINMAP_H_

#include <stdint.h>
#include "mcal.h"

// LEDs and Debug Pins
#ifndef LED_ON
  #define LED_ON        0
#endif
#ifndef LED_OFF
  #define LED_OFF       1    
#endif
#ifndef LED_OUTPUT
  #define LED_OUTPUT    0
#endif
#ifndef LED_INPUT
  #define LED_INPUT     1
#endif
    
#define LED_RD_TRIS     TP52_TRIS
#define LED_RD_WR       TP52_WR
#define LED_RD_RD       TP52_RD
#define LED_RD_INIT     {LED_RD_WR = LED_OFF; LED_RD_TRIS = 0;}
    
#define LED_GN_TRIS     TP54_TRIS
#define LED_GN_WR       TP54_WR
#define LED_GN_RD       TP54_RD
#define LED_GN_INIT     {LED_GN_WR = LED_OFF; LED_GN_TRIS = 0;}

#define UART_TX_TRIS    TPUTX_TRIS
#define UART_TX_WR      TPUTX_WR
#define UART_TX_RD      TPUTX_RD
#define UART_TX_INIT    {UART_TX_WR = 1; UART_TX_TRIS = 0;}

#define UART_RX_TRIS    TPURX_TRIS
#define UART_RX_WR      TPURX_WR
#define UART_RX_RD      TPURX_RD
#define UART_RX_INIT    {UART_RX_WR = 1; UART_RX_TRIS = 0;}

/*
#define DBGPIN_TRIS     TP39_TRIS
#define DBGPIN_WR       TP39_WR
#define DBGPIN_RD       TP39_RD
#define DBGPIN_INIT     {DBGPIN_WR = 0; DBGPIN_RD = 0;}
*/  
#define CLKOUT_TRIS     TP03_TRIS
#define CLKOUT_WR       TP03_WR
#define CLKOUT_RD       TP03_RD
#define CLKOUT_INIT     {CLKOUT_WR = 0; CLKOUT_TRIS = 0;}

#define TSTOUT_TRIS     TP35_TRIS
#define TSTOUT_WR       TP35_WR
#define TSTOUT_RD       TP35_RD
#define TSTOUT_INIT     {TSTOUT_WR = 0; TSTOUT_TRIS = 0;}

#define SWITCH_CLOSED   0
#define SWITCH_OPEN     1
#define SWITCH_TRIS     TP27_TRIS    
#define SWITCH_WR       TP27_WR
#define SWITCH_RD       TP27_RD    
#define SWITCH_INIT     {SWITCH_TRIS = 1; SWITCH_WR = 1;}   // Initializine the switch as input
    
// Converter definitions
#define BUCK_PWM        1

#define PWMH_TRIS       TP45_TRIS
#define PWMH_WR         TP45_WR
#define PWMH_RD         TP45_RD
#define PWMH_INIT       {PWMH_WR = 0; PWMH_TRIS = 0;}

#define PWML_TRIS       TP47_TRIS
#define PWML_WR         TP47_WR
#define PWML_RD         TP47_RD
#define PWML_INIT       {PWML_WR = 0; PWML_TRIS = 0;}

#define VOUT_FB_PIN     TP14_ADC_IN
#define VOUT_FB_ADCORE  TP14_ADC_CORE
#define VOUT_FB_ADCBUF  TP14_ADC_BUFFER
#define VOUT_FB_ANSEL   TP14_ANSEL
#define VOUT_FB_IF      TP14_IF
#define VOUT_FB_IE      TP14_IE
#define VOUT_FB_IP      TP14_IP
//#define VOUT_FB_ADCMPxIF TP14_ADCMPxIF
//#define VOUT_FB_ADCMPxIE TP14_ADCMPxIF
//#define VOUT_FB_ADCMPxIP TP14_ADCMPxIF

#define VIN_FB_PIN      TP10_ADC_IN
#define VIN_FB_ADCORE   TP10_ADC_CORE
#define VIN_FB_ADCBUF   TP10_ADC_BUFFER
#define VIN_FB_ANSEL    TP10_ANSEL
#define VIN_FB_IF       TP10_IF
#define VIN_FB_IE       TP10_IE
#define VIN_FB_IP       TP10_IP
//#define VIN_FB_ADCMPxIF TP10_ADCMPxIF
//#define VIN_FB_ADCMPxIE TP10_ADCMPxIF
//#define VIN_FB_ADCMPxIP TP10_ADCMPxIF

#define IL_FB_PIN       TP12_ADC_IN
#define IL_FB_ADCORE    TP12_ADC_CORE
#define IL_FB_ADCBUF    TP12_ADC_BUFFER
#define IL_FB_ANSEL     TP12_ANSEL
#define IL_FB_IF        TP12_IF
#define IL_FB_IE        TP12_IE
#define IL_FB_IP        TP12_IP
    
#define TEMP_FB_PIN     TP18_ADC_IN
#define TEMP_FB_ADCORE  TP18_ADC_CORE
#define TEMP_FB_ADCBUF  TP18_ADC_BUFFER
#define TEMP_FB_ANSEL   TP18_ANSEL
#define TEMP_FB_IF      TP18_IF
#define TEMP_FB_IE      TP18_IE
#define TEMP_FB_IP      TP18_IP

#endif	/* HAL_BOARD_PINMAP_H */

// EOF
