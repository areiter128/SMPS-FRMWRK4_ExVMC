/*
 * File:   soft_start.c
 * Author: M91406
 *
 * Created on July 31, 2018, 1:31 PM
 */


#include "task_SoftStart.h"
#include "syscfg_startup.h"
#include "tasks.h"
#include "init_control.h"

volatile uint16_t first_run = 1;
volatile uint16_t ctrl_ref_buffer = 0;
volatile uint16_t ctrl_ref_step_size = 0;
SOFT_START_OBJECT_t soft_start;

/*@@init_soft_start
 *****************************************************************************
 * Function:	 uint16_t init_soft_start(void)
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
uint16_t init_soft_start(void)
{
    
    /* ToDo: this is a placeholder soft-start function not suited for real application
     * A fully functional soft-start driver is required */

    soft_start.status.flags = 0;   // Reset soft-start status (including enable bit)
    soft_start.startup_phase = SOFT_START_STEP_INIT;    // Set startup-phase to procedure initialization
    soft_start.power_on_delay = POWER_ON_DELAY_TICKS; // set start-up delay
    soft_start.ramp_up_period = RAMP_UP_PERIOD_TICKS; // set ramp-up period 
    ctrl_ref_step_size = (ctrl_v_reference / RAMP_UP_PERIOD_TICKS);
    soft_start.power_good_delay = POWER_GOOD_DELAY_TICKS; // set power good delay

    soft_start.status.flag.enable = 1; // enable soft start
 
    return(1);
}


/*@@exec_soft_start
 *****************************************************************************
 * Function:	 uint16_t exec_soft_start(void)
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
uint16_t exec_soft_start(void)
{
    volatile uint16_t vin = 0, vout = 0, ctrl_output = 0, timeout = 0;
    volatile float dummy = 0.0;

    // Exit if Soft-Start is not enabled yet
    if (!soft_start.status.flag.enable) return(1);
    
    switch (soft_start.startup_phase)
    {
        case SOFT_START_STEP_INIT:
            // Initiate the power-on delay
            soft_start.startup_counter = soft_start.power_on_delay;
            soft_start.startup_phase = SOFT_START_STEP_POWER_ON_DELAY;
            soft_start.status.flag.ctrl_flt = 0;
            soft_start.status.flag.irq_flt = 0;
            soft_start.status.flag.fault = 0;
            soft_start.status.flag.active = 0;
            
            break;
    
        case SOFT_START_STEP_POWER_ON_DELAY:
            
            // perform dummy reads while waiting...
            vin = ADC_VIN_ADCBUF;
            vout = ADC_VOUT_ADCBUF;
            
            // set soft-start status
            soft_start.status.flag.active = 1;
            
            // wait until the power on delay has expired
            if(soft_start.startup_counter-- == 0)
            { 
                // switch to ramp-up period
                soft_start.startup_counter = soft_start.ramp_up_period; 
                soft_start.startup_phase = SOFT_START_STEP_RAMP_UP;
            }
            break;
    
        case SOFT_START_STEP_RAMP_UP:
            
            // always read output voltage 
            vout = ADC_VOUT_ADCBUF;
            if(vout == 0)
            { soft_start.status.flag.ctrl_flt = 1; }
            else
            { soft_start.status.flag.ctrl_flt = 0; }
            
            if(first_run)
            {

                // Read input and output voltage and estimate the appropriate steady state control output 
                vin = (ADC_VIN_ADCBUF << VIN2VOUT_NORM_BSFT);
                if(vout > ctrl_v_reference) { vout = ctrl_v_reference; }
                
                if(vin != 0)
                { 
                    // Pre-charge the control histories for smooth transition (no unity step))
                    dummy = ((float)vout / (float)vin);
                    dummy *= ((float)SWITCHING_PERIOD);
                    ctrl_output = (uint16_t)dummy;
                    cnpnz_vmc_Precharge(&cnpnz_vmc, 0, ctrl_output);
                }
                else
                {
                    // Reset controller and start from scratch
                    cnpnz_vmc_Reset(&cnpnz_vmc);
                }

/*               // calculate the ramp-up step size to meet ramp timing
                dummy = ((float)ctrl_v_reference - (float)vout);
                dummy = ((float)(dummy)/((float)soft_start.ramp_up_period));
                ctrl_ref_step_size = (uint16_t)dummy;
                if(ctrl_ref_step_size == 0) { ctrl_ref_step_size = 1; }
*/                
                // store target reference and reset control reference to starting point
                ctrl_ref_buffer = ctrl_v_reference;
                ctrl_v_reference = (vout + ctrl_ref_step_size);
                
                // enable PWM outputs and controller
//                fres = gspwm_ovr_output_release(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW);
                cnpnz_vmc.status.flag.enable = 1;   // enable controller (close the loop)
                
                first_run = 0;  // reset "first run" flag
            }

            // wait until control loop activity has been detected
            while((!CVRT_SEV_IRQ_IF) && (timeout++ < 50000));
            
            // ToDo: Trip fault if control loop interrupt is not starting
            if (timeout >= 50000)
            { soft_start.status.flag.irq_flt = 1; }
            else
            { soft_start.status.flag.irq_flt = 0; } // Control loop has been started properly
            
            // increment the control reference until it reaches nominal level
            if((ctrl_v_reference + ctrl_ref_step_size) < ctrl_ref_buffer)
            { ctrl_v_reference += ctrl_ref_step_size; }
            else
            { ctrl_v_reference = ctrl_ref_buffer; }

            if(soft_start.startup_counter-- == 1) 
            { ctrl_v_reference = ctrl_ref_buffer; }

            // when ramp-up is completed, switch to Power Good Delay
            if((soft_start.startup_counter == 0) && (ctrl_v_reference >= ctrl_ref_buffer))
            {
                soft_start.startup_counter = soft_start.power_good_delay; 
                soft_start.startup_phase = SOFT_START_STEP_POWER_GOOD_DELAY;
            }
            
            break;
            
        case SOFT_START_STEP_POWER_GOOD_DELAY:
            
            // wait until Power Good Delay has expired
            if(soft_start.startup_counter-- == 0)
            { 
                // switch to "Soft-Start Complete"
                soft_start.startup_counter = 0;
                soft_start.startup_phase = SOFT_START_STEP_COMPLETE;
                task_mgr.op_mode.mode = OP_MODE_NORMAL; // switch to normal operation
            }
            break;
        
        case SOFT_START_STEP_COMPLETE:
            
            // if this routine is called again after a soft-start has been performed, it will 
            // automatically reset the sequence and start from scratch
            soft_start.startup_phase = SOFT_START_STEP_INIT;
            soft_start.status.flag.active = 0;
            break;
            
        default:
            // un-initialized soft-start => return error
            return(0);
            break;
    }

    // set common fault state
    soft_start.status.flag.fault = (soft_start.status.flag.irq_flt | soft_start.status.flag.ctrl_flt);
    
    
/*    
    if(CVRT_PH1_PDC < 1000)
    {
        CVRT_PH1_PDC += 10;
    }
    else
    {
        cnpnz_vmc.status.flag.enable = 1;   // enable controller (close the loop)
        task_mgr.op_mode.mode = OP_MODE_NORMAL; // switch to normal operation
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
    }
*/
    
    return(1);
}
