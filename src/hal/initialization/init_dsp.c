/*LICENSE *****************************************************************************
 * 
 * Software License Agreement
 *
 * Copyright � 2015 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED ìAS ISî WITHOUT WARRANTY OF ANY
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


#include <xc.h>
#include <stdint.h>

#include "hal.h"
#include "mcal.h"

/*@@init_dsp
 *****************************************************************************
 * Function:	 void init_dsp(void)
 * Arguments:	 (none)
 * Return Value: true/false
 *
 * Summary:
 * initializes the embedded digital signal processor core
 *
 * Description:	
 * This routine initializes the embedded digital signal processor core with  
 * basic settings for fractional computations, 
 * 
 **************************************************************************/

volatile uint16_t init_dsp(void)
{

    volatile uint16_t fres = 0;
    
	fres = gsdsp_init_dsp(
	
		REG_CORCON_VAR_FIXED	|		// Variable Exception Processing Latency disabled
        REG_CORCON_US_SIGNED	|		// Signed multiplications
		REG_CORCON_EDT_OFF		|		// Early DO loop termination disabled
		REG_CORCON_SATA_ON		|		// Saturation enabled for accumulator A
		REG_CORCON_SATB_ON		|		// Saturation enabled for accumulator B
		REG_CORCON_SATDW_ON		|		// Saturation enabled for writes to data space
		REG_CORCON_ACCSAT_131	|		// Accumulator saturation mode 1.31
		REG_CORCON_RND_UNBIASED	|		// Unbiased (convergent) rounding enabled
		REG_CORCON_IF_FRACTIONAL |		// Fractional multiplier mode enabled
        REG_CORCON_SFA_ACTIVE           // WREG14/WREG15 are used for stack- and frame pointer
	
	);

	return(fres);

}

