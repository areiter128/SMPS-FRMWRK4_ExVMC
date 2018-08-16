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

#ifndef _P33EGS_ADC_H_
#define _P33EGS_ADC_H_

#include <stdint.h>
#include "p33SMPS_devices.h"

#include "syscfg_scaling.h"

/*@@p33FGS_adc.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33FxxGS-ADC SFRs
 *
 * Description:
 * The SMPS ADC module offers a number of registers and configuration options. This additional
 * header file contains defines for all required bit-settings. This additional
 * header file contains defines for all required bit-settings of all related registers.
 * This file is an additional header file on top of the generic device header file.
 * ***********************************************************************************************/

// Prototypes
extern inline uint16_t gsadc_module_power_up(void);
extern inline uint16_t gsadc_module_power_down(void);

extern inline uint16_t gsadc_init_adc(
                   uint16_t regADCON1L, uint16_t regADCON1H, uint16_t regADCON2L, 
                   uint16_t regADCON2H, uint16_t regADCON3L, uint16_t regADCON3H, 
                   uint16_t regADCON4L, uint16_t regADCON4H, uint16_t regADCON5L, 
                   uint16_t regADCON5H);

extern inline uint16_t gsadc_init_adc_core(uint16_t index, uint16_t regADCORExL, uint16_t regADCORExH);

extern inline uint16_t gsadc_module_enable(void);
extern inline uint16_t gsadc_module_disable(void);
extern inline uint16_t gsadc_reset(void);

extern inline uint16_t gsadc_calibrate_adc_core(uint16_t index, uint16_t calib_mode);
extern inline uint16_t gsadc_power_on_adc_core(uint16_t index);

extern inline uint16_t gsadc_set_adc_input_trigger_source(uint16_t index, uint16_t interrupt_trigger);
extern inline uint16_t gsadc_set_adc_core_interrupt(uint16_t index, uint16_t interrupt_enable, uint16_t early_interrupt_enable);

extern inline uint16_t gsadc_init_adc_comp(uint16_t index, uint16_t input_no, uint16_t regADCMPxCON, uint16_t regADCMPxLO, uint16_t regADCMPxHI);

// Device-specific Defines

#if defined (__P33SMPS_EP2__)

    #define ADC_CORE_COUNT          3					// Number of ADC Cores available
    #define ADC_ANINPUT_COUNT       12                  // Number of analog inputs
    #define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core
    
    #define ADC_ADCONL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCORE_REG_OFFSET   2

    #define ADC_ADMODL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCAL_REG_OFFSET    1
    #define ADC_ADCBUF_REG_OFFSET   1

    #define ADC_ADTRIG_REG_OFFSET   1   
    
    #define REG_AN_INPUT_L_MSK         0b0000111111111111
    #define REG_AN_INPUT_H_MSK         0b0000000000000000

    #define REG_ADCMP_COUNT         2
    #define REG_ADCMP_REG_OFFSET    2
    #define REG_ADCMPxEN_REG_OFFSET 4
    #define REG_ADCMPxLO_OFFSET     4
    #define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP5__)

    #define ADC_CORE_COUNT          5					// Number of ADC Cores available
    #define ADC_ANINPUT_COUNT       12                  // Number of analog inputs
    #define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core
    
    #define ADC_ADCONL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCORE_REG_OFFSET   2

    #define ADC_ADMODL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCAL_REG_OFFSET    1

    #define ADC_ADTRIG_REG_OFFSET   1

    #define REG_AN_INPUT_L_MSK         0b0000111111111111
    #define REG_AN_INPUT_H_MSK         0b0000000000000000

    #define REG_ADCMP_COUNT         2
    #define REG_ADCMP_REG_OFFSET    2
    #define REG_ADCMPxEN_REG_OFFSET 4
    #define REG_ADCMPxLO_OFFSET     4
    #define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP504__) 

    #define ADC_CORE_COUNT          5					// Number of ADC Cores available
    #define ADC_ANINPUT_COUNT       19                  // Number of analog inputs
    #define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core
    
    #define ADC_ADCONL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCORE_REG_OFFSET   2

    #define ADC_ADMODL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCAL_REG_OFFSET    1

    #define ADC_ADTRIG_REG_OFFSET   1

    #define REG_AN_INPUT_L_MSK         0b1111111111111111
    #define REG_AN_INPUT_H_MSK         0b0000000000000111

    #define REG_ADCMP_COUNT         2
    #define REG_ADCMP_REG_OFFSET    2
    #define REG_ADCMPxEN_REG_OFFSET 4
    #define REG_ADCMPxLO_OFFSET     4
    #define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP505__) 

    #define ADC_CORE_COUNT          5					// Number of ADC Cores available
    #define ADC_ANINPUT_COUNT       19                  // Number of analog inputs
    #define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core
    
    #define ADC_ADCONL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCORE_REG_OFFSET   2

    #define ADC_ADMODL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCAL_REG_OFFSET    1

    #define ADC_ADTRIG_REG_OFFSET   1

    #define REG_AN_INPUT_L_MSK         0b1111111111111111
    #define REG_AN_INPUT_H_MSK         0b0000000000000111

    #define REG_ADCMP_COUNT         2
    #define REG_ADCMP_REG_OFFSET    2
    #define REG_ADCMPxEN_REG_OFFSET 4
    #define REG_ADCMPxLO_OFFSET     4
    #define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP506__)

    #define ADC_CORE_COUNT          5					// Number of ADC Cores available
    #define ADC_ANINPUT_COUNT       22                  // Number of analog inputs
    #define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core
    
    #define ADC_ADCONL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCORE_REG_OFFSET   2

    #define ADC_ADMODL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCAL_REG_OFFSET    1

    #define ADC_ADTRIG_REG_OFFSET   1


    #define REG_ADC_CHANNEL_L_MSK   0b1111111111111111
    #define REG_ADC_CHANNEL_H_MSK   0b0000000000111111

    #define REG_ADCMP_COUNT         2
    #define REG_ADCMP_REG_OFFSET    2
    #define REG_ADCMPxEN_REG_OFFSET 4
    #define REG_ADCMPxLO_OFFSET     4
    #define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP702__) || defined (__P33SMPS_EP802__)

    #define ADC_CORE_COUNT          5					// Number of ADC Cores available
    #define ADC_ANINPUT_COUNT       11                  // Number of analog inputs
    #define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core
    
    #define ADC_ADCONL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCORE_REG_OFFSET   2

    #define ADC_ADMODL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCAL_REG_OFFSET    1

    #define ADC_ADTRIG_REG_OFFSET   1

    #define REG_AN_INPUT_L_MSK         0b0000111111111111
    #define REG_AN_INPUT_H_MSK         0b0000000000000000

    #define REG_ADCMP_COUNT         2
    #define REG_ADCMP_REG_OFFSET    2
    #define REG_ADCMPxEN_REG_OFFSET 4
    #define REG_ADCMPxLO_OFFSET     4
    #define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP704__) || defined (__P33SMPS_EP804__)

    #define ADC_CORE_COUNT          5					// Number of ADC Cores available
    #define ADC_ANINPUT_COUNT       17                  // Number of analog inputs
    #define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core
    
    #define ADC_ADCONL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCORE_REG_OFFSET   2

    #define ADC_ADMODL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCAL_REG_OFFSET    1

    #define ADC_ADTRIG_REG_OFFSET   1

    #define REG_AN_INPUT_L_MSK         0b1111111111111111
    #define REG_AN_INPUT_H_MSK         0b0000000000000111

    #define REG_ADCMP_COUNT         2
    #define REG_ADCMP_REG_OFFSET    2
    #define REG_ADCMPxEN_REG_OFFSET 4
    #define REG_ADCMPxLO_OFFSET     4
    #define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP705__) || defined (__P33SMPS_EP805__)

    #define ADC_CORE_COUNT          5					// Number of ADC Cores available
    #define ADC_ANINPUT_COUNT       19                  // Number of analog inputs
    #define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core
    
    #define ADC_ADCONL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCORE_REG_OFFSET   2

    #define ADC_ADMODL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCAL_REG_OFFSET    1

    #define ADC_ADTRIG_REG_OFFSET   1

    #define REG_AN_INPUT_L_MSK         0b1111111111111111
    #define REG_AN_INPUT_H_MSK         0b0000000000000111

    #define REG_ADCMP_COUNT         2
    #define REG_ADCMP_REG_OFFSET    2
    #define REG_ADCMPxEN_REG_OFFSET 4
    #define REG_ADCMPxLO_OFFSET     4
    #define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP706__) || defined (__P33SMPS_EP806__) || \
      defined (__P33SMPS_EP708__) || defined (__P33SMPS_EP808__)

    #define ADC_CORE_COUNT          5					// Number of ADC Cores available
    #define ADC_ANINPUT_COUNT       22                  // Number of analog inputs
    #define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core
    
    #define ADC_ADCONL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCORE_REG_OFFSET   2

    #define ADC_ADMODL_REG_OFFSET   2
    #define ADC_ADCONH_REG_OFFSET   2
    #define ADC_ADCAL_REG_OFFSET    1

    #define ADC_ADTRIG_REG_OFFSET   1


    #define REG_ADC_CHANNEL_L_MSK   0b1111111111111111
    #define REG_ADC_CHANNEL_H_MSK   0b0000000000111111

    #define REG_ADCMP_COUNT         2
    #define REG_ADCMP_REG_OFFSET    2
    #define REG_ADCMPxEN_REG_OFFSET 4
    #define REG_ADCMPxLO_OFFSET     4
    #define REG_ADCMPxHI_OFFSET     4


#else

// If the selected device is unknown, a warning for invalid settings will be sent to the
// output window

#warning -- ADC level trigger sensitivity settings are not valid for selected device --


#endif


// Device-specific Defines
#define ADC_VREF        DEVICE_VDD     // ADC reference voltage in [V]
#define ADC_RES_BIT     12.0    // ADC resolution in integer
#define ADC_RES         (uint16_t)(pow(2, ADC_RES_BIT)-1)    // ADC resolution in integer
#define ADC_SCALER      (float)(((float)(ADC_RES))/((float)(ADC_VREF))) // ADC Scaling in ticks/V

#define ADC_ANx_INTERRUPT_ENABLE        1       // Bit setting for enabled interrupts of a dedicated analog input
#define ADC_ANx_INTERRUPT_DISABLE       0       // Bit setting for disabled interrupts of a dedicated analog input

#define ADC_ANx_EARLY_INTERRUPT_ENABLE  1       // Bit setting for enabled early interrupts of a dedicated analog input
#define ADC_ANx_EARLY_INTERRUPT_DISABLE 0       // Bit setting for disabled early interrupts of a dedicated analog input

// General Flags
#define ADC_OFF							0b0		// Flag is used to shut down the adc module
#define ADC_ON							0b1		// Flag is used to enable the adc module

// REGISTER 19-1: ADCON1L: ANALOG-TO-DIGITAL CONTROL REGISTER 1 LOW

#define REG_ADCON1L_RESET               0b0000000000000000      // Reset ADCON 1 Low Register
#define REG_ADCON1L_VALID_DATA_MSK		0b1010000000000000		// Bit mask used to set unimplemented bits to zero
#define REG_ADCON1L_DISABLED_MASK       0b0111111111111111

#define REG_ADCON1L_ADON_ON				0b1000000000000000      // Turn ADC Module On
#define REG_ADCON1L_ADON_OFF			0b0000000000000000      // Turn ADC Module Off

#define REG_ADCON1L_ADSIDL_ON			0b0010000000000000      // Module Discontinues Operation in Idle Mode
#define REG_ADCON1L_ADSIDL_OFF			0b0000000000000000      // Module Continues Operation in Idle Mode

#define RAG_ADCON1L_PUMPEN_ON           0b0001000000000000
#define RAG_ADCON1L_PUMPEN_OFF          0b0000000000000000

// REGISTER 19-2: ADCON1H: ANALOG-TO-DIGITAL CONTROL REGISTER 1 HIGH

#define REG_ADCON1H_RESET               0b0000000001100000      // Reset ADCON 1 High Register
#define REG_ADCON1H_VALID_DATA_MSK		0b0000000011100000		// Bit mask used to set unimplemented bits to zero

#define REG_ADCON1H_FORM_FRACTIONAL		0b0000000010000000      // Result Number Format = Fractional
#define REG_ADCON1H_FORM_INTEGER		0b0000000000000000      // Result Number Format = Integer

#define REG_ADCON1H_SHRRES_12BIT        0b0000000001100000      // Set for 12-bit operation
#define REG_ADCON1H_SHRRES_10BIT        0b0000000001000000      // Set for 10-bit operation
#define REG_ADCON1H_SHRRES_8BIT         0b0000000000100000      // Set for 8-bit operation
#define REG_ADCON1H_SHRRES_6BIT         0b0000000000000000      // Set for 6-bit operation

// REGISTER 19-3: ADCON2L: ANALOG-TO-DIGITAL CONTROL REGISTER 2 LOW

#define REG_ADCON2L_RESET               0b0000000000000000      // Reset ADCON 2 Low Register
#define REG_ADCON2L_VALID_DATA_MSK		0b1101011101111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCON2L_SHRADC_CFG_MASK     0b0001011101111111      // Bit-Mask eliminating all bits not concerning the shared ADC core configuration
#define REG_ADCON2L_REF_CFG_MASK        0b1100000000000000      // Bit-Mask eliminating all bits not concerning the bandgap reference configuration

#define REG_ADCON2L_REFCIE_ON           0b1000000000000000      // Interrupt on Band Gap & Reference Voltage Ready
#define REG_ADCON2L_REFCIE_OFF          0b0000000000000000      // No Interrupt on Band Gap & Reference Voltage Ready

#define REG_ADCON2L_REFERCIE_ON         0b0100000000000000      // Interrupt on Band Gap or Reference Voltage Error
#define REG_ADCON2L_REFERCIE_OFF        0b0000000000000000      // No Interrupt on Band Gap or Reference Voltage Error

#define REG_ADCON2L_EIEN_ON             0b0001000000000000      // Early Interrupts Enabled
#define REG_ADCON2L_EIEN_OFF            0b0000000000000000      // Early Interrupts Disabled

