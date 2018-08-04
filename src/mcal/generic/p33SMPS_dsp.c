/*LICENSE *****************************************************************************************
 *
 * Software License Agreement
 *
 * Copyright (R) 2012 Microchip Technology Inc.  All rights reserved. Microchip licenses to you the
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


#include <xc.h>         // Device header file
#include <stdint.h>

#include "p33SMPS_dsp.h"

/*@@p33EGS_dsp.c
 * ************************************************************************************************
 * Summary:
 * Driver file for the dsPIC33ExxGS-DSP SFRs
 *
 * Description:
 * The embedded Digital Signal Processor offers some configuration options. This additional
 * driver file contains initialization routines for all majority required settings.
 * ***********************************************************************************************/

/*@@gsdsp_init_dsp
 * ************************************************************************************************
 * Summary:
 * Initializes the basic DSP configuration
 *
 * Parameters:
 *	regCORCON	= holds the register value for the core configuration register (CORCON)
 *
 * Description:
 * Basic options like clock source, early interrupts, format options, sampling order and modes
 * are set here.
 * ***********************************************************************************************/

uint16_t gsdsp_init_dsp(uint16_t regCORCON)
{

volatile uint16_t reg_buf=0, i_res=0;

	reg_buf = (regCORCON & REG_CORCON_WRITE_MSK);	// Status-bits will be masked out
	CORCON = reg_buf;	

	if((CORCON & REG_CORCON_WRITE_MSK) == reg_buf) i_res = 1;

	return(i_res);
	
}

