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
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 * *****************************************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _DEVICE_CONFIGURATION_UART_H_
#define	_DEVICE_CONFIGURATION_UART_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

#include "syscfg_limits.h"
#include "mcal.h"

// High Speed Analog Comparators

#if defined (__P33SMPS_EP__)

// UART #1 used for common debugging, monitoring & control

#define CVRT_UART_IDX           1                       // Index of UART module for control and monitoring
#define CVRT_UART_BAUDRATE      UART_BAUDRATE_57600		// Baudrate
#define CVRT_UART_DATA_BITS     UART_DATA_BITS_8        // Number of data bits
#define CVRT_UART_PARITY        UART_PARITY_NONE        // Parity setting of the UART 
#define CVRT_UART_STOP_BITS     UART_STOP_BITS_1        // Number of stop bits
#define CVRT_UART_IRS_PRIORITY  UART_ISR_PRIORITY_1     // Priority of the UART interrupts

#define CVRT_UART_RX_PPS_NO     63u
#define CVRT_UART_RX_PPS        PPSIN_U1RX
#define CVRT_UART_TX_PPS_NO     36u
#define CVRT_UART_TX_PPS        PPSOUT_U1TX

#define CVRT_UxRXBUF_SIZE       (32)
#define CVRT_UxTXBUF_SIZE       (32)

#if (CVRT_UART_IDX == 1)
    #define _CVRT_UxRXInterrupt _U1RXInterrupt
    #define _CVRT_UxRXIF        _U1RXIF
    #define CVRT_UxRXREG        U1RXREG

    #define _CVRT_UxTXInterrupt _U1TXInterrupt
    #define _CVRT_UxTXIF        _U1TXIF

    #define _CVRT_UxEInterrupt  _U1ErrInterrupt
    #define _CVRT_UxEIF         _U1EIF
#endif
    
#endif

#endif	/* _DEVICE_CONFIGURATION_UART_H_ */

