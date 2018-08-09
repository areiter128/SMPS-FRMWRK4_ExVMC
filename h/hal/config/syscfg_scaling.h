/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
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
 * **************************************************************************************
 * File:   system_scaling.h
 * Author: M91406
 * Comments: 
 * Revision history: 
 * 07/29/2016   initial release
 * **************************************************************************************/

#ifndef _HARDWARE_ABSTRACTION_LAYER_SYSTEM_SCALING_H_
#define	_HARDWARE_ABSTRACTION_LAYER_SYSTEM_SCALING_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <dsp.h>
#include <math.h>

#include "mcal.h"

// DSC bias voltage
#define DEVICE_VDD              3.300       // Device bias voltage in [V]

// Inductance of the main inductor
#define INDUCTANCE              2.200       // Inductance in [µH]

// Feedback Scaling

#define VIN_DIVIDER_R1          15400       // Resitance of upper voltage divider resistor in Ohm
#define VIN_DIVIDER_R2          2200        // Resitance of lower voltage divider resistor in Ohm
#define VIN_DIVIDER_RATIO   (float)(((float)VIN_DIVIDER_R2) / ((float)(VIN_DIVIDER_R1 + VIN_DIVIDER_R2)))
#define VIN_DIVIDER_RATIO_INV  (float)( 1.0 / VIN_DIVIDER_RATIO)

#define VIN_SENSE_OFFSET       0.000        // Input voltage sense offset
#define VIN_FB_OFFSET      (uint16_t)(VIN_SENSE_OFFSET * ADC_SCALER)    // Input voltage sense offset ADC ticks

#define VOUT_DIVIDER_R1         4700        // Resitance of upper voltage divider resistor in Ohm
#define VOUT_DIVIDER_R2         4700        // Resitance of lower voltage divider resistor in Ohm
#define VOUT_DIVIDER_RATIO  (float)(((float)VOUT_DIVIDER_R2) / ((float)(VOUT_DIVIDER_R1 + VOUT_DIVIDER_R2)))
#define VOUT_DIVIDER_RATIO_INV  (float)( 1.0 / VOUT_DIVIDER_RATIO)

#define VOUT_SENSE_OFFSET       0.000       // Output voltage sense offset
#define VOUT_FB_OFFSET      (int16_t)(VOUT_SENSE_OFFSET * ADC_SCALER)   // Output voltage sense offset ADC ticks


#define VIN2VOUT_NORMALIZATION  0x7fff  //(int16_t)(ceiling(log(VOUT_DIVIDER_RATIO/VIN_DIVIDER_RATIO)))
#define VIN2VOUT_NORM_BSFT      2

#if (CS_TYPE == CS_TYPE_CT)
// Defines for Current Sense Transformer feedback
#define CT_WINDING_RATIO        100.0       // CT winding ratio 1:xxx
#define CT_BURDEN_RESISTANCE     20.0       // Current Sense Transformer burden resistance in Ohm
#define CS_BI_DIRECTIONAL         0         // Current sens in uni-directional
#define CS_OFFSET                 0.000     // Current Sense zero offset 

#define IFB_SCALER_RATIO_VI     (float)(((float)(CT_BURDEN_RESISTANCE))/((float)(CT_WINDING_RATIO))) // Current feeback ratio in [V/A]
#define IFB_SCALER_RATIO_IV     (float)(1.0/((float)(IFB_SCALER_RATIO_VI))  // Current feeback ratio in [A/V]
#define IFB_SCALER_RATIO_TICKS  (float)(IFB_SCALER_RATIO_VI * ADC_SCALER)   // Current feeback ratio in [Ticks/A]
#define IFB_SCALER_OFFSET       (uint16_t)(CS_OFFSET * ADC_SCALER)          // Current sense offset ADC ticks

#elif (CS_TYPE == CS_TYPE_SHUNT_AMP)

#define CS_GAIN                 20          // Current sense gain
#define CS_SHUNT_RESISTANCE     1e-3        // Current sense resistor value
#define CS_BI_DIRECTIONAL       1           // Current sens in uni-directional
#define CS_OFFSET               1.650       // Current sense zero offset 

#define IFB_SCALER_RATIO_VI     (float)(((float)(CS_SHUNT_RESISTANCE))*((float)(CS_GAIN))) // Current feeback ratio in [V/A]
#define IFB_SCALER_RATIO_IV     (float)(1.0/((float)(IFB_SCALER_RATIO_VI))  // Current feeback ratio in [A/V]
#define IFB_SCALER_RATIO_TICKS  (float)(IFB_SCALER_RATIO_VI * ADC_SCALER)   // Current feeback ratio in [Ticks/A]
#define IFB_SCALER_OFFSET       (uint16_t)(CS_OFFSET * ADC_SCALER)          // Current sense offset ADC ticks

#endif


