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

#ifndef __P33EGS_HSACMP_H__
#define __P33EGS_HSACMP_H__

#include <stdint.h>
#include "p33SMPS_devices.h"

#include "syscfg_scaling.h"

/*@@p33GS_hsacmp.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33GS High Speed Analog Comparator SFRs
 *
 * Description:
 * The SMPS peripherals use digital-to-analog converters (DAC) to program reference voltages
 * for the on-board high-speed comparators. This module offers a number of registers and 
 * configuration options. This additional header file contains defines for all required 
 * bit-settings and comes on top of the generic device header file.
 * ***********************************************************************************************/

/* Prototypes */
extern inline uint16_t gscmp_init(uint16_t index, uint16_t regCMPCON, uint16_t regDAC);
extern inline uint16_t gscmp_enable(uint16_t index);
extern inline uint16_t gscmp_disable(uint16_t index);
extern inline uint16_t gscmp_select_input(uint16_t index, uint16_t reg_cmp_input);
extern inline uint16_t gscmp_set_threshold(uint16_t index, uint16_t threshold_value);

extern inline uint16_t gscmp_module_power_up(void);
extern inline uint16_t gscmp_module_power_down(void);
extern inline uint16_t gscmp_channel_power_up(uint16_t index);
extern inline uint16_t gscmp_channel_power_down(uint16_t index);


#define DAC_VREF        DEVICE_VDD     // DAC reference voltage in [V]
#define DAC_RES_BIT     12    // DAC resolution in integer
#define DAC_RES         (pow(2, DAC_RES_BIT)-1)    // DAC resolution in integer
#define DAC_SCALER      (float)(((float)(DAC_RES))/((float)(DAC_VREF))) // DAC Scaling in ticks/V


/* Device-specific Defines */

#if defined (__P33SMPS_EP202__)
	#define GSCMP_DEVICE_COUNT		2
	#define GSCMP_DEVICE_REG_OFFSET	0x0002

#elif defined (__P33SMPS_EP502__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP504__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP505__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP506__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002

#elif defined (__P33SMPS_EP702__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP704__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP705__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP706__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP708__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP804__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP805__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP806__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002
#elif defined (__P33SMPS_EP808__)
	#define GSCMP_DEVICE_COUNT		4
	#define GSCMP_DEVICE_REG_OFFSET	0x0002

#else
	#error === selected device not supported ===
#endif


/*@@COMPARATOR CONTROL REGISTER (CMPCON) 
 * ------------------------------------------------------------------------------------------------
 * Summary:
 * CMPCONx: COMPARATOR CONTROL REGISTER 
 *
 * Description:
 * The following defines are listing full register bit fields for every bit setting as well
 * as single bit fields for direct addressing of certain peripheral features.
 * 
 * a) Full Register Bit Fields
 * 
 *    These defines are ORed together to create one parameter of a function call.
 *    e.g. gscmp_init( 0, REG_CMPSIDL_OFF | REG_DACOE_OFF | ... | REG_RANGE_HIGH );
 * 
 * b) Single Bit Fields
 * 
 *    These defines are providing a more readable way of using direct addressing.
 *    e.g. CMPDAC1bits.CMPON = CMPON_ON;
 * 
 * -----------------------------------------------------------------------------------------------*/
#if defined (__P33SMPS_EP__)

    #define CMPCON_ORIGIN               CMP1CON     // first comparator configuration register location
    #define CMPDAC_ORIGIN               CMP1DAC     // first comparator DAC register location
    #define LEB_PERIOD_MASK				0x007F      // Leading Edge Blanking max value bit mask
    #define LEBCON_RESET				0x0000      // Leading Edge Blanking register reset value

#endif


#define REG_CMPCON_VALID_DATA_MSK       0b1011111111111111
#define REG_CMPCON_HSACMP_OFF_MASK      0b0111111111111111
#define REG_CMPDAC_VALID_DATA_MSK       0b0000111111111111

#define REG_CMPON_ON					0b1000000000000000		// Bit 15
#define REG_CMPON_OFF					0b0000000000000000
#define REG_CMPON_CLR_MASK				0b0111111111111111

