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
 * File:   isr_gpio.c
 * Author: M91406
 *
 * Created on December 19, 2016, 11:21 AM
 */


// Device header file
#include <xc.h>
#include <stdint.h>

#include "globals.h"

/***************************************************************************
ISR: 		CNInterrupt for all change notification enabled GPIOs
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _CNInterrupt() 
{	

	IFS1bits.CNIF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		_INT1Interrupt for External Interrupt #0
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _INT0Interrupt() 
{	

	IFS1bits.INT1IF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		_INT0Interrupt for External Interrupt #1
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _INT1Interrupt() 
{	

	IFS0bits.INT0IF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		_INT2Interrupt for External Interrupt #2
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _INT2Interrupt() 
{	

	IFS1bits.INT2IF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		_INT4Interrupt for External Interrupt #4
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _INT4Interrupt() 
{	

	IFS3bits.INT4IF = 0;	// Clear interrupt flag bit
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

// EOF