#define REG_ADCON2L_SHREISEL_8TAD       0b0000011100000000      // Early Interrupts 8 TADs before READY
#define REG_ADCON2L_SHREISEL_7TAD       0b0000011000000000      // Early Interrupts 7 TADs before READY
#define REG_ADCON2L_SHREISEL_6TAD       0b0000010100000000      // Early Interrupts 6 TADs before READY
#define REG_ADCON2L_SHREISEL_5TAD       0b0000010000000000      // Early Interrupts 5 TADs before READY
#define REG_ADCON2L_SHREISEL_4TAD       0b0000001100000000      // Early Interrupts 4 TADs before READY
#define REG_ADCON2L_SHREISEL_3TAD       0b0000001000000000      // Early Interrupts 3 TADs before READY
#define REG_ADCON2L_SHREISEL_2TAD       0b0000000100000000      // Early Interrupts 2 TADs before READY
#define REG_ADCON2L_SHREISEL_1TAD       0b0000000000000000      // Early Interrupts 1 TADs before READY

#define REG_SHRADCS_MSK                 0b0000000001111111      // Bit-Mask to filter on clock divider value bits
#define REG_SHRADCS(x)                  ((x >> 1) & REG_SHRADCS_MSK) 	// Shared ADC Core Input Clock Divider bits

// REGISTER 19-4: ADCON2H: ANALOG-TO-DIGITAL CONTROL REGISTER 2 HIGH

#define REG_ADCON2H_RESET               0b0000000000000000      // Reset ADCON 2 High Register
#define REG_ADCON2H_VALID_DATA_MSK		0b1100001111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCON2H_SHRADC_CFG_MASK     0b0000001111111111      // Bit-Mask eliminating all bits not concerning the shared ADC core configuration
#define REG_ADCON2H_REF_CFG_MASK        0b1100000000000000      // Bit-Mask eliminating all bits not concerning the bandgap reference configuration

#define REG_ADCON2H_REF_STAT_READ_MASK  0b1100000000000000      // Bit-Mask for reading the bandgap reference status bits
#define REG_ADCON2H_SHRSAMC_MSK         0b0000001111111111      // Bit-Mask to filter on clock periods value bits
#define REG_ADCON2H_SHRSAMC(x)          ((x-2) & REG_ADCON2H_SHRSAMC_MSK) 		// Shared ADC Core Sample Time Selection bits

// REGISTER 19-5: ADCON3L: ANALOG-TO-DIGITAL CONTROL REGISTER 3 LOW

#define REG_ADCON3L_RESET               0b0000000000000000      // Reset ADCON 3 Low Register
#define REG_ADCON3L_VALID_DATA_MSK		0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCON3L_REFSEL_AVDD_AVSS    0b0000000000000000      // Vref = AVDD to AVSS

#define REG_ADCON3L_SUSPEND_ON          0b0001000000000000      // All ADC triggers are disabled
#define REG_ADCON3L_SUSPEND_OFF         0b0000000000000000      // All ADC triggers are enabled

#define REG_ADCON3L_SUSPCIE_ON          0b0000100000000000      // Suspend Interrupt Enabled
#define REG_ADCON3L_SUSPCIE_OFF         0b0000000000000000      // Suspend Interrupt Disabled

#define REG_ADCON3L_SUSPRDY_ON          0b0000010000000000      // READ ONLY: Suspend Status ON
#define REG_ADCON3L_SUSPRDY_OFF         0b0000000000000000      // READ ONLY: Suspend Status OFF

#define REG_ADCON3L_SHRSAMP_GO          0b0000001000000000      // Individual Software Trigger for shared Core
                                                                // specified in CNVCHSEL and CNVRTCH
#define REG_ADCON3L_SHRSAMP_ADCORE      0b0000000000000000      // Individual Software Trigger for shared Core disabled

#define REG_ADCON3L_CNVRTCH_ON          0b0000000100000000      // Individual Software Trigger Status Bit ON
#define REG_ADCON3L_CNVRTCH_OFF         0b0000000000000000      // Individual Software Trigger Status Bit OFF

#define REG_ADCON3L_SWLCTRG_ON          0b0000000010000000      // Software Level-Sensitive Common Trigger ON
#define REG_ADCON3L_SWLCTRG_OFF         0b0000000000000000      // Software Level-Sensitive Common Trigger OFF
                                                                // A/D Trigger are configured in ADTRIGxL/ADTRIGxH registers

#define REG_ADCON3L_SWCTRG_ON           0b0000000001000000      // Software Common Trigger ON
#define REG_ADCON3L_SWCTRG_OFF          0b0000000000000000      // Software Common Trigger OFF
                                                                // A/D Trigger are configured in ADTRIGxL/ADTRIGxH registers

#define REG_ADCON3L_CNVCHSEL_MSK        0b0000000000111111      // Channel Number Mask
#define REG_ADCON3L_CNVCHSEL(x)      (x & REG_ADCON3L_CNVCHSEL_MSK)   // Channel Number


// REGISTER 19-6: ADCON3H: ANALOG-TO-DIGITAL CONTROL REGISTER 3 HIGH

#define REG_ADCON3H_RESET               0b1100000000000000      // Reset ADCON 3 High Register
#define REG_ADCON3H_VALID_DATA_MSK		0b1111111110001111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCON3H_CLKSEL_APLL         0b1100000000000000      // ADC Module Clock Input Selection
#define REG_ADCON3H_CLKSEL_FRC          0b1000000000000000
#define REG_ADCON3H_CLKSEL_FOSC         0b0100000000000000
#define REG_ADCON3H_CLKSEL_FSYS         0b0000000000000000

#define REG_ADCON3H_CLKDIV_MSK          0b0011111100000000      // Source Clock Divider Filter Mask
#define REG_ADCON3H_CLKDIV(x)        (((x-1) << 8) & REG_ADCON3H_CLKDIV_MSK)  // Source Clock Divider Value

#define REG_ADCON3H_SHREN_ON            0b0000000010000000      // Shared ADC Core Enabled
#define REG_ADCON3H_SHREN_OFF           0b0000000000000000      // Shared ADC Core Disabled

#define REG_ADCON3H_C3EN_ON             0b0000000000001000      // Dedicated ADC Core #3 Enabled
#define REG_ADCON3H_C3EN_OFF            0b0000000000000000      // Dedicated ADC Core #3 Disabled

#define REG_ADCON3H_C2EN_ON             0b0000000000000100      // Dedicated ADC Core #2 Enabled
#define REG_ADCON3H_C2EN_OFF            0b0000000000000000      // Dedicated ADC Core #2 Disabled

#define REG_ADCON3H_C1EN_ON             0b0000000000000010      // Dedicated ADC Core #1 Enabled
#define REG_ADCON3H_C1EN_OFF            0b0000000000000000      // Dedicated ADC Core #1 Disabled

#define REG_ADCON3H_C0EN_ON             0b0000000000000001      // Dedicated ADC Core #0 Enabled
#define REG_ADCON3H_C0EN_OFF            0b0000000000000000      // Dedicated ADC Core #0 Disabled


// REGISTER 19-7: ADCON4L: ANALOG-TO-DIGITAL CONTROL REGISTER 4 LOW

#define REG_ADCON4L_RESET               0b0000000000000000      // Reset ADCON 4 Low Register
#define REG_ADCON4L_VALID_DATA_MSK		0b0000111100001111		// Bit mask used to set unimplemented bits to zero

#define REG_SYNCTRG3_ON                 0b0000100000000000      // Core #3 synchronized to source clock
#define REG_SYNCTRG3_OFF                0b0000000000000000      // Core #3 not synchronized to source clock
#define REG_SYNCTRG2_ON                 0b0000010000000000      // Core #2 synchronized to source clock
#define REG_SYNCTRG2_OFF                0b0000000000000000      // Core #2 not synchronized to source clock
#define REG_SYNCTRG1_ON                 0b0000001000000000      // Core #1 synchronized to source clock
#define REG_SYNCTRG1_OFF                0b0000000000000000      // Core #1 not synchronized to source clock
#define REG_SYNCTRG0_ON                 0b0000000100000000      // Core #0 synchronized to source clock
#define REG_SYNCTRG0_OFF                0b0000000000000000      // Core #0 not synchronized to source clock

#define REG_SAMC3EN_ON                  0b0000000000001000      // Core #3 conversion delayed after trigger
#define REG_SAMC3EN_OFF                 0b0000000000000000      // Core #3 conversion not delayed after trigger
#define REG_SAMC2EN_ON                  0b0000000000000100      // Core #2 conversion delayed after trigger
#define REG_SAMC2EN_OFF                 0b0000000000000000      // Core #2 conversion not delayed after trigger
#define REG_SAMC1EN_ON                  0b0000000000000010      // Core #1 conversion delayed after trigger
#define REG_SAMC1EN_OFF                 0b0000000000000000      // Core #1 conversion not delayed after trigger
#define REG_SAMC0EN_ON                  0b0000000000000001      // Core #0 conversion delayed after trigger
#define REG_SAMC0EN_OFF                 0b0000000000000000      // Core #0 conversion not delayed after trigger

// REGISTER 19-8: ADCON4H: ANALOG-TO-DIGITAL CONTROL REGISTER 4 HIGH

#define REG_ADCON4H_RESET               0b0000000000000000      // Reset ADCON 4 High Register
#define REG_ADCON4H_VALID_DATA_MSK		0b0000000011111111		// Bit mask used to set unimplemented bits to zero

#define REG_C3CHS_AN3                   0b0000000000000000      // AN3 Input Default Selection
#define REG_C3CHS_AN15                  0b0000000001000000      // AN15 Input Selection

#define REG_C2CHS_AN2                   0b0000000000000000      // AN2 Input Default Selection
#define REG_C2CHS_VREF_BGAP             0b0000000000100000      // VREF Band Gap Input Selection
#define REG_C2CHS_AN11                  0b0000000000010000      // AN11 Input Selection

#define REG_C1CHS_AN1                   0b0000000000000000      // AN1 Band Gap Input Selection
#define REG_C1CHS_PGA2                  0b0000000000001000      // PGA2 Input Selection
#define REG_C1CHS_AN18                  0b0000000000000100      // AN18 Input Selection
#define REG_C1CHS_AN1ALT                0b0000000000001100      // AN1 Input Alternative Selection

#define REG_C0CHS_AN0                   0b0000000000000000      // AN0 Band Gap Input Selection
#define REG_C0CHS_PGA1                  0b0000000000000010      // PGA1 Input Selection
#define REG_C0CHS_AN7                   0b0000000000000001      // AN7 Input Selection
#define REG_C0CHS_AN0ALT                0b0000000000000011      // AN0 Input Alternative Selection

// REGISTER 19-9: ADCON5L: ANALOG-TO-DIGITAL CONTROL REGISTER 5 LOW

#define REG_ADCON5L_RESET               0b0000000000000000      // Reset ADCON 5 Low Register
#define REG_ADCON5L_VALID_DATA_MSK		0b1000111110001111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCON5L_SHRRDY_PWROK        0b1000000000000000      // Sharder ADC Core powered and ready
#define REG_ADCON5L_C3RDY_PWROK         0b0000100000000000      // Dedicated ADC Core #3 powered and ready
#define REG_ADCON5L_C2RDY_PWROK         0b0000010000000000      // Dedicated ADC Core #2 powered and ready
#define REG_ADCON5L_C1RDY_PWROK         0b0000001000000000      // Dedicated ADC Core #1 powered and ready
#define REG_ADCON5L_C0RDY_PWROK         0b0000000100000000      // Dedicated ADC Core #0 powered and ready

#define REG_ADCON5L_SHRPWR_ON           0b0000000010000000
#define REG_ADCON5L_SHRPWR_OFF          0b0000000000000000
#define REG_ADCON5L_C3PWR_ON            0b0000000000001000      // Dedicated ADC Core #3 powered
#define REG_ADCON5L_C3PWR_OFF           0b0000000000000000      // Dedicated ADC Core #3 switched off
#define REG_ADCON5L_C2PWR_ON            0b0000000000000100      // Dedicated ADC Core #2 powered
#define REG_ADCON5L_C2PWR_OFF           0b0000000000000000      // Dedicated ADC Core #2 switched off
#define REG_ADCON5L_C1PWR_ON            0b0000000000000010      // Dedicated ADC Core #1 powered
#define REG_ADCON5L_C1PWR_OFF           0b0000000000000000      // Dedicated ADC Core #1 switched off
#define REG_ADCON5L_C0PWR_ON            0b0000000000000001      // Dedicated ADC Core #0 powered
#define REG_ADCON5L_C0PWR_OFF           0b0000000000000000      // Dedicated ADC Core #0 switched off

// REGISTER 19-10: ADCON5H: ANALOG-TO-DIGITAL CONTROL REGISTER 5 HIGH

#define REG_ADCON5H_RESET               0b0000111100000000      // Reset ADCON 5 High Register
#define REG_ADCON5H_VALID_DATA_MSK		0b0000111110001111		// Bit mask used to set unimplemented bits to zero

#define REG_WARMTIME_CLK_32768			0b0000111100000000		// ADC Powewr Up Delay
#define REG_WARMTIME_CLK_16384			0b0000111000000000
#define REG_WARMTIME_CLK_8192			0b0000110100000000
#define REG_WARMTIME_CLK_4096			0b0000110000000000
#define REG_WARMTIME_CLK_2048			0b0000101100000000
#define REG_WARMTIME_CLK_1024			0b0000101000000000
#define REG_WARMTIME_CLK_512			0b0000100100000000
#define REG_WARMTIME_CLK_256			0b0000100100000000
#define REG_WARMTIME_CLK_128			0b0000011100000000
#define REG_WARMTIME_CLK_64				0b0000011000000000
#define REG_WARMTIME_CLK_32				0b0000010100000000
#define REG_WARMTIME_CLK_16				0b0000010000000000

#define REG_SHRCIE_ON                   0b0000000010000000      // Interrupt on Shared ADC Core READY
#define REG_SHRCIE_OFF                  0b0000000000000000      // NoInterrupt on Shared ADC Core READY

#define REG_C3CIE_ON                    0b0000000000001000      // Interrupt on ADC Core #3 READY
#define REG_C3CIE_OFF                   0b0000000000000000      // NoInterrupt on ADC Core #3 READY
#define REG_C2CIE_ON                    0b0000000000000100      // Interrupt on ADC Core #2 READY
#define REG_C2CIE_OFF                   0b0000000000000000      // NoInterrupt on ADC Core #2 READY
#define REG_C1CIE_ON                    0b0000000000000010      // Interrupt on ADC Core #1 READY
#define REG_C1CIE_OFF                   0b0000000000000000      // NoInterrupt on ADC Core #1 READY
#define REG_C0CIE_ON                    0b0000000000000001      // Interrupt on ADC Core #0 READY
#define REG_C0CIE_OFF                   0b0000000000000000      // NoInterrupt on ADC Core #0 READY

