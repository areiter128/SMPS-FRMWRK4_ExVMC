/*LICENSE *****************************************************************************
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


// Device header file
#include <xc.h>

#include <stdint.h>
#include "hal.h"

/*@@init_PWM
 *****************************************************************************
 * Function:	 void init_PWM(void)
 * Arguments:	 (none)
 * Return Value: (none)
 *
 * Summary:
 * Initializes the PWM module
 *
 * Description:	
 * This routine initializes the high-speed PWM module of dsPIC33 GS. Multiple
 * PWMs may be used to drive individual sections of the power converter, which 
 * are configured here accordingly. 
 * The PWM channels are the trigger source for the ADC inputs.
 *
 * See also:
 * init_ADC
 * 
 *****************************************************************************/
volatile uint16_t init_hspwm(void)
{
    volatile uint16_t i = 0, m = 0, phs = 0, trgcon = 0, fltcon = 0;
    
    // Turn on power to PWM peripheral blocks
    hspwm_module_power_up();
    
    hspwm_channel_power_up(CVRT_PH1_PWM_IDX);
    
    #if ( PWM_MPH_PHASE_COUNT >= 2 )
    hspwm_channel_power_up(CVRT_PH2_PWM_IDX);
    #endif
    #if ( PWM_MPH_PHASE_COUNT >= 3 )
    hspwm_channel_power_up(CVRT_PH3_PWM_IDX);
    #endif
    #if ( PWM_MPH_PHASE_COUNT >= 4 )
    hspwm_channel_power_up(CVRT_PH4_PWM_IDX);
    #endif
    #if ( PWM_MPH_PHASE_COUNT >= 5 )
    hspwm_channel_power_up(CVRT_PH5_PWM_IDX);
    #endif
    #if ( PWM_MPH_PHASE_COUNT >= 6 )
    hspwm_channel_power_up(CVRT_PH6_PWM_IDX);
    #endif
    #if ( PWM_MPH_PHASE_COUNT >= 7 )
    hspwm_channel_power_up(CVRT_PH7_PWM_IDX);
    #endif
    #if ( PWM_MPH_PHASE_COUNT >= 8 )
    hspwm_channel_power_up(CVRT_PH8_PWM_IDX);
    #endif
    #if ( PWM_MPH_PHASE_COUNT > 8 )
    #error === specified number of PWM channels not supported by this code module yet ===
    #endif

    // Reset PWM output pin configuration to GPIO-mode
    hspwm_reset_pwm_io();
    
	// Set up basic PWM properties (valid for all channels)
	hspwm_init_mtb(SWITCHING_FRQ_TIME_BASE, CVRT_HSPWM_PTCON_CFG, CVRT_HSPWM_PTCON2_CFG, SWITCHING_PERIOD);

    for(i=0; i<PWM_MPH_PHASE_COUNT; i++)
    { // Initialize PWM Channel for Phase #1
        
        switch (i)
        {
            case 0: 
                m = CVRT_PH1_PWM_IDX; 
                phs = MPH_PHASE_SHIFT_CH1;
                trgcon = CVRT_PH1_TRGCONx_CFG;
                fltcon = CVRT_PH1_FCLCONx_CFG;
                break;
            #if ( PWM_MPH_PHASE_COUNT >= 2 )
            case 1: 
                m = CVRT_PH2_PWM_IDX;
                phs = MPH_PHASE_SHIFT_CH2;
                trgcon = CVRT_PH2_TRGCONx_CFG;
                fltcon = CVRT_PH2_FCLCONx_CFG;
                break;
            #endif
            #if ( PWM_MPH_PHASE_COUNT >= 3 )
            case 2: 
                m = CVRT_PH3_PWM_IDX; 
                phs = MPH_PHASE_SHIFT_CH3;
                trgcon = CVRT_PH3_TRGCONx_CFG;
                fltcon = CVRT_PH3_FCLCONx_CFG;
                break;
            #endif
            #if ( PWM_MPH_PHASE_COUNT >= 4 )
            case 3: 
                m = CVRT_PH4_PWM_IDX; 
                phs = MPH_PHASE_SHIFT_CH14
                trgcon = CVRT_PH4_TRGCONx_CFG;
                fltcon = CVRT_PH4_FCLCONx_CFG;
                break;
            #endif
            #if ( PWM_MPH_PHASE_COUNT >= 5 )
            case 4: 
                m = CVRT_PH5_PWM_IDX; 
                phs = MPH_PHASE_SHIFT_CH5;
                trgcon = CVRT_PH5_TRGCONx_CFG;
                fltcon = CVRT_PH5_FCLCONx_CFG;
                break;
            #endif
            #if ( PWM_MPH_PHASE_COUNT >= 6 )
            case 5: 
                m = CVRT_PH6_PWM_IDX; 
                phs = MPH_PHASE_SHIFT_CH6;
                trgcon = CVRT_PH6_TRGCONx_CFG;
                fltcon = CVRT_PH6_FCLCONx_CFG;
                break;
            #endif
            #if ( PWM_MPH_PHASE_COUNT >= 7 )
            case 6: 
                m = CVRT_PH7_PWM_IDX; 
                phs = MPH_PHASE_SHIFT_CH7;
                trgcon = CVRT_PH7_TRGCONx_CFG;
                fltcon = CVRT_PH7_FCLCONx_CFG;
                break;
            #endif
            #if ( PWM_MPH_PHASE_COUNT == 8 )
            case 7: 
                m = CVRT_PH8_PWM_IDX; 
                phs = MPH_PHASE_SHIFT_CH8;
                trgcon = CVRT_PH8_TRGCONx_CFG;
                fltcon = CVRT_PH8_FCLCONx_CFG;
                break;
            #endif
        }
        
        hspwm_init_channel(m, CVRT_HSPWM_PWMCONx_CFG, CVRT_HSPWM_IOCONx_CFG, fltcon, CVRT_HSPWM_LEBCONx_CFG);
        hspwm_init_channel_timing_complementary(m, 0, 0, PWM_DEAD_TIME_LE, PWM_DEAD_TIME_FE);
        hspwm_set_phase(m, PWMx_HIGH_LOW, phs);
        hspwm_set_duty_cycle(m, PWMx_HIGH, 0);
        hspwm_set_leb_period(m, LEB_PERIOD);    
        hspwm_set_adc_trigger_config(m, trgcon);

        hspwm_ovr_output_hold(m, PWMx_HIGH_LOW);			// Hold both PWM channel output pins in override mode until the system is launched
        hspwm_channel_output_disable(m, PWMx_HIGH_LOW);   // Disable both PWM channel output pins
        
    }


	return(1);

}

