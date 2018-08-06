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

#include <xc.h> // Device header file
#include <stdint.h>

#include "p33GS_hsadc.h"


/*@@p33EGS_adc.c
 * ************************************************************************************************
 * Summary:
 * Driver file for the dsPIC33ExxGS-ADC SFRs
 *
 * Description:
 * The SMPS ADC module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all majority required settings.
 * ***********************************************************************************************/


/*@@gsadc_module_power_up()
 * *****************************************************************************************************
 * Summary:
 * Turns on the base power of the ADC module 
 *
 * Parameters: 
 *   (none)
 *
 * Description:
 * 
 * *****************************************************************************************************/

int gsadc_module_power_up(void)
{
        #if defined (_ABGMD)
        _ABGMD = 0;         // Turn on power to analog bandgap reference
        #endif
        _ADCMD = 0; 		// Turn on power to ADC module
        return(1);

} 

/*@@gsadc_module_power_down()
 * *****************************************************************************************************
 * Summary:
 * Turns off the base power of the ADC module 
 *
 * Parameters: 
 *   (none)
 *
 * Description:
 * 
 * *****************************************************************************************************/

int gsadc_module_power_down(void)
{
        _ADCMD = 1; 		// Turn on power to PWM channel #1
        return(1);

} 

/*@@gsadc_init_adc
 * ************************************************************************************************
 * Summary:
 * Initializes the basic ADC configuration
 *
 * Parameters:
 *	regADCON1L	= holds the register value for the ADCON register
 *				  => bit 15 of the ADCON1L register, which enables/disables the ADC module,
 *					 will automatically be masked out. Please enable the PWM module by 
 *					 calling gsadc_enable()
 *	regADCON1H	= 
 *	regADCON2L	= 
 *	regADCON2H	= 
 *	regADCON3L	= 
 *	regADCON3H	= 
 *	regADCON4L	= 
 *	regADCON4H	= 
 *	regADCON5L	= 
 *	regADCON5H	= 
 *
 * Description:
 * Basic options like clock source, early interrupts, format options, sampling order and modes
 * are set here.
 * ***********************************************************************************************/

int gsadc_init_adc(uint16_t regADCON1L, uint16_t regADCON1H, uint16_t regADCON2L, 
                   uint16_t regADCON2H, uint16_t regADCON3L, uint16_t regADCON3H, 
                   uint16_t regADCON4L, uint16_t regADCON4H, uint16_t regADCON5L, 
                   uint16_t regADCON5H)
{
    
	// Reset all ADC configuration registers to defaults

	ADCON1L	= REG_ADCON1L_RESET;			// Disable and reset ADC configuration register 1 low
	ADCON1H	= REG_ADCON1H_RESET;			// Disable and reset ADC configuration register 1 high
	ADCON2L	= REG_ADCON2L_RESET;			// Disable and reset ADC configuration register 2 low
	ADCON2H	= REG_ADCON2H_RESET;			// Disable and reset ADC configuration register 2 high
    ADCON3L = REG_ADCON3L_RESET;			// Disable and reset ADC configuration register 3 low
    ADCON3H = REG_ADCON3H_RESET;			// Disable and reset ADC configuration register 3 high
    ADCON4L = REG_ADCON4L_RESET;			// Disable and reset ADC configuration register 4 low
    ADCON4H = REG_ADCON4H_RESET;			// Disable and reset ADC configuration register 4 high
    ADCON5L = REG_ADCON5L_RESET;			// Disable and reset ADC configuration register 5 low
    ADCON5H = REG_ADCON5H_RESET;			// Disable and reset ADC configuration register 5 high
    
	// Setting ADC configuration according to user settings.
	// Please note:
	//  ADC ENABLE is masked out! The ADC has to be enabled by the user in software.
		
	ADCON1L	= (regADCON1L & (REG_ADCON1L_VALID_DATA_MSK & REG_ADCON1L_DISABLED_MASK));
    ADCON1H = (regADCON1H & REG_ADCON1H_VALID_DATA_MSK);
    ADCON2L = (regADCON2L & REG_ADCON2L_VALID_DATA_MSK);
    ADCON2H = (regADCON2H & REG_ADCON2H_VALID_DATA_MSK);
    ADCON3L = (regADCON3L & REG_ADCON3L_VALID_DATA_MSK);
    ADCON3H = (regADCON3H & REG_ADCON3H_VALID_DATA_MSK);
    ADCON4L = (regADCON4L & REG_ADCON4L_VALID_DATA_MSK);
    ADCON4H = (regADCON4H & REG_ADCON4H_VALID_DATA_MSK);
    ADCON5L = (regADCON5L & REG_ADCON5L_VALID_DATA_MSK);
    ADCON5H = (regADCON5H & REG_ADCON5H_VALID_DATA_MSK);

    // Return 1=success, 0=failure
	return(1);

}

