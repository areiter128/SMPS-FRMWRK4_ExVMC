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
/*@@p33MP_timer.h
 * ***************************************************************************
 * Summary:
 * Driver file for the dsPIC33xxxGS Timer SFRs
 *
 * Description:
 * The timer module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 *
 * File:   p33SMPS_timer.h
 * Author: M91406
 *
 * Created on October 25, 2017, 4:18 PM
 * 
 * Revision:
 * 
 * ***************************************************************************/

#ifndef _MCAL_P33_SMPS_UART_H_
#define _MCAL_P33_SMPS_UART_H_

#include <stdint.h>
#include "p33SMPS_devices.h"
#include "devcfg_clock.h"

/*@@p33FGS_timer.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33FxxGS timer SFRs
 *
 * Description:
 * The timer module offers a number of registers and configuration options. This additional
 * header file contains defines for all required settings.
 * ***********************************************************************************************/

// Device specific properties
#if defined (__P33SMPS_EP2__)
	#define UART_UART_COUNT	1
	#define UART_INDEX_REG_OFFSET	0x0008
#elif defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)
	#define UART_UART_COUNT	2
	#define UART_INDEX_REG_OFFSET	0x0008
#elif defined (__P33SMPS_CH__) 
	#define UART_UART_COUNT	2
	#define UART_INDEX_REG_OFFSET	0x0008
#elif defined (__P33SMPS_CK__)
	#define UART_UART_COUNT	3
	#define UART_INDEX_REG_OFFSET	0x0008
#else
	#error === selected device not supported ===
#endif

#if defined (__P33SMPS_EP__) 

    #define UART_UxMOD_REG_DISPOSE_MASK     0x0000
    #define UART_UxSTA_REG_DISPOSE_MASK     0x0000

    #define UART_UxMOD_REG_WRITE_MASK		0xBBFF
    #define UART_UxMOD_REG_READ_MASK		0xBBFF
    #define UART_UxMOD_REG_OFF_MASK         0x3BFF

    #define UART_UxSTA_REG_WRITE_MASK       0xECE1
    #define UART_UxSTA_REG_READ_MASK        0xEFFF

    #define UART_UxBRG_REG_WRITE_MASK       0xFFFF
    #define UART_UxBRG_REG_READ_MASK        0xFFFF

    #define UxBRGL(x)    ((uint16_t)(FCY / (16 * x)) - 1)
    #define UxBRGH(x)    ((uint16_t)(FCY / (4 * x)) - 1)

#elif defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

    #error === no device support ===
    
#endif

// Interrupt Flag-Bits & Priorities
#if ( UART_UART_COUNT >=	1 )
  #define UART1_RX_ISR_FLAG		_U1RXIF	// UART1 RX interrupt flag
  #define UART1_RX_ISR_PRIORITY	_U1RXIP	// UART1 RX interrupt priority
  #define UART1_RX_ISR_ENABLE	_U1RXIE	// UART1 RX interrupt service routine enable
#endif
#if ( UART_UART_COUNT >=	2 )
  #define UART2_ISR_FLAG		_U2RXIF	// UART2 RX interrupt flag
  #define UART2_ISR_PRIORITY	_U2RXIP	// UART2 RX interrupt priority
  #define UART2_ISR_ENABLE		_U2RXIE	// UART2 RX interrupt service routine enable
#endif
#if ( UART_UART_COUNT >=	3 )
  #error === no device support ===
#endif

typedef enum
{
  UART_ISR_PRIORITY_0 = 0, // UART interrupt service routine priority level #0 (main loop))
  UART_ISR_PRIORITY_1 = 1, // UART interrupt service routine priority level #1
  UART_ISR_PRIORITY_2 = 2, // UART interrupt service routine priority level #2
  UART_ISR_PRIORITY_3 = 3, // UART interrupt service routine priority level #3
  UART_ISR_PRIORITY_4 = 4, // UART interrupt service routine priority level #4
  UART_ISR_PRIORITY_5 = 5, // UART interrupt service routine priority level #5
  UART_ISR_PRIORITY_6 = 6, // UART interrupt service routine priority level #6
  UART_ISR_PRIORITY_7 = 7  // UART interrupt service routine priority level #7
}UART_ISR_PRIORITY_e;

typedef enum
{
  UART_ISR_DISABLED = 0,   // Disable UART interrupt service routine
  UART_ISR_ENABLED  = 1    // Enable UART interrupt service routine
}UART_ISR_ENABLE_STATE_e;

