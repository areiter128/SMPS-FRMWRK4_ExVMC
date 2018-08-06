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
/* @@p33SMPS_swdt.c
 * ***************************************************************************
 * File:   p33SMPS_swdt.c
 * Author: M91406
 *
 * Created on October 25, 2017, 4:18 PM
 * 
 * Revision:
 * 
 * ***************************************************************************/

#include "mcal.h"

uint16_t swdt_enable(SWDT_CONFIGURATION_t swdt_enable_state) {
    
    
// If the program tries to disable the watch-dog timer in software while it's enabled in 
// hardware (config bits) the function returns "non success"

    #if defined (__P33SMPS_CH2__) || defined (__P33SMPS_CH5__)

    SWDT_CONFIGURATION_t swdt;
    
    swdt.ON = 0;
    swdt.RUNDIV = SWDT_POSTSCALER_DIV_BY_4G;
    swdt.CLKSEL = SWDT_CLKSEL_SYSCLK;
    swdt.SLPDIV = SWDT_POSTSCALER_DIV_BY_4G;
    swdt.WDTWINEN = 1;
    
    swdt.ON = 1;

    WDTCONL = swdt;     // Write configuration into SFR
    
    
    #elif defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)

    RCONbits.SWDTEN = swdt_enable_state;    // enable/disable WDT

    #endif
    
    return(1);

}

uint16_t swdt_reset(void)
{

    #if defined (__P33SMPS_CH2__) || defined (__P33SMPS_CH5__)
    WDTCONH = 0x5743;
    #elif defined (__P33SMPS_EP2__) || defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)
    WDT_RESET;
    #endif

    return(1);

}
