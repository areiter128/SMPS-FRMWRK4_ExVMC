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
 * File:   devcfg_hspwm.h
 * Author: M91406
 * Comments: User configuration of the PWm peripheral
 * Revision history: v1.0, first release
 * *****************************************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _DEVICE_CONFIGURATION_HSPWM_H_
#define	_DEVICE_CONFIGURATION_HSPWM_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

// Basic PWM Settings
#define SWITCHING_FRQ_TIME_BASE		1		// Nominal switching frequency driving converter stage

// PWM Input Clock Divider
#define PWM_PCLKDIV_PRIMARY     PCLKDIV_1	// PWM frequency input divider to define PWM resolution
                                    		// Setting PCLKDIV_1, xx_2, xx_4, xx_8, xx_16, xx_32, xx_64

/* TODO: Add second clock divider for secondary master time base */

// DC/DC Converter PWM Outputs
#define CVRT_PH1_PWM_IDX			1		// Index of the PWM channel #1 used to drive the bus converter

#define PWM_MPH_PHASE_COUNT         1       // Number of phases in a multiphase-architecture

// DC/DC Converter PWM Interrupts

#define CVRT_SEV_IRQ_IF			IFS3bits.PSEMIF		// Interrupt flag bit of Special Event Interrupt
#define CVRT_SEV_IRQ_IE			IEC3bits.PSEMIE		// Interrupt enable bit of Special Event Interrupt
#define CVRT_SEV_IRQ_IP			IPC14bits.PSEMIP	// Interrupt priority of Special Event Interrupt

#define CVRT_SSEV_IRQ_IF	    IFS4bits.PSESIF     // Interrupt flag bit of Special Event Interrupt
#define CVRT_SSEV_IRQ_IE	    IEC4bits.PSESIE     // Interrupt enable bit of Special Event Interrupt
#define CVRT_SSEV_IRQ_IP	    IPC18bits.PSESIP	// Interrupt priority of Special Event Interrupt
        
#define CVRT_PH1_PWM_IRQ_IF		IFS5bits.PWM1IF		// Interrupt flag bit of PWM1
#define CVRT_PH1_PWM_IRQ_IE		IEC5bits.PWM1IE		// Interrupt enable bit of PWM1
#define CVRT_PH1_PWM_IRQ_IP		IPC23bits.PWM1IP	// Interrupt priority of PWM1


/*@@PWM-Channel Configuration
 * *****************************************************************************************************
 * Summary:
 * Set of defines for fast setup of PWM settings
 *
 * Description:
 * The following section covers all required PWM settings to operate the converter. These defines 
 * will be used in initialization and manipulation routines throughout the firmware. All edits to 
 * these settings will affect the entire firmware.
 * *****************************************************************************************************/

/* General Settings */
#if(TRIGGER_OPTION == TRG_OPTION_PWM)
#define CVRT_SEV_DEFAULT_TRIGGER    300
#define CVRT_SEV_ISR_ENABLE     SEV_INTERRUPT_ENABLED
#define CVRT_SEV_ISR_PRIORITY   5
#else
#define CVRT_SEV_ISR_ENABLE     SEV_INTERRUPT_DISABLE
#define CVRT_SEV_ISR_PRIORITY   0
#endif

/* PWM Channel #1 */        
#define CVRT_PPER				PTPER				// PWM Period register of phase #1

#define CVRT_PH1_PHS			PHASE1				// Primary PWM Period register of phase #1
#define CVRT_PH1_SPHS			SPHASE1				// Secondary PWM Period register of phase #1
#define CVRT_PH1_PDC			PDC1				// Primary PWM Duty Cycle register of phase #1
#define CVRT_PH1_SDC			SDC1				// Secondary PWM Duty Cycle register of phase #1
#define CVRT_PH1_DTR            DTR1                // Primary dead time register of phase #1
#define CVRT_PH1_ALTDTR         ALTDTR1             // Secondary dead time register of phase #1

#define CVRT_PH1_PWMH_TRIS		TRISAbits.TRISA4	// Port direction register for direct control of output PWM1H
#define CVRT_PH1_PWMH_WR		LATAbits.LATA4		// Port register for direct control of output PWM1H (write mode)
#define CVRT_PH1_PWMH_RD		PORTAbits.RA4		// Port register for direct control of output PWM1H (read mode)

