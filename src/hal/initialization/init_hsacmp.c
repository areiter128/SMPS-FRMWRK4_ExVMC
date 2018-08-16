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

#include "init_hsacmp.h"

/*@@init_hsacmp
 *****************************************************************************
 * Function:	 uint16_t init_hsacmp(void)
 * Arguments:	 (none)
 * Return Value: 1: success, 2: failure)
 *
 * Summary:
 * Initializes the high-speed analog comparator module
 *
 * Description:	
 * This routine initializes the high-speed analog comparator module of dsPIC33F GS. 
 * Multiple comparators are used to trigger certain events like over-current and 
 * over-voltage conditions. A comparator is also used for peak current control mode 
 * when enabled.
 *
 * See also:
 * init_ADC, init_PWM
 * 
 *****************************************************************************/
volatile uint16_t init_hsacmp(void)
{

    volatile uint16_t fres=1;

    /* Turn on power to comparator module, as, well as comparators for phase #1 and #2 */
    fres &= gscmp_module_power_up();    
    fres &= gscmp_channel_power_up(CVRT_OCP_CMP_IDX);
    fres &= gscmp_channel_power_up(CVRT_OVP_CMP_IDX);

	/* Initialize comparators for phase #1 and #2   */
	fres &= gscmp_init(CVRT_OCP_CMP_IDX, CVRT_OCP_CMP_CFG, CVRT_OCP_CMP_MAX);
	fres &= gscmp_select_input(CVRT_OCP_CMP_IDX, CVRT_OCP_CMP_INPUT);			// Index of the comparator input used
	fres &= gscmp_set_threshold(CVRT_OCP_CMP_IDX, CVRT_OCP_CMP_MAX);          // DAC threshold

	fres &= gscmp_init(CVRT_OVP_CMP_IDX, CVRT_OVP_CMP_CFG, CVRT_OVP_CMP_MAX);
	fres &= gscmp_select_input(CVRT_OVP_CMP_IDX, CVRT_OVP_CMP_INPUT);			// Index of the comparator input used
	fres &= gscmp_set_threshold(CVRT_OVP_CMP_IDX, CVRT_OVP_CMP_MAX);          // DAC threshold

	return(fres);

}

/*@@launch_HSACMP
 *****************************************************************************
 * Function:	 int launch_HSACMP(void)
 * Arguments:	 (none)
 * Return Value: 1: success, 2: failure)
 *
 * Summary:
 * Activates the high-speed analog comparator module
 *
 * Description:	
 * This routine activates the high-speed analog comparator module of dsPIC33 GS. 
 * Multiple comparators are used to trigger certain events like over-current and 
 * over-voltage conditions. A comparator is also used for peak current control mode 
 * when enabled.
 *
 * See also:
 * init_ADC, init_HSPWM
 * 
 *****************************************************************************/
volatile uint16_t exec_launch_hsacmp(void)
{

    volatile uint16_t fres=1;

    fres &= gscmp_enable(CVRT_OCP_CMP_IDX);
    fres &= gscmp_enable(CVRT_OVP_CMP_IDX);

    return(fres);
}