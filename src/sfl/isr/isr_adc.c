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
ISR: 		ADCAN0Interrupt for AN0
Description:	Inductor Current Phase #1
***************************************************************************/
#if defined (ADCBUF0)
void __attribute__((__interrupt__,no_auto_psv, context)) _ADCAN0Interrupt() 
{	
    volatile uint16_t dummy=0;

#if(TRIGGER_OPTION == TRG_OPTION_ADC)
    // Call control loop
    c2P2Z16bsft(&c_cmc_ph1);
#endif
    
    
	dummy = ADCBUF0;
	IFS6bits.ADCAN0IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN0RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN1Interrupt for AN1
Description:	 Input voltage ADC (ISR not used)
***************************************************************************/
#if defined (ADCBUF1)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN1Interrupt()
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF1;
	IFS6bits.ADCAN1IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN1RDY = 0;	// Clear the data is ready in buffer bits

	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN2Interrupt for AN2
Description:	Inductor Current Phase #2
***************************************************************************/
#if defined (ADCBUF2)
void __attribute__((__interrupt__,no_auto_psv, context)) _ADCAN2Interrupt() 
{	
    volatile uint16_t dummy=0;

#if(TRIGGER_OPTION == TRG_OPTION_ADC)
	// Call control loop
    c2P2Z16bsft(&c_cmc_ph2);
#endif
    
	dummy = ADCBUF2;
	IFS7bits.ADCAN2IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN2RDY = 0;	// Clear the data is ready in buffer bits

	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN3Interrupt for AN3
Description:	Output voltage ADC
***************************************************************************/
#if defined (ADCBUF3)
void __attribute__((__interrupt__, auto_psv, context)) _ADCAN3Interrupt()  
{	
    volatile uint16_t dummy=0;

#if(TRIGGER_OPTION == TRG_OPTION_ADC)
	// Call outer voltage control loop
    c3P3Z16bsft(&c_vmc);
#endif
    
    dummy = ADC_VIN_ADCBUF;
    dummy = ADC_VOUT_ADCBUF;

	dummy = ADCBUF3;
	IFS7bits.ADCAN3IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN3RDY = 0;	// Clear the data is ready in buffer bits

	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN4Interrupt for AN4
Description:	
***************************************************************************/
#if defined (ADCBUF4)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN4Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF4;
	IFS7bits.ADCAN4IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN4RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif 
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN5Interrupt for AN5
Description:	
***************************************************************************/
#if defined (ADCBUF5)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN5Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF5;
	IFS7bits.ADCAN5IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN5RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN6Interrupt for AN6
Description:	
***************************************************************************/
#if defined (ADCBUF6)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN6Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF6;
	IFS7bits.ADCAN6IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN6RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif 
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN7Interrupt for AN4
Description:	
***************************************************************************/
#if defined (ADCBUF7)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN7Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF7;
	IFS7bits.ADCAN7IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN7RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN8Interrupt for AN8
Description:	
***************************************************************************/
#if defined (ADCBUF8)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN8Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF8;
	IFS9bits.ADCAN8IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN8RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN9Interrupt for AN9
Description:	
***************************************************************************/
#if defined (ADCBUF9)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN9Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF9;
	IFS9bits.ADCAN9IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN9RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN10Interrupt for AN10
Description:	
***************************************************************************/
#if defined (ADCBUF10)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN10Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF10;
	IFS9bits.ADCAN10IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN10RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN11Interrupt for AN11
Description:	
***************************************************************************/
#if defined (ADCBUF11)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN11Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF11;
	IFS9bits.ADCAN11IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN11RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN12Interrupt for AN12
Description:	
***************************************************************************/
#if defined (ADCBUF12)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN12Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF12;
	IFS9bits.ADCAN12IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN12RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN13Interrupt for AN13
Description:	
***************************************************************************/
#if defined (ADCBUF13)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN13Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF13;
	IFS9bits.ADCAN13IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN13RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN14Interrupt for AN14
Description:	
***************************************************************************/
#if defined (ADCBUF14)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN14Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF14;
	IFS9bits.ADCAN14IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN14RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN15Interrupt for AN15
Description:	
***************************************************************************/
#if defined (ADCBUF15)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN15Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF15;
	IFS9bits.ADCAN15IF = 0;	// Clear interrupt flag bit
	ADSTATLbits.AN15RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN16Interrupt for AN16
Description:	
***************************************************************************/
#if defined (ADCBUF16)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN16Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF16;
	IFS9bits.ADCAN16IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN16RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN17Interrupt for AN17
Description:	
***************************************************************************/
#if defined (ADCBUF17)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN17Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF17;
	IFS10bits.ADCAN17IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN17RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN18Interrupt for AN18
Description:	
***************************************************************************/
#if defined (ADCBUF18)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN18Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF18;
	IFS10bits.ADCAN18IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN18RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN19Interrupt for AN19
Description:	
***************************************************************************/
#if defined (ADCBUF19)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN19Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF19;
	IFS10bits.ADCAN19IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN19RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN20Interrupt for AN20
Description:	
***************************************************************************/
#if defined (ADCBUF20)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN20Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF20;
	IFS10bits.ADCAN20IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN20RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN21Interrupt for AN21
Description:	
***************************************************************************/
#if defined (ADCBUF21)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN21Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF21;
	IFS10bits.ADCAN21IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN21RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN22Interrupt for AN22
Description:	
***************************************************************************/
#if defined (ADCBUF22)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN22Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF22;
	IFS10bits.ADCAN22IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN22RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN23Interrupt for AN23
Description:	
***************************************************************************/
#if defined (ADCBUF23)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN23Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF23;
	IFS10bits.ADCAN23IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN23RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN24Interrupt for AN24
Description:	
***************************************************************************/
#if defined (ADCBUF24)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN24Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF24;
	IFS10bits.ADCAN24IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN24RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN25Interrupt for AN25
Description:	
***************************************************************************/
#if defined (ADCBUF25)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN25Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF25;
	IFS10bits.ADCAN25IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN25RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN26Interrupt for AN26
Description:	
***************************************************************************/
#if defined (ADCBUF26)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN26Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF26;
	IFS10bits.ADCAN26IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN26RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN27Interrupt for AN27
Description:	
***************************************************************************/
#if defined (ADCBUF27)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN27Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF27;
	IFS10bits.ADCAN27IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN27RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN28Interrupt for AN28
Description:	
***************************************************************************/
#if defined (ADCBUF28)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN28Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF28;
	IFS10bits.ADCAN28IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN28RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN29Interrupt for AN29
Description:	
***************************************************************************/
#if defined (ADCBUF29)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN29Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF29;
	IFS10bits.ADCAN29IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN29RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN23Interrupt for AN30
Description:	
***************************************************************************/
#if defined (ADCBUF30)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN30Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF30;
	IFS10bits.ADCAN30IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN30RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif
/***************************************************************************
End of ISR
***************************************************************************/

/***************************************************************************
ISR: 		ADCAN23Interrupt for AN31
Description:	
***************************************************************************/
#if defined (ADCBUF31)
void __attribute__((__interrupt__,no_auto_psv)) _ADCAN31Interrupt() 
{	
    volatile uint16_t dummy=0;

	dummy = ADCBUF31;
	IFS10bits.ADCAN31IF = 0;	// Clear interrupt flag bit
	ADSTATHbits.AN31RDY = 0;	// Clear the data is ready in buffer bits
	
	return;

}
#endif

//EOF
