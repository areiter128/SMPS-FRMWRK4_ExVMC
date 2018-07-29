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

uint16_t ctrl_v_reference  = 0;

/* ***************************************************************************************/

volatile CONVERTER_t cvrt;		// Declare a CONVERTER_t Data Structure (e.g. cvrt_converter)

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
uint16_t init_VMC_Controller(void)
{

    uint16_t fres = 0;
    
	fres = cnpnz_vmc_Init();
    
    ctrl_v_reference  = (uint16_t)VOUT_FB_REF_ADC;
    
    cnpnz_vmc.ptrControlReference = &ctrl_v_reference;
    cnpnz_vmc.ADCTriggerOffset = ADC_TRIGGER_OFFSET;
    cnpnz_vmc.MinOutput = DUTY_RATIO_MIN;
    cnpnz_vmc.MaxOutput = DUTY_RATIO_MAX;
    
    return(fres);
    
}