// REGISTER 19-11: ADCORExL: DEDICATED ADC CORE x CONTROL REGISTER LOW

#define REG_ADCORExL_RESET              0b0000001111111111      // Reset ADCOREx Low Register
#define REG_ADCORExL_VALID_DATA_MSK		0b0000001111111111		// Bit mask used to set unimplemented bits to zero

#define REG_SAMC_MSK                    0b0000001111111111      // ADCOREx Conversion Delay Filter Mask
#define REG_SAMC(x)						((x-2) & REG_SAMC_MSK) 		// ADCOREx Conversion Delay Value

// REGISTER 19-12: ADCORExH: DEDICATED ADC CORE x CONTROL REGISTER HIGH

#define REG_ADCORExH_RESET              0b0000000000000000      // Reset ADCOREx High Register
#define REG_ADCORExH_VALID_DATA_MSK		0b0001111101111111		// Bit mask used to set unimplemented bits to zero

#define REG_EISEL_8TAD                  0b0001110000000000      // ADCOREx Early Interrupt 8 TADs before ready
#define REG_EISEL_7TAD                  0b0001100000000000      // ADCOREx Early Interrupt 7 TADs before ready
#define REG_EISEL_6TAD                  0b0001010000000000      // ADCOREx Early Interrupt 6 TADs before ready
#define REG_EISEL_5TAD                  0b0001000000000000      // ADCOREx Early Interrupt 5 TADs before ready
#define REG_EISEL_4TAD                  0b0000110000000000      // ADCOREx Early Interrupt 4 TADs before ready
#define REG_EISEL_3TAD                  0b0000100000000000      // ADCOREx Early Interrupt 3 TADs before ready
#define REG_EISEL_2TAD                  0b0000010000000000      // ADCOREx Early Interrupt 2 TADs before ready
#define REG_EISEL_1TAD                  0b0000000000000000      // ADCOREx Early Interrupt 1 TADs before ready

#define REG_ADC_RES_12BIT               0b0000001100000000      // ADC Core Resolution = 12bit
#define REG_ADC_RES_10BIT               0b0000001000000000      // ADC Core Resolution = 10bit
#define REG_ADC_RES_8BIT                0b0000000100000000      // ADC Core Resolution = 8bit
#define REG_ADC_RES_6BIT                0b0000000000000000      // ADC Core Resolution = 6bit

#define REG_ADCS_MSK                    0b0000000001111111      // ADC Core Clock Divider Filter Mask
#define REG_ADCS(x)                     ((x-2) & REG_ADCS_MSK)  		// ADC Core Clock Divider Value

// REGISTER 19-13: ADLVLTRGL: ADC LEVEL_SENSITIVE TRIGGER CONTROL REGISTER LOW

#define REG_ADLVLTRGL_RESET             0b0000000000000000      // Reset ADLVLTRGL Low Register
#define REG_ADLVLTRGL_VALID_DATA_MSK	0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADLVLTRGL_AN0_LEVEL         0b0000000000000001      // AN0 is Level-Triggered
#define REG_ADLVLTRGL_AN0_EDGE          0b0000000000000000      // AN0 is Edge-Triggered
#define REG_ADLVLTRGL_AN1_LEVEL         0b0000000000000010      // AN1 is Level-Triggered
#define REG_ADLVLTRGL_AN1_EDGE          0b0000000000000000      // AN1 is Edge-Triggered
#define REG_ADLVLTRGL_AN2_LEVEL         0b0000000000000100      // AN2 is Level-Triggered
#define REG_ADLVLTRGL_AN2_EDGE          0b0000000000000000      // AN2 is Edge-Triggered
#define REG_ADLVLTRGL_AN3_LEVEL         0b0000000000001000      // AN3 is Level-Triggered
#define REG_ADLVLTRGL_AN3_EDGE          0b0000000000000000      // AN3 is Edge-Triggered
#define REG_ADLVLTRGL_AN4_LEVEL         0b0000000000010000      // AN4 is Level-Triggered
#define REG_ADLVLTRGL_AN4_EDGE          0b0000000000000000      // AN4 is Edge-Triggered
#define REG_ADLVLTRGL_AN5_LEVEL         0b0000000000100000      // AN5 is Level-Triggered
#define REG_ADLVLTRGL_AN5_EDGE          0b0000000000000000      // AN5 is Edge-Triggered
#define REG_ADLVLTRGL_AN6_LEVEL         0b0000000001000000      // AN6 is Level-Triggered
#define REG_ADLVLTRGL_AN6_EDGE          0b0000000000000000      // AN6 is Edge-Triggered
#define REG_ADLVLTRGL_AN7_LEVEL         0b0000000010000000      // AN7 is Level-Triggered
#define REG_ADLVLTRGL_AN7_EDGE          0b0000000000000000      // AN7 is Edge-Triggered
#define REG_ADLVLTRGL_AN8_LEVEL         0b0000000100000000      // AN8 is Level-Triggered
#define REG_ADLVLTRGL_AN8_EDGE          0b0000000000000000      // AN8 is Edge-Triggered
#define REG_ADLVLTRGL_AN9_LEVEL         0b0000001000000000      // AN9 is Level-Triggered
#define REG_ADLVLTRGL_AN9_EDGE          0b0000000000000000      // AN9 is Edge-Triggered
#define REG_ADLVLTRGL_AN10_LEVEL        0b0000010000000000      // AN10 is Level-Triggered
#define REG_ADLVLTRGL_AN10_EDGE         0b0000000000000000      // AN10 is Edge-Triggered
#define REG_ADLVLTRGL_AN11_LEVEL        0b0000100000000000      // AN11 is Level-Triggered
#define REG_ADLVLTRGL_AN11_EDGE         0b0000000000000000      // AN11 is Edge-Triggered
#define REG_ADLVLTRGL_AN12_LEVEL        0b0001000000000000      // AN12 is Level-Triggered
#define REG_ADLVLTRGL_AN12_EDGE         0b0000000000000000      // AN12 is Edge-Triggered
#define REG_ADLVLTRGL_AN13_LEVEL        0b0010000000000000      // AN13 is Level-Triggered
#define REG_ADLVLTRGL_AN13_EDGE         0b0000000000000000      // AN13 is Edge-Triggered
#define REG_ADLVLTRGL_AN14_LEVEL        0b0100000000000000      // AN14 is Level-Triggered
#define REG_ADLVLTRGL_AN14_EDGE         0b0000000000000000      // AN14 is Edge-Triggered
#define REG_ADLVLTRGL_AN15_LEVEL        0b1000000000000000      // AN15 is Level-Triggered
#define REG_ADLVLTRGL_AN15_EDGE         0b0000000000000000      // AN15 is Edge-Triggered

// REGISTER 19-14: ADLVLTRGH: ADC LEVEL_SENSITIVE TRIGGER CONTROL REGISTER HIGH

#define REG_ADLVLTRGH_RESET             0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADLVLTRGH_VALID_DATA_MSK	0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADLVLTRGH_AN16_LEVEL        0b0000000000000001      // AN16 is Level-Triggered
#define REG_ADLVLTRGH_AN16_EDGE         0b0000000000000000      // AN16 is Edge-Triggered
#define REG_ADLVLTRGH_AN17_LEVEL        0b0000000000000010      // AN17 is Level-Triggered
#define REG_ADLVLTRGH_AN17_EDGE         0b0000000000000000      // AN17 is Edge-Triggered
#define REG_ADLVLTRGH_AN18_LEVEL        0b0000000000000100      // AN18 is Level-Triggered
#define REG_ADLVLTRGH_AN18_EDGE         0b0000000000000000      // AN18 is Edge-Triggered
#define REG_ADLVLTRGH_AN19_LEVEL        0b0000000000001000      // AN19 is Level-Triggered
#define REG_ADLVLTRGH_AN19_EDGE         0b0000000000000000      // AN19 is Edge-Triggered
#define REG_ADLVLTRGH_AN20_LEVEL        0b0000000000010000      // AN20 is Level-Triggered
#define REG_ADLVLTRGH_AN20_EDGE         0b0000000000000000      // AN20 is Edge-Triggered
#define REG_ADLVLTRGH_AN21_LEVEL        0b0000000000100000      // AN21 is Level-Triggered
#define REG_ADLVLTRGH_AN21_EDGE         0b0000000000000000      // AN21 is Edge-Triggered
#define REG_ADLVLTRGH_AN22_LEVEL        0b0000000001000000      // AN22 is Level-Triggered
#define REG_ADLVLTRGH_AN22_EDGE         0b0000000000000000      // AN22 is Edge-Triggered
#define REG_ADLVLTRGH_AN23_LEVEL        0b0000000010000000      // AN23 is Level-Triggered
#define REG_ADLVLTRGH_AN23_EDGE         0b0000000000000000      // AN23 is Edge-Triggered
#define REG_ADLVLTRGH_AN24_LEVEL        0b0000000100000000      // AN24 is Level-Triggered
#define REG_ADLVLTRGH_AN24_EDGE         0b0000000000000000      // AN24 is Edge-Triggered
#define REG_ADLVLTRGH_AN25_LEVEL        0b0000001000000000      // AN25 is Level-Triggered
#define REG_ADLVLTRGH_AN25_EDGE         0b0000000000000000      // AN25 is Edge-Triggered
#define REG_ADLVLTRGH_AN26_LEVEL        0b0000010000000000      // AN26 is Level-Triggered
#define REG_ADLVLTRGH_AN26_EDGE         0b0000000000000000      // AN26 is Edge-Triggered
#define REG_ADLVLTRGH_AN27_LEVEL        0b0000100000000000      // AN27 is Level-Triggered
#define REG_ADLVLTRGH_AN27_EDGE         0b0000000000000000      // AN27 is Edge-Triggered
#define REG_ADLVLTRGH_AN28_LEVEL        0b0001000000000000      // AN28 is Level-Triggered
#define REG_ADLVLTRGH_AN28_EDGE         0b0000000000000000      // AN28 is Edge-Triggered
#define REG_ADLVLTRGH_AN29_LEVEL        0b0010000000000000      // AN29 is Level-Triggered
#define REG_ADLVLTRGH_AN29_EDGE         0b0000000000000000      // AN29 is Edge-Triggered
#define REG_ADLVLTRGH_AN30_LEVEL        0b0100000000000000      // AN30 is Level-Triggered
#define REG_ADLVLTRGH_AN30_EDGE         0b0000000000000000      // AN30 is Edge-Triggered
#define REG_ADLVLTRGH_AN31_LEVEL        0b1000000000000000      // AN31 is Level-Triggered
#define REG_ADLVLTRGH_AN31_EDGE         0b0000000000000000      // AN31 is Edge-Triggered


// REGISTER 19-15: ADEIEH: ADC EARLY INTERRUPT ENABLE REGISTER LOW

#define REG_ADEIEL_RESET                0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADEIEH_VALID_DATA_MSK		0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADEIEL_AN0_ON               0b0000000000000001      // Early Interrupt Enabled for AN0 
#define REG_ADEIEL_AN0_OFF              0b0000000000000000      // Early Interrupt Disabled for AN0 
#define REG_ADEIEL_AN1_ON               0b0000000000000010      // Early Interrupt Enabled for AN1
#define REG_ADEIEL_AN1_OFF              0b0000000000000000      // Early Interrupt Disabled for AN1 
#define REG_ADEIEL_AN2_ON               0b0000000000000100      // Early Interrupt Enabled for AN2
#define REG_ADEIEL_AN2_OFF              0b0000000000000000      // Early Interrupt Disabled for AN2 
#define REG_ADEIEL_AN3_ON               0b0000000000001000      // Early Interrupt Enabled for AN3
#define REG_ADEIEL_AN3_OFF              0b0000000000000000      // Early Interrupt Disabled for AN3 
#define REG_ADEIEL_AN4_ON               0b0000000000010000      // Early Interrupt Enabled for AN4
#define REG_ADEIEL_AN4_OFF              0b0000000000000000      // Early Interrupt Disabled for AN4 
#define REG_ADEIEL_AN5_ON               0b0000000000100000      // Early Interrupt Enabled for AN5
#define REG_ADEIEL_AN5_OFF              0b0000000000000000      // Early Interrupt Disabled for AN5 
#define REG_ADEIEL_AN6_ON               0b0000000001000000      // Early Interrupt Enabled for AN6
#define REG_ADEIEL_AN6_OFF              0b0000000000000000      // Early Interrupt Disabled for AN6 
#define REG_ADEIEL_AN7_ON               0b0000000010000000      // Early Interrupt Enabled for AN7
#define REG_ADEIEL_AN7_OFF              0b0000000000000000      // Early Interrupt Disabled for AN7 
#define REG_ADEIEL_AN8_ON               0b0000000100000000      // Early Interrupt Enabled for AN8
#define REG_ADEIEL_AN8_OFF              0b0000000000000000      // Early Interrupt Disabled for AN8 
#define REG_ADEIEL_AN9_ON               0b0000001000000000      // Early Interrupt Enabled for AN9
#define REG_ADEIEL_AN9_OFF              0b0000000000000000      // Early Interrupt Disabled for AN9 
#define REG_ADEIEL_AN10_ON              0b0000010000000000      // Early Interrupt Enabled for AN10 
#define REG_ADEIEL_AN10_OFF             0b0000000000000000      // Early Interrupt Disabled for AN10 
#define REG_ADEIEL_AN11_ON              0b0000100000000000      // Early Interrupt Enabled for AN11
#define REG_ADEIEL_AN11_OFF             0b0000000000000000      // Early Interrupt Disabled for AN11 
#define REG_ADEIEL_AN12_ON              0b0001000000000000      // Early Interrupt Enabled for AN12
#define REG_ADEIEL_AN12_OFF             0b0000000000000000      // Early Interrupt Disabled for AN12 
#define REG_ADEIEL_AN13_ON              0b0010000000000000      // Early Interrupt Enabled for AN13
#define REG_ADEIEL_AN13_OFF             0b0000000000000000      // Early Interrupt Disabled for AN13 
#define REG_ADEIEL_AN14_ON              0b0100000000000000      // Early Interrupt Enabled for AN14
#define REG_ADEIEL_AN14_OFF             0b0000000000000000      // Early Interrupt Disabled for AN14 
#define REG_ADEIEL_AN15_ON              0b1000000000000000      // Early Interrupt Enabled for AN15
#define REG_ADEIEL_AN15_OFF             0b0000000000000000      // Early Interrupt Disabled for AN15


// REGISTER 19-16: ADEIEH: ADC EARLY INTERRUPT ENABLE REGISTER HIGH

