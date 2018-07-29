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

#include <xc.h>     // Device header file
#include <stdint.h>

#include "p33GS_hsacmp.h"



/*@@p33GS_hsacmp.c
 * ************************************************************************************************
 * Summary:
 * Driver file for the dsPIC33 GS High Speed Analog Comparator and DAC Modules
 *
 * Description:
 * This driver file provides standard C-functions to initialize,, configure, enable/disable and 
 * and set values of the high speed analog comparators with integrated Digital-To-Analog converters
 * (DAC)
 * ***********************************************************************************************/


/*@@gscmp_init
 * ************************************************************************************************
 * Summary:
 * Initializes the high-speed analog comparator configuration register
 *
 * Parameters:
 *	index		= integer selecting the comparator used
 *	regCMPCON	= holds the register value for the CMPCON register
 *				  => bit 15 of the CMPCON register, which enables/disables the comparator
 *					 module, will automatically be masked out.
 *					 Please enable the comparator module by calling gscmp_enable()
 *	regDAC		= comparator digital-to-analog converter output voltage value
 *
 * Description:
 * freely addressable hardware driver offering pre-defined functions for certain
 * standard tasks like initialization, enable/disable and setting a reference value
 * ***********************************************************************************************/
uint16_t gscmp_init(uint16_t index, uint16_t regCMPCON, uint16_t regDAC)
{

volatile uint16_t *regptr;
volatile uint16_t reg_offset=0;

	if ((index > GSCMP_DEVICE_COUNT) || (GSCMP_DEVICE_COUNT == 0)) return(0);

	reg_offset = ((index-1) * GSCMP_DEVICE_REG_OFFSET);
	regptr  = (volatile uint16_t *)&CMPCON_ORIGIN + reg_offset;
	*regptr = ((regCMPCON & REG_CMPCON_VALID_DATA_MSK) & REG_CMPCON_HSACMP_OFF_MASK);		/* Comparator ENABLE is masked out */

	regptr  = (volatile uint16_t *)&CMPDAC_ORIGIN + reg_offset;
	*regptr = (regDAC & REG_CMPDAC_VALID_DATA_MSK);				/* Comparator DAC value is limited to 10 bit */

	return(1);

}


/*@@gscmp_module_power_up()
 * ************************************************************************************************
 * Summary:
 * turns on power to entire comparator module 
 *
 * Parameters: (none)
 *
 * Description:
 * Enables the power to the high-speed analog comparator module of the dsPIC33 GS. Each comparator 
 * has its individual module power enable bit and has to be enabled additionally.
 *
 * ***********************************************************************************************/

uint16_t gscmp_module_power_up(void)
{
    #if defined (_P33SMPS_TLAH_)
    _ABGMD = 0;     // Turn on power to analog bandgap reference for DAC
    #endif
    
    _CMPMD = 0;     // Turn on power to entire comparator module
    return(1);
}

/*@@gscmp_module_power_down()
 * ************************************************************************************************
 * Summary:
 * turns off power to entire comparator module 
 *
 * Parameters: (none)
 *
 * Description:
 * Disables the power to the high-speed analog comparator module of the dsPIC33 GS. Each comparator 
 * has its individual module power disable bit and has to be disabled additionally.
 *
 * ***********************************************************************************************/

uint16_t gscmp_module_power_down(void)
{
    _CMPMD = 1;     // Turn off power to entire comparator module
    return(1);
}

/*@@gscmp_channel_power_up()
 * ************************************************************************************************
 * Summary:
 * turns on power to entire comparator module 
 *
 * Parameters: (none)
 *
 * Description:
 * Enables the power to one specific high-speed analog comparator of the dsPIC33 GS. Each comparator 
 * has its individual module power enable bit. 
 *
 * ***********************************************************************************************/

uint16_t gscmp_channel_power_up(uint16_t index)
{

	if ((index > GSCMP_DEVICE_COUNT) || (GSCMP_DEVICE_COUNT == 0)) return(0);
    
    switch (index){
    #if (GSCMP_DEVICE_COUNT >= 1)
    case 1:
        _CMP1MD = 0;    // Turn on power to specific comparator
        break;
    #endif
    #if (GSCMP_DEVICE_COUNT >= 2)
    case 2:
        _CMP2MD = 0;    // Turn on power to specific comparator
        break;
    #endif
    #if (GSCMP_DEVICE_COUNT >= 3)
    case 3:
        _CMP3MD = 0;    // Turn on power to specific comparator
        break;
    #endif
    #if (GSCMP_DEVICE_COUNT >= 4)
    case 4:
        _CMP4MD = 0;    // Turn on power to specific comparator
        break;
    #endif
    default:
        return(0);
        break;
    }

	return(1);

}

/*@@gscmp_channel_power_down()
 * ************************************************************************************************
 * Summary:
 * turns off power to entire comparator module 
 *
 * Parameters: index of the selected analog comparator
 *
 * Description:
 * Disables the power to one specific high-speed analog comparator of the dsPIC33 GS. Each comparator 
 * has its individual module power disable bit. 
 *
 * ***********************************************************************************************/