typedef enum
{
    UART_BAUDRATE_75 = 75,
    UART_BAUDRATE_110 = 110,
    UART_BAUDRATE_134 = 134,
    UART_BAUDRATE_150 = 150,
    UART_BAUDRATE_300 = 300,
    UART_BAUDRATE_600 = 600,
    UART_BAUDRATE_1200 = 1200,
    UART_BAUDRATE_1800 = 1800,
    UART_BAUDRATE_2400 = 2400,
    UART_BAUDRATE_4800 = 4800,
    UART_BAUDRATE_7200 = 7200,
    UART_BAUDRATE_9600 = 9600,
    UART_BAUDRATE_14400 = 14400,
    UART_BAUDRATE_19200 = 19200,
    UART_BAUDRATE_38400 = 38400,
    UART_BAUDRATE_57600 = 57600,
    UART_BAUDRATE_115200 = 115200,
    UART_BAUDRATE_128000 = 128000
}UART_BAUDRATE_SETTING_e;

typedef enum
{
    UART_DATA_BITS_8,
    UART_DATA_BITS_9
}UART_DATA_BIT_SETTING_e;

typedef enum
{
    UART_STOP_BITS_1,
    UART_STOP_BITS_2
}UART_STOP_BIT_SETTING_e;

typedef enum
{
    UART_PARITY_NONE,
    UART_PARITY_ODD,
    UART_PARITY_EVEN,
}UART_PARITY_SETTING_e;

// Generic Defines

typedef enum
{
    UART_ENABLED_ON  = 1,
    UART_ENABLED_OFF = 0
}UART_ENABLED_STATE_e;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  TxCON - Register Flags
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#if defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)

// UxMODE: UARTx MODE REGISTER

    // Full Register Bit Fields
    typedef enum
    {
        REG_UARTEN_ON           = 0b1000000000000000,
        REG_UARTEN_OFF          = 0b0000000000000000,

        REG_USIDL_ON            = 0b0000000000000000,
        REG_USIDL_OFF           = 0b0010000000000000,

        REG_IREN_ON             = 0b0001000000000000,
        REG_IREN_OFF            = 0b0000000000000000,

        REG_RTSMD_SIMPLEX       = 0b0000100000000000,
        REG_RTSMD_FLOW_CONTROL  = 0b0000000000000000,

        REG_UEN_TX_RX_BCLK      = 0b0000001100000000,
        REG_UEN_TX_RX_CTS_RTS	= 0b0000001000000000,
        REG_UEN_TX_RX_RTS       = 0b0000000100000000,
        REG_UEN_TX_RX           = 0b0000000000000000,

        REG_WAKE_ENABLED        = 0b0000000010000000,		
        REG_WAKE_DISABLED       = 0b0000000000000000,		

        REG_LPBACK_ENABLED      = 0b0000000001000000,		
        REG_LPBACK_DISABLED     = 0b0000000000000000,		

        REG_ABAUD_ENABLED       = 0b0000000000100000,		
        REG_ABAUD_DISABLED      = 0b0000000000000000,		

        REG_URXINV_ENABLED      = 0b0000000000010000,		
        REG_URXINV_DISABLED     = 0b0000000000000000,		

        REG_BRGH_HIGH_SPEED     = 0b0000000000001000,		
        REG_BRGH_STANDARD       = 0b0000000000000000,		

        REG_PDSEL_9_DBITS_NO_PARITY    = 0b0000000000000110,		
        REG_PDSEL_8_DBITS_ODD_PARITY   = 0b0000000000000100,		
        REG_PDSEL_8_DBITS_EVEN_PARITY  = 0b0000000000000010,		
        REG_PDSEL_8_DBITS_NO_PARITY    = 0b0000000000000000,		

        REG_STSEL_2_STOP_BIT    = 0b0000000000000001,		
        REG_STSEL_1_STOP_BIT    = 0b0000000000000000		

    }REG_UxMODE_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum
    {
        UARTEN_ON           = 0b1,
        UARTEN_OFF          = 0b0,

        USIDL_ON            = 0b0,
        USIDL_OFF           = 0b1,

        IREN_ON             = 0b1,
        IREN_OFF            = 0b0,

        RTSMD_SIMPLEX       = 0b1,
        RTSMD_FLOW_CONTROL  = 0b0,

        UEN_TX_RX_BCLK      = 0b11,
        UEN_TX_RX_CTS_RTS	= 0b10,
        UEN_TX_RX_RTS       = 0b01,
        UEN_TX_RX           = 0b00,

        WAKE_ENABLED        = 0b1,		
        WAKE_DISABLED       = 0b0,		

        LPBACK_ENABLED      = 0b1,		
        LPBACK_DISABLED     = 0b0,		

        ABAUD_ENABLED       = 0b1,		
        ABAUD_DISABLED      = 0b0,		

        URXINV_ENABLED      = 0b1,		
        URXINV_DISABLED     = 0b0,		

        BRGH_HIGH_SPEED     = 0b1,		
        BRGH_STANDARD       = 0b0,		

        PDSEL_9_DBITS_NO_PARITY    = 0b11,		
        PDSEL_8_DBITS_ODD_PARITY   = 0b10,		
        PDSEL_8_DBITS_EVEN_PARITY  = 0b01,		
        PDSEL_8_DBITS_NO_PARITY    = 0b00,		

        STSEL_2_STOP_BIT    = 0b1,		
        STSEL_1_STOP_BIT    = 0b0		

    }REG_UxMODE_FLAGS_e;

    typedef struct
    {
        volatile unsigned stel  :1;	// Bit #0: Stop Bit Selection bit
        volatile unsigned pdsel	:2;	// Bit #1-2: Parity and Data Selection bits
        volatile unsigned brgh  :1;	// Bit #3: High Baud Rate Enable bit
        volatile unsigned uxinv	:1;	// Bit #4: UARTx Receive Polarity Inversion bit
        volatile unsigned abaud	:1;	// Bit #5: Auto-Baud Enable bit
        volatile unsigned lpback:1; // Bit #6: UARTx Loopback Mode Select bit
        volatile unsigned wake	:1;	// Bit #7: Wake-up on Start Bit Detect During Sleep Mode Enable bit
        volatile unsigned uen	:2;	// Bit #8-9: UARTx Pin Enable bits
        volatile unsigned		:1;	// Bit #10: reserved
        volatile unsigned rtsmd	:1;	// Bit #11: Mode Selection for UxRTS Pin bit
        volatile unsigned iren	:1;	// Bit #12: IrDA® Encoder and Decoder Enable bit
        volatile unsigned usidl	:1;	// Bit #13: UARTx Stop in Idle Mode bit
        volatile unsigned		:1;	// Bit #14: reserved
        volatile unsigned uarten:1;	// Bit #15: UARTx Enable bit
    }__attribute__((packed))UxMODE_CONTROL_REGISTER_BIT_FIELD_t;

    