#define REG_ADEIEH_RESET                0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADEIEH_VALID_DATA_MSK		0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADEIEH_AN16_ON              0b0000000000000001      // Early Interrupt Enabled for AN16
#define REG_ADEIEH_AN16_OFF             0b0000000000000000      // Early Interrupt Disabled for AN16 
#define REG_ADEIEH_AN17_ON              0b0000000000000010      // Early Interrupt Enabled for AN17
#define REG_ADEIEH_AN17_OFF             0b0000000000000000      // Early Interrupt Disabled for AN17 
#define REG_ADEIEH_AN18_ON              0b0000000000000100      // Early Interrupt Enabled for AN18
#define REG_ADEIEH_AN18_OFF             0b0000000000000000      // Early Interrupt Disabled for AN18 
#define REG_ADEIEH_AN19_ON              0b0000000000001000      // Early Interrupt Enabled for AN19
#define REG_ADEIEH_AN19_OFF             0b0000000000000000      // Early Interrupt Disabled for AN19 
#define REG_ADEIEH_AN20_ON              0b0000000000010000      // Early Interrupt Enabled for AN20
#define REG_ADEIEH_AN20_OFF             0b0000000000000000      // Early Interrupt Disabled for AN20 
#define REG_ADEIEH_AN21_ON              0b0000000000100000      // Early Interrupt Enabled for AN21
#define REG_ADEIEH_AN21_OFF             0b0000000000000000      // Early Interrupt Disabled for AN21 
#define REG_ADEIEH_AN22_ON              0b0000000001000000      // Early Interrupt Enabled for AN22
#define REG_ADEIEH_AN22_OFF             0b0000000000000000      // Early Interrupt Disabled for AN22 
#define REG_ADEIEH_AN23_ON              0b0000000010000000      // Early Interrupt Enabled for AN23
#define REG_ADEIEH_AN23_OFF             0b0000000000000000      // Early Interrupt Disabled for AN23 
#define REG_ADEIEH_AN24_ON              0b0000000100000000      // Early Interrupt Enabled for AN24
#define REG_ADEIEH_AN24_OFF             0b0000000000000000      // Early Interrupt Disabled for AN24 
#define REG_ADEIEH_AN25_ON              0b0000001000000000      // Early Interrupt Enabled for AN25
#define REG_ADEIEH_AN25_OFF             0b0000000000000000      // Early Interrupt Disabled for AN25 
#define REG_ADEIEH_AN26_ON              0b0000010000000000      // Early Interrupt Enabled for AN26
#define REG_ADEIEH_AN26_OFF             0b0000000000000000      // Early Interrupt Disabled for AN26 
#define REG_ADEIEH_AN27_ON              0b0000100000000000      // Early Interrupt Enabled for AN27
#define REG_ADEIEH_AN27_OFF             0b0000000000000000      // Early Interrupt Disabled for AN27 
#define REG_ADEIEH_AN28_ON              0b0001000000000000      // Early Interrupt Enabled for AN28
#define REG_ADEIEH_AN28_OFF             0b0000000000000000      // Early Interrupt Disabled for AN28 
#define REG_ADEIEH_AN29_ON              0b0010000000000000      // Early Interrupt Enabled for AN29
#define REG_ADEIEH_AN29_OFF             0b0000000000000000      // Early Interrupt Disabled for AN29 
#define REG_ADEIEH_AN30_ON              0b0100000000000000      // Early Interrupt Enabled for AN30
#define REG_ADEIEH_AN30_OFF             0b0000000000000000      // Early Interrupt Disabled for AN30 
#define REG_ADEIEH_AN31_ON              0b1000000000000000      // Early Interrupt Enabled for AN31
#define REG_ADEIEH_AN31_OFF             0b0000000000000000      // Early Interrupt Disabled for AN31


// REGISTER 19-17: ADEISTATL: ADC EARLY INTERRUPT STATUS REGISTER LOW

#define REG_ADEISTATL_RESET             0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADEISTATL_VALID_DATA_MSK	0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADEISTATL_AN0_SET           0b0000000000000001      // Early Interrupt Status SET for AN0 
#define REG_ADEISTATL_AN0_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN0 
#define REG_ADEISTATL_AN1_SET           0b0000000000000010      // Early Interrupt Status SET for AN1
#define REG_ADEISTATL_AN1_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN1 
#define REG_ADEISTATL_AN2_SET           0b0000000000000100      // Early Interrupt Status SET for AN2
#define REG_ADEISTATL_AN2_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN2 
#define REG_ADEISTATL_AN3_SET           0b0000000000001000      // Early Interrupt Status SET for AN3
#define REG_ADEISTATL_AN3_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN3 
#define REG_ADEISTATL_AN4_SET           0b0000000000010000      // Early Interrupt Status SET for AN4
#define REG_ADEISTATL_AN4_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN4 
#define REG_ADEISTATL_AN5_SET           0b0000000000100000      // Early Interrupt Status SET for AN5
#define REG_ADEISTATL_AN5_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN5 
#define REG_ADEISTATL_AN6_SET           0b0000000001000000      // Early Interrupt Status SET for AN6
#define REG_ADEISTATL_AN6_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN6 
#define REG_ADEISTATL_AN7_SET           0b0000000010000000      // Early Interrupt Status SET for AN7
#define REG_ADEISTATL_AN7_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN7 
#define REG_ADEISTATL_AN8_SET           0b0000000100000000      // Early Interrupt Status SET for AN8
#define REG_ADEISTATL_AN8_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN8 
#define REG_ADEISTATL_AN9_SET           0b0000001000000000      // Early Interrupt Status SET for AN9
#define REG_ADEISTATL_AN9_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN9 
#define REG_ADEISTATL_AN10_SET          0b0000010000000000      // Early Interrupt Status SET for AN10 
#define REG_ADEISTATL_AN10_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN10 
#define REG_ADEISTATL_AN11_SET          0b0000100000000000      // Early Interrupt Status SET for AN11
#define REG_ADEISTATL_AN11_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN11 
#define REG_ADEISTATL_AN12_SET          0b0001000000000000      // Early Interrupt Status SET for AN12
#define REG_ADEISTATL_AN12_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN12 
#define REG_ADEISTATL_AN13_SET          0b0010000000000000      // Early Interrupt Status SET for AN13
#define REG_ADEISTATL_AN13_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN13 
#define REG_ADEISTATL_AN14_SET          0b0100000000000000      // Early Interrupt Status SET for AN14
#define REG_ADEISTATL_AN14_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN14 
#define REG_ADEISTATL_AN15_SET          0b1000000000000000      // Early Interrupt Status SET for AN15
#define REG_ADEISTATL_AN15_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN15


// REGISTER 19-18: ADEISTATH: ADC EARLY INTERRUPT STATUS REGISTER HIGH

#define REG_ADEISTATH_RESET             0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADEISTATH_VALID_DATA_MSK	0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADEISTATH_AN16_SET          0b0000000000000001      // Early Interrupt Status SET for AN16
#define REG_ADEISTATH_AN16_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN16 
#define REG_ADEISTATH_AN17_SET          0b0000000000000010      // Early Interrupt Status SET for AN17
#define REG_ADEISTATH_AN17_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN17 
#define REG_ADEISTATH_AN18_SET          0b0000000000000100      // Early Interrupt Status SET for AN18
#define REG_ADEISTATH_AN18_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN18 
#define REG_ADEISTATH_AN19_SET          0b0000000000001000      // Early Interrupt Status SET for AN19
#define REG_ADEISTATH_AN19_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN19 
#define REG_ADEISTATH_AN20_SET          0b0000000000010000      // Early Interrupt Status SET for AN20
#define REG_ADEISTATH_AN20_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN20 
#define REG_ADEISTATH_AN21_SET          0b0000000000100000      // Early Interrupt Status SET for AN21
#define REG_ADEISTATH_AN21_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN21 
#define REG_ADEISTATH_AN22_SET          0b0000000001000000      // Early Interrupt Status SET for AN22
#define REG_ADEISTATH_AN22_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN22 
#define REG_ADEISTATH_AN23_SET          0b0000000010000000      // Early Interrupt Status SET for AN23
#define REG_ADEISTATH_AN23_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN23 
#define REG_ADEISTATH_AN24_SET          0b0000000100000000      // Early Interrupt Status SET for AN24
#define REG_ADEISTATH_AN24_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN24 
#define REG_ADEISTATH_AN25_SET          0b0000001000000000      // Early Interrupt Status SET for AN25
#define REG_ADEISTATH_AN25_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN25 
#define REG_ADEISTATH_AN26_SET          0b0000010000000000      // Early Interrupt Status SET for AN26
#define REG_ADEISTATH_AN26_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN26 
#define REG_ADEISTATH_AN27_SET          0b0000100000000000      // Early Interrupt Status SET for AN27
#define REG_ADEISTATH_AN27_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN27 
#define REG_ADEISTATH_AN28_SET          0b0001000000000000      // Early Interrupt Status SET for AN28
#define REG_ADEISTATH_AN28_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN28 
#define REG_ADEISTATH_AN29_SET          0b0010000000000000      // Early Interrupt Status SET for AN29
#define REG_ADEISTATH_AN29_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN29 
#define REG_ADEISTATH_AN30_SET          0b0100000000000000      // Early Interrupt Status SET for AN30
#define REG_ADEISTATH_AN30_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN30 
#define REG_ADEISTATH_AN31_SET          0b1000000000000000      // Early Interrupt Status SET for AN31
#define REG_ADEISTATH_AN31_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN31


// REGISTER 19-19: ADMOD0L: ADC INPUT MODE CONTROL REGISTER 0 LOW

#define REG_ADMOD0L_RESET                0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADMOD0L_VALID_DATA_MSK		 0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADMOD0L_AN0_DIFF             0b0000000000000010      // AN0 operates in Differential mode
#define REG_ADMOD0L_AN0_SNGE             0b0000000000000000      // AN0 operates in single ended mode
#define REG_ADMOD0L_AN1_DIFF             0b0000000000001000      // AN1 operates in Differential mode
#define REG_ADMOD0L_AN1_SNGE             0b0000000000000000      // AN1 operates in single ended mode
#define REG_ADMOD0L_AN2_DIFF             0b0000000000100000      // AN2 operates in Differential mode
#define REG_ADMOD0L_AN2_SNGE             0b0000000000000000      // AN2 operates in single ended mode
#define REG_ADMOD0L_AN3_DIFF             0b0000000010000000      // AN3 operates in Differential mode
#define REG_ADMOD0L_AN3_SNGE             0b0000000000000000      // AN3 operates in single ended mode
#define REG_ADMOD0L_AN4_DIFF             0b0000001000000000      // AN4 operates in Differential mode
#define REG_ADMOD0L_AN4_SNGE             0b0000000000000000      // AN4 operates in single ended mode
#define REG_ADMOD0L_AN5_DIFF             0b0000100000000000      // AN5 operates in Differential mode
#define REG_ADMOD0L_AN5_SNGE             0b0000000000000000      // AN5 operates in single ended mode
#define REG_ADMOD0L_AN6_DIFF             0b0010000000000000      // AN6 operates in Differential mode
#define REG_ADMOD0L_AN6_SNGE             0b0000000000000000      // AN6 operates in single ended mode
#define REG_ADMOD0L_AN7_DIFF             0b1000000000000000      // AN7 operates in Differential mode
#define REG_ADMOD0L_AN7_SNGE             0b0000000000000000      // AN7 operates in single ended mode

#define REG_ADMOD0L_AN0_SIGNED           0b0000000000000001      // In differential mode AN0 output will be signed
#define REG_ADMOD0L_AN0_UNSIGNED         0b0000000000000000      // In differential mode AN0 output will be unsigned
#define REG_ADMOD0L_AN1_SIGNED           0b0000000000000100      // In differential mode AN1 output will be signed
#define REG_ADMOD0L_AN1_UNSIGNED         0b0000000000000000      // In differential mode AN1 output will be unsigned
#define REG_ADMOD0L_AN2_SIGNED           0b0000000000010000      // In differential mode AN2 output will be signed
#define REG_ADMOD0L_AN2_UNSIGNED         0b0000000000000000      // In differential mode AN2 output will be unsigned
#define REG_ADMOD0L_AN3_SIGNED           0b0000000001000000      // In differential mode AN3 output will be signed
#define REG_ADMOD0L_AN3_UNSIGNED         0b0000000000000000      // In differential mode AN3 output will be unsigned
#define REG_ADMOD0L_AN4_SIGNED           0b0000000100000000      // In differential mode AN4 output will be signed
#define REG_ADMOD0L_AN4_UNSIGNED         0b0000000000000000      // In differential mode AN4 output will be unsigned
#define REG_ADMOD0L_AN5_SIGNED           0b0000010000000000      // In differential mode AN5 output will be signed
#define REG_ADMOD0L_AN5_UNSIGNED         0b0000000000000000      // In differential mode AN5 output will be unsigned
#define REG_ADMOD0L_AN6_SIGNED           0b0001000000000000      // In differential mode AN6 output will be signed
#define REG_ADMOD0L_AN6_UNSIGNED         0b0000000000000000      // In differential mode AN6 output will be unsigned
#define REG_ADMOD0L_AN7_SIGNED           0b0100000000000000      // In differential mode AN7 output will be signed
#define REG_ADMOD0L_AN7_UNSIGNED         0b0000000000000000      // In differential mode AN7 output will be unsigned


// REGISTER 19-20: ADMOD0H: ADC INPUT MODE CONTROL REGISTER 0 HIGH

#define REG_ADMOD0H_RESET                0b0000000000000000      // Reset ADMOD0H High Register
#define REG_ADMOD0H_VALID_DATA_MSK		 0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADMOD0H_AN8_DIFF             0b0000000000000010      // AN8 operates in Differential mode
#define REG_ADMOD0H_AN8_SNGE             0b0000000000000000      // AN8 operates in single ended mode
#define REG_ADMOD0H_AN9_DIFF             0b0000000000001000      // AN9 operates in Differential mode
#define REG_ADMOD0H_AN9_SNGE             0b0000000000000000      // AN9 operates in single ended mode
#define REG_ADMOD0H_AN10_DIFF            0b0000000000100000      // AN10 operates in Differential mode
#define REG_ADMOD0H_AN10_SNGE            0b0000000000000000      // AN10 operates in single ended mode
#define REG_ADMOD0H_AN11_DIFF            0b0000000010000000      // AN11 operates in Differential mode
#define REG_ADMOD0H_AN11_SNGE            0b0000000000000000      // AN11 operates in single ended mode
#define REG_ADMOD0H_AN12_DIFF            0b0000001000000000      // AN12 operates in Differential mode
#define REG_ADMOD0H_AN12_SNGE            0b0000000000000000      // AN12 operates in single ended mode
#define REG_ADMOD0H_AN13_DIFF            0b0000100000000000      // AN13 operates in Differential mode
#define REG_ADMOD0H_AN13_SNGE            0b0000000000000000      // AN13 operates in single ended mode
#define REG_ADMOD0H_AN14_DIFF            0b0010000000000000      // AN14 operates in Differential mode
#define REG_ADMOD0H_AN14_SNGE            0b0000000000000000      // AN14 operates in single ended mode
#define REG_ADMOD0H_AN15_DIFF            0b1000000000000000      // AN15 operates in Differential mode
#define REG_ADMOD0H_AN15_SNGE            0b0000000000000000      // AN15 operates in single ended mode