uint16_t gscmp_channel_power_down(uint16_t index)
{

	if ((index > GSCMP_DEVICE_COUNT) || (GSCMP_DEVICE_COUNT == 0)) return(0);
    
    switch (index){
    #if (GSCMP_DEVICE_COUNT >= 1)
    case 1:
        _CMP1MD = 1;    // Turn off power to specific comparator
        break;
    #endif
    #if (GSCMP_DEVICE_COUNT >= 2)
    case 2:
        _CMP2MD = 1;    // Turn off power to specific comparator
        break;
    #endif
    #if (GSCMP_DEVICE_COUNT >= 3)
    case 3:
        _CMP3MD = 1;    // Turn off power to specific comparator
        break;
    #endif
    #if (GSCMP_DEVICE_COUNT >= 4)
    case 4:
        _CMP4MD = 1;    // Turn off power to specific comparator
        break;
    #endif
    default:
        return(0);
        break;
    }

	return(1);

}


/*@@gscmp_enable()
 * ************************************************************************************************
 * Summary:
 * Enables a specific analog comparator 
 *
 * Parameters: (none)
 *
 * Description:
 * Enables one specific high-speed analog comparator of the dsPIC33 GS. Each comparator has its
 * individual enable bit. 
 *
 * ***********************************************************************************************/

uint16_t gscmp_enable(uint16_t index)
{

volatile uint16_t *regptr;
volatile uint16_t reg_offset=0;

	if ((index > GSCMP_DEVICE_COUNT) || (GSCMP_DEVICE_COUNT == 0)) return(0);

	reg_offset = ((index-1) * GSCMP_DEVICE_REG_OFFSET);
	regptr  = (volatile uint16_t *)&CMPCON_ORIGIN + reg_offset;
	*regptr |= REG_CMPON_ON;				/* Comparator ENABLE bit is set */
	if(!(*regptr & REG_CMPON_ON)) return(0);

	return(1);

}


/*@@gscmp_disable()
 * ************************************************************************************************
 * Summary:
 * Disables a specific analog comparator 
 *
 * Parameters: (none)
 *
 * Description:
 * Enables the PWM module with previous configurations. This routine also incorporates an errata
 * on certain dsPIC GS devices encountering glitches when PWM is turned on.
 * ***********************************************************************************************/

uint16_t gscmp_disable(uint16_t index)
{

volatile uint16_t *regptr;
volatile uint16_t reg_offset=0;

	if ((index > GSCMP_DEVICE_COUNT) || (GSCMP_DEVICE_COUNT == 0)) return(0);

	reg_offset = ((index-1) * GSCMP_DEVICE_REG_OFFSET);
	regptr   = (volatile uint16_t *)&CMPCON_ORIGIN + reg_offset;
	*regptr &=  (REG_CMPON_CLR_MASK & REG_CMPCON_VALID_DATA_MSK);	/* Comparator ENABLE bit is cleared */
	if(*regptr & REG_CMPON_ON) return(0);

	return(1);

}

/*@@gscmp_select_input()
 * ************************************************************************************************
 * Summary:
 * Selects a specific analog comparator input
 *
 * Parameters: comparator index 1 to n
 *
 * Description:
 * Selects one specific high-speed analog comparator input pin of the dsPIC33 GS. Each comparator has its
 * individual setting. 
 *
 * ***********************************************************************************************/

uint16_t gscmp_select_input(uint16_t index, uint16_t reg_cmp_input)
{

volatile uint16_t *regptr;
volatile uint16_t reg_offset=0;
volatile uint16_t reg_buf=0;

	if ((index > GSCMP_DEVICE_COUNT) || (GSCMP_DEVICE_COUNT == 0)) return(0);

	reg_offset = ((index-1) * GSCMP_DEVICE_REG_OFFSET);
	regptr  = (volatile uint16_t *)&CMPCON_ORIGIN + reg_offset;
	reg_buf = ((*regptr & REG_CMPCON_VALID_DATA_MSK) & REG_INSEL_CLR_MASK);
    *regptr = (reg_buf | (reg_cmp_input & REG_INSEL_SET_MASK));		/* Comparator input bit setting */

	return(1);

}


/*@@gscmp_set_threshold()
 * ************************************************************************************************
 * Summary:
 * Sets the DAC value to generate a certain reference voltage
 *
 * Parameters: 
 *	index:		comparator index 1 to n
 *	dac_value:	integer number within the DAC resolution	
 * 
 * Description:
 * Sets the trip threshold of the analog comparator given by [index] as a common integer
 * value within the available range of the resolution of the DAC
 *
 * ***********************************************************************************************/

uint16_t gscmp_set_threshold(uint16_t index, uint16_t threshold_value)
{

volatile uint16_t *regptr;
volatile uint16_t reg_offset=0;

	if ((index > GSCMP_DEVICE_COUNT) || (GSCMP_DEVICE_COUNT == 0)) return(0);

	reg_offset = ((index-1) * GSCMP_DEVICE_REG_OFFSET);
	regptr  = (volatile uint16_t *)&CMPDAC_ORIGIN + reg_offset;
	*regptr = (threshold_value & REG_CMPDAC_VALID_DATA_MSK);		/* Comparator DAC bit setting */

	return(1);

}

/* EOF */
