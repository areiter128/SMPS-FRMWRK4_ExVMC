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
 */

/* 
 * File:        00124_R10_EP806_pinmap.h
 * Author:      M91406
 * Comments:    Hardware abstraction layer for dsPIC33EP128GS806 daughter card version 0.2
 * Revision history: 1.0    (initial release)
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _00124_R10_EP806_PINMAP_H
#define	_00124_R10_EP806_PINMAP_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

// Generic defines
#ifndef PINDIR_INPUT
#define PINDIR_INPUT    1
#endif
#ifndef PINDIR_OUTPUT
#define PINDIR_OUTPUT   0
#endif
#ifndef PINSTATE_HIGH
#define PINSTATE_HIGH   1
#endif
#ifndef PINSTATE_LOW
#define PINSTATE_LOW    0
#endif

#ifndef LED_ON
  #define LED_ON        0
#endif
#ifndef LED_OFF
  #define LED_OFF       1    
#endif
#ifndef LED_OUTPUT
  #define LED_OUTPUT    0
#endif
#ifndef LED_INPUT
  #define LED_INPUT     1
#endif

// On-Board peripherals
#define DBGLED1_TRIS    TRISCbits.TRISC14
#define DBGLED1_WR      LATCbits.LATC14
#define DBGLED1_RD      PORTCbits.RC14
#define DBGLED1_INIT    {DBGLED1_WR = LED_OFF; DBGLED1_TRIS = 0;}

// Header Test Points

#define	TP03_TRIS   TRISDbits.TRISD13
#define	TP03_WR     LATDbits.LATD13
#define	TP03_RD     PORTDbits.RD13

#define	TP04_TRIS   TRISDbits.TRISD7
#define	TP04_WR     LATDbits.LATD7
#define	TP04_RD     PORTDbits.RD7

#define	TP05_TRIS   TRISCbits.TRISC10
#define	TP05_WR     LATCbits.LATC10
#define	TP05_RD     PORTCbits.RC10

#define	TP06_TRIS   TRISAbits.TRISA2
#define	TP06_WR     LATAbits.LATA2
#define	TP06_RD     PORTAbits.RA2

#define	TP07_TRIS   TRISBbits.TRISB3
#define	TP07_WR     LATBbits.LATB3
#define	TP07_RD     PORTBbits.RB3

#define	TP08_TRIS       TRISCbits.TRISC2
#define	TP08_WR         LATCbits.LATC2
#define	TP08_RD         PORTCbits.LATC2

#define	TP09_TRIS       TRISCbits.TRISC9
#define	TP09_WR         LATCbits.LATC9
#define	TP09_RD         PORTCbits.RC9

#define TP10_ADC_IN     3
#define TP10_ADC_CORE   3
#define TP10_ADC_BUFFER ADCBUF3
#define TP10_ANSEL      ANSELBbits.ANSB3
#define TP10_IF         _ADCAN3IF
#define TP10_IE         _ADCAN3IE
#define TP10_IP         _ADCAN3IP

#define	TP10_TRIS       TRISBbits.TRISB3
#define	TP10_WR         LATBbits.LATB3
#define	TP10_RD         PORTBbits.RB3

#define	TP11_TRIS       TRISDbits.TRISD2
#define	TP11_WR         LATDbits.LATD2
#define	TP11_RD         PORTDbits.RD2

#define TP12_ADC_IN     0
#define TP12_ADC_CORE   0
#define TP12_ADC_BUFFER ADCBUF0
#define TP12_ANSEL      ANSELAbits.ANSA0
#define TP12_IF         _ADCAN0IF
#define TP12_IE         _ADCAN0IE
#define TP12_IP         _ADCAN0IP

#define	TP12_TRIS       TRISAbits.TRISA0
#define	TP12_WR         LATAbits.LATA0
#define	TP12_RD         PORTAbits.RA0

/* not connected 
#define	TP13_TRIS   
#define	TP13_WR
#define	TP13_RD
   not connected */

#define TP14_ADC_IN     1
#define TP14_ADC_CORE   1
#define TP14_ADC_BUFFER ADCBUF1
#define TP14_ANSEL      ANSELAbits.ANSA1
#define TP14_IF         _ADCAN1IF
#define TP14_IE         _ADCAN1IE
#define TP14_IP         _ADCAN1IP

#define	TP14_TRIS       TRISAbits.TRISA1
#define	TP14_WR         LATAbits.LATA1
#define	TP14_RD         PORTAbits.RA1

