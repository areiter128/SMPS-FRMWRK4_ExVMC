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

#ifndef __SYSTEM_DESIGN_LIMITS_H__
#define	__SYSTEM_DESIGN_LIMITS_H__

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <dsp.h>
#include <math.h>

#include "syscfg_scaling.h"

// Converter input and output voltage and current levels

#define VIN_MINIMUM         6.000       // input voltage minimum (Under-Voltage-Lockout-Level)
#define VIN_MINIMUM_HYST    0.500       // input voltage minimum (Under-Voltage-Lockout Hysteresis Level)
#define VIN_UVLO_TRIP       (uint16_t)(VIN_MINIMUM * VIN_DIVIDER_RATIO * ADC_SCALER) // Input voltage sense ADC ticks
#define VIN_UVLO_RELEASE    (uint16_t)((VIN_MINIMUM + VIN_MINIMUM_HYST) * VIN_DIVIDER_RATIO * ADC_SCALER) // Input voltage sense ADC ticks

#define VIN_NOMINAL         12.000       // Nominal input voltage in [V]
#define VIN_FB_REF_ADC      (uint16_t)((float)VIN_DIVIDER_RATIO * (float)VIN_NOMINAL * ADC_SCALER)   // Input voltage feedback in ADC ticks

#define VIN_MAXIMUM         20.000      // input voltage maximum (Under-Voltage-Lockout-Level)
#define VIN_MAXIMUM_HYST    0.500       // input voltage maximum (Under-Voltage-Lockout Hysteresis Level)
#define VIN_OVLO_TRIP       (uint16_t)((float)VIN_MAXIMUM * (float)VIN_DIVIDER_RATIO * (float)ADC_SCALER) // Input voltage sense ADC ticks
#define VIN_OVLO_RELEASE    (uint16_t)(((float)VIN_MAXIMUM - (float)VIN_MAXIMUM_HYST) * (float)VIN_DIVIDER_RATIO * (float)ADC_SCALER) // Input voltage sense ADC ticks


#define VOUT_NOMINAL         3.300       // Nominal output voltage in [V]
#define VOUT_FB_REF_ADC      (uint16_t)((float)VOUT_DIVIDER_RATIO * (float)VOUT_NOMINAL * (float)ADC_SCALER)   // Output voltage feedback in ADC ticks

#define VOUT_MAXIMUM         6.000       // Output voltage minimum (Output Over-Voltage-Protection-Level)
#define VOUT_MAXIMUM_HYST    0.300       // Output voltage maximum (Output Over-Voltage-Protection Hysteresis Level)
#define VOUT_OVP_TRIP       (uint16_t)((float)VOUT_MAXIMUM * (float)VOUT_DIVIDER_RATIO * (float)ADC_SCALER) // Output voltage sense ADC ticks
#define VOUT_OVP_RELEASE    (uint16_t)(((float)VOUT_MAXIMUM - (float)VOUT_MAXIMUM_HYST) * (float)VOUT_DIVIDER_RATIO * (float)ADC_SCALER) // Output voltage sense ADC ticks


#define IL_MAXIMUM          8.000
#define IL_OCP_TRIP         (uint16_t)((((float)IL_MAXIMUM * (float)IFB_SCALER_RATIO_VI) + ((float)IFB_SCALER_OFFSET_V)) * (float)DAC_SCALER) // Output voltage sense ADC ticks

#define DUTY_RATIO_MIN      0.02    // Minimum duty ration 
#define DUTY_RATIO_MAX      0.90    // maximum duty ratio
#define DUTY_RATIO_MIN_REG (uint16_t)((float)DUTY_RATIO_MIN * (float)SWITCHING_PERIOD)
#define DUTY_RATIO_MAX_REG (uint16_t)((float)DUTY_RATIO_MAX * (float)SWITCHING_PERIOD)

#endif	/* __SYSTEM_DESIGN_LIMITS_H__ */

