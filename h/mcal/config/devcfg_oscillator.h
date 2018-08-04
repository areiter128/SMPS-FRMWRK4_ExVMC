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
#ifndef _DEVICE_CONFIGURATION_OSCILLATOR_H_
#define	_DEVICE_CONFIGURATION_OSCILLATOR_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>


/*@@System Oscillator Settings
 * ************************************************************************************************
 * Summary:
 * Predefined settings for standard oscillator configurations
 *
 * Description:
 * These defines are used to setup the oscillator using predefined settings to achieve common
 * system clock speeds/frequencies. By selecting one of the given MIPS_xx options, all required register
 * values for scalers and gating options will be selected and adjusted accordingly.
 * ***********************************************************************************************/

/* device speed definitions */
#define MIPS40	0
#define MIPS50	1
#define MIPS60	2
#define MIPS70	4
#define MIPS90	5
#define MIPS100 6

/* user settings */
#define USE_EXTERNAL_OSC	0			// Usage of external oscillator (0= Internal FRC, 1= external Oscillator)
                                        // If FRS is selected, FRC will be tuned to 7.5 MHz
#define MCU_SPEED			MIPS70		// Device speed selection (MIPS40, MIPS50, MIPS60, MIPS70)


#if (USE_EXTERNAL_OSC == 1)
    EXT_OSC_FREQ        8000000         // Specify frequency of the external oscillator in [Hz]
#endif
        
#endif	/* _DEVICE_CONFIGURATION_OSCILLATOR_H_ */