#define CVRT_PH1_PWML_TRIS		TRISAbits.TRISA3	// Port direction register for direct control of output PWM1L
#define CVRT_PH1_PWML_WR		LATAbits.LATA3		// Port register for direct control of output PWM1L (write mode)
#define CVRT_PH1_PWML_RD		PORTAbits.RA3		// Port register for direct control of output PWM1L (read mode)

#define CVRT_PH1_FCLCONx_CFG   (REG_IFLTMOD_NORMAL | \
                                REG_CLSRC_NONE | \
                                REG_CLPOL_ACTIVE_HIGH | \
                                REG_CLMOD_OFF | \
                                REG_FLTSRC_NONE | \
                                REG_FLTPOL_ACTIVE_HIGH | \
                                REG_FLTMOD_DISABLED \
                                )

#define CVRT_PH1_TRGCONx_CFG   (REG_TRGDIV_STEPSIZE_1 | \
                                REG_DUAL_TRIGGER_MODE_OFF | \
                                REG_TRGSTRT_POSTSCALE_0 \
                                )

#if(TRIGGER_OPTION == TRG_OPTION_PWM)
#define CVRT_PH1_PWM_ISR_ENABLE     PWMx_INTERRUPT_DISABLED          // Enable/Disable generation of interrupts of selected PWM channel
#define CVRT_PH1_PWM_ISR_PRIORITY   0                               // Set interrupt priority for phase #1 inductor current sampling
#else
#define CVRT_PH1_PWM_ISR_ENABLE         PWMx_INTERRUPT_DISABLE      // Enable/Disable generation of interrupts of selected PWM channel
#define CVRT_PH1_PWM_ISR_PRIORITY   0                               // Set interrupt priority for phase #1 inductor current sampling
#endif



/* PWM General Settings valid for all phases */
#define CVRT_HSPWM_PTCON_CFG   (REG_PTEN_OFF | \
                                REG_PTSIDL_OFF | \
                                REG_SEIEN_ON | \
                                REG_EIPU_OFF | \
                                REG_SYNCPOL_HIGH | \
                                REG_SYNCOEN_OFF | \
                                REG_SYNCEN_OFF | \
                                REG_SYNCSRC_SYNCI1 | \
                                REG_SEVTPS_1_TO_1 \
                                )

// Clock divider = 2^n (n=0,1,2,3,4,5,6) 
// Don't use 1,5 or 6 on silicon revision B3 and earlier (see errata)
#define CVRT_HSPWM_PTCON2_CFG  (PWM_PCLKDIV_PRIMARY)
        
#define CVRT_HSPWM_PWMCONx_CFG (REG_FLTIEN_OFF | \
                                REG_CLIEN_OFF | \
                                REG_TRGIEN_ON |	\
                                REG_ITB_MASTER | \
                                REG_MDCS_INDEPENDENT | \
                                REG_DTC_POSITIVE | \
                                REG_MTBS_USE_PRIMARY_TIME_BASE | \
                                REG_CAM_OFF | \
                                REG_XPRES_OFF | \
                                REG_IUE_OFF \
                                )

#define CVRT_HSPWM_IOCONx_CFG  (REG_PWMH_IO_CONTROL_OFF | \
                                REG_PWML_IO_CONTROL_OFF | \
                                REG_POLH_ACTIVE_HIGH | \
                                REG_POLL_ACTIVE_HIGH | \
                                REG_PMOD_COMPLEMENTARY | \
                                REG_OVRENH_OFF | \
                                REG_OVRENL_OFF | \
                                REG_OVRDAT_LOW_LOW | \
                                REG_FLTDAT_LOW_LOW | \
                                REG_CLDAT_LOW_HIGH | \
                                REG_SWAP_OFF | \
                                REG_OSYNC_ON \
                                )        

#define CVRT_HSPWM_LEBCONx_CFG (REG_LEBTRG_PWMxH_RISING_ON | \
                                REG_LEBTRG_PWMxH_FALLING_OFF | \
                                REG_LEBTRG_PWMxL_RISING_OFF | \
                                REG_LEBTRG_PWMxL_FALLING_OFF | \
                                REG_FLTLEBEN_OFF | \
                                REG_CLLEBEN_ON \
                                )        


#endif	/* _DEVICE_CONFIGURATION_HSPWM_H_ */

