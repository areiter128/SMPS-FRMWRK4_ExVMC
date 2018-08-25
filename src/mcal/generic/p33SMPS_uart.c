/*LICENSE ********************************************************************
 * Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 * ***************************************************************************/
/*@@p33MP_timer.c
 * ***************************************************************************
 * Summary:
 * Driver file for the dsPIC33xxxGS UART SFRs
 *
 * Description:
 * The uart module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 *
 * File:   p33SMPS_uart.c
 * Author: M91406
 *
 * Created on October 26, 2017, 1:10 PM
 * 
 * Revision:
 * 
 * ***************************************************************************/

// Device header file
#include <xc.h>
#include <stdint.h>

#include "p33SMPS_uart.h"


/*@@p33SMPS_uart.c
 * ************************************************************************************************
 * Summary:
 * Driver file for the dsPIC33xxxGS and dsPIC33xxxMP UART SFRs
 *
 * Description:
 * The uart module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 * ***********************************************************************************************/

/*@@gstmr_init_uart
 * ************************************************************************************************
 * Summary:
 * Initializes a specific UART unit
 *
 * Parameters:
 *	index		= selects the register address range of the target UART unit
 *	regUxMODE   = Basic UART unit configuration
 *	regUxSTA    = Enhanced UART unit configuration and status bits
 *
 * Description:
 * This routine is setting the uart configuration. This routine needs to be called before a UART
 * port is opened to ensure the baudrate settings and hardware flow control is applied properly.
 * ***********************************************************************************************/

uint16_t gsuart_init_uart(uint16_t index, UxMODE_CONTROL_REGISTER_t regUxMODE, UxSTA_CONTROL_REGISTER_t regUxSTA)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0;

	if (index > UART_UART_COUNT) return(0);
    
	reg_offset = ((index-1) * UART_INDEX_REG_OFFSET);

    regptr  = (volatile uint16_t *)&U1MODE;
    *regptr = (((uint16_t)regUxMODE.reg_block & UART_UxMOD_REG_WRITE_MASK) & UART_UxMOD_REG_OFF_MASK);	// UART ENABLE is masked out !!!
    
    regptr  = (volatile uint16_t *)&U1STA;
    *regptr = ((uint16_t)regUxSTA.reg_block & UART_UxSTA_REG_WRITE_MASK);	// may reset all status bits

    return(1);
}

/*@@gsuart_open_port
 * ************************************************************************************************
 * Summary:
 * Initializes a specific UART unit
 *
 * Parameters:
 *	index		= selects the register address range of the target UART unit
 *	baud        = baudrate of the selected UART unit
 *	data_bits   = number of data bits of the selected UART unit
 *	parity      = parity setting of the selected UART unit
 *	stop_bits   = number of stop bits of the selected UART unit
 * isr_priority = interrupt service routine priority of this UART unit
 *
 * Description:
 * This routine is setting the timer pre-scaler in accordance to apply the
 * desired period using a 16-bit time base. Therefore the 16bit mode is enforced
 * and any pre-scaler settings will be ignored. The timer will remain disabled after
 * initialization and has to be enabled by the user.
 * ***********************************************************************************************/

uint16_t gsuart_open_port(uint16_t index, 
    UART_BAUDRATE_SETTING_e baud, UART_DATA_BIT_SETTING_e data_bits, UART_PARITY_SETTING_e parity, UART_STOP_BIT_SETTING_e stop_bits, 
    UART_ISR_PRIORITY_e isr_priority)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0, reg_buf=0;
    volatile uint32_t brg_buf=0;

	if (index > UART_UART_COUNT) return(0);     // Check if index is valid
    
    // Determine SFR offset depending on given index
	reg_offset = ((index - 1) * (volatile uint16_t)UART_INDEX_REG_OFFSET);

    // Set data bits and parity
    switch(data_bits)
    {
        case UART_DATA_BITS_8:
            
            switch(parity)
            {
                case UART_PARITY_NONE:
                    reg_buf |= REG_PDSEL_8_DBITS_NO_PARITY;
                    break;

                case UART_PARITY_ODD:
                    reg_buf |= REG_PDSEL_8_DBITS_ODD_PARITY;
                    break;

                case UART_PARITY_EVEN:
                    reg_buf |= REG_PDSEL_8_DBITS_EVEN_PARITY;
                    break;
                
                default:    // invalid setting
                    return(0);
                    break;
            }
            
            break;
            
        case UART_DATA_BITS_9:
            reg_buf |= REG_PDSEL_9_DBITS_NO_PARITY;
            break;
            
        default:    // invalid setting
            return(0);
            break;
    }        
    
    // set stop-bits
    switch(stop_bits)
    {
        case UART_STOP_BITS_1:
            reg_buf |= REG_STSEL_1_STOP_BIT;
            break;
            
        case UART_STOP_BITS_2:
            reg_buf |= REG_STSEL_2_STOP_BIT;
            break;

        default:    // invalid setting
            return(0);
            break;
    }        
    
    // Calculate the baud rate 
    brg_buf = UxBRGL(baud);
    
    if(brg_buf < 0xFFFF)
    { 
        reg_buf |= REG_BRGH_STANDARD; 
    }
    else
    { 
        brg_buf = UxBRGH(baud);
        reg_buf |= REG_BRGH_HIGH_SPEED; 
    }

    
    // Set the baud rate register
    regptr  = (volatile uint16_t *)&U1BRG + reg_offset;
    *regptr = ((volatile uint16_t)brg_buf & UART_UxBRG_REG_WRITE_MASK);	
    
    // Set basic configuration
    regptr  = (volatile uint16_t *)&U1MODE + reg_offset;
    *regptr = ((reg_buf & UART_UxMOD_REG_WRITE_MASK) | REG_UARTEN_ON);	// UART ENABLE is masked out !!!

    
	return(1);

}

