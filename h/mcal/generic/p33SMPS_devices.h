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
    
    #define _P33SMPS_YGAR_    1

#elif defined (__dsPIC33FJ32GS406__) || defined (__dsPIC33FJ64GS406__) || \
      defined (__dsPIC33FJ32GS606__) || defined (__dsPIC33FJ64GS606__) || \
      defined (__dsPIC33FJ32GS608__) || defined (__dsPIC33FJ64GS608__) || \
	  defined (__dsPIC33FJ32GS610__) || defined (__dsPIC33FJ64GS610__)
// UEAA family of devices

    #define _P33SMPS_UEAA_    2

#elif defined (__dsPIC33FJ06GS001__) || defined (__dsPIC33FJ06GS101A__) || \
	  defined (__dsPIC33FJ06GS102A__) || defined (__dsPIC33FJ16GS202A__) || \
	  defined (__dsPIC33FJ09GS302__) 
// UEAG family of devices

    #define _P33SMPS_UEAG_    3

#elif defined (__dsPIC33EP16GS202__) || defined (__dsPIC33EP32GS202__)
// TLAL family of devices

    #define _P33SMPS_TLAL_    4

#elif defined (__dsPIC33EP16GS502__) || defined (__dsPIC33EP32GS502__) || defined (__dsPIC33EP64GS502__) || \
      defined (__dsPIC33EP16GS504__) || defined (__dsPIC33EP32GS504__) || defined (__dsPIC33EP64GS504__) || \
      defined (__dsPIC33EP16GS505__) || defined (__dsPIC33EP32GS505__) || defined (__dsPIC33EP64GS505__) || \
      defined (__dsPIC33EP16GS506__) || defined (__dsPIC33EP32GS506__) || defined (__dsPIC33EP64GS506__)
// TLAH family of devices

    #define _P33SMPS_TLAH_    5

#elif defined (__dsPIC33EP128GS702__) || defined (__dsPIC33EP128GS704__) || defined (__dsPIC33EP128GS705__) || \
      defined (__dsPIC33EP128GS706__) || defined (__dsPIC33EP64GS708__) || defined (__dsPIC33EP128GS708__) || \
      defined (__dsPIC33EP64GS804__) || defined (__dsPIC33EP128GS804__) || defined (__dsPIC33EP64GS805__) || \
      defined (__dsPIC33EP128GS805__) || defined (__dsPIC33EP64GS806__) || defined (__dsPIC33EP128GS806__) || \
      defined (__dsPIC33EP64GS808__) || defined (__dsPIC33EP128GS808__)
// TLAY family of devices

    #define _P33SMPS_TLAY_    6

#elif defined (__dsPIC33CH64MP202__) || defined (__dsPIC33CH128MP202__) || \
      defined (__dsPIC33CH64MP203__) || defined (__dsPIC33CH128MP203__) || \
      defined (__dsPIC33CH64MP204__) || defined (__dsPIC33CH128MP204__) || \
      defined (__dsPIC33CH64MP206__) || defined (__dsPIC33CH128MP206__) || \
      defined (__dsPIC33CH64MP208__) || defined (__dsPIC33CH128MP208__)
// Gemini family of devices

    #define _P33SMPS_WACA_    7

#elif defined (__dsPIC33CH64MP502__) || defined (__dsPIC33CH128MP502__) || \
      defined (__dsPIC33CH64MP504__) || defined (__dsPIC33CH128MP504__) || \
      defined (__dsPIC33CH64MP505__) || defined (__dsPIC33CH128MP505__) || \
      defined (__dsPIC33CH64MP506__) || defined (__dsPIC33CH128MP506__) || \
      defined (__dsPIC33CH64MP508__) || defined (__dsPIC33CH128MP508__)
// Gemini family of devices with CAN FD

    #define _P33SMPS_WACS_    8

#else

 #error === selected device not supported by peripheral driver libraries ===

#endif


#if defined (__dsPIC33EP16GS202__) || defined (__dsPIC33EP32GS202__)
    #define _P33SMPS_TLAL2_
#elif defined (__dsPIC33EP16GS502__) || defined (__dsPIC33EP32GS502__) || defined (__dsPIC33EP64GS502__) 
    #define _P33SMPS_TLAH2_
#elif defined (__dsPIC33EP16GS504__) || defined (__dsPIC33EP32GS504__) || defined (__dsPIC33EP64GS504__) 
    #define _P33SMPS_TLAH4_
#elif defined (__dsPIC33EP16GS505__) || defined (__dsPIC33EP32GS505__) || defined (__dsPIC33EP64GS505__)
    #define _P33SMPS_TLAH5_
#elif defined (__dsPIC33EP16GS506__) || defined (__dsPIC33EP32GS506__) || defined (__dsPIC33EP64GS506__)
    #define _P33SMPS_TLAH6_
#elif defined (__dsPIC33EP128GS702__) 
    #define _P33SMPS_TLAY2_
#elif defined (__dsPIC33EP128GS704__) || defined (__dsPIC33EP64GS804__) || defined (__dsPIC33EP128GS804__)
    #define _P33SMPS_TLAY4_
#elif defined (__dsPIC33EP128GS705__) || defined (__dsPIC33EP64GS805__) || defined (__dsPIC33EP128GS805__)
    #define _P33SMPS_TLAY5_
#elif defined (__dsPIC33EP128GS706__) || defined (__dsPIC33EP64GS806__) || defined (__dsPIC33EP128GS806__)
    #define _P33SMPS_TLAY6_
#elif defined (__dsPIC33EP64GS708__) || defined (__dsPIC33EP128GS708__) || defined (__dsPIC33EP64GS808__) || defined (__dsPIC33EP128GS808__)
    #define _P33SMPS_TLAY8_
#elif defined (__dsPIC33CH64GS202__)  || defined (__dsPIC33CH128MP202__) || defined (__dsPIC33CH64GS502__)  || defined (__dsPIC33CH128MP502__)
    #define _P33SMPS_WACA2_
#elif defined (__dsPIC33CH64GS203__)  || defined (__dsPIC33CH128MP203__) || (__dsPIC33CH64GS503__)  || defined (__dsPIC33CH128MP503__)
    #define _P33SMPS_WACA3_
#elif defined (__dsPIC33CH64GS204__)  || defined (__dsPIC33CH128MP204__) || (__dsPIC33CH64GS504__)  || defined (__dsPIC33CH128MP504__)
    #define _P33SMPS_WACA4_
#elif defined (__dsPIC33CH64GS206__)  || defined (__dsPIC33CH128MP206__) || (__dsPIC33CH64GS506__)  || defined (__dsPIC33CH128MP506__)
    #define _P33SMPS_WACA6_
#elif defined (__dsPIC33CH64GS208__)  || defined (__dsPIC33CH128MP208__) || (__dsPIC33CH64GS508__)  || defined (__dsPIC33CH128MP508__)
    #define _P33SMPS_WACA8_
#endif



#endif	/* MCAL_P33_SMPS_DEVICE_DEFINITION_H */