// UxSTA: UARTx STATUS AND CONTROL REGISTER
    
    // Full Register Bit Fields
    typedef enum
    {
        REG_UTXISEL_BUF_EMTPY   = 0b1000000000000000,
        REG_UTXISEL_TX_COMPLETE = 0b0010000000000000,
        REG_UTXISEL_BUF_CUE     = 0b0000000000000000,

        REG_UTXINV_ON           = 0b0100000000000000,
        REG_UTXINV_OFF          = 0b0000000000000000,

        REG_UTXBRK_ON           = 0b0000100000000000,
        REG_UTXBRK_OFF          = 0b0000000000000000,

        REG_UTXEN_ON            = 0b0000010000000000,
        REG_UTXEN_OFF           = 0b0000000000000000,

        REG_UTXBF_ON            = 0b0000001000000000,
        REG_UTXBF_OFF           = 0b0000000000000000,
            
        REG_TRMT_ON             = 0b0000000100000000,
        REG_TRMT_OFF            = 0b0000000000000000,
            
        REG_URXISEL_BUF_FULL    = 0b0000000011000000,
        REG_URXISEL_BUF_75      = 0b0000000010000000,
        REG_URXISEL_BUF_RECEIVE = 0b0000000001000000,

        REG_ADDEN_ENABLED      = 0b0000000000100000,		
        REG_ADDEN_DISABLED     = 0b0000000000000000,		

        REG_RIDLE_ENABLED      = 0b0000000000010000,		
        REG_RIDLE_DISABLED     = 0b0000000000000000,		

        REG_PERR_ENABLED       = 0b0000000000001000,		
        REG_PERR_DISABLED      = 0b0000000000000000,		

        REG_FERR_ENABLED       = 0b0000000000000100,		
        REG_FERR_DISABLED      = 0b0000000000000000,		
            
        REG_OERR_ENABLED       = 0b0000000000000010,		
        REG_OERR_DISABLED      = 0b0000000000000000,		
            
        REG_URXDA_ENABLED      = 0b0000000000000001,		
        REG_URXDA_DISABLED     = 0b0000000000000000		

    }REG_UxSTA_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum
    {
        UTXISEL1_BUF_EMTPY   = 0b1,
        UTXISEL1_TX_COMPLETE = 0b0,
        UTXISEL1_BUF_CUE     = 0b0,

        UTXISEL0_BUF_EMTPY   = 0b0,
        UTXISEL0_TX_COMPLETE = 0b1,
        UTXISEL0_BUF_CUE     = 0b0,
    
        UTXINV_ON           = 0b1,
        UTXINV_OFF          = 0b0,

        UTXBRK_ON           = 0b1,
        UTXBRK_OFF          = 0b0,

        UTXEN_ON            = 0b1,
        UTXEN_OFF           = 0b0,

        UTXBF_ON            = 0b1,
        UTXBF_OFF           = 0b0,
            
        TRMT_ON             = 0b1,
        TRMT_OFF            = 0b0,
            
        URXISEL_BUF_FULL    = 0b11,
        URXISEL_BUF_75      = 0b10,
        URXISEL_BUF_RECEIVE = 0b01,

        ADDEN_ENABLED      = 0b1,		
        ADDEN_DISABLED     = 0b0,		

        RIDLE_ENABLED      = 0b1,		
        RIDLE_DISABLED     = 0b0,		

        PERR_ENABLED       = 0b1,		
        PERR_DISABLED      = 0b0,		

        FERR_ENABLED       = 0b1,		
        FERR_DISABLED      = 0b0,		
            
        OERR_ENABLED       = 0b1,		
        OERR_DISABLED      = 0b0,		
            
        URXDA_ENABLED      = 0b1,		
        URXDA_DISABLED     = 0b0		

    }REG_UxSTA_FLAGS_e;

    typedef struct
    {
        volatile unsigned urxda :1;	// Bit #0: UARTx Receive Buffer Data Available bit (read-only)
        volatile unsigned oerr	:1;	// Bit #1: Receive Buffer Overrun Error Status bit (clear/read-only)
        volatile unsigned ferr	:1;	// Bit #2: Framing Error Status bit (read-only)
        volatile unsigned perr  :1;	// Bit #3: Parity Error Status bit (read-only)
        volatile unsigned ridle	:1;	// Bit #4: Receiver Idle bit (read-only)
        volatile unsigned adden	:1;	// Bit #5: Address Character Detect bit (bit 8 of received data = 1)
        volatile unsigned urxisel:2; // Bit #6-7: UARTx Receive Interrupt Mode Selection bits
        volatile unsigned trmt	:1;	// Bit #8: Transmit Shift Register Empty bit (read-only)
        volatile unsigned utsbf	:1;	// Bit #9: UARTx Transmit Buffer Full Status bit (read-only)
        volatile unsigned utxen	:1;	// Bit #10: UARTx Transmit Enable bit
        volatile unsigned utxbrk:1;	// Bit #11: UARTx Transmit Break bit
        volatile unsigned		:1;	// Bit #12: reserved
        volatile unsigned utxiseldl0:1;	// Bit #13: UARTx Transmission Interrupt Mode Selection bit 0
        volatile unsigned utxinv:1;	// Bit #14: UARTx Transmit Polarity Inversion bit
        volatile unsigned utxiseldl1:1;	// Bit #15: UARTx Transmission Interrupt Mode Selection bit 1
    }__attribute__((packed))UxSTA_CONTROL_REGISTER_BIT_FIELD_t;


