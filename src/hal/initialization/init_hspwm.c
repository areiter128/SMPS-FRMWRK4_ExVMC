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
uint16_t init_hspwm(void)
{
    // Turn on power to peripheral blocks
    gspwm_module_power_up();
    
    gspwm_channel_power_up(CVRT_PH1_PWM_IDX);
    
    #if ( PWM_MPH_PHASE_COUNT >= 2 )
    gspwm_channel_power_up(CVRT_PH2_PWM_IDX);
    #endif
    #if ( PWM_MPH_PHASE_COUNT >= 3 )
    gspwm_channel_power_up(CVRT_PH3_PWM_IDX);
    #endif
    #if ( PWM_MPH_PHASE_COUNT >= 4 )
    gspwm_channel_power_up(CVRT_PH4_PWM_IDX);
    #endif

    // Reset PWM output pin configuration to GPIO-mode
    gspwm_reset_pwm_io();
    
	// Set up basic PWM properties (valid for all channels)
	gspwm_init_mtb(SWITCHING_FRQ_TIME_BASE, CVRT_HSPWM_PTCON_CFG, CVRT_HSPWM_PTCON2_CFG, SWITCHING_PERIOD);

    // Initialize PWM Channel for Phase #1
    gspwm_init_channel(CVRT_PH1_PWM_IDX, CVRT_HSPWM_PWMCONx_CFG, CVRT_HSPWM_IOCONx_CFG, CVRT_PH1_FCLCONx_CFG, CVRT_HSPWM_LEBCONx_CFG);
	gspwm_init_channel_timing_complementary(CVRT_PH1_PWM_IDX, 0, 0, PWM_DEAD_TIME_LE, PWM_DEAD_TIME_FE);
    gspwm_set_phase(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW, MPH_PHASE_SHIFT_CH1);
    gspwm_set_duty_cycle(CVRT_PH1_PWM_IDX, PWMx_HIGH, 0);
    gspwm_set_leb_period(CVRT_PH1_PWM_IDX, LEB_PERIOD);    
    gspwm_set_adc_trigger_config(CVRT_PH1_PWM_IDX, CVRT_PH1_TRGCONx_CFG);

    gspwm_ovr_output_hold(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW);			// Hold both PWM channel output pins in override mode until the system is launched
    gspwm_channel_output_disable(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW);   // Disable both PWM channel output pins

    // Initialize PWM Channel for Phase #2
    #if ( PWM_MPH_PHASE_COUNT >= 2 )
    gspwm_init_channel(CVRT_PH2_PWM_IDX, CVRT_HSPWM_PWMCONx_CFG, CVRT_HSPWM_IOCONx_CFG, CVRT_PH2_FCLCONx_CFG, CVRT_HSPWM_LEBCONx_CFG);
	gspwm_init_channel_timing_complementary(CVRT_PH2_PWM_IDX, 0, 0, PWM_DEAD_TIME_LE, PWM_DEAD_TIME_FE);
    gspwm_set_phase(CVRT_PH2_PWM_IDX, PWMx_HIGH_LOW, MPH_PHASE_SHIFT_CH2);
    gspwm_set_duty_cycle(CVRT_PH2_PWM_IDX, PWMx_HIGH, 0);
    gspwm_set_leb_period(CVRT_PH2_PWM_IDX, LEB_PERIOD);    
    gspwm_set_adc_trigger_config(CVRT_PH2_PWM_IDX, CVRT_PH2_TRGCONx_CFG);
	
    gspwm_ovr_output_hold(CVRT_PH2_PWM_IDX, PWMx_HIGH_LOW);			// Hold both PWM channel output pins in override mode until the system is launched
    gspwm_channel_output_disable(CVRT_PH2_PWM_IDX, PWMx_HIGH_LOW);   // Disable both PWM channel output pins
    #endif

    // Initialize PWM Channel for Phase #3
    #if ( PWM_MPH_PHASE_COUNT >= 3 )
    gspwm_init_channel(CVRT_PH3_PWM_IDX, CVRT_HSPWM_PWMCONx_CFG, CVRT_HSPWM_IOCONx_CFG, CVRT_PH2_FCLCONx_CFG, CVRT_HSPWM_LEBCONx_CFG);
	gspwm_init_channel_timing_complementary(CVRT_PH3_PWM_IDX, 0, 0, PWM_DEAD_TIME_LE, PWM_DEAD_TIME_FE);
    gspwm_set_phase(CVRT_PH3_PWM_IDX, PWMx_HIGH_LOW, MPH_PHASE_SHIFT_CH3);
    gspwm_set_duty_cycle(CVRT_PH3_PWM_IDX, PWMx_HIGH, 0);
    gspwm_set_leb_period(CVRT_PH3_PWM_IDX, LEB_PERIOD);    
    gspwm_set_adc_trigger_config(CVRT_PH3_PWM_IDX, CVRT_PH3_TRGCONx_CFG);
	
    gspwm_ovr_output_hold(CVRT_PH3_PWM_IDX, PWMx_HIGH_LOW);			// Hold both PWM channel output pins in override mode until the system is launched
    gspwm_channel_output_disable(CVRT_PH3_PWM_IDX, PWMx_HIGH_LOW);   // Disable both PWM channel output pins
    #endif
    
    // Initialize PWM Channel for Phase #4
    #if ( PWM_MPH_PHASE_COUNT >= 4 )
    gspwm_init_channel(CVRT_PH4_PWM_IDX, CVRT_HSPWM_PWMCONx_CFG, CVRT_HSPWM_IOCONx_CFG, CVRT_PH2_FCLCONx_CFG, CVRT_HSPWM_LEBCONx_CFG);
	gspwm_init_channel_timing_complementary(CVRT_PH4_PWM_IDX, 0, 0, PWM_DEAD_TIME_LE, PWM_DEAD_TIME_FE);
    gspwm_set_phase(CVRT_PH4_PWM_IDX, PWMx_HIGH_LOW, MPH_PHASE_SHIFT_CH4);
    gspwm_set_duty_cycle(CVRT_PH4_PWM_IDX, PWMx_HIGH, 0);
    gspwm_set_leb_period(CVRT_PH4_PWM_IDX, LEB_PERIOD);    
    gspwm_set_adc_trigger_config(CVRT_PH4_PWM_IDX, CVRT_PH4_TRGCONx_CFG);
	
    gspwm_ovr_output_hold(CVRT_PH4_PWM_IDX, PWMx_HIGH_LOW);			// Hold both PWM channel output pins in override mode until the system is launched
    gspwm_channel_output_disable(CVRT_PH4_PWM_IDX, PWMx_HIGH_LOW);   // Disable both PWM channel output pins
    #endif
    

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
uint16_t exec_launch_hspwm(void)
{
    uint16_t i_res=1;
    
    i_res &= gspwm_module_enable();

    // Interrupt Configuration = TESTCODE =
    i_res = gspwm_set_sevtcmp_value(PWM_PRIMARY, CVRT_SEV_DEFAULT_TRIGGER);
    CVRT_SEV_IRQ_IF = 0;                                // Reset Interrupt Flag
    CVRT_SEV_IRQ_IP = CVRT_SEV_ISR_PRIORITY;            // Set Interrupt Priority
    CVRT_SEV_IRQ_IE = SEV_INTERRUPT_DISABLE;            // Enable/Disable Interrupt

    // Launch PWM1
    i_res &= gspwm_channel_output_enable(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW);
    i_res &= gspwm_set_duty_cycle(CVRT_PH1_PWM_IDX, PWMx_HIGH, 0);
    i_res &= gspwm_ovr_output_release(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW);

    CVRT_PH1_PWM_IRQ_IF = 0;                            // Reset Interrupt Flag 
    CVRT_PH1_PWM_IRQ_IP = CVRT_PH1_PWM_ISR_PRIORITY;    // Set Interrupt Priority
    CVRT_PH1_PWM_IRQ_IE = CVRT_PH1_PWM_ISR_ENABLE;      // Enable/Disable ISR
    
    // Launch PWM2
    #if ( PWM_MPH_PHASE_COUNT >= 2 )

    i_res &= gspwm_channel_output_enable(CVRT_PH2_PWM_IDX, PWMx_HIGH_LOW);
    i_res &= gspwm_set_duty_cycle(CVRT_PH2_PWM_IDX, PWMx_HIGH, 0);
    i_res &= gspwm_ovr_output_release(CVRT_PH2_PWM_IDX, PWMx_HIGH_LOW);

    CVRT_PH2_PWM_IRQ_IF = 0;                            // Reset Interrupt Flag 
    CVRT_PH2_PWM_IRQ_IP = CVRT_PH2_PWM_ISR_PRIORITY;    // Set INterrupt Priority
    CVRT_PH2_PWM_IRQ_IE = CVRT_PH2_PWM_ISR_ENABLE;      // Enable/Disable ISR

    #endif
    
    // Launch PWM3
    #if ( PWM_MPH_PHASE_COUNT >= 3 )

    i_res &= gspwm_channel_output_enable(CVRT_PH3_PWM_IDX, PWMx_HIGH_LOW);
    i_res &= gspwm_set_duty_cycle(CVRT_PH3_PWM_IDX, PWMx_HIGH, 0);
    i_res &= gspwm_ovr_output_release(CVRT_PH3_PWM_IDX, PWMx_HIGH_LOW);

    CVRT_PH3_PWM_IRQ_IF = 0;                            // Reset Interrupt Flag 
    CVRT_PH3_PWM_IRQ_IP = CVRT_PH3_PWM_ISR_PRIORITY;    // Set INterrupt Priority
    CVRT_PH3_PWM_IRQ_IE = CVRT_PH3_PWM_ISR_ENABLE;      // Enable/Disable ISR

    #endif
    
    // Launch PWM4
    #if ( PWM_MPH_PHASE_COUNT >= 4 )

    i_res &= gspwm_channel_output_enable(CVRT_PH4_PWM_IDX, PWMx_HIGH_LOW);
    i_res &= gspwm_set_duty_cycle(CVRT_PH4_PWM_IDX, PWMx_HIGH, 0);
    i_res &= gspwm_ovr_output_release(CVRT_PH4_PWM_IDX, PWMx_HIGH_LOW);

    CVRT_PH4_PWM_IRQ_IF = 0;                            // Reset Interrupt Flag 
    CVRT_PH4_PWM_IRQ_IP = CVRT_PH4_PWM_ISR_PRIORITY;    // Set INterrupt Priority
    CVRT_PH4_PWM_IRQ_IE = CVRT_PH4_PWM_ISR_ENABLE;      // Enable/Disable ISR

    #endif
    
    
    return(i_res);
    
}


/*@@launch_hspwm
 *****************************************************************************
 * Function:	 int soft_start_hspwm(void)
 * Arguments:	 (none)
 * Return Value: 
 *  1: success
 *  0: failure
 *
 * Summary:
 * Activates the PWM module
 *
 * Description:	
 * This routine is test code only to evaluate soft-start implementations
 *
 * See also:
 * init_HSPWM
 * 
 *****************************************************************************/
uint16_t exec_soft_start_hspwm(void)
{
    /* ToDo: this is a placeholder soft-start function not suited for real application
     * A fully functional soft-start driver is required */

    if(CVRT_PH1_PDC < 1000)
    {
        CVRT_PH1_PDC += 10;
    }
    else
    {
        task_mgr.op_mode.mode = OP_MODE_NORMAL;
    }
 
    return(1);
}
