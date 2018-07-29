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
 * File:        p33CH128MP506_pim_r3_pinmap.h
 * Author:      M91406
 * Comments:    Hardware abstraction layer for dsPIC33CH128MP506 daughter card revision 3.0
 * Board No:    00133
 * Revision history: 1.0    (initial release)
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _00133_R3_MP506_PINMAP_H
#define	_00133_R3_MP506_PINMAP_H

#include <xc.h> // include processor files - each processor file is guarded.  

// Generic defines
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
#define DBGLED1_TRIS    TRISDbits.TRISD15
#define DBGLED1_WR      LATDbits.LATD15
#define DBGLED1_RD      PORTDbits.RD15
#define DBGLED1_INIT    {DBGLED1_WR = LED_OFF; DBGLED1_TRIS = 0;}

// Header Test Points

//#define TP01_TRIS (reserved) => connected to GND
//#define TP01_WR   (reserved) => connected to GND
//#define TP01_RD   (reserved) => connected to GND

//#define TP02_TRIS (reserved) => connected to GND
//#define TP02_WR   (reserved) => connected to GND
//#define TP02_RD   (reserved) => connected to GND

#define	TP03_TRIS   TRISBbits.TRISB2
#define	TP03_WR     LATBbits.LATB2
#define	TP03_RD     PORTBbits.RB2

#define	TP04_TRIS   TRISCbits.TRISC7
#define	TP04_WR     LATCbits.LATC7
#define	TP04_RD     PORTCbits.RC7

#define TP05_TRIS   TRISCbits.TRISC0 // => connected to op-amp 1 input
#define TP05_WR     LATCbits.LATC0  // => connected to op-amp 1 input
#define TP05_RD     PORTCbits.RC0   // => connected to op-amp 1 input

#define TP06_TRIS   TRISCbits.TRISC2 // => connected to op-amp 2 input
#define TP06_WR     LATCbits.LATC2  // => connected to op-amp 2 input
#define TP06_RD     PORTCbits.RC2   // => connected to op-amp 2 input

/* not connected 
#define	TP07_TRIS   (reserved) => not connected
#define	TP07_WR     (reserved) => not connected
#define	TP07_RD     (reserved) => not connected
   not connected */

#define	TP08_TRIS   TRISCbits.TRISC3
#define	TP08_WR     LATCbits.LATC3
#define	TP08_RD     PORTCbits.LATC3

#define	TP09_TRIS   TRISDbits.TRISD11 // => connected to op-amp 3 input
#define	TP09_WR     LATDbits.LATD11 // => connected to op-amp 3 input
#define	TP09_RD     PORTDbits.RD11  // => connected to op-amp 3 input

#define	TP10_TRIS   TRISCbits.TRISC1 // => connected to op-amp 4 input
#define	TP10_WR     LATCbits.LATC1  // => connected to op-amp 4 input
#define	TP10_RD     PORTCbits.RC1   // => connected to op-amp 4 input

#define	TP11_TRIS   TRISAbits.TRISA2
#define	TP11_WR     LATAbits.LATA2
#define	TP11_RD     PORTAbits.RA2

#define	TP12_TRIS   TRISAbits.TRISA3
#define	TP12_WR     LATAbits.LATA3
#define	TP12_RD     PORTAbits.RA3

#define	TP13_TRIS   TRISAbits.TRISA1
#define	TP13_WR     LATAbits.LATA1
#define	TP13_RD     PORTAbits.RA1

#define	TP14_TRIS   TRISAbits.TRISA4
#define	TP14_WR     LATAbits.LATA4
#define	TP14_RD     PORTAbits.RA4

#define	TP15_TRIS   TRISAbits.TRISA0
#define	TP15_WR     LATAbits.LATA0
#define	TP15_RD     PORTAbits.RA0

#define	TP16_TRIS   TRISDbits.TRISD10
#define	TP16_WR     LATDbits.LATD10
#define	TP16_RD     PORTDbits.RD10

#define	TP17_TRIS   TRISDbits.TRISD12
#define	TP17_WR     LATDbits.LATD12
#define	TP17_RD     PORTDbits.RD12

#define	TP18_TRIS   TRISCbits.TRISC6
#define	TP18_WR     LATCbits.LATC6
#define	TP18_RD     PORTCbits.RC6

/* not connected 
#define	TP19_TRIS   (reserved) => not connected
#define	TP19_WR     (reserved) => not connected
#define	TP19_RD     (reserved) => not connected
   not connected */

#define	TP20_TRIS   TRISBbits.TRISB1
#define	TP20_WR     LATBbits.LATB1
#define	TP20_RD     PORTBbits.RB1

/* not connected 
#define	TP21_TRIS   (reserved) => not present
#define	TP21_WR     (reserved) => not present
#define	TP21_RD     (reserved) => not present
   not connected */

/* not connected 
#define	TP22_TRIS   (reserved) => not present
#define	TP22_WR     (reserved) => not present
#define	TP22_RD     (reserved) => not present
   not connected */

/* not connected 
#define	TP23_TRIS   (reserved) => not connected
#define	TP23_WR     (reserved) => not connected
#define	TP23_RD     (reserved) => not connected
   not connected */