#elif defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

    #error === selected device not supported by peripheral driver libraries ===

#else
    #error === selected device not supported by peripheral driver libraries ===
#endif

typedef union 
{
	volatile REG_UxMODE_BIT_FIELD_e reg_block;
	volatile UxMODE_CONTROL_REGISTER_BIT_FIELD_t flags;
}UxMODE_CONTROL_REGISTER_t;

typedef union 
{
	volatile REG_UxSTA_BIT_FIELD_e reg_block;
	volatile UxSTA_CONTROL_REGISTER_BIT_FIELD_t flags;
}UxSTA_CONTROL_REGISTER_t;

// Prototypes

extern inline uint16_t gstmr_init_uart(uint16_t index, UxMODE_CONTROL_REGISTER_BIT_FIELD_t regUxMODE, UxSTA_CONTROL_REGISTER_BIT_FIELD_t regUxSTA);
extern inline uint16_t gsuart_enable(uint16_t index);
extern inline uint16_t gsuart_disable(uint16_t index);
extern inline uint16_t gsuart_dispose(uint16_t index);

extern inline uint16_t gsuart_power_on(uint16_t index);
extern inline uint16_t gsuart_power_off(uint16_t index);

extern inline uint16_t gsuart_open_port(uint16_t index, 
    UART_BAUDRATE_SETTING_e baud, UART_DATA_BIT_SETTING_e data_bits, UART_PARITY_SETTING_e parity, UART_STOP_BIT_SETTING_e stop_bits, 
    UART_ISR_PRIORITY_e isr_priority);


#endif  /* _MCAL_P33_SMPS_UART_H_ */
// End of File