#define REG_ADMOD0H_AN8_SIGNED           0b0000000000000001      // In differential mode AN8 output will be signed
#define REG_ADMOD0H_AN8_UNSIGNED         0b0000000000000000      // In differential mode AN8 output will be unsigned
#define REG_ADMOD0H_AN9_SIGNED           0b0000000000000100      // In differential mode AN9 output will be signed
#define REG_ADMOD0H_AN9_UNSIGNED         0b0000000000000000      // In differential mode AN9 output will be unsigned
#define REG_ADMOD0H_AN10_SIGNED          0b0000000000010000      // In differential mode AN10 output will be signed
#define REG_ADMOD0H_AN10_UNSIGNED        0b0000000000000000      // In differential mode AN10 output will be unsigned
#define REG_ADMOD0H_AN11_SIGNED          0b0000000001000000      // In differential mode AN11 output will be signed
#define REG_ADMOD0H_AN11_UNSIGNED        0b0000000000000000      // In differential mode AN11 output will be unsigned
#define REG_ADMOD0H_AN12_SIGNED          0b0000000100000000      // In differential mode AN12 output will be signed
#define REG_ADMOD0H_AN12_UNSIGNED        0b0000000000000000      // In differential mode AN12 output will be unsigned
#define REG_ADMOD0H_AN13_SIGNED          0b0000010000000000      // In differential mode AN13 output will be signed
#define REG_ADMOD0H_AN13_UNSIGNED        0b0000000000000000      // In differential mode AN13 output will be unsigned
#define REG_ADMOD0H_AN14_SIGNED          0b0001000000000000      // In differential mode AN14 output will be signed
#define REG_ADMOD0H_AN14_UNSIGNED        0b0000000000000000      // In differential mode AN14 output will be unsigned
#define REG_ADMOD0H_AN15_SIGNED          0b0100000000000000      // In differential mode AN15 output will be signed
#define REG_ADMOD0H_AN15_UNSIGNED        0b0000000000000000      // In differential mode AN15 output will be unsigned


// REGISTER 19-21: ADMOD1L: ADC INPUT MODE CONTROL REGISTER 1 LOW

#define REG_ADMOD1L_RESET                0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADMOD1L_VALID_DATA_MSK		 0b0000111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADMOD1L_AN16_DIFF            0b0000000000000010      // AN16 operates in Differential mode
#define REG_ADMOD1L_AN16_SNGE            0b0000000000000000      // AN16 operates in single ended mode
#define REG_ADMOD1L_AN17_DIFF            0b0000000000001000      // AN17 operates in Differential mode
#define REG_ADMOD1L_AN17_SNGE            0b0000000000000000      // AN17 operates in single ended mode
#define REG_ADMOD1L_AN18_DIFF            0b0000000000100000      // AN18 operates in Differential mode
#define REG_ADMOD1L_AN18_SNGE            0b0000000000000000      // AN18 operates in single ended mode
#define REG_ADMOD1L_AN19_DIFF            0b0000000010000000      // AN19 operates in Differential mode
#define REG_ADMOD1L_AN19_SNGE            0b0000000000000000      // AN19 operates in single ended mode
#define REG_ADMOD1L_AN20_DIFF            0b0000001000000000      // AN20 operates in Differential mode
#define REG_ADMOD1L_AN20_SNGE            0b0000000000000000      // AN20 operates in single ended mode
#define REG_ADMOD1L_AN21_DIFF            0b0000100000000000      // AN21 operates in Differential mode
#define REG_ADMOD1L_AN21_SNGE            0b0000000000000000      // AN21 operates in single ended mode
#define REG_ADMOD1L_AN22_DIFF            0b0010000000000000      // AN22 operates in Differential mode
#define REG_ADMOD1L_AN22_SNGE            0b0000000000000000      // AN22 operates in single ended mode
#define REG_ADMOD1L_AN23_DIFF            0b1000000000000000      // AN23 operates in Differential mode
#define REG_ADMOD1L_AN23_SNGE            0b0000000000000000      // AN23 operates in single ended mode

#define REG_ADMOD1L_AN16_SIGNED          0b0000000000000001      // In differential mode AN8 output will be signed
#define REG_ADMOD1L_AN16_UNSIGNED        0b0000000000000000      // In differential mode AN8 output will be unsigned
#define REG_ADMOD1L_AN17_SIGNED          0b0000000000000100      // In differential mode AN9 output will be signed
#define REG_ADMOD1L_AN17_UNSIGNED        0b0000000000000000      // In differential mode AN9 output will be unsigned
#define REG_ADMOD1L_AN18_SIGNED          0b0000000000010000      // In differential mode AN10 output will be signed
#define REG_ADMOD1L_AN18_UNSIGNED        0b0000000000000000      // In differential mode AN10 output will be unsigned
#define REG_ADMOD1L_AN19_SIGNED          0b0000000001000000      // In differential mode AN11 output will be signed
#define REG_ADMOD1L_AN19_UNSIGNED        0b0000000000000000      // In differential mode AN11 output will be unsigned
#define REG_ADMOD1L_AN20_SIGNED          0b0000000100000000      // In differential mode AN12 output will be signed
#define REG_ADMOD1L_AN20_UNSIGNED        0b0000000000000000      // In differential mode AN12 output will be unsigned
#define REG_ADMOD1L_AN21_SIGNED          0b0000010000000000      // In differential mode AN13 output will be signed
#define REG_ADMOD1L_AN21_UNSIGNED        0b0000000000000000      // In differential mode AN13 output will be unsigned
#define REG_ADMOD1L_AN22_SIGNED          0b0001000000000000      // In differential mode AN14 output will be signed
#define REG_ADMOD1L_AN22_UNSIGNED        0b0000000000000000      // In differential mode AN14 output will be unsigned
#define REG_ADMOD1L_AN23_SIGNED          0b0100000000000000      // In differential mode AN15 output will be signed
#define REG_ADMOD1L_AN23_UNSIGNED        0b0000000000000000      // In differential mode AN15 output will be unsigned


#ifdef ADMOD1H
// REGISTER 19-xx: ADMOD1H: ADC INPUT MODE CONTROL REGISTER 1 HIGH

#define REG_ADMOD1H_RESET                0b0000000000000000      // Reset ADMOD0H High Register
#define REG_ADMOD1H_VALID_DATA_MSK		 0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADMOD1H_AN24_DIFF            0b0000000000000010      // AN24 operates in Differential mode
#define REG_ADMOD1H_AN24_SNGE            0b0000000000000000      // AN24 operates in single ended mode
#define REG_ADMOD1H_AN25_DIFF            0b0000000000001000      // AN25 operates in Differential mode
#define REG_ADMOD1H_AN25_SNGE            0b0000000000000000      // AN25 operates in single ended mode
#define REG_ADMOD1H_AN26_DIFF            0b0000000000100000      // AN26 operates in Differential mode
#define REG_ADMOD1H_AN26_SNGE            0b0000000000000000      // AN26 operates in single ended mode
#define REG_ADMOD1H_AN27_DIFF            0b0000000010000000      // AN27 operates in Differential mode
#define REG_ADMOD1H_AN27_SNGE            0b0000000000000000      // AN27 operates in single ended mode
#define REG_ADMOD1H_AN28_DIFF            0b0000001000000000      // AN28 operates in Differential mode
#define REG_ADMOD1H_AN28_SNGE            0b0000000000000000      // AN28 operates in single ended mode
#define REG_ADMOD1H_AN29_DIFF            0b0000100000000000      // AN29 operates in Differential mode
#define REG_ADMOD1H_AN29_SNGE            0b0000000000000000      // AN29 operates in single ended mode
#define REG_ADMOD1H_AN30_DIFF            0b0010000000000000      // AN30 operates in Differential mode
#define REG_ADMOD1H_AN30_SNGE            0b0000000000000000      // AN30 operates in single ended mode
#define REG_ADMOD1H_AN31_DIFF            0b1000000000000000      // AN31 operates in Differential mode
#define REG_ADMOD1H_AN31_SNGE            0b0000000000000000      // AN31 operates in single ended mode

#define REG_ADMOD1H_AN24_SIGNED          0b0000000000000001      // In differential mode AN24 output will be signed
#define REG_ADMOD1H_AN24_UNSIGNED        0b0000000000000000      // In differential mode AN24 output will be unsigned
#define REG_ADMOD1H_AN25_SIGNED          0b0000000000000100      // In differential mode AN25 output will be signed
#define REG_ADMOD1H_AN25_UNSIGNED        0b0000000000000000      // In differential mode AN25 output will be unsigned
#define REG_ADMOD1H_AN26_SIGNED          0b0000000000010000      // In differential mode AN26 output will be signed
#define REG_ADMOD1H_AN26_UNSIGNED        0b0000000000000000      // In differential mode AN26 output will be unsigned
#define REG_ADMOD1H_AN27_SIGNED          0b0000000001000000      // In differential mode AN27 output will be signed
#define REG_ADMOD1H_AN27_UNSIGNED        0b0000000000000000      // In differential mode AN27 output will be unsigned
#define REG_ADMOD1H_AN28_SIGNED          0b0000000100000000      // In differential mode AN28 output will be signed
#define REG_ADMOD1H_AN28_UNSIGNED        0b0000000000000000      // In differential mode AN28 output will be unsigned
#define REG_ADMOD1H_AN29_SIGNED          0b0000010000000000      // In differential mode AN29 output will be signed
#define REG_ADMOD1H_AN29_UNSIGNED        0b0000000000000000      // In differential mode AN29 output will be unsigned
#define REG_ADMOD1H_AN30_SIGNED          0b0001000000000000      // In differential mode AN30 output will be signed
#define REG_ADMOD1H_AN30_UNSIGNED        0b0000000000000000      // In differential mode AN30 output will be unsigned
#define REG_ADMOD1H_AN31_SIGNED          0b0100000000000000      // In differential mode AN31 output will be signed
#define REG_ADMOD1H_AN31_UNSIGNED        0b0000000000000000      // In differential mode AN31 output will be unsigned

#endif

// REGISTER 19-22: ADIEL: ADC INTERRUPT ENABLE REGISTER LOW

#define REG_ADIEL_RESET                 0b0000000000000000      // Reset ADIEL Low Register
#define REG_ADIEL_VALID_DATA_MSK		0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADIEL_AN0_ON                0b0000000000000001      // Interrupt enabled for AN0 
#define REG_ADIEL_AN0_OFF               0b0000000000000000      // Interrupt disabled for AN0 
#define REG_ADIEL_AN1_ON                0b0000000000000010      // Interrupt enabled for AN1
#define REG_ADIEL_AN1_OFF               0b0000000000000000      // Interrupt disabled for AN1 
#define REG_ADIEL_AN2_ON                0b0000000000000100      // Interrupt enabled for AN2
#define REG_ADIEL_AN2_OFF               0b0000000000000000      // Interrupt disabled for AN2 
#define REG_ADIEL_AN3_ON                0b0000000000001000      // Interrupt enabled for AN3
#define REG_ADIEL_AN3_OFF               0b0000000000000000      // Interrupt disabled for AN3 
#define REG_ADIEL_AN4_ON                0b0000000000010000      // Interrupt enabled for AN4
#define REG_ADIEL_AN4_OFF               0b0000000000000000      // Interrupt disabled for AN4 
#define REG_ADIEL_AN5_ON                0b0000000000100000      // Interrupt enabled for AN5
#define REG_ADIEL_AN5_OFF               0b0000000000000000      // Interrupt disabled for AN5 
#define REG_ADIEL_AN6_ON                0b0000000001000000      // Interrupt enabled for AN6
#define REG_ADIEL_AN6_OFF               0b0000000000000000      // Interrupt disabled for AN6 
#define REG_ADIEL_AN7_ON                0b0000000010000000      // Interrupt enabled for AN7
#define REG_ADIEL_AN7_OFF               0b0000000000000000      // Interrupt disabled for AN7 
#define REG_ADIEL_AN8_ON                0b0000000100000000      // Interrupt enabled for AN8
#define REG_ADIEL_AN8_OFF               0b0000000000000000      // Interrupt disabled for AN8 
#define REG_ADIEL_AN9_ON                0b0000001000000000      // Interrupt enabled for AN9
#define REG_ADIEL_AN9_OFF               0b0000000000000000      // Interrupt disabled for AN9 
#define REG_ADIEL_AN10_ON               0b0000010000000000      // Interrupt enabled for AN10 
#define REG_ADIEL_AN10_OFF              0b0000000000000000      // Interrupt disabled for AN10 
#define REG_ADIEL_AN11_ON               0b0000100000000000      // Interrupt enabled for AN11
#define REG_ADIEL_AN11_OFF              0b0000000000000000      // Interrupt disabled for AN11 
#define REG_ADIEL_AN12_ON               0b0001000000000000      // Interrupt enabled for AN12
#define REG_ADIEL_AN12_OFF              0b0000000000000000      // Interrupt disabled for AN12 
#define REG_ADIEL_AN13_ON               0b0010000000000000      // Interrupt enabled for AN13
#define REG_ADIEL_AN13_OFF              0b0000000000000000      // Interrupt disabled for AN13 
#define REG_ADIEL_AN14_ON               0b0100000000000000      // Interrupt enabled for AN14
#define REG_ADIEL_AN14_OFF              0b0000000000000000      // Interrupt disabled for AN14 
#define REG_ADIEL_AN15_ON               0b1000000000000000      // Interrupt enabled for AN15
#define REG_ADIEL_AN15_OFF              0b0000000000000000      // Interrupt disabled for AN15


// REGISTER 19-23: ADIEH: ADC INTERRUPT ENABLE REGISTER HIGH