/*@@launch_hspwm
 *****************************************************************************
 * Function:	 int launch_hspwm(void)
 * Arguments:	 (none)
 * Return Value: 
 *  1: success
 *  0: failure
 *
 * Summary:
 * Activates the PWM module
 *
 * Description:	
 * This routine activates the high-speed PWM module of dsPIC33 GS. Multiple
 * PWMs may be used to drive individual sections of the power converter, which 
 * have been configured and initialized before this function is called.
 *
 * See also:
 * init_hspwm
 * 
 *****************************************************************************/
volatile uint16_t exec_launch_hspwm(void)
{
    volatile uint16_t fres = 0;
    

    // Interrupt Configuration = TESTCODE =
    fres = hspwm_set_sevtcmp_value(PWM_PRIMARY, CVRT_SEV_DEFAULT_TRIGGER);
    CVRT_SEV_IRQ_IF = 0;                                // Reset Interrupt Flag
    CVRT_SEV_IRQ_IP = CVRT_SEV_ISR_PRIORITY;            // Set Interrupt Priority
    CVRT_SEV_IRQ_IE = CVRT_SEV_ISR_ENABLE;              // Enable/Disable Interrupt

//    CVRT_PH1_PWM_IRQ_IF = 0;                            // Reset Interrupt Flag 
//    CVRT_PH1_PWM_IRQ_IP = CVRT_PH1_PWM_ISR_PRIORITY;    // Set Interrupt Priority
//    CVRT_PH1_PWM_IRQ_IE = CVRT_PH1_PWM_ISR_ENABLE;      // Enable/Disable ISR

    // Enable PWM peripheral
    fres &= hspwm_module_enable();

    // Launch PWM1
    fres &= hspwm_channel_output_enable(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW);
    fres &= hspwm_set_duty_cycle(CVRT_PH1_PWM_IDX, PWMx_HIGH, 0);
    fres &= hspwm_ovr_output_release(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW);
    
    // Launch PWM2
    #if ( PWM_MPH_PHASE_COUNT >= 2 )

    CVRT_PH2_PWM_IRQ_IF = 0;                            // Reset Interrupt Flag 
    CVRT_PH2_PWM_IRQ_IP = CVRT_PH2_PWM_ISR_PRIORITY;    // Set INterrupt Priority
    CVRT_PH2_PWM_IRQ_IE = CVRT_PH2_PWM_ISR_ENABLE;      // Enable/Disable ISR

    fres &= hspwm_channel_output_enable(CVRT_PH2_PWM_IDX, PWMx_HIGH_LOW);
    fres &= hspwm_set_duty_cycle(CVRT_PH2_PWM_IDX, PWMx_HIGH, 0);
    fres &= hspwm_ovr_output_release(CVRT_PH2_PWM_IDX, PWMx_HIGH_LOW);

    #endif
    
    // Launch PWM3
    #if ( PWM_MPH_PHASE_COUNT >= 3 )

    CVRT_PH3_PWM_IRQ_IF = 0;                            // Reset Interrupt Flag 
    CVRT_PH3_PWM_IRQ_IP = CVRT_PH3_PWM_ISR_PRIORITY;    // Set INterrupt Priority
    CVRT_PH3_PWM_IRQ_IE = CVRT_PH3_PWM_ISR_ENABLE;      // Enable/Disable ISR

    fres &= hspwm_channel_output_enable(CVRT_PH3_PWM_IDX, PWMx_HIGH_LOW);
    fres &= hspwm_set_duty_cycle(CVRT_PH3_PWM_IDX, PWMx_HIGH, 0);
    fres &= hspwm_ovr_output_release(CVRT_PH3_PWM_IDX, PWMx_HIGH_LOW);

    #endif
    
    // Launch PWM4
    #if ( PWM_MPH_PHASE_COUNT >= 4 )

    CVRT_PH4_PWM_IRQ_IF = 0;                            // Reset Interrupt Flag 
    CVRT_PH4_PWM_IRQ_IP = CVRT_PH4_PWM_ISR_PRIORITY;    // Set INterrupt Priority
    CVRT_PH4_PWM_IRQ_IE = CVRT_PH4_PWM_ISR_ENABLE;      // Enable/Disable ISR

    fres &= hspwm_channel_output_enable(CVRT_PH4_PWM_IDX, PWMx_HIGH_LOW);
    fres &= hspwm_set_duty_cycle(CVRT_PH4_PWM_IDX, PWMx_HIGH, 0);
    fres &= hspwm_ovr_output_release(CVRT_PH4_PWM_IDX, PWMx_HIGH_LOW);

    #endif
    
    
    return(fres);
    
}