#define REG_CMPSIDL_ON					0b0010000000000000		// Bit 13
#define REG_CMPSIDL_OFF					0b0000000000000000

#define REG_HYSSEL_20MV					0b0001100000000000		// Bit 12-11
#define REG_HYSSEL_10MV					0b0001000000000000
#define REG_HYSSEL_5MV					0b0000100000000000
#define REG_HYSSEL_NONE					0b0000000000000000
#define REG_HYSSEL_CLR_MASK				0b1110011111111111

#define REG_FLTREN_ON					0b0000010000000000		// Bit 10
#define REG_FLTREN_OFF					0b0000000000000000

#define REG_FCLKSEL_PWMCLK				0b0000001000000000		// Bit 9
#define REG_FCLKSEL_SYSCLK				0b0000000000000000

#define REG_DACOE_ON					0b0000000100000000		// Bit 8
#define REG_DACOE_OFF					0b0000000000000000

#define REG_INSEL_CMPxA					0b0000000000000000		// Bit 7-6
#define REG_INSEL_CMPxB					0b0000000001000000
#define REG_INSEL_CMPxC					0b0000000010000000
#define REG_INSEL_CMPxD					0b0000000011000000
#define REG_INSEL_ALT_PGA2				0b0000000001000000
#define REG_INSEL_ALT_PGA1				0b0000000000000000
#define REG_INSEL_CLR_MASK				0b1111111100111111
#define REG_INSEL_SET_MASK				0b0000000011000000

#define REG_EXTREF_ENABLED				0b0000000000100000		// Bit 5
#define REG_EXTREF_DISABLED				0b0000000000000000

#define REG_HYSPOL_FALLING_EDGE			0b0000000000010000		// Bit 4
#define REG_HYSPOL_RISING_EDGE			0b0000000000000000

#define REG_CMPSTAT_HIGH				0b0000000000001000		// Bit 3 - READ ONLY
#define REG_CMPSTAT_LOW					0b0000000000000000

#define REG_ALTINP_ALTERNATE			0b0000000000000100		// Bit 2
#define REG_ALTINP_DEFAULT				0b0000000000000000		

#define REG_CMPPOL_INVERTED				0b0000000000000010		// Bit 1
#define REG_CMPPOL_NON_INVERTED			0b0000000000000000

#if defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

	#define REG_RANGE_HIGH				0b0000000000000001		// Bit0

#endif

// Single Register Bit Fields

#define CMPON_ON						0b1
#define CMPON_OFF						0b0

#define CMPSIDL_ON						0b1
#define CMPSIDL_OFF						0b0

#define HYSSEL_45MV						0b11					// Bit 12-11
#define HYSSEL_30MV						0b10
#define HYSSEL_15MV						0b01
#define HYSSEL_NONE						0b00

#define FLTREN_ON						0b1						// Bit 10
#define FLTREN_OFF						0b0

#define FCLKSEL_PWMCLK					0b1						// Bit 9
#define FCLKSEL_SYSCLK					0b0

#define DACOE_ON						0b1						// Bit 8
#define DACOE_OFF						0b0

#define INSEL_CMPxA						0b00					// Bit 7-6
#define INSEL_CMPxB						0b01
#define INSEL_CMPxC						0b10
#define INSEL_CMPxD						0b11
#define INSEL_ALT_PGA2					0b01
#define INSEL_ALT_PGA1					0b00

#define EXTREF_ENABLED					0b1						// Bit 5
#define EXTREF_DISABLED					0b0

#define HYSPOL_FALLING_EDGE				0b1						// Bit 4
#define HYSPOL_RISING_EDGE				0b0

#define CMPSTAT_HIGH					0b1						// Bit 3
#define CMPSTAT_LOW						0b0

#define ALTINP_ALTERNATE				0b1						// Bit 2
#define ALTINP_DEFAULT					0b0	

#define CMPPOL_INVERTED					0b1						// Bit 1
#define CMPPOL_NON_INVERTED				0b0

#if defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

	#define RANGE_HIGH					0b1						// Bit 0

#endif

#endif  // EOF __P33EGS_HSACMP_H__
