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

#ifndef _P33EGS_DSP_H_
#define _P33EGS_DSP_H_

#include "p33SMPS_devices.h"

/*@@p33GS_dsp.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33FxxGS-DSP SFRs
 *
 * Description:
 * The embedded Digital Signal Processor offers some configuration options. This additional
 * header file contains defines for all required bit-settings of all related registers.
 * This file is an additional header file on top of the generic device header file.
 * ***********************************************************************************************/

// Prototypes

extern inline uint16_t gsdsp_init_dsp(uint16_t regCORCON);

// Global Flags and bit-masks

#if   defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJA__) ||  defined (__P33SMPS_FJC__)

  #define REG_CORCON_UNUSED_MSK         0b1110000000000000
  #define REG_CORCON_WRITE_MSK			0b0001100011110111

#elif defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)

  #define REG_CORCON_UNUSED_MSK         0b0100000000000000
  #define REG_CORCON_WRITE_MSK			0b1011100011110011

#elif defined (__P33SMPS_CH2__) || defined (__P33SMPS_CH5__)

#endif

// CORCON: CORE CONTROL REGISTER

#if defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)

  #define REG_CORCON_VAR_VARIABLE       0b1000000000000000
  #define REG_CORCON_VAR_FIXED          0b0000000000000000

  #define REG_CORCON_US_MIXED 			0b0010000000000000

#endif

#define REG_CORCON_US_UNSIGNED			0b0001000000000000
#define REG_CORCON_US_SIGNED			0b0000000000000000

#define REG_CORCON_EDT_ON				0b0000100000000000
#define REG_CORCON_EDT_OFF				0b0000000000000000

#define REG_CORCON_STAT_DL_7			0b0000011100000000
#define REG_CORCON_STAT_DL_6			0b0000011000000000
#define REG_CORCON_STAT_DL_5			0b0000010100000000
#define REG_CORCON_STAT_DL_4			0b0000010000000000
#define REG_CORCON_STAT_DL_3			0b0000001100000000
#define REG_CORCON_STAT_DL_2			0b0000001000000000
#define REG_CORCON_STAT_DL_1			0b0000000100000000
#define REG_CORCON_STAT_DL_0			0b0000000000000000

#define REG_CORCON_SATA_ON				0b0000000010000000
#define REG_CORCON_SATA_OFF				0b0000000000000000

#define REG_CORCON_SATB_ON				0b0000000001000000
#define REG_CORCON_SATB_OFF				0b0000000000000000

#define REG_CORCON_SATDW_ON				0b0000000000100000
#define REG_CORCON_SATDW_OFF			0b0000000000000000

#define REG_CORCON_ACCSAT_931			0b0000000000010000
#define REG_CORCON_ACCSAT_131			0b0000000000000000

#define REG_CORCON_STAT_IPL3_GT7		0b0000000000001000
#define REG_CORCON_STAT_IPL3_LT7		0b0000000000000000

#if   defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJA__) ||  defined (__P33SMPS_FJC__)

  #define REG_CORCON_PSV_ON				0b0000000000000100
  #define REG_CORCON_PSV_OFF			0b0000000000000000

#elif defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)

  #define REG_CORCON_SFA_ACTIVE			0b0000000000000100
  #define REG_CORCON_SFA_INACTIVE		0b0000000000000000

#endif

#define REG_CORCON_RND_BIASED			0b0000000000000010
#define REG_CORCON_RND_UNBIASED			0b0000000000000000

#define REG_CORCON_IF_INTEGER			0b0000000000000001
#define REG_CORCON_IF_FRACTIONAL		0b0000000000000000


#endif

