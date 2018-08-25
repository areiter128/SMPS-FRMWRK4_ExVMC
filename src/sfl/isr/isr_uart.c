/*LICENSE *****************************************************************************
 * 
 * Software License Agreement
 *
 * Copyright � 2015 Microchip Technology Inc.  All rights reserved.
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
 **************************************************************************** */
/*
 * File:   isr_uart.c
 * Author: M91406
 *
 * Created on December 19, 2016, 11:12 AM
 **************************************************************************** */


// Device header file
#include <xc.h>
#include <stdint.h>

#include "globals.h"

#if defined (U1MODE)
/***************************************************************************
ISR: 		Transmit Interrupt for UART #1
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _U1TXInterrupt() 
{	

	_U1TXIF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		Receive Interrupt for UART #1
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _U1RXInterrupt() 
{	

	_U1RXIF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		Receive Interrupt for UART #1
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _U1ErrInterrupt() 
{	

	_U1EIF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/
#endif

#if defined (U2MODE)
/***************************************************************************
ISR: 		Transmit Interrupt for UART #2
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _U2TXInterrupt() 
{	

	_U2TXIF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		Receive Interrupt for UART #2
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _U2RXInterrupt() 
{	

	_U2RXIF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		Receive Interrupt for UART #2
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _U2ErrInterrupt() 
{	

	_U2EIF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/
#endif

#if defined (U3MODE)
/***************************************************************************
ISR: 		Transmit Interrupt for UART #3
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _U3TXInterrupt() 
{	

	_U3TXIF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/
#endif

#if defined (U4MODE)
/***************************************************************************
ISR: 		Transmit Interrupt for UART #4
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _U4TXInterrupt() 
{	

	_U4TXIF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/
#endif

// EOF
