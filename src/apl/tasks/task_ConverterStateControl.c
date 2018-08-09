/*
 * File:   task_ConverterStateControl.c
 * Author: M91406
 *
 * Created on August 6, 2018, 5:40 PM
 */


#include "task_ConverterStateControl.h"

volatile uint16_t cvrt_ShutDown(void)
{
    cnpnz_vmc.status.flag.enable = 0; // turn off controller
    gspwm_set_duty_cycle(CVRT_PH1_PWM_IDX, PWM_PRIMARY, 0); // turn off duty cycle
    gspwm_ovr_output_hold(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW); // override PWM outputs
    
    cnpnz_vmc_Reset(&cnpnz_vmc);    // Reset control histories
    
    return(1);
}

volatile uint16_t cvrt_StartUp(void)
{
//    gspwm_set_duty_cycle(CVRT_PH1_PWM_IDX, PWM_PRIMARY, 0); // turn off duty cycle
//    gspwm_ovr_output_release(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW); // override PWM outputs
//    
//    init_soft_start();
//    cnpnz_vmc_Reset(&cnpnz_vmc);    // Reset control histories
//
//    //cnpnz_vmc.status.flag.enable = 1; // turn off controller
//    soft_start.status.flag.enable = 1;
    
    return(1);
}