// System Settings
#define SWITCHING_FREQUENCY		350000      // Nominal switching frequency per converter phase in [Hz]
#define PWM_DEAD_TIME_LE		50          // Nominal dead time at the leading edge in [ns]
#define PWM_DEAD_TIME_FE		70          // Nominal dead time at the falling edge in [ns]
#define LEB_PERIOD_LE			150e-9		// Leading Edge Blanking period in nanoseconds
#define ADC_TRIG_OFFSET         100e-9      // ADC trigger offset compensating for propagat6ion delays

/*@@PWM-related Timing Settings
 * ************************************************************************************************
 * Summary:
 * Set of defines and marcos for easy migration to new hardware
 *
 * Description:
 * This macro calculates the Master Time Base register value for the desired switching
 * frequency according to the value given by SWITCHING_FREQUENCY, based on the oscillator
 * frequency settings and the post-scaler setting (PCLKDIV) which finally determines the PWM 
 * resolution.
 * 
 * The switching frequency specification includes a center frequency setting (= desired switching 
 * fequency) and an upper and lower limit, which will be used for chaotic spread spectrum modulation.
 * This modulation technique will randomly jitter the frequency within the given range.
 * 
 * See also:
 * USE_SPREAD_SPECTRUM_MODULATION 
 * ************************************************************************************************/

// Macros are used to translate physical values into register values

#define FSW_CENTER_PERIOD   (((uint16_t)(((float)((1.0/(float)(SWITCHING_FREQUENCY))/T_ACLK)-1)))>>PWM_PCLKDIV_PRIMARY)
#if (USE_SPREAD_SPECTRUM_MODULATION == 1)
  #define FSW_CENTER_OFFSET   (FSW_CENTER_PERIOD - ((uint16_t)(((uint32_t)(FSW_CENTER_PERIOD) * (uint32_t)(SSM_NOM_MODULATION_FACTOR)) >> 16)))
#else
  #define FSW_CENTER_OFFSET   0 // ((uint16_t)(FSW_CENTER_PERIOD))
#endif

#define SWITCHING_PERIOD_MIN    ((uint16_t)(FSW_CENTER_PERIOD - FSW_CENTER_OFFSET))
#define SWITCHING_PERIOD_MAX    ((uint16_t)(FSW_CENTER_PERIOD + FSW_CENTER_OFFSET))
#define SWITCHING_PERIOD_NOM    ((uint16_t)(FSW_CENTER_PERIOD))

#if (USE_SPREAD_SPECTRUM_MODULATION == 1)
  #define SWITCHING_PERIOD        SWITCHING_PERIOD_MAX
#else
  #define SWITCHING_PERIOD        SWITCHING_PERIOD_NOM
#endif

// Macro calculating ADC offset period counter value based on time base frequency selection
#define ADC_TRIGGER_OFFSET	((uint16_t)((uint16_t)(((float)(ADC_TRIG_OFFSET))/((float)(T_ACLK))) >> PWM_PCLKDIV_PRIMARY) & REG_LEB_PERIOD_MASK)

// Macro calculating Leading Edge Blanking period counter value based on time base frequency selection
#define LEB_PERIOD			((uint16_t)((uint16_t)(((float)(LEB_PERIOD_LE))/((float)(T_ACLK))) >> PWM_PCLKDIV_PRIMARY) & REG_LEB_PERIOD_MASK)

// Macros phase-shifting PWMs equally across one period when multiple phases are operated 
#define MPH_PHASE_SHIFT_CH1 (0 * (uint16_t)((float)SWITCHING_PERIOD / (float)PWM_MPH_PHASE_COUNT))
#define MPH_PHASE_SHIFT_CH2 (1 * (uint16_t)((float)SWITCHING_PERIOD / (float)PWM_MPH_PHASE_COUNT))
#define MPH_PHASE_SHIFT_CH3 (2 * (uint16_t)((float)SWITCHING_PERIOD / (float)PWM_MPH_PHASE_COUNT))
#define MPH_PHASE_SHIFT_CH4 (3 * (uint16_t)((float)SWITCHING_PERIOD / (float)PWM_MPH_PHASE_COUNT))
#define MPH_PHASE_SHIFT_CH5 (4 * (uint16_t)((float)SWITCHING_PERIOD / (float)PWM_MPH_PHASE_COUNT))
#define MPH_PHASE_SHIFT_CH6 (5 * (uint16_t)((float)SWITCHING_PERIOD / (float)PWM_MPH_PHASE_COUNT))
#define MPH_PHASE_SHIFT_CH7 (6 * (uint16_t)((float)SWITCHING_PERIOD / (float)PWM_MPH_PHASE_COUNT))
#define MPH_PHASE_SHIFT_CH8 (7 * (uint16_t)((float)SWITCHING_PERIOD / (float)PWM_MPH_PHASE_COUNT))

#endif	/* _HARDWARE_ABSTRACTION_LAYER_SYSTEM_SCALING_H_ */

