/*
 * File:   soft_start.c
 * Author: M91406
 *
 * Created on July 31, 2018, 1:31 PM
 */


#include "task_FaultHandler.h"
#include "task_SoftStart.h"
#include "syscfg_startup.h"
#include "tasks.h"
#include "init_control.h"

volatile uint16_t first_run = 1;
volatile uint16_t ctrl_ref_buffer = 0;

volatile SOFT_START_OBJECT_t soft_start;
#if (INCLUDE_SOFT_SHUT_DOWN == 1)
volatile SOFT_SHUT_DOWN_OBJECT_t soft_shutdwn;
#endif 

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
volatile uint16_t init_soft_start(void)
{
    
    /* ToDo: this is a placeholder soft-start function not suited for real application
     * A fully functional soft-start driver is required */

    soft_start.status.flags = 0;   // Reset soft-start status (including enable bit)
    soft_start.phase = SOFT_START_STEP_INIT;    // Set startup-phase to procedure initialization
    soft_start.power_on_delay = POWER_ON_DELAY_TICKS; // set start-up delay
    soft_start.ramp_up_period = RAMP_UP_PERIOD_TICKS; // set ramp-up period 
    soft_start.ref_increment = (ctrl_v_reference / RAMP_UP_PERIOD_TICKS);
    soft_start.power_good_delay = POWER_GOOD_DELAY_TICKS; // set power good delay
    
    soft_start.output_tracking_filter = 0xFFC0; // Value-filter for output tracking
    
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
 * State-machine driving the output into regulation
 *
 * Description:	
 * This routine starts the power converter stage considering the most recent 
 * input/output conditions and drives up the output to the desired output state.
 * The start-up timing is defined in syscfg_startup.h and covers three phases:
 * 
 *  - Power On Delay: the firmware waits until the given time period has
 *                    expired
 *  - Ramp Up Period: the firmware starts at the recent output value and drives
 *                    the control reference  up until the output has reached the
 *                    nominal regulation point.
 *  - Power Good Delay: The firmware waits until the given time period has expired
 *                    before switching over into "Normal Operation Mode"
 *
 * See also:
 * init_hspwm_
 * 
 *****************************************************************************/
volatile uint16_t exec_soft_start(void)
{
    volatile uint16_t vin = 0, vout = 0, ctrl_output = 0, timeout = 0;
    volatile float dummy = 0.0;

    // Exit if Soft-Start is not enabled yet
    if (!soft_start.status.flag.enable) return(1);
    
    switch (soft_start.phase)
    {
        case SOFT_START_STEP_INIT:
            
            // Initiate the power-on delay
            soft_start.counter = soft_start.power_on_delay;
            soft_start.phase = SOFT_START_STEP_POWER_ON_DELAY;
            soft_start.status.flag.ctrl_flt = 0;
            soft_start.status.flag.irq_flt = 0;
            soft_start.status.flag.fault = 0;
            soft_start.status.flag.active = 0;

            fault_object_list[FLTOBJ_SOFT_START]->status.flags.fltchken = 1;
            fault_object_list[FLTOBJ_UVLO]->status.flags.fltchken = 1;
            fault_object_list[FLTOBJ_OVLO]->status.flags.fltchken = 1;

            first_run = 1;
            
            break;
    
        case SOFT_START_STEP_POWER_ON_DELAY:

            // perform dummy reads while waiting...
            vin = ADC_VIN_ADCBUF;
            vout = ADC_VOUT_ADCBUF;
            
            // set soft-start status
            soft_start.status.flag.active = 1;
            
            // wait until the power on delay has expired
            if(soft_start.counter-- == 0)
            { 
                // switch to ramp-up period
                soft_start.counter = soft_start.ramp_up_period; 
                soft_start.phase = SOFT_START_STEP_RAMP_UP;
            }
            break;
    
        case SOFT_START_STEP_RAMP_UP:

            // always read output voltage to track if soft-start is showing effect
            vout = ADC_VOUT_ADCBUF;
            
            // Initially, determine the ramp starting point, enable the PWM outputs
            // and control loop
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

                // store target reference and reset control reference to starting point
                ctrl_ref_buffer = ctrl_v_reference;
                ctrl_v_reference = (vout + soft_start.ref_increment);
                
                // enable PWM outputs and controller
                hspwm_ovr_output_release(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW);
                cnpnz_vmc.status.flag.enable = 1;   // enable controller (close the loop)
                
                // wait until control loop activity has been detected at least once
                CVRT_SEV_IRQ_IF = 0;
                if (!INTCON2bits.GIE)
                { INTCON2bits.GIE = 1; }
                while((!CVRT_SEV_IRQ_IF) && (timeout++ < 50000));
            
                // ToDo: Trip fault if control loop interrupt is not starting
                if (timeout >= 50000)
                { soft_start.status.flag.irq_flt = 1; }
                // Control loop has been started properly
                else
                { soft_start.status.flag.irq_flt = 0; }
            
                // reset "first run" flag
                first_run = 0;  

            }

            // Check if output voltage is following the reference
            if((vout & soft_start.output_tracking_filter) == (ctrl_v_reference & soft_start.output_tracking_filter))
            { soft_start.status.flag.ctrl_flt = 1; }
            else
            { soft_start.status.flag.ctrl_flt = 0; }
            
            // increment the control reference until it reaches nominal level
            if((ctrl_v_reference + soft_start.ref_increment) < ctrl_ref_buffer)
            { ctrl_v_reference += soft_start.ref_increment; }
            else
            { ctrl_v_reference = ctrl_ref_buffer; }

            if(soft_start.counter-- == 1) 
            { ctrl_v_reference = ctrl_ref_buffer; }

            // when ramp-up is completed, switch to Power Good Delay
            if((soft_start.counter == 0) && (ctrl_v_reference >= ctrl_ref_buffer))
            {
                soft_start.counter = soft_start.power_good_delay; 
                soft_start.phase = SOFT_START_STEP_POWER_GOOD_DELAY;
            }
            
            break;
            
        case SOFT_START_STEP_POWER_GOOD_DELAY:
            
            // wait until Power Good Delay has expired
            if(soft_start.counter-- == 0)
            { 
                // switch to "Soft-Start Complete"
                soft_start.counter = 0;
                soft_start.phase = SOFT_START_STEP_COMPLETE;
            }
            break;
        
        case SOFT_START_STEP_COMPLETE:
            
            // if this routine is called again after a soft-start has been performed, it will 
            // automatically reset the sequence and start from scratch
            soft_start.status.flag.active = 0;
            task_mgr.op_mode.mode = OP_MODE_NORMAL; // switch to normal operation
            soft_start.phase = SOFT_START_STEP_INIT;
            break;
            
        default:
            // un-initialized soft-start => return error
            return(0);
            break;
    }

    // set common fault state
    soft_start.status.flag.fault = (soft_start.status.flag.irq_flt | soft_start.status.flag.ctrl_flt);
    
    
    return(1);
}

