/* ****************************************************************************************************
 * Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 * *****************************************************************************************************
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 * *****************************************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _DEVICE_CONFIGURATION_ADC_H_
#define	_DEVICE_CONFIGURATION_ADC_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

#include "mcal.h"           // The MCAL header file gives access to generic peripheral drivers
#include "syscfg_options.h"
#include "PLEU0049.R1_board_pinmap.h"   // "00126_R10_EP202_BITCOIN_pinmap.h"


// Generic settings for ADC module and shared and dedicated cores
#define ADC_GENERAL_CLOCK_DIVIDER   1   // ADC Module Clock Divider Setting

#define DEDICATED_CORE_SAMPLING_TIME 2  // Sampling time of the dedicated ADC cores
#define DEDICATED_ADC_CLOCK_DIVIDER 2  // Clock divider of the dedicated ADC core

#define SHARED_CORE_SAMPLING_TIME   10  // Sampling time of the shared ADC core
#define SHARED_ADC_CLOCK_DIVIDER 2  // Clock divider of the shared ADC core

// Generic ADC configuration registers
#define ADC_ADCON1L_CFG       (REG_ADCON1L_ADON_OFF | \
                                REG_ADCON1L_ADSIDL_ON \
                               )
                                   
#define ADC_ADCON1H_CFG       (REG_ADCON1H_FORM_INTEGER | \
                                REG_ADCON1H_SHRRES_12BIT \
                               )

#define ADC_ADCON2L_CFG       (REG_ADCON2L_REFCIE_OFF | \
                                REG_ADCON2L_REFERCIE_OFF | \
                                REG_ADCON2L_EIEN_ON | \
                                REG_ADCON2L_SHREISEL_1TAD | \
                                REG_SHRADCS(SHARED_ADC_CLOCK_DIVIDER) \
                               )

#define ADC_ADCON2H_CFG       REG_ADCON2H_SHRSAMC(SHARED_CORE_SAMPLING_TIME)

#define ADC_ADCON3L_CFG       (REG_ADCON3L_REFSEL_AVDD_AVSS | \
                                REG_ADCON3L_SUSPEND_OFF | \
                                REG_ADCON3L_SUSPCIE_OFF | \
                                REG_ADCON3L_SHRSAMP_ADCORE | \
                                REG_ADCON3L_CNVRTCH_OFF | \
                                REG_ADCON3L_SWLCTRG_OFF | \
                                REG_ADCON3L_SWCTRG_OFF | \
                                REG_ADCON3L_CNVCHSEL(0) \
                               )

#define ADC_ADCON3H_CFG       (REG_ADCON3H_CLKSEL_FOSC | \
                                REG_ADCON3H_CLKDIV(ADC_GENERAL_CLOCK_DIVIDER) | \
                                REG_ADCON3H_C0EN_OFF | \
                                REG_ADCON3H_C1EN_OFF | \
                                REG_ADCON3H_C2EN_OFF | \
                                REG_ADCON3H_C3EN_OFF | \
                                REG_ADCON3H_SHREN_OFF \
                               )

#define ADC_ADCON4L_CFG       (REG_SYNCTRG0_OFF | \
                                REG_SYNCTRG1_OFF | \
                                REG_SYNCTRG2_OFF | \
                                REG_SYNCTRG3_OFF | \
                                REG_SAMC0EN_OFF | \
                                REG_SAMC1EN_OFF | \
                                REG_SAMC2EN_OFF | \
                                REG_SAMC3EN_OFF \
                               )

#define ADC_ADCON4H_CFG       (REG_C0CHS_AN0 | \
                                REG_C1CHS_AN1 | \
                                REG_C2CHS_AN2 | \
                                REG_C3CHS_AN3 \
                               )

#define ADC_ADCON5L_CFG       (REG_ADCON5L_C0PWR_OFF | \
                                REG_ADCON5L_C1PWR_OFF | \
                                REG_ADCON5L_C2PWR_OFF | \
                                REG_ADCON5L_C3PWR_OFF | \
                                REG_ADCON5L_SHRPWR_OFF \
                               )

#define ADC_ADCON5H_CFG       (REG_WARMTIME_CLK_32768 | \
                                REG_C0CIE_OFF | \
                                REG_C1CIE_OFF | \
                                REG_C2CIE_OFF | \
                                REG_C3CIE_OFF | \
                                REG_SHRCIE_OFF \
                               )

#define ADC_ADCAL_CALIB_MODE    REG_ADC_CALIB_MODE_SINGLE_ENDED

#define ADC_ADCMP_VOUT          0
#define ADC_ADCMP_VOUT_CFG    (REG_ADCMPxCON_CMPEN_ON | \
                                REG_ADCMPxCON_IE_OFF | \
                                REG_ADCMPxCON_BTWN_OFF | \
                                REG_ADCMPxCON_HIHI_ON | \
                                REG_ADCMPxCON_HILO_OFF | \
                                REG_ADCMPxCON_LOHI_OFF | \
                                REG_ADCMPxCON_LOLO_OFF \
                               )

#define ADC_ADCMP_VIN          1
#define ADC_ADCMP_VIN_CFG     (REG_ADCMPxCON_CMPEN_ON | \
                                REG_ADCMPxCON_IE_OFF | \
                                REG_ADCMPxCON_BTWN_OFF | \
                                REG_ADCMPxCON_HIHI_ON | \
                                REG_ADCMPxCON_HILO_OFF | \
                                REG_ADCMPxCON_LOHI_OFF | \
                                REG_ADCMPxCON_LOLO_ON \
                               )


// ADC Triggers provided by other paripherals

#define ADC_VIN_TRIG			STRIG1				// ADC Trigger Register for input voltage
#define ADC_VOUT_TRIG			TRIG1				// ADC Trigger Register for output voltage
#define ADC_PH1_IL_TRIG         TRIG1				// ADC Trigger Register of inductor current phase #1


// ADC Feedback

// Output Voltage Sensing
#define ADC_VOUT_ADCORE         VOUT_FB_ADCORE   	// ADC buffer where the output voltage value is written to
#define ADC_VOUT_ANALOG_INPUT   VOUT_FB_PIN         // Index number of the analog input used
#define ADC_VOUT_ADCBUF         VOUT_FB_ADCBUF      // ADC buffer where the output voltage value is written to

#define ADC_VOUT_ADCORExL_CFG   REG_SAMC(SHARED_CORE_SAMPLING_TIME)

#define ADC_VOUT_ADCORExH_CFG  (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(SHARED_ADC_CLOCK_DIVIDER) \
                               )

#define ADC_VOUT_TRIG_COMPARE   ADC_VOUT_TRIG                   // PWM Trigger Compare Register of output voltage
#define ADC_VOUT_TRIG_SOURCE    REG_ADTRIGx_TRGSRC_PWM1_PRIM    // ADC Trigger Source Register of output voltage

#if(TRIGGER_OPTION == TRG_OPTION_ADC)
  #define ADC_VOUT_ADCORE_EIE     ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
  #define ADC_VOUT_ADIN_IE        ADC_ANx_INTERRUPT_ENABLE        // Enable/Disable generation of interrupts of selected analog input
  #define ADC_VOUT_ISR_PRIORITY   3                               // Set interrupt priority for output voltage sampling
#else
  #define ADC_VOUT_ADCORE_EIE     ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
  #define ADC_VOUT_ADIN_IE        ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of selected analog input
  #define ADC_VOUT_ISR_PRIORITY   0                               // Set interrupt priority for output voltage sampling
#endif

#define ADC_VOUT_ADC_ANSEL      VOUT_FB_ANSEL       // Input ANx is on Pin XX => Set as Analog Input
#define ADC_VOUT_ADC_IF         VOUT_FB_IF          // Interrupt flag bit of AN3
#define ADC_VOUT_ADC_IE         VOUT_FB_IE          // Interrupt enable bit of AN3
#define ADC_VOUT_ADC_IP         VOUT_FB_IP          // Interrupt priority of AN3

#define ADC_VOUT_ADCMP_IF       VOUT_FB_ADCMPxIF  // Interrupt flag bit of ADC comparator triggering VIN OORs
#define ADC_VOUT_ADCMP_IE       VOUT_FB_ADCMPxIE  // Interrupt enable bit of ADC comparator triggering VIN OORs
#define ADC_VOUT_ADCMP_IP       VOUT_FB_ADCMPxIP  // Interrupt priority of ADC comparator triggering VIN OORs

// Input Voltage Sensing
#define ADC_VIN_ADCORE          VIN_FB_ADCORE   	// ADC buffer where the output voltage value is written to
#define ADC_VIN_ANALOG_INPUT    VIN_FB_PIN          // Index number of the analog input used
#define ADC_VIN_ADCBUF			VIN_FB_ADCBUF		// ADC buffer where the input current value is written to

#define ADC_VIN_ADCORExL_CFG    REG_SAMC(SHARED_CORE_SAMPLING_TIME)

#define ADC_VIN_ADCORExH_CFG   (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(SHARED_ADC_CLOCK_DIVIDER) \
                               )

#define ADC_VIN_TRIG_COMPARE    ADC_VIN_TRIG                    // PWM Trigger Compare Register of input voltage
#define ADC_VIN_TRIG_SOURCE     REG_ADTRIGx_TRGSRC_PWM1_SEC     // ADC Trigger Source Register of input voltage
                                
#define ADC_VIN_ADCORE_EIE      ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_VIN_ADIN_IE         ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of selected analog input
#define ADC_VIN_ISR_PRIORITY    0                               // Set interrupt priority for input voltage sampling

#define ADC_VIN_ADC_ANSEL       VIN_FB_ANSEL        // Input ANx is on Pin XX => Set as Analog Input
#define ADC_VIN_ADC_IF			VIN_FB_IF	// Interrupt flag bit of AN2
#define ADC_VIN_ADC_IE			VIN_FB_IE	// Interrupt enable bit of AN2
#define ADC_VIN_ADC_IP			VIN_FB_IP	// Interrupt priority of AN2

#define ADC_VIN_ADCMP_IF        VIN_FB_ADCMPxIF  // Interrupt flag bit of ADC comparator triggering VIN OORs
#define ADC_VIN_ADCMP_IE        VIN_FB_ADCMPxIE  // Interrupt enable bit of ADC comparator triggering VIN OORs
#define ADC_VIN_ADCMP_IP        VIN_FB_ADCMPxIP  // Interrupt priority of ADC comparator triggering VIN OORs

// Inductor Current Sensing Phase #1
#define ADC_PH1_IL_ADCORE		IL_FB_ADCORE   	// ADC buffer where the output voltage value is written to
#define ADC_PH1_IL_ANALOG_INPUT IL_FB_PIN       // Index number of the analog input used
#define ADC_PH1_IL_ADCBUF		IL_FB_ADCBUF    // ADC buffer where the inductor current value is written to

#define ADC_PH1_IL_ADCORExL_CFG REG_SAMC(DEDICATED_CORE_SAMPLING_TIME)

#define ADC_PH1_IL_ADCORExH_CFG (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(DEDICATED_ADC_CLOCK_DIVIDER) \
                               )

#define ADC_PH1_IL_TRIG_COMPARE ADC_PH1_IL_TRIG                 // PWM Trigger Compare Register of inductor current phase #1
#define ADC_PH1_IL_TRIG_SOURCE  REG_ADTRIGx_TRGSRC_PWM1_PRIM    // ADC Trigger Source Register of inductor current phase #1

#if(TRIGGER_OPTION == TRG_OPTION_ADC)

  #define ADC_PH1_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
  #define ADC_PH1_IL_ADIN_IE      ADC_ANx_INTERRUPT_ENABLE        // Enable/Disable generation of interrupts of selected analog input
  #define ADC_PH1_IL_ISR_PRIORITY 4                               // Set interrupt priority for phase #1 inductor current sampling
#else
  #define ADC_PH1_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_DISABLE  // Enable/Disable Early Interrupts for selected analog input
  #define ADC_PH1_IL_ADIN_IE      ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of selected analog input
  #define ADC_PH1_IL_ISR_PRIORITY 0                               // Set interrupt priority for phase #1 inductor current sampling
#endif

#define ADC_PH1_IL_ANSEL        IL_FB_ANSEL         // Input AN1 is on Pin RA1 => Set as Analog Input
#define ADC_PH1_IL_ADC_IF		IL_FB_IF            // Interrupt flag bit for selected analog input
#define ADC_PH1_IL_ADC_IE		IL_FB_IE            // Interrupt enable bit for selected analog input
#define ADC_PH1_IL_ADC_IP		IL_FB_IP        	// Interrupt priority for selected analog input


// Temperature Sensing
#define ADC_TEMP_ADCORE         TEMP_FB_ADCORE   	// ADC core used to sample the temperature value
#define ADC_TEMP_ANALOG_INPUT   TEMP_FB_PIN         // Index number of the analog input used
#define ADC_TEMP_ADCBUF         TEMP_FB_ADCBUF      // ADC buffer where the temperature value is written to

#define ADC_TEMP_ADCORExL_CFG   REG_SAMC(SHARED_CORE_SAMPLING_TIME)

#define ADC_TEMP_ADCORExH_CFG  (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(SHARED_ADC_CLOCK_DIVIDER) \
                               )

#define ADC_TEMP_TRIG_SOURCE    REG_ADTRIGx_TRGSRC_PWM1_SEC     // ADC Trigger Source Register of temperature

#define ADC_TEMP_ADCORE_EIE     ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_TEMP_ADIN_IE        ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of selected analog input
#define ADC_TEMP_ISR_PRIORITY   0                               // Set interrupt priority for temperature sampling

#define ADC_TEMP_ADC_ANSEL      TEMP_FB_ANSEL       // Input ANx is on Pin XX => Set as Analog Input
#define ADC_TEMP_ADC_IF         TEMP_FB_IF          // Interrupt flag bit of ANx
#define ADC_TEMP_ADC_IE         TEMP_FB_IE          // Interrupt enable bit of ANx
#define ADC_TEMP_ADC_IP         TEMP_FB_IP          // Interrupt priority of ANx


#endif	/* _DEVICE_CONFIGURATION_ADC_H_ */

