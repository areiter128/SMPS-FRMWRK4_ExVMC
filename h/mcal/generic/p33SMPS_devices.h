/*LICENSE ********************************************************************
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
 * ***************************************************************************/
/* @@p33SMPS_devices.h
 * ****************************************************************************
 * File:   p33SMPS_devices.h
 * Author: M91406
 * Comments: Additional defines to identify the selected device to simplify device switch selections 
 * Revision history: 
 *  06/28/17    Initial release covering YGAR, UEAA, UEAG, TLAL and TLAH
 *  02/26/17    added TLAY devices
 *  08/29/17    added WACS
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MCAL_P33_SMPS_DEVICE_DEFINITION_H
#define	MCAL_P33_SMPS_DEVICE_DEFINITION_H

#include <xc.h> // include processor files - each processor file is guarded.  

#if defined (__dsPIC33FJ06GS101__) || defined (__dsPIC33FJ06GS102__) || \
	defined (__dsPIC33FJ06GS202__) || defined (__dsPIC33FJ16GS402__) || \
	defined (__dsPIC33FJ16GS404__) || defined (__dsPIC33FJ16GS502__) || \
	defined (__dsPIC33FJ16GS504__)
// YGAR family of devices
    
    #define __P33SMPS_FJ__

#elif defined (__dsPIC33FJ32GS406__) || defined (__dsPIC33FJ64GS406__) || \
      defined (__dsPIC33FJ32GS606__) || defined (__dsPIC33FJ64GS606__) || \
      defined (__dsPIC33FJ32GS608__) || defined (__dsPIC33FJ64GS608__) || \
	  defined (__dsPIC33FJ32GS610__) || defined (__dsPIC33FJ64GS610__)
// UEAA family of devices

    #define __P33SMPS_FJC__

#elif defined (__dsPIC33FJ06GS001__) || defined (__dsPIC33FJ06GS101A__) || \
	  defined (__dsPIC33FJ06GS102A__) || defined (__dsPIC33FJ16GS202A__) || \
	  defined (__dsPIC33FJ09GS302__) 
// UEAG family of devices

    #define __P33SMPS_FJA__

#elif defined (__dsPIC33EP16GS202__) || defined (__dsPIC33EP32GS202__)
// TLAL family of devices

    #define __P33SMPS_EP__
    #define __P33SMPS_EP2__

#elif defined (__dsPIC33EP16GS502__) || defined (__dsPIC33EP32GS502__) || defined (__dsPIC33EP64GS502__) || \
      defined (__dsPIC33EP16GS504__) || defined (__dsPIC33EP32GS504__) || defined (__dsPIC33EP64GS504__) || \
      defined (__dsPIC33EP16GS505__) || defined (__dsPIC33EP32GS505__) || defined (__dsPIC33EP64GS505__) || \
      defined (__dsPIC33EP16GS506__) || defined (__dsPIC33EP32GS506__) || defined (__dsPIC33EP64GS506__)
// TLAH family of devices

    #define __P33SMPS_EP__
    #define __P33SMPS_EP5__

#elif defined (__dsPIC33EP128GS702__) || defined (__dsPIC33EP128GS704__) || defined (__dsPIC33EP128GS705__) || \
      defined (__dsPIC33EP128GS706__) || defined (__dsPIC33EP64GS708__) || defined (__dsPIC33EP128GS708__) || \
      defined (__dsPIC33EP64GS804__) || defined (__dsPIC33EP128GS804__) || defined (__dsPIC33EP64GS805__) || \
      defined (__dsPIC33EP128GS805__) || defined (__dsPIC33EP64GS806__) || defined (__dsPIC33EP128GS806__) || \
      defined (__dsPIC33EP64GS808__) || defined (__dsPIC33EP128GS808__)
// TLAY family of devices

    #define __P33SMPS_EP__
    #define __P33SMPS_EP7__
    #define __P33SMPS_EP8__

#elif defined (__dsPIC33CH64MP202__) || defined (__dsPIC33CH128MP202__) || \
      defined (__dsPIC33CH64MP203__) || defined (__dsPIC33CH128MP203__) || \
      defined (__dsPIC33CH64MP204__) || defined (__dsPIC33CH128MP204__) || \
      defined (__dsPIC33CH64MP206__) || defined (__dsPIC33CH128MP206__) || \
      defined (__dsPIC33CH64MP208__) || defined (__dsPIC33CH128MP208__)
// Gemini family of devices 

    #define __P33SMPS_CH__
    #define __P33SMPS_CH2__

#elif defined (__dsPIC33CH64MP502__) || defined (__dsPIC33CH128MP502__) || \
      defined (__dsPIC33CH64MP504__) || defined (__dsPIC33CH128MP504__) || \
      defined (__dsPIC33CH64MP505__) || defined (__dsPIC33CH128MP505__) || \
      defined (__dsPIC33CH64MP506__) || defined (__dsPIC33CH128MP506__) || \
      defined (__dsPIC33CH64MP508__) || defined (__dsPIC33CH128MP508__)
// Gemini family of devices with CAN FD

    #define __P33SMPS_CH__
    #define __P33SMPS_CH5__

#elif defined (__dsPIC33CK32MP502__) || defined (__dsPIC33CK64MP502__) || defined (__dsPIC33CK128MP502__) || defined (__dsPIC33CK256MP502__) || \
      defined (__dsPIC33CK32MP503__) || defined (__dsPIC33CK64MP503__) || defined (__dsPIC33CK128MP503__) || defined (__dsPIC33CK256MP503__) || \
      defined (__dsPIC33CK32MP505__) || defined (__dsPIC33CK64MP505__) || defined (__dsPIC33CK128MP505__) || defined (__dsPIC33CK256MP505__) || \
      defined (__dsPIC33CK32MP506__) || defined (__dsPIC33CK64MP506__) || defined (__dsPIC33CK128MP506__) || defined (__dsPIC33CK256MP506__) || \
      defined (__dsPIC33CK64MP508__) || defined (__dsPIC33CK128MP508__) || defined (__dsPIC33CK256MP508__)
// Sagitta family of devices with CAN FD

    #define __P33SMPS_CK__
    #define __P33SMPS_CK5__

#else

 #error === selected device not supported by peripheral driver libraries ===

#endif

#if defined (__dsPIC33FJ06GS101__) 
    #define __P33SMPS_FJ101__
#elif defined (__dsPIC33FJ06GS102__) 
    #define __P33SMPS_FJ102__
#elif defined (__dsPIC33FJ06GS202__) 
    #define __P33SMPS_FJ202__
#elif defined (__dsPIC33FJ16GS402__) 
    #define __P33SMPS_FJ402__
#elif defined (__dsPIC33FJ16GS404__) 
    #define __P33SMPS_FJ404__
#elif defined (__dsPIC33FJ16GS502__) 
    #define __P33SMPS_FJ502__
#elif defined (__dsPIC33FJ16GS504__)
    #define __P33SMPS_FJ504__

#elif defined (__dsPIC33FJ06GS001__) 
    #define __P33SMPS_FJA001__
#elif defined (__dsPIC33FJ06GS101A__) 
    #define __P33SMPS_FJA101__
#elif defined (__dsPIC33FJ06GS102A__)
    #define __P33SMPS_FJA102__
#elif defined (__dsPIC33FJ16GS202A__) 
    #define __P33SMPS_FJA202__
#elif defined (__dsPIC33FJ09GS302__) 
    #define __P33SMPS_FJA302__

#elif defined (__dsPIC33FJ32GS406__) || defined (__dsPIC33FJ64GS406__)
    #define __P33SMPS_FJ406__
#elif defined (__dsPIC33FJ32GS606__) || defined (__dsPIC33FJ64GS606__)
    #define __P33SMPS_FJ606__
#elif defined (__dsPIC33FJ32GS608__) || defined (__dsPIC33FJ64GS608__)
    #define __P33SMPS_FJ608__
#elif defined (__dsPIC33FJ32GS610__) || defined (__dsPIC33FJ64GS610__)
    #define __P33SMPS_FJ610__

#elif defined (__dsPIC33EP16GS202__) || defined (__dsPIC33EP32GS202__)
    #define __P33SMPS_EP202__
#elif defined (__dsPIC33EP16GS502__) || defined (__dsPIC33EP32GS502__) || defined (__dsPIC33EP64GS502__) 
    #define __P33SMPS_EP502__
#elif defined (__dsPIC33EP16GS504__) || defined (__dsPIC33EP32GS504__) || defined (__dsPIC33EP64GS504__) 
    #define __P33SMPS_EP504__
#elif defined (__dsPIC33EP16GS505__) || defined (__dsPIC33EP32GS505__) || defined (__dsPIC33EP64GS505__)
    #define __P33SMPS_EP505__
#elif defined (__dsPIC33EP16GS506__) || defined (__dsPIC33EP32GS506__) || defined (__dsPIC33EP64GS506__)
    #define __P33SMPS_EP506__

#elif defined (__dsPIC33EP128GS702__) 
    #define __P33SMPS_EP702__
#elif defined (__dsPIC33EP128GS704__) 
    #define __P33SMPS_EP704__
#elif defined (__dsPIC33EP128GS705__) 
    #define __P33SMPS_EP705__
#elif defined (__dsPIC33EP128GS706__) 
    #define __P33SMPS_EP706__
#elif defined (__dsPIC33EP64GS708__) || defined (__dsPIC33EP128GS708__) 
    #define __P33SMPS_EP708__

#elif defined (__dsPIC33EP64GS804__) || defined (__dsPIC33EP128GS804__)
    #define __P33SMPS_EP804__
#elif defined (__dsPIC33EP64GS805__) || defined (__dsPIC33EP128GS805__)
    #define __P33SMPS_EP805__
#elif defined (__dsPIC33EP64GS806__) || defined (__dsPIC33EP128GS806__)
    #define __P33SMPS_EP806__
#elif defined (__dsPIC33EP64GS808__) || defined (__dsPIC33EP128GS808__)
    #define __P33SMPS_EP808__

#elif defined (__dsPIC33CH64MP202__)  || defined (__dsPIC33CH128MP202__)
    #define __P33SMPS_CH202__
#elif defined (__dsPIC33CH64MP203__)  || defined (__dsPIC33CH128MP203__)
    #define __P33SMPS_CH203__
#elif defined (__dsPIC33CH64MP204__)  || defined (__dsPIC33CH128MP204__)
    #define __P33SMPS_CH204__
#elif defined (__dsPIC33CH64MP206__)  || defined (__dsPIC33CH128MP206__)
    #define __P33SMPS_CH206__
#elif defined (__dsPIC33CH64MP208__)  || defined (__dsPIC33CH128MP208__)
    #define __P33SMPS_CH208__

#elif defined (__dsPIC33CH64MP502__)  || defined (__dsPIC33CH128MP502__)
    #define __P33SMPS_CH502__
#elif defined (__dsPIC33CH64MP503__)  || defined (__dsPIC33CH128MP503__)
    #define __P33SMPS_CH503__
#elif defined (__dsPIC33CH64MP504__)  || defined (__dsPIC33CH128MP504__)
    #define __P33SMPS_CH504__
#elif defined (__dsPIC33CH64MP506__)  || defined (__dsPIC33CH128MP506__)
    #define __P33SMPS_CH506__
#elif defined (__dsPIC33CH64MP508__)  || defined (__dsPIC33CH128MP508__)
    #define __P33SMPS_CH508__

#elif defined (__dsPIC33CK32MP502__) || defined (__dsPIC33CK64MP502__) || defined (__dsPIC33CK128MP502__) || defined (__dsPIC33CK256MP502__)
    #define __P33SMPS_CK502__
#elif defined (__dsPIC33CK32MP503__) || defined (__dsPIC33CK64MP503__) || defined (__dsPIC33CK128MP503__) || defined (__dsPIC33CK256MP503__)
    #define __P33SMPS_CK503__
#elif defined (__dsPIC33CK32MP505__) || defined (__dsPIC33CK64MP505__) || defined (__dsPIC33CK128MP505__) || defined (__dsPIC33CK256MP505__)
    #define __P33SMPS_CK505__
#elif defined (__dsPIC33CK32MP506__) || defined (__dsPIC33CK64MP506__) || defined (__dsPIC33CK128MP506__) || defined (__dsPIC33CK256MP506__)
    #define __P33SMPS_CK506__
#elif defined (__dsPIC33CK64MP508__) || defined (__dsPIC33CK128MP508__) || defined (__dsPIC33CK256MP508__)
    #define __P33SMPS_CK508__
#else
    #error === selected device not supported by peripheral driver libraries ===
#endif



#endif	/* MCAL_P33_SMPS_DEVICE_DEFINITION_H */