// Loop Test Points
#define	TP24_TRIS   TRISCbits.TRISC8
#define	TP24_WR     LATCbits.LATC8
#define	TP24_RD     PORTCbits.RC8

#define	TP25_TRIS   TRISBbits.TRISB12
#define	TP25_WR     LATBbits.LATB12
#define	TP25_RD     PORTBbits.RB12

#define	TP26_TRIS   TRISDbits.TRISD14
#define	TP26_WR     LATDbits.LATD14
#define	TP26_RD     PORTDbits.RD14

#define	TP27_TRIS   TRISBbits.TRISB13
#define	TP27_WR     LATBbits.LATB13
#define	TP27_RD     PORTBbits.RB13

#define	TP28_TRIS   TRISDbits.TRISD9
#define	TP28_WR     LATDbits.LATD9
#define	TP28_RD     PORTDbits.RD9

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

#define	TP31_TRIS   TRISDbits.TRISD6
#define	TP31_WR     LATDbits.LATD6
#define	TP31_RD     PORTDbits.RD6

#define	TP32_TRIS   TRISCbits.TRISC9
#define	TP32_WR     LATCbits.LATC9
#define	TP32_RD     PORTCbits.RC9

#define	TP33_TRIS   TRISDbits.TRISD5
#define	TP33_WR     LATDbits.LATD5
#define	TP33_RD     PORTDbits.RD5

#define	TP34_TRIS   TRISBbits.TRISB11
#define	TP34_WR     LATBbits.LATB11
#define	TP34_RD     PORTBbits.RB11

#define	TP35_TRIS   TRISBbits.TRISB14
#define	TP35_WR     LATBbits.LATB14
#define	TP35_RD     PORTBbits.RB14

#define	TP36_TRIS   TRISBbits.TRISB10
#define	TP36_WR     LATBbits.LATB10
#define	TP36_RD     PORTBbits.RB10

#define	TP37_TRIS   TRISDbits.TRISD4
#define	TP37_WR     LATDbits.LATD4
#define	TP37_RD     PORTDbits.RD4

#define	TP38_TRIS   TRISBbits.TRISB15
#define	TP38_WR     LATBbits.LATB15
#define	TP38_RD     PORTBbits.RB15

#define	TP39_TRIS   TRISDbits.TRISD2
#define	TP39_WR     LATDbits.LATD2
#define	TP39_RD     PORTDbits.RD2

#define	TP40_TRIS   TRISCbits.TRISC5
#define	TP40_WR     LATCbits.LATC5
#define	TP40_RD     PORTCbits.RC5

#define	TP41_TRIS   TRISDbits.TRISD3
#define	TP41_WR     LATDbits.LATD3
#define	TP41_RD     PORTDbits.RD3

#define	TP42_TRIS   TRISCbits.TRISC4
#define	TP42_WR     LATCbits.LATC4
#define	TP42_RD     PORTCbits.RC4

#define	TP43_TRIS   TRISDbits.TRISD1
#define	TP43_WR     LATDbits.LATD1
#define	TP43_RD     PORTDbits.RD1

#define	TP44_TRIS   TRISDbits.TRISD0
#define	TP44_WR     LATDbits.LATD0
#define	TP44_RD     PORTDbits.RD0

#define	TP45_TRIS   TRISCbits.TRISC10
#define	TP45_WR     LATCbits.LATC10
#define	TP45_RD     PORTCbits.RC10

#define	TP46_TRIS   TRISCbits.TRISC12
#define	TP46_WR     LATCbits.LATC12
#define	TP46_RD     PORTCbits.RC12

#define	TP47_TRIS   TRISCbits.TRISC11
#define	TP47_WR     LATCbits.LATC11
#define	TP47_RD     PORTCbits.RC11

#define	TP48_TRIS   TRISCbits.TRISC13
#define	TP48_WR     LATCbits.LATC13
#define	TP48_RD     PORTCbits.RC13

/* MCLR 
#define	TP49_TRIS   TRISCbits.TRISC10
#define	TP49_WR     LATCbits.LATC10
#define	TP49_RD     PORTCbits.RC10
   MCLR */

#define TP50_TRIS   TRISDbits.TRISD7
#define	TP50_WR     LATDbits.LATD7
#define	TP50_RD     PORTDbits.RD7

#define TP51_TRIS   TRISBbits.TRISB4
#define	TP51_WR     LATBbits.LATB4
#define	TP51_RD     PORTBbits.RB4

#define TP52_TRIS   TRISDbits.TRISD8
#define	TP52_WR     LATDbits.LATD8
#define	TP52_RD     PORTDbits.RD8

#define TP53_TRIS   TRISBbits.TRISB6
#define	TP53_WR     LATBbits.LATB6
#define	TP53_RD     PORTBbits.RB6

#define	TP54_TRIS   TRISDbits.TRISD13
#define	TP54_WR     LATDbits.LATD13
#define	TP54_RD     PORTDbits.RD13

#define	TP55_TRIS   TRISBbits.TRISB5
#define	TP55_WR     LATBbits.LATB5
#define	TP55_RD     PORTBbits.RB5

#define	TP56_TRIS   TRISBbits.TRISB3
#define	TP56_WR     LATBbits.LATB3
#define	TP56_RD     PORTBbits.RB3




#endif	/* _00133_R3_MP506_PINMAP_H */

