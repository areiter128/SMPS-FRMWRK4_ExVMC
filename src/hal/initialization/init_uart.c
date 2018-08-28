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

#include "init_uart.h"

/*@@init_smps_uart
 *****************************************************************************
 * Function:	 uint16_t init_smps_uart(void)
 * Arguments:	 (none)
 * Return Value: 1: success, 2: failure)
 *
 * Summary:
 * Initializes the UART module and opens a port
 *
 * Description:	
 * This routine initializes the UART peripheral module of the dsPIC33 and opens 
 * a port with user defined settings. 
 * Multiple UARTs can be used in parallel using the initialization routine 
 * below.
 *
 * See also:
 * (none)
 * 
 *****************************************************************************/
volatile uint16_t init_smps_uart(void)
{

    volatile uint16_t fres=1;

    /* map UART pins to device pins */
    pps_UnlockIO();
    pps_RemapInput(CVRT_UART_RX_PPS_NO, CVRT_UART_RX_PPS);
    pps_RemapOutput(CVRT_UART_TX_PPS_NO, CVRT_UART_TX_PPS);
    pps_LockIO();
    
    UART_TX_INIT;
    
    /* Turn on power to comparator module, as, well as comparators for phase #1 and #2 */
    fres &= gsuart_power_on(CVRT_UART_IDX);

	/* Initialize UART for monitoring & control */
	fres &= gsuart_open_port(CVRT_UART_IDX, 
                CVRT_UART_BAUDRATE, CVRT_UART_DATA_BITS, CVRT_UART_PARITY, CVRT_UART_STOP_BITS, 
                CVRT_UART_IRS_PRIORITY);

    
	return(fres);

}