/*@@gsadc_init_adc_core
 * ************************************************************************************************
 * Summary:
 * Initializes an individual ADC Core configuration
 *
 * Parameters:
 *	regADCORExL	= holds the register value for the ADCORExL register
 *	regADCORExH	= holds the register value for the ADCORExL register
 *
 * Description:
 * Basic options like conversion delay, early interrupt period, ADC resolution and input clock
 * dividers are set here.
 * ***********************************************************************************************/

int gsadc_init_adc_core(uint16_t index, uint16_t regADCORExL, uint16_t regADCORExH)
{

volatile uint16_t *regptr;
volatile uint16_t reg_offset=0;

	if (index >= ADC_CORE_COUNT) return(0);

    reg_offset = ( index * ADC_ADCORE_REG_OFFSET );
    regptr = (volatile uint16_t *)&ADCORE0L + reg_offset;
    *regptr = (regADCORExL & REG_ADCORExL_VALID_DATA_MSK);

    reg_offset = ( index * ADC_ADCORE_REG_OFFSET );
    regptr = (volatile uint16_t *)&ADCORE0H + reg_offset;
    *regptr = (regADCORExH & REG_ADCORExH_VALID_DATA_MSK);

    return(1);
    
}

/*@@gsadc_module_enable()
 * ************************************************************************************************
 * Summary:
 * Enables the ADC module
 *
 * Parameters: (none)
 *
 * Description:
 * The ADC module has a start-up time of a couple of micro seconds. Therefore the 
 * enable-instruction is followed by a short delay loop.
 * ***********************************************************************************************/

int gsadc_module_enable(void)
{

	ADCON1Lbits.ADON	= ADC_ON; 	// Enable ADC module

	return(ADCON1Lbits.ADON);
	 
}

/*@@gsadc_module_disable()
 * ************************************************************************************************
 * Summary:
 * Disables the ADC module
 *
 * Parameters: (none)
 *
 * Description:
 * Disables the entire ADC module, which will also affect the port registers. Fault states 
 * at certain pins will be lost as every pin will be re-configured as GPIO.
 * ***********************************************************************************************/

int gsadc_module_disable(void)
{

	ADCON1Lbits.ADON = ADC_OFF;			// Disable ADC module 

	return(1);

}

/*@@gsadc_reset()
 * ************************************************************************************************
 * Summary:
 * Resets ADC configuration
 *
 * Parameters:	(none)
 *
 * Description:
 * Resets the entire ADC configuration including the port control registers. All ANx-inputs will
 * become GPIOs.
 * ***********************************************************************************************/

int gsadc_reset(void)
{
	// Reset all ADC configuration registers to defaults

	ADCON1Lbits.ADON = ADC_OFF;				// Disable ADC
  
	ADCON1L	= REG_ADCON1L_RESET;			// Disable and reset ADC configuration register 1 low
	ADCON1H	= REG_ADCON1H_RESET;			// Disable and reset ADC configuration register 1 high
	ADCON2L	= REG_ADCON2L_RESET;			// Disable and reset ADC configuration register 2 low
	ADCON2H	= REG_ADCON2H_RESET;			// Disable and reset ADC configuration register 2 high
    ADCON3L = REG_ADCON3L_RESET;			// Disable and reset ADC configuration register 3 low
    ADCON3H = REG_ADCON3H_RESET;			// Disable and reset ADC configuration register 3 high
    ADCON4L = REG_ADCON4L_RESET;			// Disable and reset ADC configuration register 4 low
    ADCON4H = REG_ADCON4H_RESET;			// Disable and reset ADC configuration register 4 high
    ADCON5L = REG_ADCON5L_RESET;			// Disable and reset ADC configuration register 5 low
    ADCON5H = REG_ADCON5H_RESET;			// Disable and reset ADC configuration register 5 high
    
	return(1);
}