/* not connected 
#define	TP15_TRIS
#define	TP15_WR
#define	TP15_RD
   not connected */

#define	TP16_TRIS
#define	TP16_WR
#define	TP16_RD

#define	TP17_TRIS
#define	TP17_WR
#define	TP17_RD

#define TP18_ADC_IN     4
#define TP18_ADC_CORE   4
#define TP18_ADC_BUFFER ADCBUF4
#define TP18_ANSEL      ANSELBbits.ANSB9
#define TP18_IF         _ADCAN4IF
#define TP18_IE         _ADCAN4IE
#define TP18_IP         _ADCAN4IP

#define TP18_CMPxIN     

#define	TP18_TRIS       TRISBbits.TRISB9
#define	TP18_WR         LATBbits.LATB9
#define	TP18_RD         PORTBbits.RB9

/* not connected 
#define	TP19_TRIS
#define	TP19_WR
#define	TP19_RD
   not connected */

#define	TP20_TRIS       
#define	TP20_WR
#define	TP20_RD

// Loop Test Points
#define	TP24_TRIS
#define	TP24_WR
#define	TP24_RD

#define	TP25_TRIS
#define	TP25_WR
#define	TP25_RD

#define	TP26_TRIS
#define	TP26_WR
#define	TP26_RD

#define	TP27_TRIS   TRISCbits.TRISC5
#define	TP27_WR     LATCbits.LATC5
#define	TP27_RD     PORTCbits.RC5

#define	TP28_TRIS
#define	TP28_WR
#define	TP28_RD

/* not connected 
#define	TP29_TRIS
#define	TP29_WR
#define	TP29_RD
   not connected */

/* not connected 
#define	TP30_TRIS
#define	TP30_WR
#define	TP30_RD
   not connected */

#define	TP31_TRIS
#define	TP31_WR
#define	TP31_RD

#define	TP32_TRIS
#define	TP32_WR
#define	TP32_RD

#define	TP33_TRIS
#define	TP33_WR
#define	TP33_RD

#define	TP34_TRIS
#define	TP34_WR
#define	TP34_RD

#define	TP35_TRIS
#define	TP35_WR
#define	TP35_RD

#define	TP36_TRIS
#define	TP36_WR
#define	TP36_RD

#define	TP37_TRIS
#define	TP37_WR
#define	TP37_RD

#define	TP38_TRIS
#define	TP38_WR
#define	TP38_RD

#define	TP39_TRIS   TRISBbits.TRISB5
#define	TP39_WR     LATBbits.LATB5
#define	TP39_RD     PORTBbits.RB5

#define	TP40_TRIS
#define	TP40_WR
#define	TP40_RD

#define	TP41_TRIS
#define	TP41_WR
#define	TP41_RD

#define	TP42_TRIS
#define	TP42_WR
#define	TP42_RD

#define	TP43_TRIS
#define	TP43_WR
#define	TP43_RD

#define	TP44_TRIS
#define	TP44_WR
#define	TP44_RD

#define	TP45_TRIS   TRISAbits.TRISA4
#define	TP45_WR     LATAbits.LATA4
#define	TP45_RD     PORTAbits.RA4

#define	TP46_TRIS
#define	TP46_WR
#define	TP46_RD

#define	TP47_TRIS   TRISAbits.TRISA3
#define	TP47_WR     LATAbits.LATA3
#define	TP47_RD     PORTAbits.RA3

#define	TP48_TRIS
#define	TP48_WR
#define	TP48_RD


#define TP52_TRIS   TRISDbits.TRISD10
#define	TP52_WR     LATDbits.LATD10
#define	TP52_RD     PORTDbits.RD10

#define	TP53_TRIS   TRISBbits.TRISB15
#define	TP53_WR     LATBbits.LATB15
#define	TP53_RD     PORTBbits.RB15

#define	TP54_TRIS   TRISDbits.TRISD11
#define	TP54_WR     LATDbits.LATD11
#define	TP54_RD     PORTDbits.RD11

#define	TP55_TRIS   TRISBbits.TRISB8
#define	TP55_WR     LATBbits.LATB8
#define	TP55_RD     PORTBbits.RB8

#define	TP56_TRIS   TRISDbits.TRISD12
#define	TP56_WR     LATDbits.LATD12
#define	TP56_RD     PORTDbits.RD12




#endif	/* _00124_R10_EP806_PINMAP_H */

