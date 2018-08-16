/*
 * File:   control.c
 * Author: M91406
 *
 * Created on July 25, 2018, 8:31 PM
 */


#include "init_control.h"

/* ***************************************************************************************
 * Global converter default settings, threshold and scaling
 * ***************************************************************************************/

volatile uint16_t ctrl_v_reference  = 0;

/* ***************************************************************************************/


/* ***************************************************************************************/

/*@@init_VMC_Controller
 *****************************************************************************
 * Function:	 uint16_t init_VMC_Controller(void)
 * Arguments:	 (none)
 * Return Value: 
 *  1: success
 *  0: failure
 *
 * Summary:
 * Initializes the voltage loop controller
 * 
 * Description:	
 * Configures the voltage loop controller data structure, loads default 
 * coefficients and clears the control histories.
 *
 * See also:
 * 
 * 
 *****************************************************************************/
volatile uint16_t init_VMC_Controller(void)
{

    volatile uint16_t fres = 0;
    
	fres = cnpnz_vmc_Init();
    
    ctrl_v_reference  = (uint16_t)VOUT_FB_REF_ADC;
    
    cnpnz_vmc.ptrControlReference = &ctrl_v_reference;
    cnpnz_vmc.ptrSource = &VOUT_FB_ADCBUF;
    cnpnz_vmc.ptrTarget = &CVRT_PH1_PDC;
    cnpnz_vmc.ptrADCTriggerRegister = &ADC_VOUT_TRIG;
    cnpnz_vmc.ADCTriggerOffset = (ADC_TRIGGER_OFFSET + (SWITCHING_PERIOD_NOM >> 1));
    cnpnz_vmc.MinOutput = DUTY_RATIO_MIN_REG;
    cnpnz_vmc.MaxOutput = DUTY_RATIO_MAX_REG;
    
//    cnpnz_vmc.status.flag.enable = 1;
    
    return(fres);
    
}