#if (INCLUDE_SOFT_SHUT_DOWN == 1)


/*@@init_soft_shut_down
 *****************************************************************************
 * Function:	 uint16_t init_soft_shut_down(void)
 * Arguments:	 (none)
 * Return Value: 
 *  1: success
 *  0: failure
 *
 * Summary:
 * drives down the output and turns off control and PWM
 *
 * Description:	
 * This routine is test code only to evaluate soft shut down implementations
 *
 * See also:
 * init_HSPWM
 * 
 *****************************************************************************/
volatile uint16_t init_soft_shut_down(void)
{
    
    /* ToDo: this is a placeholder soft-start function not suited for real application
     * A fully functional soft-start driver is required */

    soft_shutdwn.status.flags = 0;   // Reset soft-start status (including enable bit)
    soft_shutdwn.phase = SOFT_SHUT_DOWN_STEP_INIT;    // Set startup-phase to procedure initialization
    soft_shutdwn.power_off_delay = POWER_OFF_DELAY_TICKS; // set start-up delay
    soft_shutdwn.ramp_down_period = RAMP_DOWN_PERIOD_TICKS; // set ramp-up period 
    soft_shutdwn.ref_decrement = (ctrl_v_reference / RAMP_DOWN_PERIOD_TICKS);
    
    soft_shutdwn.output_tracking_filter = 0xFFC0; // Value-filter for output tracking
    
    soft_shutdwn.status.flag.enable = 1; // enable soft start
 
    return(1);
}

/*@@exec_soft_shut_down
 *****************************************************************************
 * Function:	 uint16_t exec_soft_shut_down(void)
 * Arguments:	 (none)
 * Return Value: 
 *  1: success
 *  0: failure
 *
 * Summary:
 * State-machine driving the output down to zero
 *
 * Description:	
 * This routine shuts down the power converter stage considering the most recent 
 * input/output conditions and drives down the output to the desired output state (zero).
 * The shut-down timing is defined in syscfg_startup.h and covers three phases:
 * 
 *  - Power Off Delay: the firmware waits until the given time period has
 *                    expired before ramping down the output
 *  - Ramp Down Period: the firmware starts at the recent output value and drives
 *                    the control reference down until the output has reached the
 *                    nominal off point (e.g. zero).
 *
 * See also:
 * init_HSPWM
 * 
 *****************************************************************************/
