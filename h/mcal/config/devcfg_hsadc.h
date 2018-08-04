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
//#include "devcfg_hspwm.h"   // The device configuration of the PWM module has to be included to gain access
                            // to converter specific trigger settings


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
                                REG_SHRADCS(2) \
                               )

#define ADC_ADCON2H_CFG       REG_ADCON2H_SHRSAMC(2)

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
                                REG_ADCON3H_CLKDIV(1) | \
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

#if (PWM_MPH_PHASE_COUNT >= 1)
#define ADC_PH1_IL_TRIG         TRIG1				// ADC Trigger Register of inductor current phase #1
#elif (PWM_MPH_PHASE_COUNT >= 2)
#define ADC_PH2_IL_TRIG         TRIG2				// ADC Trigger Register of inductor current phase #2
#elif (PWM_MPH_PHASE_COUNT >= 3)
#define ADC_PH3_IL_TRIG         TRIG3				// ADC Trigger Register of inductor current phase #3
#elif (PWM_MPH_PHASE_COUNT >= 4)
#define ADC_PH4_IL_TRIG         TRIG4				// ADC Trigger Register of inductor current phase #4
#elif (PWM_MPH_PHASE_COUNT >= 5)
#define ADC_PH4_IL_TRIG         TRIG5				// ADC Trigger Register of inductor current phase #5
#elif (PWM_MPH_PHASE_COUNT >= 6)
#define ADC_PH4_IL_TRIG         TRIG6				// ADC Trigger Register of inductor current phase #6
#elif (PWM_MPH_PHASE_COUNT >= 7)
#define ADC_PH4_IL_TRIG         TRIG7				// ADC Trigger Register of inductor current phase #7
#elif (PWM_MPH_PHASE_COUNT == 8)
#define ADC_PH4_IL_TRIG         TRIG8				// ADC Trigger Register of inductor current phase #8
#elif (PWM_MPH_PHASE_COUNT > 8)
#error === converter phase count recently not supported by this library ===
#endif

#if (PWM_MPH_PHASE_COUNT >= 1)
  #define ADC_VIN_TRIG			STRIG1				// ADC Trigger Register for input voltage
  #define ADC_VOUT_TRIG			TRIG1				// ADC Trigger Register for output voltage
#elif (PWM_MPH_PHASE_COUNT >= 2)
  #define ADC_VIN_TRIG			TRIG2				// ADC Trigger Register for input voltage
  #define ADC_VOUT_TRIG			TRIG2				// ADC Trigger Register for output voltage
#elif (PWM_MPH_PHASE_COUNT >= 3)
  #define ADC_VIN_TRIG			TRIG3				// ADC Trigger Register for input voltage
  #define ADC_VOUT_TRIG			TRIG3				// ADC Trigger Register for output voltage
#elif (PWM_MPH_PHASE_COUNT >= 4)
  #define ADC_VIN_TRIG			TRIG4				// ADC Trigger Register for input voltage
  #define ADC_VOUT_TRIG			TRIG4				// ADC Trigger Register for output voltage
#elif (PWM_MPH_PHASE_COUNT >= 5)
  #define ADC_VIN_TRIG			TRIG5				// ADC Trigger Register for input voltage
  #define ADC_VOUT_TRIG			TRIG5				// ADC Trigger Register for output voltage
#elif (PWM_MPH_PHASE_COUNT >= 6)
  #define ADC_VIN_TRIG			TRIG6				// ADC Trigger Register for input voltage
  #define ADC_VOUT_TRIG			TRIG6				// ADC Trigger Register for output voltage
#elif (PWM_MPH_PHASE_COUNT >= 7)
  #define ADC_VIN_TRIG			TRIG7				// ADC Trigger Register for input voltage
  #define ADC_VOUT_TRIG			TRIG7				// ADC Trigger Register for output voltage
#elif (PWM_MPH_PHASE_COUNT == 8)
  #define ADC_VIN_TRIG			TRIG8				// ADC Trigger Register for input voltage
  #define ADC_VOUT_TRIG			TRIG8				// ADC Trigger Register for output voltage
#elif (PWM_MPH_PHASE_COUNT > 8)
  #error === converter phase count recently not supported by this library ===
#endif


// ADC Feedback