#define REG_ADIEH_RESET                 0b0000000000000000      // Reset ADIEH High Register
#define REG_ADIEH_VALID_DATA_MSK		0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADIEH_AN16_ON               0b0000000000000001      // Interrupt enabled for AN16
#define REG_ADIEH_AN16_OFF              0b0000000000000000      // Interrupt disabled for AN16 
#define REG_ADIEH_AN17_ON               0b0000000000000010      // Interrupt enabled for AN17
#define REG_ADIEH_AN17_OFF              0b0000000000000000      // Interrupt disabled for AN17 
#define REG_ADIEH_AN18_ON               0b0000000000000100      // Interrupt enabled for AN18
#define REG_ADIEH_AN18_OFF              0b0000000000000000      // Interrupt disabled for AN18 
#define REG_ADIEH_AN19_ON               0b0000000000001000      // Interrupt enabled for AN19
#define REG_ADIEH_AN19_OFF              0b0000000000000000      // Interrupt disabled for AN19 
#define REG_ADIEH_AN20_ON               0b0000000000010000      // Interrupt enabled for AN20
#define REG_ADIEH_AN20_OFF              0b0000000000000000      // Interrupt disabled for AN20 
#define REG_ADIEH_AN21_ON               0b0000000000100000      // Interrupt enabled for AN21
#define REG_ADIEH_AN21_OFF              0b0000000000000000      // Interrupt disabled for AN21 
#define REG_ADIEH_AN22_ON               0b0000000001000000      // Interrupt enabled for AN22
#define REG_ADIEH_AN22_OFF              0b0000000000000000      // Interrupt disabled for AN22 
#define REG_ADIEH_AN23_ON               0b0000000010000000      // Interrupt enabled for AN23
#define REG_ADIEH_AN23_OFF              0b0000000000000000      // Interrupt disabled for AN23 
#define REG_ADIEH_AN24_ON               0b0000000100000000      // Interrupt enabled for AN24
#define REG_ADIEH_AN24_OFF              0b0000000000000000      // Interrupt disabled for AN24 
#define REG_ADIEH_AN25_ON               0b0000001000000000      // Interrupt enabled for AN25
#define REG_ADIEH_AN25_OFF              0b0000000000000000      // Interrupt disabled for AN25 
#define REG_ADIEH_AN26_ON               0b0000010000000000      // Interrupt enabled for AN26
#define REG_ADIEH_AN26_OFF              0b0000000000000000      // Interrupt disabled for AN26 
#define REG_ADIEH_AN27_ON               0b0000100000000000      // Interrupt enabled for AN27
#define REG_ADIEH_AN27_OFF              0b0000000000000000      // Interrupt disabled for AN27 
#define REG_ADIEH_AN28_ON               0b0001000000000000      // Interrupt enabled for AN28
#define REG_ADIEH_AN28_OFF              0b0000000000000000      // Interrupt disabled for AN28 
#define REG_ADIEH_AN29_ON               0b0010000000000000      // Interrupt enabled for AN29
#define REG_ADIEH_AN29_OFF              0b0000000000000000      // Interrupt disabled for AN29 
#define REG_ADIEH_AN30_ON               0b0100000000000000      // Interrupt enabled for AN30
#define REG_ADIEH_AN30_OFF              0b0000000000000000      // Interrupt disabled for AN30 
#define REG_ADIEH_AN31_ON               0b1000000000000000      // Interrupt enabled for AN31
#define REG_ADIEH_AN31_OFF              0b0000000000000000      // Interrupt disabled for AN31


// REGISTER 19-24: ADSTATL: ADC DATA READY STATUS REGISTER LOW

#define REG_ADSTATL_RESET               0b0000000000000000      // Reset ADSTATL Low Register
#define REG_ADSTATL_VALID_DATA_MSK		0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADSTATL_AN0_SET             0b0000000000000001      // DATA READY bit is set for AN0 
#define REG_ADSTATL_AN0_CLR             0b0000000000000000      // DATA READY bit is cleared for AN0 
#define REG_ADSTATL_AN1_SET             0b0000000000000010      // DATA READY bit is set AN1
#define REG_ADSTATL_AN1_CLR             0b0000000000000000      // DATA READY bit is cleared for AN1 
#define REG_ADSTATL_AN2_SET             0b0000000000000100      // DATA READY bit is set for AN2
#define REG_ADSTATL_AN2_CLR             0b0000000000000000      // DATA READY bit is cleared for AN2 
#define REG_ADSTATL_AN3_SET             0b0000000000001000      // DATA READY bit is set for AN3
#define REG_ADSTATL_AN3_CLR             0b0000000000000000      // DATA READY bit is cleared for AN3 
#define REG_ADSTATL_AN4_SET             0b0000000000010000      // DATA READY bit is set for AN4
#define REG_ADSTATL_AN4_CLR             0b0000000000000000      // DATA READY bit is cleared for AN4 
#define REG_ADSTATL_AN5_SET             0b0000000000100000      // DATA READY bit is set for AN5
#define REG_ADSTATL_AN5_CLR             0b0000000000000000      // DATA READY bit is cleared for AN5 
#define REG_ADSTATL_AN6_SET             0b0000000001000000      // DATA READY bit is set for AN6
#define REG_ADSTATL_AN6_CLR             0b0000000000000000      // DATA READY bit is cleared for AN6 
#define REG_ADSTATL_AN7_SET             0b0000000010000000      // DATA READY bit is set for AN7
#define REG_ADSTATL_AN7_CLR             0b0000000000000000      // DATA READY bit is cleared for AN7 
#define REG_ADSTATL_AN8_SET             0b0000000100000000      // DATA READY bit is set for AN8
#define REG_ADSTATL_AN8_CLR             0b0000000000000000      // DATA READY bit is cleared for AN8 
#define REG_ADSTATL_AN9_SET             0b0000001000000000      // DATA READY bit is set for AN9
#define REG_ADSTATL_AN9_CLR             0b0000000000000000      // DATA READY bit is cleared for AN9 
#define REG_ADSTATL_AN10_SET            0b0000010000000000      // DATA READY bit is set for AN10 
#define REG_ADSTATL_AN10_CLR            0b0000000000000000      // DATA READY bit is cleared for AN10 
#define REG_ADSTATL_AN11_SET            0b0000100000000000      // DATA READY bit is set for AN11
#define REG_ADSTATL_AN11_CLR            0b0000000000000000      // DATA READY bit is cleared for AN11 
#define REG_ADSTATL_AN12_SET            0b0001000000000000      // DATA READY bit is set for AN12
#define REG_ADSTATL_AN12_CLR            0b0000000000000000      // DATA READY bit is cleared for AN12 
#define REG_ADSTATL_AN13_SET            0b0010000000000000      // DATA READY bit is set for AN13
#define REG_ADSTATL_AN13_CLR            0b0000000000000000      // DATA READY bit is cleared for AN13 
#define REG_ADSTATL_AN14_SET            0b0100000000000000      // DATA READY bit is set for AN14
#define REG_ADSTATL_AN14_CLR            0b0000000000000000      // DATA READY bit is cleared for AN14 
#define REG_ADSTATL_AN15_SET            0b1000000000000000      // DATA READY bit is set for AN15
#define REG_ADSTATL_AN15_CLR            0b0000000000000000      // DATA READY bit is cleared for AN15


// REGISTER 19-25: ADSTATH: ADC DATA READY STATUS REGISTER HIGH

#define REG_ADSTATH_RESET               0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADSTATH_VALID_DATA_MSK		0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADSTATH_AN16_SET            0b0000000000000001      // DATA READY bit is set for AN16
#define REG_ADSTATH_AN16_CLR            0b0000000000000000      // DATA READY bit is cleared for AN16 
#define REG_ADSTATH_AN17_SET            0b0000000000000010      // DATA READY bit is set for AN17
#define REG_ADSTATH_AN17_CLR            0b0000000000000000      // DATA READY bit is cleared for AN17 
#define REG_ADSTATH_AN18_SET            0b0000000000000100      // DATA READY bit is set for AN18
#define REG_ADSTATH_AN18_CLR            0b0000000000000000      // DATA READY bit is cleared for AN18 
#define REG_ADSTATH_AN19_SET            0b0000000000001000      // DATA READY bit is set for AN19
#define REG_ADSTATH_AN19_CLR            0b0000000000000000      // DATA READY bit is cleared for AN19 
#define REG_ADSTATH_AN20_SET            0b0000000000010000      // DATA READY bit is set for AN20
#define REG_ADSTATH_AN20_CLR            0b0000000000000000      // DATA READY bit is cleared for AN20 
#define REG_ADSTATH_AN21_SET            0b0000000000100000      // DATA READY bit is set for AN21
#define REG_ADSTATH_AN21_CLR            0b0000000000000000      // DATA READY bit is cleared for AN21 
#define REG_ADSTATH_AN22_SET            0b0000000001000000      // DATA READY bit is set for AN22
#define REG_ADSTATH_AN22_CLR            0b0000000000000000      // DATA READY bit is cleared for AN22 
#define REG_ADSTATH_AN23_SET            0b0000000010000000      // DATA READY bit is set for AN23
#define REG_ADSTATH_AN23_CLR            0b0000000000000000      // DATA READY bit is cleared for AN23 
#define REG_ADSTATH_AN24_SET            0b0000000100000000      // DATA READY bit is set for AN24
#define REG_ADSTATH_AN24_CLR            0b0000000000000000      // DATA READY bit is cleared for AN24 
#define REG_ADSTATH_AN25_SET            0b0000001000000000      // DATA READY bit is set for AN25
#define REG_ADSTATH_AN25_CLR            0b0000000000000000      // DATA READY bit is cleared for AN25 
#define REG_ADSTATH_AN26_SET            0b0000010000000000      // DATA READY bit is set for AN26
#define REG_ADSTATH_AN26_CLR            0b0000000000000000      // DATA READY bit is cleared for AN26 
#define REG_ADSTATH_AN27_SET            0b0000100000000000      // DATA READY bit is set for AN27
#define REG_ADSTATH_AN27_CLR            0b0000000000000000      // DATA READY bit is cleared for AN27 
#define REG_ADSTATH_AN28_SET            0b0001000000000000      // DATA READY bit is set for AN28
#define REG_ADSTATH_AN28_CLR            0b0000000000000000      // DATA READY bit is cleared for AN28 
#define REG_ADSTATH_AN29_SET            0b0010000000000000      // DATA READY bit is set for AN29
#define REG_ADSTATH_AN29_CLR            0b0000000000000000      // DATA READY bit is cleared for AN29 
#define REG_ADSTATH_AN30_SET            0b0100000000000000      // DATA READY bit is set for AN30
#define REG_ADSTATH_AN30_CLR            0b0000000000000000      // DATA READY bit is cleared for AN30 
#define REG_ADSTATH_AN31_SET            0b1000000000000000      // DATA READY bit is set for AN31
#define REG_ADSTATH_AN31_CLR            0b0000000000000000      // DATA READY bit is cleared for AN31


// REGISTER 19-26: ADTRGxL/H: ADC CHANNEL x TRIGGER SELECTION REGISTER LOW

#define REG_ADTRIGx_TRGSRC_RESET        0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADTRIGx_VALID_DATA_MSK		0b0001111100011111		// Bit mask used to set unimplemented bits to zero

#define REG_ADTRIGxH_TRGSRC_ADTRG31     0b0001111100000000      // Trigger source: ADC Trigger #31
//reserved
#define REG_ADTRIGxH_TRGSRC_PWM3_CLTRG  0b0001101000000000      // Trigger source: PWM Generator #3 Current LImit
#define REG_ADTRIGxH_TRGSRC_PWM2_CLTRG  0b0001100100000000      // Trigger source: PWM Generator #2 Current LImit
#define REG_ADTRIGxH_TRGSRC_PWM1_CLTRG  0b0001100000000000      // Trigger source: PWM Generator #1 Current LImit
//reserved
#define REG_ADTRIGxH_TRGSRC_OC1_TRG     0b0001011000000000      // Trigger source: PWM Generator #3 Secondary
//reserved
#define REG_ADTRIGxH_TRGSRC_PWM3_SEC    0b0001000100000000      // Trigger source: PWM Generator #3 Secondary
#define REG_ADTRIGxH_TRGSRC_PWM2_SEC    0b0001000000000000      // Trigger source: PWM Generator #2 Secondary
#define REG_ADTRIGxH_TRGSRC_PWM1_SEC    0b0000111100000000      // Trigger source: PWM Generator #1 Secondary 
#define REG_ADTRIGxH_TRGSRC_PWMSEV_SEC  0b0000111000000000      // Trigger source: PWM Special Event Secondary
#define REG_ADTRIGxH_TRGSRC_TMR2PR      0b0000110100000000      // Trigger source: Timer #2 Period Match 
#define REG_ADTRIGxH_TRGSRC_TMR1PR      0b0000110000000000      // Trigger source: Timer #1 Period Match 
//reserved
#define REG_ADTRIGxH_TRGSRC_PWM3_PRIM   0b0000011100000000      // Trigger source: PWM Generator #3 Primary 
#define REG_ADTRIGxH_TRGSRC_PWM2_PRIM   0b0000011000000000      // Trigger source: PWM Generator #2 Primary 
#define REG_ADTRIGxH_TRGSRC_PWM1_PRIM   0b0000010100000000      // Trigger source: PWM Generator #1 Primary 
#define REG_ADTRIGxH_TRGSRC_PWMSEV_PRIM 0b0000010000000000      // Trigger source: PWM Special Event Primary
//reserved
#define REG_ADTRIGxH_TRGSRC_LSWTRG      0b0000001000000000      // Trigger source: Level Software Trigger
#define REG_ADTRIGxH_TRGSRC_CSWTRG      0b0000000100000000      // Trigger source: Common Software Trigger
#define REG_ADTRIGxH_TRGSRC_NONE        0b0000000000000000      // Trigger source: No trigger is selected

