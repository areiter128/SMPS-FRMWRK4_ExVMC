/*@@Software License Agreement
 * ************************************************************************************************
 *
 * Software License Agreement
 *
 * Copyright © 2012 Microchip Technology Inc.  All rights reserved. Microchip licenses to you the
 * right to use, modify, copy and distribute Software only when embedded on a Microchip 
 * microcontroller or digital signal controller, which is integrated into your product or third 
 * party product (pursuant to the sublicense terms in the accompanying license agreement).
 *
 * You should refer to the license agreement accompanying this Software for additional information 
 * regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR 
 * IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR 
 * OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT  
 * LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS  
 * OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY  
 * THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *
 * ***********************************************************************************************/

#include "p33SMPS_pps.h"

/*@@p33GS_pps.c
 * ************************************************************************************************
 * Summary:
 * Generic Peripheral Pin Select (PPS) Driver Module
 *
 * Dependencies:    
 * pps.h
 *
 * Description:
 * Some low-pincount devices have the capability to assign digital functions to a range of 
 * free configurable pins (RPx). This driver module offers functions to read from and write to
 * the configuration registers, which will connect a digital peripheral bock with a selected 
 * pin.
 *
 * References:
 * dsPIC33F Reference Manual, Section 10: I/O Ports, Chapter 10.3: Peripheral Multiplexing
 *
 * Author:	Andreas Reiter, Microchip Technology
 * Version: 1.2
 *
 * History:
 *	11/04/2008	First Release
 *  08/25/2009	Added definitions for new peripherals
 *  02/05/2012	Format transfer
 *  04/11/1016	Added definitions and compile switches for dsPIC33EP GS
 *
 * ***********************************************************************************************/

/*@@pps_LockIO
 * ************************************************************************************************
 * Summary:
 * Locks the Peripheral Pin Select Configuration registers against accidential changes
 *
 * Parameters:
 *	(none)
 *
 * Returns:
 *	(none)
 *
 * Description:
 * This inline-assembly routine locks the Port Multiplexing Configuration registers by keeping
 * the required number of cycles during the Lock pocess. This function has to be called once 
 * before digital functions are mapped to a specific pin. Once called, a series of assignments
 * can be executed.
 * 
 * Note:
 * If bit IOL1WAY in the Oscillator Configuration Bits (FOSC) is set, only one pin assignment
 * operation will be allowed. all following calls of Unlock() or Lock() will be ignored. 
 *
 * See Also:
 *	p33EGS_pps.h, FOSC, IOL1WAY, IOL1WAY_ON, IOL1WAY_OFF; pps_UnlockIO
 * 
 * ***********************************************************************************************/
void pps_LockIO(void){

	asm volatile
	(	"nop \n"
		"disi #7 \n"
		"mov #OSCCON,w1 \n"
		"mov #0x46, w2 \n"
		"mov #0x57, w3 \n"
		"mov.b w2,[w1] \n"
		"mov.b w3,[w1] \n"
		"bset OSCCON, #6 \n"
		"disi #0 \n"			// see errata
		"nop \n"
	);
}

/*@@pps_UnlockIO
 * ************************************************************************************************
 * Summary:
 * Unlocks the Peripheral Pin Select Configuration registers to enable changes
 *
 * Parameters:
 *	(none)
 *
 * Returns:
 *	(none)
 *
 * Description:
 * This inline-assembly routine unlocks the Port Multiplexing Configuration registers by keeping
 * the required number of cycles during the unlock pocess. This function has to be called once 
 * after digital functions have been mapped to a specific pin, to prevent accidential changes. 
 * 
 * Note:
 * If bit IOL1WAY in the Oscillator Configuration Bits (FOSC) is set, only one pin assignment
 * operation wil be allowed. all following calls of Unlock() or Lock() will be ignored. 
 *
 * See Also:
 *	pps.h, FOSC, IOL1WAY, IOL1WAY_ON, IOL1WAY_OFF, pps_LockIO
 * 
 * ***********************************************************************************************/
void pps_UnlockIO(void){

	asm volatile
	(	"nop \n"
		"disi #7 \n"
		"mov #OSCCON,w1 \n"
		"mov #0x46, w2 \n"
		"mov #0x57, w3 \n"
		"mov.b w2,[w1] \n"
		"mov.b w3,[w1] \n"
		"bclr OSCCON, #6 \n"
		"disi #0 \n"			// see errata
		"nop \n"
	);
}

/*@@pps_RemapOutput
 * ************************************************************************************************
 * Summary:
 * Assigns a digital function output to a pin
 *
 * Parameters:
 *	unsigned char pinno: Number of the RPx-pin, which should be assigned to the function
 *	unsigned char peripheral: Function, which should be assigned to the pin
 *
 * Returns:
 *	1: Success
 *	0: Error
 *
 * Description:
 * Any supported digital function output (e.g. UART TxD) can be assigned to one of the RPx pins
 * of the MCU/DSC. To assign a function output to a pin, call 
 *
 *	pps_RemapOutput([RP-NUMBER], [FUNCTION])
 * 
 * Example:
 *	lres |= pps_RemapOutput(PIN_RP9 , PPSOUT_SYNCO1);	// Assign RP9 to PWMSyncClkOutput
 *
 * See Also:
 *	pps.h, FOSC, IOL1WAY, IOL1WAY_ON, IOL1WAY_OFF, pps_LockIO, pps_UnlockIO, pps_RemapInput, 
 *  pps_UnmapOutput, pps_UnmapInput
 * 
 * ***********************************************************************************************/