// Output Voltage Sensing
#define ADC_VOUT_ADCORE         TP14_ADC_CORE   	// ADC buffer where the output voltage value is written to
#define ADC_VOUT_ANALOG_INPUT   TP14_ADC_IN         // Index number of the analog input used
#define ADC_VOUT_ADCBUF         TP14_ADC_BUFFER 	// ADC buffer where the output voltage value is written to

#define ADC_VOUT_ADCORExL_CFG   REG_SAMC(2)

#define ADC_VOUT_ADCORExH_CFG  (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(2) \
                               )

#define ADC_VOUT_TRIG_COMPARE   ADC_VOUT_TRIG                   // PWM Trigger Compare Register of output voltage
#define ADC_VOUT_TRIG_SOURCE    REG_ADTRIGx_TRGSRC_PWM1_PRIM    // ADC Trigger Source Register of output voltage

#if(TRIGGER_OPTION == TRG_OPTION_ADC)
#define ADC_VOUT_ADCORE_EIE     ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_VOUT_ADIN_IE        ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of selected analog input
#define ADC_VOUT_ISR_PRIORITY   0                               // Set interrupt priority for output voltage sampling
#else
#define ADC_VOUT_ADCORE_EIE     ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_VOUT_ADIN_IE        ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of selected analog input
#define ADC_VOUT_ISR_PRIORITY   0                               // Set interrupt priority for output voltage sampling
#endif

#define ADC_VOUT_ADC_ANSEL      ANSELBbits.ANSB0    // Input AN3 is on Pin RB0 => Set as Analog Input
#define ADC_VOUT_ADC_IF         IFS7bits.ADCAN3IF	// Interrupt flag bit of AN3
#define ADC_VOUT_ADC_IE         IEC7bits.ADCAN3IE	// Interrupt enable bit of AN3
#define ADC_VOUT_ADC_IP         IPC28bits.ADCAN3IP	// Interrupt priority of AN3

#define ADC_VOUT_ADCMP_IF       IFS11bits.ADCMP1IF  // Interrupt flag bit of ADC comparator triggering VIN OORs
#define ADC_VOUT_ADCMP_IE       IEC11bits.ADCMP1IE  // Interrupt enable bit of ADC comparator triggering VIN OORs
#define ADC_VOUT_ADCMP_IP       IPC44bits.ADCMP1IP  // Interrupt priority of ADC comparator triggering VIN OORs

// Input Voltage Sensing
#define ADC_VIN_ADCORE          3   				// ADC buffer where the output voltage value is written to
#define ADC_VIN_ANALOG_INPUT    3                   // Index number of the analog input used
#define ADC_VIN_ADCBUF			ADCBUF3				// ADC buffer where the input current value is written to

#define ADC_VIN_ADCORExL_CFG    REG_SAMC(2)

#define ADC_VIN_ADCORExH_CFG   (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(2) \
                               )

#define ADC_VIN_TRIG_COMPARE    ADC_VIN_TRIG                    // PWM Trigger Compare Register of input voltage
#define ADC_VIN_TRIG_SOURCE     REG_ADTRIGx_TRGSRC_PWM1_PRIM    // ADC Trigger Source Register of input voltage
                                
#define ADC_VIN_ADCORE_EIE      ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_VIN_ADIN_IE         ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of selected analog input
#define ADC_VIN_ISR_PRIORITY    3                               // Set interrupt priority for input voltage sampling

#define ADC_VIN_ADC_ANSEL       ANSELAbits.ANSA2    // Input AN2 is on Pin RA2 => Set as Analog Input
#define ADC_VIN_ADC_IF			IFS6bits.ADCAN1IF	// Interrupt flag bit of AN2
#define ADC_VIN_ADC_IE			IEC6bits.ADCAN1IE	// Interrupt enable bit of AN2
#define ADC_VIN_ADC_IP			IPC27bits.ADCAN1IP	// Interrupt priority of AN2

#define ADC_VIN_ADCMP_IF        IFS11bits.ADCMP0IF  // Interrupt flag bit of ADC comparator triggering VIN OORs
#define ADC_VIN_ADCMP_IE        IEC11bits.ADCMP0IE  // Interrupt enable bit of ADC comparator triggering VIN OORs
#define ADC_VIN_ADCMP_IP        IPC44bits.ADCMP0IP  // Interrupt priority of ADC comparator triggering VIN OORs