#define REG_ADTRIGxL_TRGSRC_ADTRG31     0b0000000000011111      // Trigger source: ADC Trigger #31
//reserved
#define REG_ADTRIGxL_TRGSRC_PWM3_CLTRG  0b0000000000011010      // Trigger source: PWM Generator #3 Current LImit
#define REG_ADTRIGxL_TRGSRC_PWM2_CLTRG  0b0000000000011001      // Trigger source: PWM Generator #2 Current LImit
#define REG_ADTRIGxL_TRGSRC_PWM1_CLTRG  0b0000000000011000      // Trigger source: PWM Generator #1 Current LImit
//reserved
#define REG_ADTRIGxL_TRGSRC_OC1_TRG     0b0000000000010110      // Trigger source: PWM Generator #3 Secondary
//reserved
#define REG_ADTRIGxL_TRGSRC_PWM3_SEC    0b0000000000010001      // Trigger source: PWM Generator #3 Secondary
#define REG_ADTRIGxL_TRGSRC_PWM2_SEC    0b0000000000010000      // Trigger source: PWM Generator #2 Secondary
#define REG_ADTRIGxL_TRGSRC_PWM1_SEC    0b0000000000001111      // Trigger source: PWM Generator #1 Secondary 
#define REG_ADTRIGxL_TRGSRC_PWMSEV_SEC  0b0000000000001110      // Trigger source: PWM Special Event Secondary
#define REG_ADTRIGxL_TRGSRC_TMR2PR      0b0000000000001101      // Trigger source: Timer #2 Period Match 
#define REG_ADTRIGxL_TRGSRC_TMR1PR      0b0000000000001100      // Trigger source: Timer #1 Period Match 
//reserved
#define REG_ADTRIGxL_TRGSRC_PWM3_PRIM   0b0000000000000111      // Trigger source: PWM Generator #3 Primary 
#define REG_ADTRIGxL_TRGSRC_PWM2_PRIM   0b0000000000000110      // Trigger source: PWM Generator #2 Primary 
#define REG_ADTRIGxL_TRGSRC_PWM1_PRIM   0b0000000000000101      // Trigger source: PWM Generator #1 Primary 
#define REG_ADTRIGxL_TRGSRC_PWMSEV_PRIM 0b0000000000000100      // Trigger source: PWM Special Event Primary
//reserved
#define REG_ADTRIGxL_TRGSRC_LSWTRG      0b0000000000000010      // Trigger source: Level Software Trigger
#define REG_ADTRIGxL_TRGSRC_CSWTRG      0b0000000000000001      // Trigger source: Common Software Trigger
#define REG_ADTRIGxL_TRGSRC_NONE        0b0000000000000000      // Trigger source: No trigger is selected

// EXTENSION TO REGISTER 19-26: ADTRGxL/H
#define REG_ADTRIGx_TRGSRC_ADTRG31      0b0000000000011111      // Trigger source: ADC Trigger #31
//reserved
#define REG_ADTRIGx_TRGSRC_PWM3_CLTRG   0b0000000000011010      // Trigger source: PWM Generator #3 Current LImit
#define REG_ADTRIGx_TRGSRC_PWM2_CLTRG   0b0000000000011001      // Trigger source: PWM Generator #2 Current LImit
#define REG_ADTRIGx_TRGSRC_PWM1_CLTRG   0b0000000000011000      // Trigger source: PWM Generator #1 Current LImit
//reserved
#define REG_ADTRIGx_TRGSRC_OC1_TRG      0b0000000000010110      // Trigger source: PWM Generator #3 Secondary
//reserved
#define REG_ADTRIGx_TRGSRC_PWM3_SEC     0b0000000000010001      // Trigger source: PWM Generator #3 Secondary
#define REG_ADTRIGx_TRGSRC_PWM2_SEC     0b0000000000010000      // Trigger source: PWM Generator #2 Secondary
#define REG_ADTRIGx_TRGSRC_PWM1_SEC     0b0000000000001111      // Trigger source: PWM Generator #1 Secondary 
#define REG_ADTRIGx_TRGSRC_PWMSEV_SEC   0b0000000000001110      // Trigger source: PWM Special Event Secondary
#define REG_ADTRIGx_TRGSRC_TMR2PR       0b0000000000001101      // Trigger source: Timer #2 Period Match 
#define REG_ADTRIGx_TRGSRC_TMR1PR       0b0000000000001100      // Trigger source: Timer #1 Period Match 
//reserved
#define REG_ADTRIGx_TRGSRC_PWM3_PRIM    0b0000000000000111      // Trigger source: PWM Generator #3 Primary 
#define REG_ADTRIGx_TRGSRC_PWM2_PRIM    0b0000000000000110      // Trigger source: PWM Generator #2 Primary 
#define REG_ADTRIGx_TRGSRC_PWM1_PRIM    0b0000000000000101      // Trigger source: PWM Generator #1 Primary 
#define REG_ADTRIGx_TRGSRC_PWMSEV_PRIM  0b0000000000000100      // Trigger source: PWM Special Event Primary
//reserved
#define REG_ADTRIGx_TRGSRC_LSWTRG       0b0000000000000010      // Trigger source: Level Software Trigger
#define REG_ADTRIGx_TRGSRC_CSWTRG       0b0000000000000001      // Trigger source: Common Software Trigger
#define REG_ADTRIGx_TRGSRC_NONE         0b0000000000000000      // Trigger source: No trigger is selected


// REGISTER 19-27: ADCAL0L: ADC CALIBRATION REGISTER 0 LOW

#define REG_ADCAL0L_RESET               0b0000000000000000      // ADC core #0 & #1 calibration reset
#define REG_ADCAL0L_VALID_DATA_MSK		0b1000111110001111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCAL0L_CAL1RDY_DONE        0b1000000000000000      // ADC core #1 calibration completed
#define REG_ADCAL0L_CAL1RDY_PEND        0b0000000000000000      // ADC core #1 calibration pending

#define REG_ADCAL0L_CAL1SKIP_BYPASS     0b0000100000000000      // ADC core #1 calibration will be skipped
#define REG_ADCAL0L_CAL1SKIP_CALIB      0b0000000000000000      // ADC core #1 calibration will be performed

#define REG_ADCAL0L_CAL1DIFF_DIFF       0b0000010000000000      // ADC core #1 differential input calibration 
#define REG_ADCAL0L_CAL1DIFF_SNGM       0b0000000000000000      // ADC core #1 single ended input calibration 

#define REG_ADCAL0L_CAL1EN_UNLOCKED     0b0000001000000000      // ADC core #1 calibration bits accessable
#define REG_ADCAL0L_CAL1EN_LOCKED       0b0000000000000000      // ADC core #1 calibration bits blocked 

#define REG_ADCAL0L_CAL1RUN_EXECUTE     0b0000000100000000      // ADC core #1 execute calibration 
#define REG_ADCAL0L_CAL1RUN_READY       0b0000000000000000      // ADC core #1 ready for calibration 

#define REG_ADCAL0L_CAL0RDY_DONE        0b0000000010000000      // ADC core #0 calibration completed
#define REG_ADCAL0L_CAL0RDY_PEND        0b0000000000000000      // ADC core #0 calibration pending

#define REG_ADCAL0L_CAL0SKIP_BYPASS     0b0000000000001000      // ADC core #0 calibration will be skipped
#define REG_ADCAL0L_CAL0SKIP_CALIB      0b0000000000000000      // ADC core #0 calibration will be performed

#define REG_ADCAL0L_CAL0DIFF_DIFF       0b0000000000000100      // ADC core #0 differential input calibration 
#define REG_ADCAL0L_CAL0DIFF_SNGM       0b0000000000000000      // ADC core #0 single ended input calibration 

#define REG_ADCAL0L_CAL0EN_UNLOCKED     0b0000000000000010      // ADC core #0 calibration bits accessable
#define REG_ADCAL0L_CAL0EN_LOCKED       0b0000000000000000      // ADC core #0 calibration bits blocked 

#define REG_ADCAL0L_CAL0RUN_EXECUTE     0b0000000000000001      // ADC core #0 execute calibration 
#define REG_ADCAL0L_CAL0RUN_READY       0b0000000000000000      // ADC core #0 ready for calibration 


// REGISTER 19-28: ADCAL0H: ADC CALIBRATION REGISTER 0 HIGH
#define REG_ADCAL0H_RESET               0b0000000000000000      // ADC core #2 & #3 calibration reset
#define REG_ADCAL0H_VALID_DATA_MSK		0b1000111110001111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCAL0H_CAL3RDY_DONE        0b1000000000000000      // ADC core #3 calibration completed
#define REG_ADCAL0H_CAL3RDY_PEND        0b0000000000000000      // ADC core #3 calibration pending

#define REG_ADCAL0H_CAL3SKIP_BYPASS     0b0000100000000000      // ADC core #3 calibration will be skipped
#define REG_ADCAL0H_CAL3SKIP_CALIB      0b0000000000000000      // ADC core #3 calibration will be performed

#define REG_ADCAL0H_CAL3DIFF_DIFF       0b0000010000000000      // ADC core #3 differential input calibration 
#define REG_ADCAL0H_CAL3DIFF_SNGM       0b0000000000000000      // ADC core #3 single ended input calibration 

#define REG_ADCAL0H_CAL3EN_UNLOCKED     0b0000001000000000      // ADC core #3 calibration bits accessable
#define REG_ADCAL0H_CAL3EN_LOCKED       0b0000000000000000      // ADC core #3 calibration bits blocked 

#define REG_ADCAL0H_CAL3RUN_EXECUTE     0b0000000100000000      // ADC core #3 execute calibration 
#define REG_ADCAL0H_CAL3RUN_READY       0b0000000000000000      // ADC core #3 ready for calibration 

#define REG_ADCAL0H_CAL2RDY_DONE        0b0000000010000000      // ADC core #2 calibration completed
#define REG_ADCAL0H_CAL2RDY_PEND        0b0000000000000000      // ADC core #2 calibration pending

#define REG_ADCAL0H_CAL2SKIP_BYPASS     0b0000000000001000      // ADC core #2 calibration will be skipped
#define REG_ADCAL0H_CAL2SKIP_CALIB      0b0000000000000000      // ADC core #2 calibration will be performed

#define REG_ADCAL0H_CAL2DIFF_DIFF       0b0000000000000100      // ADC core #2 differential input calibration 
#define REG_ADCAL0H_CAL2DIFF_SNGM       0b0000000000000000      // ADC core #2 single ended input calibration 

#define REG_ADCAL0H_CAL2EN_UNLOCKED     0b0000000000000010      // ADC core #2 calibration bits accessable
#define REG_ADCAL0H_CAL2EN_LOCKED       0b0000000000000000      // ADC core #2 calibration bits blocked 

#define REG_ADCAL0H_CAL2RUN_EXECUTE     0b0000000000000001      // ADC core #2 execute calibration 
#define REG_ADCAL0H_CAL2RUN_READY       0b0000000000000000      // ADC core #2 ready for calibration 


// REGISTER 19-29: ADCAL1H: ADC CALIBRATION REGISTER 1 HIGH
#define REG_ADCAL1H_RESET               0b0000000000000000      // ADC shared core calibration reset
#define REG_ADCAL1H_VALID_DATA_MSK		0b1000111100000000		// Bit mask used to set unimplemented bits to zero

#define REG_ADCAL1H_CSHRRDY_DONE        0b1000000000000000      // ADC shared core calibration completed
#define REG_ADCAL1H_CSHRRDY_PEND        0b0000000000000000      // ADC shared core calibration pending

#define REG_ADCAL1H_CSHRSKIP_BYPASS     0b0000100000000000      // ADC shared core calibration will be skipped
#define REG_ADCAL1H_CSHRSKIP_CALIB      0b0000000000000000      // ADC shared core calibration will be performed

#define REG_ADCAL1H_CSHRDIFF_DIFF       0b0000010000000000      // ADC shared core differential input calibration 
#define REG_ADCAL1H_CSHRDIFF_SNGM       0b0000000000000000      // ADC shared core single ended input calibration 

#define REG_ADCAL1H_CSHREN_UNLOCKED     0b0000001000000000      // ADC shared core calibration bits accessable
#define REG_ADCAL1H_CSHREN_LOCKED       0b0000000000000000      // ADC shared core calibration bits blocked 

#define REG_ADCAL1H_CSHRRUN_EXECUTE     0b0000000100000000      // ADC shared core execute calibration 
#define REG_ADCAL1H_CSHRRUN_READY       0b0000000000000000      // ADC shared core ready for calibration 


// EXTENSION TO REGISTERS 19-27/28/29: ADCAL0L/ADCAL0H/ADCAL1L: ADC CALIBRATION REGISTERS
#define REG_ADCALx_LB_VALID_DATA_MSK	 0b0000000010001111		// Low Byte Bit mask used to set unimplemented bits to zero
#define REG_ADCALx_VALID_DATA_MSK		 0b1000111110001111		// Word Bit mask used to set unimplemented bits to zero

#define REG_ADC_CALIB_MODE_SINGLE_ENDED  0b1000101110001011 // Single Ended Mode Calibration
#define REG_ADC_CALIB_MODE_DIFFERENTIAL  0b1000111110001111 // Differenial Mode Calibration

#define REG_ADCALx_LB_CALxRDY_SET_MSK    0b0000000010000000
#define REG_ADCALx_LB_CALxRDY_CLR_MSK   (0b1111111101111111  & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_LB_CALxSKIP_SET_MSK   0b0000000000001000
#define REG_ADCALx_LB_CALxSKIP_CLR_MSK  (0b1111111111110111  & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_LB_CALxDIFF_SET_MSK   0b0000000000000100
#define REG_ADCALx_LB_CALxDIFF_CLR_MSK  (0b1111111111111011 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_LB_CALxEN_SET_MSK     0b0000000000000010
#define REG_ADCALx_LB_CALxEN_CLR_MSK    (0b1111111111111101 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_LB_CALxRUN_SET_MSK    0b0000000000000001
#define REG_ADCALx_LB_CALxRUN_CLR_MSK   (0b1111111111111110 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_VALID_DATA_MSK	 0b1000111100000000		// High Byte Bit mask used to set unimplemented bits to zero

#define REG_ADCALx_HB_CALxRDY_SET_MSK    0b1000000000000000
#define REG_ADCALx_HB_CALxRDY_CLR_MSK   (0b0111111111111111  & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_CALxSKIP_SET_MSK   0b0000100000000000
#define REG_ADCALx_HB_CALxSKIP_CLR_MSK  (0b1111011111111111  & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_CALxDIFF_SET_MSK   0b0000010000000000
#define REG_ADCALx_HB_CALxDIFF_CLR_MSK  (0b1111101111111111 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_CALxEN_SET_MSK     0b0000001000000000
#define REG_ADCALx_HB_CALxEN_CLR_MSK    (0b1111110111111111 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_CALxRUN_SET_MSK    0b0000000100000000
#define REG_ADCALx_HB_CALxRUN_CLR_MSK   (0b1111111011111111 & REG_ADCALx_VALID_DATA_MSK)


// REGISTER 19-30: ADCMPxCON: ADC DIGITAL COMPARATOR x CONTROL REGISTER