/*@@gsuart_enable
 * ************************************************************************************************
 * Summary:
 * Enables a specific, pre-configured UART unit 
 *
 * Parameters:
 *	index		= selects the register address range of the target UART unit
 *
 * Description:
 * This routine is enabling the selected UART as it was configured previously.
 * ***********************************************************************************************/

uint16_t gsuart_enable(uint16_t index)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0, reg_buf=0;
	
	if (index > UART_UART_COUNT) return(0); // Skip if index is out of range

	reg_offset = ((index-1) * UART_INDEX_REG_OFFSET);

    regptr  = (volatile uint16_t *)&U1MODE;
    reg_buf = (*regptr | REG_UARTEN_ON);
    *regptr = (reg_buf & UART_UxMOD_REG_WRITE_MASK);	

	return(1);

}

/*@@gsuart_disable
 * ************************************************************************************************
 * Summary:
 * Disables a specific, pre-configured UART unit 
 *
 * Parameters:
 *	index		= selects the register address range of the target UART unit
 *
 * Description:
 * This routine is disabling the selected UART as it was configured previously.
 * ***********************************************************************************************/

uint16_t gsuart_disable(uint16_t index)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0, reg_buf=0;
	
	if (index > UART_UART_COUNT) return(0); // Skip if index is out of range

	reg_offset = ((index-1) * UART_INDEX_REG_OFFSET);

    regptr  = (volatile uint16_t *)&U1MODE;
    reg_buf = (*regptr & UART_UxMOD_REG_OFF_MASK);
    *regptr = (reg_buf & UART_UxMOD_REG_WRITE_MASK);	

	return(1);

}


/*@@gsuart_dispose
 * ************************************************************************************************
 * Summary:
 * Resets a specific UART unit 
 *
 * Parameters:
 *	index		= selects the register address range of the target UART unit
 *
 * Description:
 * This routine is disabling the selected UART and resets its entire configuration.
 * ***********************************************************************************************/

uint16_t gsuart_dispose(uint16_t index)
{
	
    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0;
	
	if (index > UART_UART_COUNT) return(0); // Skip if index is out of range

	reg_offset = ((index-1) * UART_INDEX_REG_OFFSET);
	
    regptr  = (volatile uint16_t *)&U1MODE;
    *regptr = UART_UxMOD_REG_DISPOSE_MASK;
    
    regptr  = (volatile uint16_t *)&U1STA;
    *regptr = UART_UxSTA_REG_DISPOSE_MASK;	
    
	return(1);

}

/*@@gsuart_power_on
 * ************************************************************************************************
 * Summary:
 * Turns on the power to a given UART unit 
 *
 * Parameters:
 *	index		= selects the PMD register-bit of the target UART unit
 *
 * Description:
 * This routine is enabling the power supply to the user-defined UART module.
 * ***********************************************************************************************/

uint16_t gsuart_power_on(uint16_t index)
{

	if (index > UART_UART_COUNT) return(0); // Skip if index is out of range

    // Turn on power to peripheral module
    #ifdef _U1MD
        if(index == 1) { _U1MD = 0; }
    #endif
    #ifdef _U2MD
        if(index == 2) { _U2MD = 0; }
    #endif
    #ifdef _U3MD
        if(index == 3) { _U3MD = 0; }
    #endif
    #ifdef _U4MD
        if(index == 4) { _U4MD = 0; }
    #endif

	return(1);

}


/*@@gsuart_power_off
 * ************************************************************************************************
 * Summary:
 * Turns off the power to a given UART unit 
 *
 * Parameters:
 *	index		= selects the PMD register-bit of the target UART unit
 *
 * Description:
 * This routine is disabling the power supply to the user-defined UART module.
 * ***********************************************************************************************/

uint16_t gsuart_power_off(uint16_t index)
{

	if (index > UART_UART_COUNT) return(0); // Skip if index is out of range

    // Turn on power to peripheral module
    #ifdef _U1MD
        if(index == 1) { _U1MD = 1; }
    #endif
    #ifdef _U2MD
        if(index == 2) { _U2MD = 1; }
    #endif
    #ifdef _U3MD
        if(index == 3) { _U3MD = 1; }
    #endif
    #ifdef _U4MD
        if(index == 4) { _U4MD = 1; }
    #endif

	return(1);

}


// EOF
