/*LICENSE *********************************************************************
 * 
 * Software License Agreement
 *
 * Copyright © 2015 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
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

#ifndef _1PH_CONVERTER_DEFINITIONS_H_
#define _1PH_CONVERTER_DEFINITIONS_H_

#include <stdint.h>

#include "hal.h"
#include "npnz16b.h"

/*@@syscfg_cvrt.h
 * ************************************************************************************************
 * Summary:
 * Set of user defines and declarations for the DC/DC converter
 *
 * Description:
 * A single or multiphase phase converter is used to generate a specific output voltage. 
 * This file declares data structures, defines and variables used to control the output voltage and 
 * providing additional information about status and operating conditions.
 * ***********************************************************************************************/

/*@@CONVERTER_t
 * ************************************************************************************************
 * Summary:
 * Four phase converter data structures
 *
 * Description:
 * A single or multiphase phase converter is used to generate a specific output voltage. 
 * CONVERTER_t merges other data structures to provide bundled access to operating conditions
 * and essential settings.
 * ***********************************************************************************************/

/* status items data structure to monitor a power converter */

typedef struct {
    volatile unsigned flt_otw : 1; // Bit 0: over temperature protection fault
    volatile unsigned flt_otp : 1; // Bit 1: over temperature protection fault
    volatile unsigned flt_ovp : 1; // Bit 2: output over voltage protection fault
    volatile unsigned flt_uvlo : 1; // Bit 3: input under voltage lock out fault
    volatile unsigned flt_ovlo : 1; // Bit 4: input over voltage lock out fault
    volatile unsigned flt_ocp : 1; // Bit 5: over current protection fault
    volatile unsigned flt_ssf : 1; // Bit 6: soft-start failure 
    volatile unsigned : 1; // Bit 7: reserved
    volatile unsigned : 1; // Bit 8: reserved
    volatile unsigned : 1; // Bit 9: reserved
    volatile unsigned : 1; // Bit 10: reserved
    volatile unsigned : 1; // Bit 11: reserved
    volatile unsigned : 1; // Bit 12: reserved
    volatile unsigned : 1; // Bit 13: reserved
    volatile unsigned : 1; // Bit 14: reserved
    volatile unsigned enable : 1; // Bit 15: reserved
} __attribute__((packed))CONVERTER_STATUS_BIT_FIELD_t;

typedef union {
    volatile CONVERTER_STATUS_BIT_FIELD_t flag;
    volatile uint16_t flags;
} __attribute__((packed))CONVERTER_STATUS_t;

/* converter data structure */

typedef struct {
    
    volatile uint16_t* input_voltage; // Recent Input Voltage
    volatile uint16_t* output_voltage; // Recent Output Voltage measured at phase #1
    volatile int16_t   average_current; // Total average converter output current (bi-directional)
    volatile uint16_t* phase_current1; // Inductor current phase #1
    volatile uint16_t* switching_period; // Recent switching period (= 1/fsw)
    volatile uint16_t* duty_cycle1; // Recent duty cycle register phase #1
    
    volatile uint16_t  phase_hwcl1; // Inductor current limitation phase #1

    volatile uint16_t  voltage_reference; // Voltage Loop Reference
    volatile uint16_t  current_reference; // Phase current reference
    
}CONVERTER_SETTINGS_t;


typedef struct {

    // Default 2P2Z/3P3Z/4P4Z/5P5Z compensator data structure
    volatile cNPNZ16b_t* compensator;    // Add a generic nPnZ compensator structure with clamping
    
} __attribute__((packed)) VOLTAGE_LOOP_SETTINGS_t;

typedef struct {    
    
    // Generic status information
    volatile CONVERTER_STATUS_t status; // Converter Stage Status Code

    // Hardware-specific converter settings and properties
    volatile CONVERTER_SETTINGS_t converter; // Generic converter settings
    
    // Controller and Converter Objects
    volatile VOLTAGE_LOOP_SETTINGS_t c_vmc;        // Declare a NPNZ_t Data Structure for the outer voltage loop

}__attribute__((packed))CONVERTER_t;
//} CONVERTER_t;


#endif
// EOF _4PH_CONVERTER_DEFINITIONS_H_