#define REG_ADCMPxCON_RESET             0b0000000000000000      // ADC Digital Comparator Configuration Reset
#define REG_ADCMPxCON_VALID_DATA_RD_MSK	0b0001111111111111		// Bit mask used to set unimplemented bits to zero
#define REG_ADCMPxCON_VALID_DATA_WR_MSK	0b0000000011011111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxLO_RESET              0b0000000000000000      // ADC Digital Comparator Lower Compare Value Reset
#define REG_ADCMPxLO_VALID_DATA_MASK    0b1111111111111111      // Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxHI_RESET              0b0000000000000000      // ADC Digital Comparator Upper Compare Value Reset
#define REG_ADCMPxHI_VALID_DATA_MASK    0b1111111111111111      // Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxCON_CHNL_MSK			0b0001111100000000		// ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL(x)        ((x << 8) & REG_ADCMPxCON_CHNL_MSK)    // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_NO(x)     ((x & REG_ADCMPxCON_CHNL_MSK) >> 8)    // Macro to extract the active ANx input channel no

#define REG_ADCMPxCON_CHNL_AN31         0b0001111100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN30         0b0001111000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN29         0b0001110100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN28         0b0001110000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN27         0b0001101100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN26         0b0001101000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN25         0b0001100100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN24         0b0001100000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN23         0b0001011100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN22         0b0001011000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN21         0b0001010100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN20         0b0001010000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN19         0b0001001100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN18         0b0001001000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN17         0b0001000100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN16         0b0001000000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN15         0b0000111100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN14         0b0000111000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN13         0b0000110100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN12         0b0000110000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN11         0b0000101100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN10         0b0000101000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN9          0b0000100100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN8          0b0000100000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN7          0b0000011100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN6          0b0000011000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN5          0b0000010100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN4          0b0000010000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN3          0b0000001100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN2          0b0000001000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN1          0b0000000100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN0          0b0000000000000000      // ADC Input Number used for comparison

#define REG_ADCMPxCON_CMPEN_ON          0b0000000010000000      // ADC Digital Comparator Enabled
#define REG_ADCMPxCON_CMPEN_OFF         0b0000000000000000      // ADC Digital Comparator Disabled

#define REG_ADCMPxCON_IE_ON             0b0000000001000000      // ADC Digital Comparator Common Interrupt Enabled
#define REG_ADCMPxCON_IE_OFF            0b0000000000000000      // ADC Digital Comparator Common Interrupt Disabled

#define REG_ADCMPxCON_STAT_ACTIVE       0b0000000000100000      // ADC Digital Comparator Common Interrupt Active
#define REG_ADCMPxCON_STAT_READY        0b0000000000000000      // ADC Digital Comparator Common Interrupt Pending

#define REG_ADCMPxCON_BTWN_ON           0b0000000000010000      // Generate Interrupt when ADC buffer between min & max
#define REG_ADCMPxCON_BTWN_OFF          0b0000000000000000      // No Interrupt when ADC buffer between min & max

#define REG_ADCMPxCON_HIHI_ON           0b0000000000001000      // Generate Interrupt when ADC buffer >= max
#define REG_ADCMPxCON_HIHI_OFF          0b0000000000000000      // No Interrupt when ADC buffer >= max

#define REG_ADCMPxCON_HILO_ON           0b0000000000000100      // Generate Interrupt when ADC buffer < min
#define REG_ADCMPxCON_HILO_OFF          0b0000000000000000      // No Interrupt when ADC buffer < min

#define REG_ADCMPxCON_LOHI_ON           0b0000000000000010      // Generate Interrupt when ADC buffer > min
#define REG_ADCMPxCON_LOHI_OFF          0b0000000000000000      // No Interrupt when ADC buffer > min

#define REG_ADCMPxCON_LOLO_ON           0b0000000000000001      // Generate Interrupt when ADC buffer < min
#define REG_ADCMPxCON_LOLO_OFF          0b0000000000000000      // No Interrupt when ADC buffer < min

// REGISTER 19-31: ADCMPxENL: ADC DIGITAL COMPARATOR x CHANNEL ENABLE REGISTER LOW

#define REG_ADCMPxENL_RESET             0b0000000000000000      // Reset ADCMPxENL Register
#define REG_ADCMPxENL_VALID_DATA_MSK	0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxENL_AN0_ON            0b0000000000000001      // Interrupt enabled for AN0 
#define REG_ADCMPxENL_AN0_OFF           0b0000000000000000      // Interrupt disabled for AN0 
#define REG_ADCMPxENL_AN1_ON            0b0000000000000010      // Interrupt enabled for AN1
#define REG_ADCMPxENL_AN1_OFF           0b0000000000000000      // Interrupt disabled for AN1 
#define REG_ADCMPxENL_AN2_ON            0b0000000000000100      // Interrupt enabled for AN2
#define REG_ADCMPxENL_AN2_OFF           0b0000000000000000      // Interrupt disabled for AN2 
#define REG_ADCMPxENL_AN3_ON            0b0000000000001000      // Interrupt enabled for AN3
#define REG_ADCMPxENL_AN3_OFF           0b0000000000000000      // Interrupt disabled for AN3 
#define REG_ADCMPxENL_AN4_ON            0b0000000000010000      // Interrupt enabled for AN4
#define REG_ADCMPxENL_AN4_OFF           0b0000000000000000      // Interrupt disabled for AN4 
#define REG_ADCMPxENL_AN5_ON            0b0000000000100000      // Interrupt enabled for AN5
#define REG_ADCMPxENL_AN5_OFF           0b0000000000000000      // Interrupt disabled for AN5 
#define REG_ADCMPxENL_AN6_ON            0b0000000001000000      // Interrupt enabled for AN6
#define REG_ADCMPxENL_AN6_OFF           0b0000000000000000      // Interrupt disabled for AN6 
#define REG_ADCMPxENL_AN7_ON            0b0000000010000000      // Interrupt enabled for AN7
#define REG_ADCMPxENL_AN7_OFF           0b0000000000000000      // Interrupt disabled for AN7 
#define REG_ADCMPxENL_AN8_ON            0b0000000100000000      // Interrupt enabled for AN8
#define REG_ADCMPxENL_AN8_OFF           0b0000000000000000      // Interrupt disabled for AN8 
#define REG_ADCMPxENL_AN9_ON            0b0000001000000000      // Interrupt enabled for AN9
#define REG_ADCMPxENL_AN9_OFF           0b0000000000000000      // Interrupt disabled for AN9 
#define REG_ADCMPxENL_AN10_ON           0b0000010000000000      // Interrupt enabled for AN10 
#define REG_ADCMPxENL_AN10_OFF          0b0000000000000000      // Interrupt disabled for AN10 
#define REG_ADCMPxENL_AN11_ON           0b0000100000000000      // Interrupt enabled for AN11
#define REG_ADCMPxENL_AN11_OFF          0b0000000000000000      // Interrupt disabled for AN11 
#define REG_ADCMPxENL_AN12_ON           0b0001000000000000      // Interrupt enabled for AN12
#define REG_ADCMPxENL_AN12_OFF          0b0000000000000000      // Interrupt disabled for AN12 
#define REG_ADCMPxENL_AN13_ON           0b0010000000000000      // Interrupt enabled for AN13
#define REG_ADCMPxENL_AN13_OFF          0b0000000000000000      // Interrupt disabled for AN13 
#define REG_ADCMPxENL_AN14_ON           0b0100000000000000      // Interrupt enabled for AN14
#define REG_ADCMPxENL_AN14_OFF          0b0000000000000000      // Interrupt disabled for AN14 
#define REG_ADCMPxENL_AN15_ON           0b1000000000000000      // Interrupt enabled for AN15
#define REG_ADCMPxENL_AN15_OFF          0b0000000000000000      // Interrupt disabled for AN15

// REGISTER 19-32: ADCMPxENH: ADC DIGITAL COMPARATOR x CHANNEL ENABLE REGISTER HIGH

#define REG_ADCMPxENH_RESET             0b0000000000000000      // Reset ADCMPxENH High Register
#define REG_ADCMPxENH_VALID_DATA_MSK	0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxENH_AN16_ON           0b0000000000000001      // Interrupt enabled for AN16
#define REG_ADCMPxENH_AN16_OFF          0b0000000000000000      // Interrupt disabled for AN16 
#define REG_ADCMPxENH_AN17_ON           0b0000000000000010      // Interrupt enabled for AN17
#define REG_ADCMPxENH_AN17_OFF          0b0000000000000000      // Interrupt disabled for AN17 
#define REG_ADCMPxENH_AN18_ON           0b0000000000000100      // Interrupt enabled for AN18
#define REG_ADCMPxENH_AN18_OFF          0b0000000000000000      // Interrupt disabled for AN18 
#define REG_ADCMPxENH_AN19_ON           0b0000000000001000      // Interrupt enabled for AN19
#define REG_ADCMPxENH_AN19_OFF          0b0000000000000000      // Interrupt disabled for AN19 
#define REG_ADCMPxENH_AN20_ON           0b0000000000010000      // Interrupt enabled for AN20
#define REG_ADCMPxENH_AN20_OFF          0b0000000000000000      // Interrupt disabled for AN20 
#define REG_ADCMPxENH_AN21_ON           0b0000000000100000      // Interrupt enabled for AN21
#define REG_ADCMPxENH_AN21_OFF          0b0000000000000000      // Interrupt disabled for AN21 
#define REG_ADCMPxENH_AN22_ON           0b0000000001000000      // Interrupt enabled for AN22
#define REG_ADCMPxENH_AN22_OFF          0b0000000000000000      // Interrupt disabled for AN22 
#define REG_ADCMPxENH_AN23_ON           0b0000000010000000      // Interrupt enabled for AN23
#define REG_ADCMPxENH_AN23_OFF          0b0000000000000000      // Interrupt disabled for AN23 
#define REG_ADCMPxENH_AN24_ON           0b0000000100000000      // Interrupt enabled for AN24
#define REG_ADCMPxENH_AN24_OFF          0b0000000000000000      // Interrupt disabled for AN24 
#define REG_ADCMPxENH_AN25_ON           0b0000001000000000      // Interrupt enabled for AN25
#define REG_ADCMPxENH_AN25_OFF          0b0000000000000000      // Interrupt disabled for AN25 
#define REG_ADCMPxENH_AN26_ON           0b0000010000000000      // Interrupt enabled for AN26
#define REG_ADCMPxENH_AN26_OFF          0b0000000000000000      // Interrupt disabled for AN26 
#define REG_ADCMPxENH_AN27_ON           0b0000100000000000      // Interrupt enabled for AN27
#define REG_ADCMPxENH_AN27_OFF          0b0000000000000000      // Interrupt disabled for AN27 
#define REG_ADCMPxENH_AN28_ON           0b0001000000000000      // Interrupt enabled for AN28
#define REG_ADCMPxENH_AN28_OFF          0b0000000000000000      // Interrupt disabled for AN28 
#define REG_ADCMPxENH_AN29_ON           0b0010000000000000      // Interrupt enabled for AN29
#define REG_ADCMPxENH_AN29_OFF          0b0000000000000000      // Interrupt disabled for AN29 
#define REG_ADCMPxENH_AN30_ON           0b0100000000000000      // Interrupt enabled for AN30
#define REG_ADCMPxENH_AN30_OFF          0b0000000000000000      // Interrupt disabled for AN30 
#define REG_ADCMPxENH_AN31_ON           0b1000000000000000      // Interrupt enabled for AN31
#define REG_ADCMPxENH_AN31_OFF          0b0000000000000000      // Interrupt disabled for AN31


// REGISTER 19-33: ADFLxCON: ADC DIGITAL FILTER x CONTROL REGISTER

#define REG_ADFLxCON_RESET                  0b0000000000000000      // Reset ADFLxCON Register
#define REG_ADFLxCON_VALID_DATA_MSK			0b1111111100011111		// Bit mask used to set unimplemented bits to zero

#define REG_ADFLxCON_FLEN_ON                0b1000000000000000      // Digital filter enabled
#define REG_ADFLxCON_FLEN_OFF               0b0000000000000000      // Digital filter disabled

#define REG_ADFLxCON_MODE_LEFT_ALIGN_256X   0b0111110000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_128X   0b0111100000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_64X    0b0111010000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_32X    0b0111000000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_16     0b0110110000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_8X     0b0110100000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_4X     0b0110010000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_2X     0b0110000000000000      // Digital filter result alignment left

#define REG_ADFLxCON_MODE_RIGHT_ALIGN_128X  0b0001110000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_32X   0b0001100000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_8X    0b0001010000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_2X    0b0001000000000000      // Digital filter result alignment right

#define REG_ADFLxCON_MODE_RIGHT_ALIGN_256X  0b0000110000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_64X   0b0000100000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_16X   0b0000010000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_4X    0b0000000000000000      // Digital filter result alignment right

#define REG_ADFLxCON_IE_ON                  0b0000001000000000      // Digital filter result ready interrupt enabled
#define REG_ADFLxCON_IE_OFF                 0b0000000000000000      // Digital filter result ready interrupt disabled

#define REG_ADFLxCON_RDY_READY              0b0000000100000000      // Digital filter result ready 
#define REG_ADFLxCON_RDY_PEND               0b0000000000000000      // Digital filter result pending

#define REG_ADFLxCON_INPUT_MSK              0b0000000001111111      // ADC Core Clock Divider Filter Mask
#define REG_ADFLxCON_INPUT(x)            (x & REG_ADFLxCON_INPUT_MSK)     // Digital Filter ADC Input Number

#define REG_ADFLxCON_INPUT_AN31             0b0000000000011111      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN30             0b0000000000011110      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN29             0b0000000000011101      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN28             0b0000000000011100      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN27             0b0000000000011011      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN26             0b0000000000011010      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN25             0b0000000000011001      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN24             0b0000000000011000      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN23             0b0000000000010111      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN22             0b0000000000010110      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN21             0b0000000000010101      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN20             0b0000000000010100      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN19             0b0000000000010011      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN18             0b0000000000010010      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN17             0b0000000000010001      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN16             0b0000000000010000      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN15             0b0000000000001111      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN14             0b0000000000001110      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN13             0b0000000000001101      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN12             0b0000000000001100      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN11             0b0000000000001011      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN10             0b0000000000001010      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN9              0b0000000000001001      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN8              0b0000000000001000      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN7              0b0000000000000111      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN6              0b0000000000000110      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN5              0b0000000000000101      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN4              0b0000000000000100      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN3              0b0000000000000011      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN2              0b0000000000000010      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN1              0b0000000000000001      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN0              0b0000000000000000      // Digital Filter ADC Input Number 




#endif