/*@@gsadc_calibrate_adc_core()
 * ************************************************************************************************
 * Summary:
 * Calls the ADC calibration of a single ADC core
 *
 * Parameters:	(none)
 *
 * Description:
 * The individual ADC cores of the ADC peripheral require a self calibration procedure 
 * to meet the values given in the data sheet. The following function performs the self
 * calibration of the given ADC core.
 * ***********************************************************************************************/

int gsadc_calibrate_adc_core(uint16_t index, uint16_t calib_mode)
{
	volatile uint16_t timeout=0;
    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0;
    
    if (index >= ADC_CORE_COUNT) return(0);
    
    reg_offset = ((index >> 1) * ADC_ADCAL_REG_OFFSET);   // Index is divided by 2 due to shared registers
    regptr = (volatile uint16_t *)&ADCAL0L + reg_offset;
    
    // differentiate between odd and even indices due to shared registers
    if (index == ADC_SHARED_CORE_INDEX) {

        regptr = (volatile uint16_t *)&ADCAL1H + reg_offset;

        *regptr |= REG_ADCALx_HB_CALxEN_SET_MSK;  // Enable calibration
        *regptr &= REG_ADCALx_HB_CALxSKIP_CLR_MSK;  // Initiate calibration
        *regptr &= ((calib_mode << 8) | REG_ADCALx_HB_CALxDIFF_CLR_MSK);  // Set calibration mode (differential or single ended))
        *regptr |= REG_ADCALx_HB_CALxRUN_SET_MSK;  // Initiate calibration

        // Wait until ADC core calibration has completed
        while( ((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0) && (timeout++<5000));
        if((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0) return(0);  // If core doesn't enter READY state, return failure
        
        *regptr &= REG_ADCALx_HB_CALxEN_CLR_MSK;  // Disable calibration
        
    }
    else if(index & 0x0001) {
        // Odd index (1, 3, 5, ...) and shared ADC bits are located in the high-byte of the register word
        
        *regptr |= REG_ADCALx_HB_CALxEN_SET_MSK;  // Enable calibration
        *regptr &= REG_ADCALx_HB_CALxSKIP_CLR_MSK;  // Initiate calibration
        *regptr &= ((calib_mode << 8) | REG_ADCALx_HB_CALxDIFF_CLR_MSK);  // Set calibration mode (differential or single ended))
        *regptr |= REG_ADCALx_HB_CALxRUN_SET_MSK;  // Initiate calibration

        // Wait until ADC core calibration has completed
        while( ((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0) && (timeout++<5000));
        if((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0) return(0);  // If core doesn't enter READY state, return failure
        
        *regptr &= REG_ADCALx_HB_CALxEN_CLR_MSK;  // Disable calibration

    }
    else{
        // Even index (0, 2, 4, ...) bits are located in the low-byte of the register word
        
        *regptr |= REG_ADCALx_LB_CALxEN_SET_MSK;  // Enable calibration
        *regptr &= REG_ADCALx_LB_CALxSKIP_CLR_MSK;  // Initiate calibration
        *regptr &= (calib_mode | REG_ADCALx_LB_CALxDIFF_CLR_MSK);  // Set calibration mode (differential or single ended))
        *regptr |= REG_ADCALx_LB_CALxRUN_SET_MSK;  // Initiate calibration

        // Wait until ADC core calibration has completed
        while( ((*regptr & REG_ADCALx_LB_CALxRDY_SET_MSK) == 0) && (timeout++<5000));
        if((*regptr & REG_ADCALx_LB_CALxRDY_SET_MSK) == 0) return(0);  // If core doesn't enter READY state, return failure
        
        *regptr &= REG_ADCALx_LB_CALxEN_CLR_MSK;  // Disable calibration

    }
	
	return(1);
	
}

/*@@gsadc_power_on_adc_core()
 * ************************************************************************************************
 * Summary:
 * Turns on a single ADC core considering warm-up time
 *
 * Parameters:	(none)
 *
 * Description:
 * The individual ADC cores of the ADC peripheral require a self calibration procedure 
 * to meet the values given in the data sheet. The following function performs the self
 * calibration of the given ADC core.
 * ***********************************************************************************************/

int gsadc_power_on_adc_core(uint16_t index)
{
	volatile uint16_t timeout=0;
    volatile uint16_t *regptr;
    volatile uint16_t reg_buf=0;
    
    if (index >= ADC_CORE_COUNT) return(0);
    
    regptr = (volatile uint16_t *)&ADCON5L;
    
    // Power on ADC core x 
    if(index == ADC_SHARED_CORE_INDEX) { 
      // Shared CorePower Setting is located in Bit #7, while all 
      // others are enumerated on Bits #0, #1, etc
        reg_buf  = (REG_ADCON5L_SHRPWR_ON & REG_ADCON5L_VALID_DATA_MSK);
        *regptr |= reg_buf;
        
    }
    else {
      // Dedicated core power on enable bits are set based on the index/bit position 
        reg_buf  = ((0x0001 << index) & REG_ADCON5L_VALID_DATA_MSK);
        *regptr |= reg_buf;
    }
    
    reg_buf <<= 8;   // Shift selected bit up into the high-word of ADCON5L for the status check
    
    // Wait until ADC core woke up and is ready
    while(((*regptr & reg_buf) == 0) && (timeout++<5000));
    if(!(timeout < 5000))    return(0);  // If core doesn't enter READY state, return failure


    // Set pointer onto ADC core enable register ADCON3H
    regptr = (volatile uint16_t *)&ADCON3H;
    
    // Power on ADC core x 
    if(index == ADC_SHARED_CORE_INDEX) { 
      // Shared CorePower Setting is located in Bit #7, while all 
      // others are enumerated on Bits #0, #1, etc
        reg_buf  = (REG_ADCON3H_SHREN_ON & REG_ADCON3H_VALID_DATA_MSK);
        *regptr |= reg_buf;
        
    }
    else {
      // Dedicated core power on enable bits are set based on the index/bit position 
        *regptr |= ((0x0001 << index) & REG_ADCON3H_VALID_DATA_MSK);
    }
    
	return(1);
	
}

/*@@gsadc_set_adc_core_trigger()
 * ************************************************************************************************
 * Summary:
 * Configures interrupt trigger setting of an individual Analog Input
 *
 * Parameters:	1: success, 0: failure
 *
 * Description:
 * 
 * ***********************************************************************************************/

int gsadc_set_adc_input_trigger_source(uint16_t index, uint16_t trigger_source)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;
    
    if (index >= ADC_ANINPUT_COUNT) return(0);

    reg_offset = ((index >> 1) * ADC_ADTRIG_REG_OFFSET);   // Index is divided by 2 due to shared registers
    regptr = (volatile uint16_t *)&ADTRIG0L + reg_offset;

    if (index & 0x0001) {
    // Odd analog input numbers are located in the high-byte of the register word
        reg_buf = ((trigger_source << 8) & REG_ADTRIGx_VALID_DATA_MSK);
        *regptr |= reg_buf;
    }
    else{
    // Even analog input numbers are located in the low-byte of the register word
        reg_buf = (trigger_source & REG_ADTRIGx_VALID_DATA_MSK);
        *regptr |= reg_buf;

    }

    return(1);
}

/*@@gsadc_set_adc_core_interrupt()
 * ************************************************************************************************
 * Summary:
 * configures the interrupt generation of a single ADC core
 *
 * Parameters:	(none)
 *
 * Description:
 * The individual ADC cores of the ADC peripheral support the generation of interrupts. Further
 * Those interrupts can be "pulled-in" to compensate the interrupt latency of the controller
 * ***********************************************************************************************/

int gsadc_set_adc_core_interrupt(uint16_t index, uint16_t interrupt_enable, uint16_t early_interrupt_enable)
{
    volatile uint16_t *regptr;
    
    if (index >= ADC_ANINPUT_COUNT) return(0);
    
    if (index<16) {   

        // Setting the Early Interrupt Enable Bit
        regptr = (volatile uint16_t *)&ADEIEL;
        *regptr |= (early_interrupt_enable << index);

        // Setting the Interrupt Enable Bit
        regptr = (volatile uint16_t *)&ADIEL;
        *regptr |= (interrupt_enable << index);
    }
    else {

        index -= 16;

        #ifdef ADEIEH
        // Setting the Early Interrupt Enable Bit
        regptr = (volatile uint16_t *)&ADEIEH;
        *regptr |= (early_interrupt_enable << index);

        // Setting the Interrupt Enable Bit
        regptr = (volatile uint16_t *)&ADIEH;
        *regptr |= (interrupt_enable << index);
        #else
        return(0);
        #endif
    }
    
	return(1);
	
}

/*@@gsadc_init_adc_comp
 * ************************************************************************************************
 * Summary:
 * Initializes an individual digital ADC Comparator configuration
 *
 * Parameters:
 *	regADCMPxCON = holds the register value for the ADC comparator configuration register (ADCMPxCON)
 *	regADCMP0ENx = holds the register value for the ADC input used as data input
 *  regADCMPxLO = holds the compare value for the lower trip point threshold
 *  regADCMPxHI = holds the compare value for the upper trip point threshold
 * 
 * Description:
 * The ADC peripheral features a digital comparator, which compares the latest sample of a dedicated
 * ANx input with given upper and lower threshold values. If the values is outside the given range,
 * an interrupt will be triggered (if enabled).
 * This routine allows configuration of the comparator, the input source and its thresholds.
 * ***********************************************************************************************/

int gsadc_init_adc_comp(uint16_t index, uint16_t input_no, uint16_t regADCMPxCON, uint16_t regADCMPxLO, uint16_t regADCMPxHI)
{

volatile uint16_t *regptr;
volatile uint16_t reg_offset=0;

	if (index >= REG_ADCMP_COUNT) return(0);

    // ADC Comparator Configuration
    reg_offset = ( index * REG_ADCMP_REG_OFFSET );
    regptr = (volatile uint16_t *)&ADCMP0CON + reg_offset;
    *regptr = (regADCMPxCON & REG_ADCMPxCON_VALID_DATA_WR_MSK);

    // Lower Threshold Compare Value
    reg_offset = ( index * REG_ADCMPxLO_OFFSET );
    regptr = (volatile uint16_t *)&ADCMP0LO + reg_offset;
    *regptr = (regADCMPxLO & REG_ADCMPxLO_VALID_DATA_MASK);

    // Upper Threshold Compare Value
    reg_offset = ( index * REG_ADCMPxHI_OFFSET );
    regptr = (volatile uint16_t *)&ADCMP0HI + reg_offset;
    *regptr = (regADCMPxHI & REG_ADCMPxHI_VALID_DATA_MASK);
    
    // Assigning ANx inputs for the comparison
    if (input_no < 16) {   

        // Enabling the corresponding analog input comparator input
        reg_offset = ( index * REG_ADCMPxEN_REG_OFFSET );
        regptr = (volatile uint16_t *)&ADCMP0ENL + reg_offset;
        *regptr = (1 << input_no);

    }
    else if (input_no < 32) {

        input_no -= 16;

        #ifdef ADCMP0ENH
        // Enabling the corresponding analog input comparator input
        reg_offset = ( index * REG_ADCMPxEN_REG_OFFSET );
        regptr = (volatile uint16_t *)&ADCMP0ENH + reg_offset;
        *regptr = (1 << input_no);
        #else
        return(0);
        #endif
    }
    else { return(0); }
    
    return(1);
    
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

// EOF
