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
ISR: 		PWM Special Event Match Interrupt
Description: 
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv, context)) _PWMSpEventMatchInterrupt()
{	

#if(TRIGGER_OPTION == TRG_OPTION_PWM)
	// Call outer voltage control loop
    cnpnz_vmc_Update(&cnpnz_vmc);
#endif
    
	IFS3bits.PSEMIF = 0; // clear interrupt flag

	return;

}

/***************************************************************************
ISR: 		PWM Secondary Special Event Match Interrupt
Description: 
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _PWMSecSpEventMatchInterrupt()
{
    
    Nop();
    Nop();
    Nop();
    
    IFS4bits.PSESIF = 0; // clear interrupt flag
    return;
    
}

/***************************************************************************
ISR: 		PWM1Interrupt
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv, context)) _PWM1Interrupt() 
{	

    
	IFS5bits.PWM1IF = 0;	// Clear interrupt flag bit

	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		PWM2Interrupt
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv, context)) _PWM2Interrupt() 
{	
    
	IFS5bits.PWM2IF = 0;	// Clear interrupt flag bit
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		PWM3Interrupt
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv, context)) _PWM3Interrupt() 
{	
	IFS6bits.PWM3IF = 0;	// Clear interrupt flag bit
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		PWM4Interrupt
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv, context)) _PWM4Interrupt() 
{	
	IFS6bits.PWM4IF = 0;	// Clear interrupt flag bit
	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

#if defined (_P33GS_UEAA_) || defined (_P33GS_TLAH_) || defined (_P33GS_TLAY_)

/***************************************************************************
ISR: 		PWM5Interrupt
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _PWM5Interrupt() 
{	


	IFS6bits.PWM5IF = 0;	// Clear interrupt flag bit

	return;

}
/***************************************************************************
End of ISR
***************************************************************************/

#elif defined (_P33GS_UEAA_) || defined (_P33GS_TLAY_)

/***************************************************************************
ISR: 		PWM6Interrupt
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _PWM6Interrupt() 
{	


	IFS6bits.PWM6IF = 0;	// Clear interrupt flag bit

	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

#if defined (__dsPIC33FJ32GS608__) || defined (__dsPIC33FJ32GS610__) || \
	defined (__dsPIC33FJ64GS608__) || defined (__dsPIC33FJ64GS610__)

/***************************************************************************
ISR: 		PWM7Interrupt
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _PWM7Interrupt() 
{	


	IFS6bits.PWM7IF = 0;	// Clear interrupt flag bit

	return;

}
/***************************************************************************
End of ISR
***************************************************************************/
#endif

#if defined (__dsPIC33FJ32GS608__) || defined (__dsPIC33FJ32GS610__) || \
	defined (__dsPIC33FJ64GS608__) || defined (__dsPIC33FJ64GS610__)

/***************************************************************************
ISR: 		PWM8Interrupt
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _PWM8Interrupt() 
{	


	IFS6bits.PWM8IF = 0;	// Clear interrupt flag bit

	return;

}
/***************************************************************************
End of ISR
***************************************************************************/
#endif

#if defined (__dsPIC33FJ32GS610__) || defined (__dsPIC33FJ64GS610__)

/***************************************************************************
ISR: 		PWM9Interrupt
Description:	
***************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _PWM9Interrupt() 
{	


	IFS6bits.PWM9IF = 0;	// Clear interrupt flag bit

	return;

}
/***************************************************************************
End of ISR
***************************************************************************/
#endif 