#if (PWM_MPH_PHASE_COUNT >= 1)

// Inductor Current Sensing Phase #1
#define ADC_PH1_IL_ADCORE		0   				// ADC buffer where the output voltage value is written to
#define ADC_PH1_IL_ANALOG_INPUT 0                   // Index number of the analog input used
#define ADC_PH1_IL_ADCBUF		ADCBUF0				// ADC buffer where the inductor current value is written to

#define ADC_PH1_IL_ADCORExL_CFG REG_SAMC(2)

#define ADC_PH1_IL_ADCORExH_CFG (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(2) \
                               )

#define ADC_PH1_IL_TRIG_COMPARE ADC_PH1_IL_TRIG                 // PWM Trigger Compare Register of inductor current phase #1
#define ADC_PH1_IL_TRIG_SOURCE  REG_ADTRIGx_TRGSRC_PWM1_PRIM    // ADC Trigger Source Register of inductor current phase #1

#if(TRIGGER_OPTION == TRG_OPTION_ADC)

#define ADC_PH1_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_PH1_IL_ADIN_IE      ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of selected analog input
#define ADC_PH1_IL_ISR_PRIORITY 4                               // Set interrupt priority for phase #1 inductor current sampling
#else
#define ADC_PH1_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_DISABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_PH1_IL_ADIN_IE      ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of selected analog input
#define ADC_PH1_IL_ISR_PRIORITY 0                               // Set interrupt priority for phase #1 inductor current sampling
#endif

#define ADC_PH1_IL_ANSEL        ANSELAbits.ANSA1    // Input AN1 is on Pin RA1 => Set as Analog Input
#define ADC_PH1_IL_ADC_IF		IFS6bits.ADCAN1IF	// Interrupt flag bit for selected analog input
#define ADC_PH1_IL_ADC_IE		IEC6bits.ADCAN1IE	// Interrupt enable bit for selected analog input
#define ADC_PH1_IL_ADC_IP		IPC27bits.ADCAN1IP	// Interrupt priority for selected analog input

#elif (PWM_MPH_PHASE_COUNT >= 2)

// Inductor Current Sensing Phase #2
#define ADC_PH2_IL_ADCORE		2   				// ADC buffer where the output voltage value is written to
#define ADC_PH2_IL_ANALOG_INPUT 2                   // Index number of the analog input used
#define ADC_PH2_IL_ADCBUF		ADCBUF2				// ADC buffer where the inductor current value is written to

#define ADC_PH2_IL_ADCORExL_CFG   REG_SAMC(2)

#define ADC_PH2_IL_ADCORExH_CFG (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(2) \
                               )

#define ADC_PH2_IL_TRIG_COMPARE ADC_PH2_IL_TRIG                 // PWM Trigger Compare Register of inductor current phase #2
#define ADC_PH2_IL_TRIG_SOURCE  REG_ADTRIGx_TRGSRC_PWM2_PRIM    // ADC Trigger Source Register of inductor current phase #2

#if(TRIGGER_OPTION == TRG_OPTION_ADC)
#define ADC_PH2_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_PH2_IL_ADIN_IE      ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of  selected analog input
#define ADC_PH2_IL_ISR_PRIORITY 5                               // Set interrupt priority for phase #2 inductor current sampling
#else
#define ADC_PH2_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_PH2_IL_ADIN_IE      ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of  selected analog input
#define ADC_PH2_IL_ISR_PRIORITY 0                               // Set interrupt priority for phase #2 inductor current sampling
#endif


#define ADC_PH2_IL_ANSEL        ANSELAbits.ANSA2    // Input AN2 is on Pin RA2 => Set as Analog Input
#define ADC_PH2_IL_ADC_IF		IFS7bits.ADCAN2IF	// Interrupt flag bit of AN2
#define ADC_PH2_IL_ADC_IE		IEC7bits.ADCAN2IE	// Interrupt enable bit of AN2
#define ADC_PH2_IL_ADC_IP		IPC28bits.ADCAN2IP	// Interrupt priority of AN2

#elif (PWM_MPH_PHASE_COUNT >= 3)

// Inductor Current Sensing Phase #3
#define ADC_PH3_IL_ADCORE		3   				// ADC buffer where the output voltage value is written to
#define ADC_PH3_IL_ANALOG_INPUT 3                   // Index number of the analog input used
#define ADC_PH3_IL_ADCBUF		ADCBUF3				// ADC buffer where the inductor current value is written to

