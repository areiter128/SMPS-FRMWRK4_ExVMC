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
/* @@p33SMPS_swdt.h
 * ***************************************************************************
 * File:   p33SMPS_swdt.h
 * Author: M91406
 *
 * Created on October 25, 2017, 4:18 PM
 * 
 * Revision:
 * 
 * ***************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MCAL_P33_SMPS_SWDT_H
#define	MCAL_P33_SMPS_SWDT_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "p33SMPS_devices.h"


#if defined (__P33SMPS_EP__) 
typedef enum
{
    SWDT_DISABLED = 0,
    SWDT_ENABLED = 1 
}SWDT_CONFIGURATION_t;

#elif defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

#define SWDT_POSTSCALER_DIV_BY_2     0b00000
#define SWDT_POSTSCALER_DIV_BY_4     0b00001
#define SWDT_POSTSCALER_DIV_BY_8     0b00010
#define SWDT_POSTSCALER_DIV_BY_16    0b00011
#define SWDT_POSTSCALER_DIV_BY_32    0b00100
#define SWDT_POSTSCALER_DIV_BY_64    0b00101
#define SWDT_POSTSCALER_DIV_BY_128   0b00110
#define SWDT_POSTSCALER_DIV_BY_256   0b00111
#define SWDT_POSTSCALER_DIV_BY_512   0b01000
#define SWDT_POSTSCALER_DIV_BY_1k    0b01001
#define SWDT_POSTSCALER_DIV_BY_2k    0b01010
#define SWDT_POSTSCALER_DIV_BY_4k    0b01011
#define SWDT_POSTSCALER_DIV_BY_8k    0b01100
#define SWDT_POSTSCALER_DIV_BY_16k   0b01101
#define SWDT_POSTSCALER_DIV_BY_32k   0b01110
#define SWDT_POSTSCALER_DIV_BY_64k   0b01111
#define SWDT_POSTSCALER_DIV_BY_128k  0b10000
#define SWDT_POSTSCALER_DIV_BY_256k  0b10001
#define SWDT_POSTSCALER_DIV_BY_512k  0b10010
#define SWDT_POSTSCALER_DIV_BY_1M    0b10011
#define SWDT_POSTSCALER_DIV_BY_2M    0b10100
#define SWDT_POSTSCALER_DIV_BY_4M    0b10101
#define SWDT_POSTSCALER_DIV_BY_8M    0b10110
#define SWDT_POSTSCALER_DIV_BY_16M   0b10111
#define SWDT_POSTSCALER_DIV_BY_32M   0b11000
#define SWDT_POSTSCALER_DIV_BY_64M   0b11001
#define SWDT_POSTSCALER_DIV_BY_128M  0b11010
#define SWDT_POSTSCALER_DIV_BY_256M  0b11011
#define SWDT_POSTSCALER_DIV_BY_512M  0b11100
#define SWDT_POSTSCALER_DIV_BY_1G    0b11101
#define SWDT_POSTSCALER_DIV_BY_2G    0b11110
#define SWDT_POSTSCALER_DIV_BY_4G    0b11111


#define SWDT_CLKSEL_LPRC     0b11
#define SWDT_CLKSEL_FRC      0b10
#define SWDT_CLKSEL_RESERVED 0b01
#define SWDT_CLKSEL_SYSCLK   0b00

typedef struct
{
    volatile uint16_t WDTWINEN:1; // bit 0: Watchdog Timer Window Enable bit
    volatile uint16_t SLPDIV:5; //bit 5-1: Sleep and Idle Mode WDT Postscaler Status bits
    volatile uint16_t CLKSEL:2; // bit 7-6: WDT Run Mode Clock Select Status bits
    volatile uint16_t RUNDIV:5; // bit 12-8: WDT Run Mode Postscaler Status bits
    volatile uint16_t reserved:2; // bit 14-13: not used/reserved
    volatile uint16_t ON :1; // bit15: enable/disable watchdog timer (if not enabled in hardware)
}SWDT_CONFIGURATION_REGISTER_t;

typedef union 
{
	volatile uint16_t reg_block;    // buffer for 16-bit word read/write operations
	volatile SWDT_CONFIGURATION_REGISTER_t config;  // data structure for single bit addressing operations
}SWDT_CONFIGURATION_t;


#endif

extern inline uint16_t swdt_enable(SWDT_CONFIGURATION_t swdt_enable_state);
extern inline uint16_t swdt_reset(void);
    
#endif	/* MCAL_P33_SMPS_SWDT_H */

