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
 *****************************************************************************/


// Device header file
#include <xc.h>
#include <stdint.h>

#include "globals.h"

/***************************************************************************
ISR: 		ADCMP1Interrupt for ADC input comparator #0 threshold violation
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _ADCMP0Interrupt() 
{	
volatile uint16_t dummy=0;

	dummy = ADCBUF1;
    
	IFS11bits.ADCMP0IF = 0;	// Clear interrupt flag bit

    Nop();
    Nop();
    Nop();
	
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCMP1Interrupt for ADC input comparator #1 threshold violation
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _ADCMP1Interrupt()
{	

    Nop();
    Nop();
    Nop();

	IFS11bits.ADCMP1IF = 0;	// Clear interrupt flag bit

	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

//EOF