#define ADC_PH3_IL_ADCORExL_CFG   REG_SAMC(2)

#define ADC_PH3_IL_ADCORExH_CFG  (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(2) \
                               )

#define ADC_PH3_IL_TRIG_COMPARE ADC_PH3_IL_TRIG                 // PWM Trigger Compare Register of inductor current phase #2
#define ADC_PH3_IL_TRIG_SOURCE  REG_ADTRIGx_TRGSRC_PWM2_PRIM    // ADC Trigger Source Register of inductor current phase #2

#if(TRIGGER_OPTION == TRG_OPTION_ADC)
#define ADC_PH3_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_PH3_IL_ADIN_IE      ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of  selected analog input
#define ADC_PH3_IL_ISR_PRIORITY 5                               // Set interrupt priority for phase #2 inductor current sampling
#else
#define ADC_PH3_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_PH3_IL_ADIN_IE      ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of  selected analog input
#define ADC_PH3_IL_ISR_PRIORITY 0                               // Set interrupt priority for phase #2 inductor current sampling
#endif

#define ADC_PH3_IL_ANSEL        ANSELAbits.ANSA2    // Input AN2 is on Pin RA2 => Set as Analog Input
#define ADC_PH3_IL_ADC_IF		IFS7bits.ADCAN2IF	// Interrupt flag bit of AN2
#define ADC_PH3_IL_ADC_IE		IEC7bits.ADCAN2IE	// Interrupt enable bit of AN2
#define ADC_PH3_IL_ADC_IP		IPC28bits.ADCAN2IP	// Interrupt priority of AN2

#elif (PWM_MPH_PHASE_COUNT >= 4)

// Inductor Current Sensing Phase #4
#define ADC_PH4_IL_ADCORE		4   				// ADC buffer where the output voltage value is written to
#define ADC_PH4_IL_ANALOG_INPUT 4                   // Index number of the analog input used
#define ADC_PH4_IL_ADCBUF		ADCBUF4				// ADC buffer where the inductor current value is written to

#define ADC_PH4_IL_ADCORExL_CFG   REG_SAMC(2)

#define ADC_PH4_IL_ADCORExH_CFG  (REG_EISEL_8TAD | \
                                REG_ADC_RES_12BIT | \
                                REG_ADCS(2) \
                               )

#define ADC_PH4_IL_TRIG_COMPARE ADC_PH3_IL_TRIG                 // PWM Trigger Compare Register of inductor current phase #2
#define ADC_PH4_IL_TRIG_SOURCE  REG_ADTRIGx_TRGSRC_PWM2_PRIM    // ADC Trigger Source Register of inductor current phase #2

#if(TRIGGER_OPTION == TRG_OPTION_ADC)
#define ADC_PH4_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_PH4_IL_ADIN_IE      ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of  selected analog input
#define ADC_PH4_IL_ISR_PRIORITY 5                               // Set interrupt priority for phase #2 inductor current sampling
#else
#define ADC_PH4_IL_ADCORE_EIE   ADC_ANx_EARLY_INTERRUPT_ENABLE  // Enable/Disable Early Interrupts for selected analog input
#define ADC_PH4_IL_ADIN_IE      ADC_ANx_INTERRUPT_DISABLE       // Enable/Disable generation of interrupts of  selected analog input
#define ADC_PH4_IL_ISR_PRIORITY 0                               // Set interrupt priority for phase #2 inductor current sampling
#endif

#define ADC_PH4_IL_ANSEL        ANSELAbits.ANSA2    // Input AN2 is on Pin RA2 => Set as Analog Input
#define ADC_PH4_IL_ADC_IF		IFS7bits.ADCAN2IF	// Interrupt flag bit of AN2
#define ADC_PH4_IL_ADC_IE		IEC7bits.ADCAN2IE	// Interrupt enable bit of AN2
#define ADC_PH4_IL_ADC_IP		IPC28bits.ADCAN2IP	// Interrupt priority of AN2


#elif (PWM_MPH_PHASE_COUNT > 8)

#error === converter phase count recently not supported by this library ===

#endif


#endif	/* _DEVICE_CONFIGURATION_ADC_H_ */

