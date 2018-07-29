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
#include "init_hsadc.h"

/*@@init_adc
 *****************************************************************************
 * Function:	 void init_adc(void)
 * Arguments:	 (none)
 * Return Value: (none)
 *
 * Summary:
 * initializes the analog-to-digital converter
 *
 * Description:	
 * This routine initializes the analog-to-digital converter with basic 
 * settings and configures the input pairs, 
 * 
 **************************************************************************/

uint16_t init_hsadc(void)
{
    uint16_t i_res=1;

	// Set Analog inputs

    ADC_VOUT_ADC_ANSEL = 1;    // 1: Enable Analog Input, 0: Disable Analog Input
    ADC_VIN_ADC_ANSEL = 1;     // 1: Enable Analog Input, 0: Disable Analog Input
    ADC_PH1_IL_ANSEL = 1;      // 1: Enable Analog Input, 0: Disable Analog Input
    
    // Turn on ADC module power
    i_res = gsadc_module_power_up();
    
    // Run basic initialization of ADC module features
	i_res &= gsadc_init_adc(
        ADC_ADCON1L_CFG, ADC_ADCON1H_CFG, ADC_ADCON2L_CFG, ADC_ADCON2H_CFG,
        ADC_ADCON3L_CFG, ADC_ADCON3H_CFG, ADC_ADCON4L_CFG, ADC_ADCON4H_CFG, 
        ADC_ADCON5L_CFG, ADC_ADCON5H_CFG);

    // Initialize individual ADC cores
    i_res &= gsadc_init_adc_core(ADC_VOUT_ADCORE, ADC_VOUT_ADCORExL_CFG, ADC_VOUT_ADCORExH_CFG);
    i_res &= gsadc_init_adc_core(ADC_VIN_ADCORE, ADC_VIN_ADCORExL_CFG, ADC_VIN_ADCORExH_CFG);
    i_res &= gsadc_init_adc_core(ADC_PH1_IL_ADCORE, ADC_PH1_IL_ADCORExL_CFG, ADC_PH1_IL_ADCORExH_CFG);
    
    // Enable ADC Module
    i_res &= gsadc_module_enable();
    
    // Power on ADC cores and run calibration
    i_res &= gsadc_power_on_adc_core(ADC_VOUT_ADCORE);
    i_res &= gsadc_calibrate_adc_core(ADC_VOUT_ADCORE, ADC_ADCAL_CALIB_MODE);

    i_res &= gsadc_power_on_adc_core(ADC_VIN_ADCORE);
    i_res &= gsadc_calibrate_adc_core(ADC_VIN_ADCORE, ADC_ADCAL_CALIB_MODE);

    i_res &= gsadc_power_on_adc_core(ADC_PH1_IL_ADCORE);
    i_res &= gsadc_calibrate_adc_core(ADC_PH1_IL_ADCORE, ADC_ADCAL_CALIB_MODE);

    // Set ADC Interrupt Trigger
    i_res &= gsadc_set_adc_input_trigger_source(ADC_VOUT_ANALOG_INPUT, ADC_VOUT_TRIG_SOURCE);
    i_res &= gsadc_set_adc_input_trigger_source(ADC_VIN_ANALOG_INPUT, ADC_VIN_TRIG_SOURCE);
    i_res &= gsadc_set_adc_input_trigger_source(ADC_PH1_IL_ANALOG_INPUT, ADC_PH1_IL_TRIG_SOURCE);

    // Set up digital comparators for input and output voltage
    i_res &= gsadc_init_adc_comp( ADC_ADCMP_VIN, ADC_VIN_ANALOG_INPUT, ADC_ADCMP_VIN_CFG, VIN_UVLO_TRIP, VIN_OVLO_TRIP );
    i_res &= gsadc_init_adc_comp( ADC_ADCMP_VOUT, ADC_VOUT_ANALOG_INPUT, ADC_ADCMP_VOUT_CFG, 0, VOUT_OVP_TRIP );
    
    // Set up Interrupts
    i_res &= gsadc_set_adc_core_interrupt(ADC_VOUT_ANALOG_INPUT, ADC_VOUT_ADIN_IE, ADC_VOUT_ADCORE_EIE);
    i_res &= gsadc_set_adc_core_interrupt(ADC_VIN_ANALOG_INPUT, ADC_VIN_ADIN_IE, ADC_VIN_ADCORE_EIE);
    i_res &= gsadc_set_adc_core_interrupt(ADC_PH1_IL_ANALOG_INPUT, ADC_PH1_IL_ADIN_IE, ADC_PH1_IL_ADCORE_EIE);

    STRIG1 = 7000;  // TODO: Move this setting into system configuration
    
    ADC_VIN_ADCMP_IP = 3;
    ADC_VIN_ADCMP_IF = 0;
    ADC_VIN_ADCMP_IE = 0;

    ADC_VOUT_ADCMP_IP = 3;
    ADC_VOUT_ADCMP_IF = 0;
    ADC_VOUT_ADCMP_IE = 0;

	return(i_res);
	
}


/*@@launch_ADC
 *****************************************************************************
 * Function:	 void launch_ADC(void)
 * Arguments:	 (none)
 * Return Value: 1: success, 0: failure
 *
 * Summary:
 * Activates the analog-to-digital converter
 *
 * Description:	
 * This routine activates the analog-to-digital converter with basic 
 * settings including configured interrupt sources and settings. 
 * 
 **************************************************************************/

uint16_t exec_launch_hsadc(void)
{
    uint16_t i_res=1;
    uint16_t dummy_buffer=0;

    i_res &= gspwm_set_adc_trigger(CVRT_PH1_PWM_IDX, PWMx_HIGH, 500);

    ADC_VOUT_ADC_IF = 0;                            // Reset Interrupt Flag Bit
    dummy_buffer = ADC_VOUT_ADCBUF;                 // Dummy Read
    ADC_VOUT_ADC_IP = ADC_VOUT_ISR_PRIORITY;        // Set Interrupt Priority
    ADC_VOUT_ADC_IE = ADC_VOUT_ADIN_IE;             // Enable/Disable Interrupt

    ADC_VIN_ADC_IF = 0;
    dummy_buffer = ADC_VIN_ADCBUF;                  // Dummy Read
    ADC_VIN_ADC_IP = ADC_VIN_ISR_PRIORITY;          // Set Interrupt Priority
    ADC_VIN_ADC_IE = ADC_VIN_ADIN_IE;               // Enable/Disable Interrupt
    
    ADC_PH1_IL_ADC_IF = 0;
    dummy_buffer = ADC_PH1_IL_ADCBUF;               // Dummy Read
    ADC_PH1_IL_ADC_IP = ADC_PH1_IL_ISR_PRIORITY;    // Set Interrupt Priority
    ADC_PH1_IL_ADC_IE = ADC_PH1_IL_ADIN_IE;         // Enable/Disable Interrupt
    
    return(i_res);
}
    