volatile uint16_t exec_soft_shut_down(void)
{
    volatile uint16_t vin = 0, vout = 0, timeout = 0;

    // Exit if Soft Shut Down is not enabled yet
    if (!soft_shutdwn.status.flag.enable) return(1);
    
    switch (soft_shutdwn.phase)
    {
        case SOFT_SHUT_DOWN_STEP_INIT:
            
            // Initiate the power-on delay
            soft_shutdwn.counter = soft_shutdwn.power_off_delay;
            soft_shutdwn.phase = SOFT_SHUT_DOWN_STEP_POWER_OFF_DELAY;
            soft_shutdwn.status.flag.ctrl_flt = 0;
            soft_shutdwn.status.flag.irq_flt = 0;
            soft_shutdwn.status.flag.fault = 0;
            soft_shutdwn.status.flag.active = 0;

            fault_object_list[FLTOBJ_SOFT_SHUT_DOWN]->status.flags.fltchken = 1;

            first_run = 1;
            
            break;
    
        case SOFT_SHUT_DOWN_STEP_POWER_OFF_DELAY:

            // perform dummy reads while waiting...
            vin = ADC_VIN_ADCBUF;
            vout = ADC_VOUT_ADCBUF;
            
            // set soft-start status
            soft_shutdwn.status.flag.active = 1;
            
            // wait until the power off delay has expired
            if(soft_shutdwn.counter-- == 0)
            { 
                // switch to ramp-up period
                soft_shutdwn.counter = soft_shutdwn.ramp_down_period; 
                soft_shutdwn.phase = SOFT_SHUT_DOWN_STEP_RAMP_DOWN;
            }
            break;
    
        case SOFT_SHUT_DOWN_STEP_RAMP_DOWN:

            // always read output voltage to track if soft-shut down is showing effect
            vout = ADC_VOUT_ADCBUF;
            
            // Initially, determine the ramp starting point
            if(first_run)
            {

                // Store target reference and reset control reference to starting point
                ctrl_ref_buffer = ctrl_v_reference;
                
                if(soft_shutdwn.ref_decrement < ctrl_v_reference)
                { ctrl_v_reference -= soft_shutdwn.ref_decrement; }
                else
                { ctrl_v_reference = 0; }
                
                
                // wait until control loop activity has been detected at least once
                CVRT_SEV_IRQ_IF = 0;
                if (!INTCON2bits.GIE)
                { INTCON2bits.GIE = 1; }
                while((!CVRT_SEV_IRQ_IF) && (timeout++ < 50000));
            
                // ToDo: Trip fault if control loop interrupt is not starting
                if (timeout >= 50000)
                { soft_shutdwn.status.flag.irq_flt = 1; }
                // Control loop has been started properly
                else
                { soft_shutdwn.status.flag.irq_flt = 0; }
            
                // reset "first run" flag
                first_run = 0;  

            }

            // Check if output voltage is following the reference
            if((vout & soft_shutdwn.output_tracking_filter) == (ctrl_v_reference & soft_shutdwn.output_tracking_filter))
            { soft_shutdwn.status.flag.ctrl_flt = 1; }
            else
            { soft_shutdwn.status.flag.ctrl_flt = 0; }
            
            // increment the control reference until it reaches nominal level
            if((ctrl_v_reference > soft_shutdwn.ref_decrement))
            { ctrl_v_reference -= soft_shutdwn.ref_decrement; }
            else
            { ctrl_v_reference = 0; }

            if(soft_shutdwn.counter-- == 1) 
            { ctrl_v_reference = 0; }

            // when ramp-up is completed, switch to Power Good Delay
            if((soft_shutdwn.counter == 0) && (ctrl_v_reference == 0))
            {
                // switch to "Soft-Shut Down Complete"
                soft_shutdwn.counter = 0;
                soft_shutdwn.phase = SOFT_SHUT_DOWN_STEP_COMPLETE;
            }
            break;
        
        case SOFT_SHUT_DOWN_STEP_COMPLETE:
            
            // if this routine is called again after a soft-start has been performed, it will 
            // automatically reset the sequence and start from scratch
            soft_shutdwn.status.flag.active = 0;
            task_mgr.op_mode.mode = OP_MODE_STANDBY; // switch to normal operation
            soft_shutdwn.phase = SOFT_SHUT_DOWN_STEP_INIT;
            
            // disable PWM outputs and controller
            hspwm_ovr_output_hold(CVRT_PH1_PWM_IDX, PWMx_HIGH_LOW);
            cnpnz_vmc.status.flag.enable = 0;   // disable controller (close the loop)
            
            break;
            
        default:
            // un-initialized soft-start => return error
            return(0);
            break;
    }

    // set common fault state
    soft_shutdwn.status.flag.fault = (soft_shutdwn.status.flag.irq_flt | soft_shutdwn.status.flag.ctrl_flt);
    
    
    return(1);
}

#endif

