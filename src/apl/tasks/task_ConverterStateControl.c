/*
 * File:   task_ConverterStateControl.c
 * Author: M91406
 *
 * Created on August 6, 2018, 5:40 PM
 */


#include "task_ConverterStateControl.h"

//volatile CONVERTER_t cvrt;

volatile uint16_t cvrt_InitConverter(void)
{
/*    
    cvrt.c_vmc = &cnpnz_vmc;    // voltage loop controller 

    cvrt.converter.voltage_reference = cnpnz_vmc.ptrControlReference;
    cvrt.converter.output_voltage = cnpnz_vmc.ptrSource;
    cvrt.converter.duty_cycle1 = cnpnz_vmc.ptrTarget;
    cvrt.converter.switching_period = &CVRT_PPER;
    cvrt.converter.cpu_load = &task_mgr.cpu_load.load;
*/    
    return(1);
}

volatile uint16_t cvrt_ShutDown(void)
{
    cnpnz_vmc.status.flag.enable = 0; // turn off controller
    hspwm_set_duty_cycle(CVRT_PH1_PWM_IDX, PWM_PRIMARY, 0); // turn off duty cycle
    hspwm_ovr_output_hold(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW); // override PWM outputs
    
    cnpnz_vmc_Reset(&cnpnz_vmc);    // Reset control histories
    
    return(1);
}

volatile uint16_t cvrt_StartUp(void)
{
//    hspwm_set_duty_cycle(CVRT_PH1_PWM_IDX, PWM_PRIMARY, 0); // turn off duty cycle
//    hspwm_ovr_output_release(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW); // override PWM outputs
//    
//    init_soft_start();
//    cnpnz_vmc_Reset(&cnpnz_vmc);    // Reset control histories
//
//    //cnpnz_vmc.status.flag.enable = 1; // turn off controller
//    soft_start.status.flag.enable = 1;
    
    return(1);
}