unsigned char pps_RemapOutput(unsigned char pinno, unsigned char peripheral){
	
static volatile unsigned char *regptr;
unsigned char val;
  
	// PPS pins on some devices don't start at 0 and offset-handling is required
	if ( pinno < RP_PINNO_MIN ) 
    {
        return (0); 	// Pin-No mismatch => return with error
    }

    #if defined (__P33SMPS_EP__)
    
    else if((RP_PINNO_MIN < pinno) && (pinno < RP_PINNO_GAP_MIN))
    {
        pinno = pinno - RP_PINNO_MIN;	// subtract register offset
    }
    else if((RP_PINNO_GAP_MIN < pinno) && (pinno < RP_PINNO_GAP_MAX))
    {
        return (0); 	// Pin-No mismatch => return with error
    }
    else if((RP_PINNO_GAP_MAX <= pinno) && (pinno <= RP_PINNO_MAX))
    {
        pinno = (pinno - RP_PINNO_GAP_MAX);	// subtract register offset
        pinno = pinno + PR_PINNO_GAP_OFFSET; // account for the lower registers
    }
    #else
        pinno -= RP_PINNO_MIN;	// subtract register offset
    #endif
    
	// Map selected pin function
	if ((pinno < RP_PINNO_MAX) || (pinno == PIN_RP_TO_VSS))	// check if pin assign is 
	{ 														// within a valid range
		regptr = (volatile unsigned char *)&RPOR0 + pinno;	// get basic address
	
		// get byte address offset based on requested pin: regptr += pinno;                  
		*regptr = peripheral;	// copy requested configuration  
		val = 1;				// report success
	}
	else                      // otherwise report failure 
	{
		val = 0;
	}
	return val;
}

/*@@pps_RemapInput
 * ************************************************************************************************
 * Summary:
 * Assigns a pin to a digital function input
 *
 * Parameters:
 *	unsigned char pinno: Number of the RPx-pin, which should be assigned to the function
 *	unsigned char peripheral: Function, which should be assigned to the pin
 *
 * Returns:
 *	1: Success
 *	0: Error
 *
 * Description:
 * Any RPx pin can be assigned to a supported digital function input (e.g. UART RxD). To assign 
 * a pin to a function input, call 
 *
 *	pps_RemapInput([RP-NUMBER], [FUNCTION])
 * 
 * Example:
 *	lres |= pps_RemapInput(PIN_RP10, PPSIN_U1RX);		// Assign RP10 to UART1 RxD
 *
 * See Also:
 *	pps.h, FOSC, IOL1WAY, IOL1WAY_ON, IOL1WAY_OFF, pps_LockIO, pps_UnlockIO, pps_RemapOutput, 
 *  pps_UnmapInput, pps_UnmapOutput
 * 
 * ***********************************************************************************************/
unsigned char pps_RemapInput(unsigned char pinno, unsigned char *regptr)
{
unsigned char c_ret;
  
	// Map selected pin function
	if ((pinno < RP_PINNO_MAX) || (pinno == PIN_RP_TO_VSS))		// check if pin assign is 
	{ 															// within a valid range
		*regptr = pinno;
		c_ret = 1;				// report success
	}
	else                      // otherwise report failure
	{
		c_ret = 0;
	}
	return c_ret;
  
}

/*@@pps_UnmapOutput
 * ************************************************************************************************
 * Summary:
 * Disconnects a pin from a digital function output
 *
 * Parameters:
 *	unsigned char pinno: Number of the RPx-pin
 *
 * Returns:
 *	1: Success
 *	0: Error
 *
 * Description:
 * An existing assignment between any RPx pin and a supported digital function output will be
 * dissolved.
 *
 *	pps_UnmapOutput([RP-NUMBER])
 * 
 * Example:
 *	lres |= pps_UnmapOutput(PIN_RP9);		// Dissolve RP9 assignment
 *
 * See Also:
 *	pps.h, FOSC, IOL1WAY, IOL1WAY_ON, IOL1WAY_OFF, pps_LockIO, pps_UnlockIO, pps_RemapInput, 
 *  pps_RemapOutput, pps_UnmapInput
 * 
 * ***********************************************************************************************/
unsigned char pps_UnmapOutput(unsigned char pinno)
{
unsigned char val;

	// PPS pins on some devices don't start at 0 and offset-handling is required
	if (RP_PINNO_MIN > pinno)
	{
		return (0); 	// Pin-No mismatch => return with error
	}
	else
	{
		pinno -= RP_PINNO_MIN;
	}

	// Unmap selected pin function
	val = pps_RemapOutput(pinno, PPSOUT_NONE);
	return val;

}

/*@@pps_UnmapInput
 * ************************************************************************************************
 * Summary:
 * Disconnects a pin from a digital function input
 *
 * Parameters:
 *	unsigned char pinno: Number of the RPx-pin
 *
 * Returns:
 *	1: Success
 *	0: Error
 *
 * Description:
 * An existing assignment between any RPx pin and a supported digital function input will be
 * dissolved.
 *
 *	pps_UnmapInput([RP-NUMBER])
 * 
 * Example:
 *	lres |= pps_UnmapInput(PIN_RP10);		// Dissolve RP10 assignment
 *
 * See Also:
 *	pps.h, FOSC, IOL1WAY, IOL1WAY_ON, IOL1WAY_OFF, pps_LockIO, pps_UnlockIO, pps_RemapInput, 
 *  pps_RemapOutput, pps_UnmapOutput
 * 
 * ***********************************************************************************************/
unsigned char pps_UnmapInput(unsigned char *regptr)
{
unsigned char val;

	// Unmap selected pin function
	val = pps_RemapInput(PIN_RP_TO_VSS, regptr);
	return val;

}

// End Of File
