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
/* @@init_swdt.h
 * *************************************************************************** 
 * File:   init_swdt.h
 * Author: M91406
 *
 * Created on July 28, 2017, 11:04 AM
 * ***************************************************************************/

#ifndef _HARDWARE_ABSTRACTION_LAYER_SOFTWARE_WATCH_DOG_INITIALIZATION_H_
#define	_HARDWARE_ABSTRACTION_LAYER_SOFTWARE_WATCH_DOG_INITIALIZATION_H_

#include <xc.h>
#include <stdint.h>
#include "mcal.h"

/* ***********************************************************************************************
 * PROTOTYPES
 * ***********************************************************************************************/
extern volatile uint16_t init_SoftwareWatchDogTimer(void);

#endif	/* _HARDWARE_ABSTRACTION_LAYER_SOFTWARE_WATCH_DOG_INITIALIZATION_H_ */

