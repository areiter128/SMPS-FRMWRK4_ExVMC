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
#ifndef _DEVICE_CONFIGURATION_HSACMP_H_
#define	_DEVICE_CONFIGURATION_HSACMP_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

#include "syscfg_limits.h"
#include "mcal.h"

// High Speed Analog Comparators


// Comparator #1 used for over current protection

#define CVRT_OCP_CMP_IDX		1					// Analog inductor current comparator
#define CVRT_OCP_CMP_INPUT      REG_INSEL_CMPxA		// Analog comparator input selection1
#define CVRT_OCP_CMPDAC         CMP1DAC         	// D/A converter of the analog comparator
#define CVRT_OCP_CMPDAC_IDX     1                	// D/A converter index of the analog comparator
#define CVRT_OCP_CMP_MIN        0x0000              // Minimum value of the 12-bit DAC
#define CVRT_OCP_CMP_MAX        0x0FFF              // Maximum value of the 12-bit DAC
#define CVRT_OCP_CMP_NOM        IL_OCP_TRIP         // Nominal value of the 12-bit DAC
        
#if defined (__P33SMPS_EP2__)

   #define CVRT_OCP_CMP_CFG    (REG_CMPON_OFF | \
                                REG_CMPSIDL_OFF | \
                                REG_HYSSEL_20MV | \
                                REG_FLTREN_OFF | \
                                REG_FCLKSEL_PWMCLK | \
                                REG_DACOE_ON | \
                                REG_EXTREF_DISABLED | \
                                HYSPOL_FALLING_EDGE | \
                                REG_ALTINP_DEFAULT | \
                                REG_CMPPOL_NON_INVERTED \
                                )

#elif defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

   #define CVRT_OCP_CMP_CFG    (REG_CMPON_OFF | \
                                REG_CMPSIDL_OFF | \
                                REG_HYSSEL_20MV | \
                                REG_FLTREN_OFF | \
                                REG_FCLKSEL_PWMCLK | \
                                REG_DACOE_ON | \
                                REG_EXTREF_DISABLED | \
                                HYSPOL_FALLING_EDGE | \
                                REG_ALTINP_DEFAULT | \
                                REG_CMPPOL_NON_INVERTED | \
                                REG_RANGE_HIGH \
                                )

#endif

// Comparator #2 used for output over voltage protection

#define CVRT_OVP_CMP_IDX		2					// Analog inductor current comparator of phase #2
#define CVRT_OVP_CMP_INPUT      REG_INSEL_CMPxB		// Analog comparator input selection
#define CVRT_OVP_CMPDAC         CMP2DAC             // D/A converter of the analog comparator of phase #2
#define CVRT_OVP_CMPDAC_IDX     1                	// D/A converter index of the analog comparator
#define CVRT_OVP_CMP_MIN        0x0000              // Minimum value of the 12-bit DAC
#define CVRT_OVP_CMP_MAX        0x0FFF              // Maximum value of the 12-bit DAC
#define CVRT_OVP_CMP_NOM        VOUT_OVP_TRIP       // Nominal value of the 12-bit DAC

#if defined (__P33SMPS_EP2__)

   #define CVRT_OVP_CMP_CFG    (REG_CMPON_OFF | \
                                REG_CMPSIDL_OFF | \
                                REG_HYSSEL_20MV | \
                                REG_FLTREN_ON | \
                                REG_FCLKSEL_PWMCLK | \
                                REG_DACOE_OFF | \
                                REG_EXTREF_DISABLED | \
                                HYSPOL_FALLING_EDGE | \
                                REG_ALTINP_DEFAULT | \
                                REG_CMPPOL_NON_INVERTED \
                                )


#elif defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

   #define CVRT_OVP_CMP_CFG    (REG_CMPON_OFF | \
                                REG_CMPSIDL_OFF | \
                                REG_HYSSEL_20MV | \
                                REG_FLTREN_ON | \
                                REG_FCLKSEL_PWMCLK | \
                                REG_DACOE_OFF | \
                                REG_EXTREF_DISABLED | \
                                HYSPOL_FALLING_EDGE | \
                                REG_ALTINP_DEFAULT | \
                                REG_CMPPOL_NON_INVERTED | \
                                REG_RANGE_HIGH \
                                )

#endif


#endif	/* _DEVICE_CONFIGURATION_HSACMP_H_ */

