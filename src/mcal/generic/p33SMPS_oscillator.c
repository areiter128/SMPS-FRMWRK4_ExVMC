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
/* @@p33SMPS_oscillator.c
 * ***************************************************************************
 *
 * File:   p33SMPS_oscillator.c
 * Author: M91406
 *
 * Created on October 27, 2017, 11:24 AM
 * ***************************************************************************/

/* ************************************************************************************************
 * PRIVATE DEFINES
 * ************************************************************************************************/

#include <stdint.h>
#include "p33SMPS_oscillator.h"

/* ************************************************************************************************
 * PRIVATE DEFINES
 * ************************************************************************************************/
#define OSC_CLKSW_TIMEOUT	5000	// value to set the timeout for clock switching operations



/*@@init_FOSC(t_OSC_CONFIG OscCfg, t_OSC_FRCDIVN FrcDiv, int8_t FrcTune)
 * ************************************************************************************************
 * Summary:
 * Initializes the major oscillator and the PLL module step by step by using clock switching
 * in software. Each step is tested and verified
 *
 * Parameters:
 *	t_OSC_CONFIG OscCfg (includes oscillator type and PLL configuration)
 *  t_OSC_FRCDIVN FrcDiv (Fast RC Oscillator post divider)
 *	signed int FrcTune (Fast RC oscillator tuning valie)
 *
 * Returns:
 *  0 = unspecified clock failure detected
 *  1 = clock switch successful
 *  2 = clock switch failed
 *  4 = currently selected clock differs from selected clock source
 *  8 = PLL didn't lock in within given time frame
 *
 * Description:
 * Microchip's 16-Bit devices offer a safe 2-step start-up mode, using the internal FRC during power up, 
 * followed by a user defined switch-over to the desired oscillator. 
 * Though this can also be done in hardware automatically, this software-version of the switch-over offers
 * a better solution to verify each step and enables the user to implement some error handling in the case
 * of failure.
 * This function can be used to select a new oscillator at runtime. Each configuration step
 * will be verified before the next step is performed.
 *
 * Please Note:
 * If a oscillator switch-over is performed, additional settings in the _FOSCSEL and _FOSC
 * registers of the configuration bits may be required
 * ************************************************************************************************/

int16_t init_FOSC(OSC_CONFIG_t OscCfg, OSC_FRCDIVN_e FrcDiv, int8_t FrcTune)
{

    volatile uint16_t i=0, err=0, res=0;

// Configure Oscillator to operate the device at desired speed
//
// Example: Configuration for 180 MHz (=> 90 MIPS) operation with an internal 8 MHz RC oscillator
// 
//    Fosc = Fin  *  M / ( N1 * N2 * N3 )
// => Fosc = 8.00 * 180 / ( 4 *  1 * 1 ) = 360 Mhz
// => Fpllo = Fosc / 2 = 180 MHz

//    Fcy  = Fpllo  / 2
// => Fcy  = 180 Mhz / 2 = 90 MIPS

    // Set oscillator tuning
    if ((FrcTune < FRCTUN_MIN) || (FrcTune > FRCTUN_MAX)) // If FRC Tuning register value is out of range, exit here
    {
        res |= OSCERR_FRCTUN;
    }
    else if(FrcTune != OSCTUNbits.TUN)      // If oscillator tuning is requested...
    {
    	OSCTUNbits.TUN = FrcTune;           // Set Tuning Register for FRC Oscillator
    }
    
    // Set FRC divider
    if(FrcDiv != CLKDIVbits.FRCDIV)         // If fast RC oscillator scaling is requested...
    {
    	CLKDIVbits.FRCDIV   = FrcDiv;       // Set FRC frequency divider
    }

    // Switch to target oscillator
	if ((OSCCONbits.COSC != OscCfg.osc_type) && (OSCCONbits.CLKLOCK == 0))
	{
	// Switch to desired system clock, if clock switching is enabled

	    __builtin_write_OSCCONH(OscCfg.osc_type);           // Specify the new oscillator (e.g.: PRIMARY XT w/ PLL)
    	__builtin_write_OSCCONL(OSCCON | 0x01);  	// Set Switch Command to perform the switch-over

		// Make sure that the desired oscillator is available 
		// and the switch-over was successfully performed

    	// Wait for Clock switch to occur
        while ((OSCCONbits.OSWEN != 0) && (i<OSC_CLKSW_TIMEOUT))
        { i++; }
        if (i>=OSC_CLKSW_TIMEOUT) err = 1;
        i=0;    // reset counter

		while((OSCCONbits.COSC != OSCCONbits.NOSC) && (i<OSC_CLKSW_TIMEOUT))	// Wait for switch-over to
		{ i++; }																// selected Oscillator
        if (i>=OSC_CLKSW_TIMEOUT) err |= 1;
        i=0;    // reset counter
	
		if ((OSCCONbits.OSWEN == 1) || (OSCCONbits.COSC != OSCCONbits.NOSC) || (err==1)) 	// Error occurred? 
		{ res |= OSCERR_CSF; }									// => If yes, return error code
																

	}
	else if ((OSCCONbits.COSC != OscCfg.osc_type) && (OSCCONbits.CLKLOCK == 1))
	{ // If clock switching is disabled, and the current clock differs from the desired clock,
	  // return error code

			res |= OSCERR_CSD;
	}


#if defined (_P33SMPS_WACA_) || defined (_P33SMPS_WACS_)
	// Configure PLL pre-scaler, PLL post-scaler, PLL divisor
    
    CLKDIVbits.PLLPRE	= OscCfg.N1;		// N1 (non zero)
	PLLFBD				= OscCfg.M;         // M  = PLLFBD 
    PLLDIVbits.POST1DIV	= OscCfg.N2;        // N2 (non zero)
    PLLDIVbits.POST2DIV = OscCfg.N3;        // N3 (non zero)

	PLLDIVbits.VCODIV   = OscCfg.VCODIV;    // FVCO Scaler 1:1

#elif defined (_P33SMPS_YGAR_) || defined (_P33SMPS_UEAG_) || defined (_P33SMPS_UEAA_) || \
      defined (_P33SMPS_TLAL_) || defined (_P33SMPS_TLAH_) || defined (_P33SMPS_TLAY_)

    CLKDIVbits.PLLPRE	= OscCfg.N1;		// N1 (non zero)
	PLLFBD				= (OscCfg.M - 2);   // M  = PLLFBD 
    CLKDIVbits.PLLPOST	= OscCfg.N2;        // N2 (non zero)

#else
    #error === selected device not supported by MCAL driver ===
#endif
    
    // Lock registers against accidental changes
    OSCCONbits.CLKLOCK = 1;
    
    while((OSCCONbits.LOCK != 1) && (i<OSC_CLKSW_TIMEOUT))		// Wait 5000 while loops for PLL to Lock
	{ i++; }
    i=0;    // reset counter
	
	if ((OSCCONbits.LOCK != 1) || (i>=OSC_CLKSW_TIMEOUT))		// Error occurred? 
	{ res |= OSCERR_PLL_LCK; }						// => If yes, return error code

// Return Success/Failure
    if( res == 0 ) res = (1 - OSCCONbits.CF);       // Return oscillator fail status bit
	return(res);                                    // (1=Success, 0=Failure)

}

// =================================================================================================
//
//	Function: int16_t InitACLK( void )
//
// =================================================================================================
//	Initializes the Auxiliary PLL module of the dsPICC33-GS parts
//
//  Please Note:
//	This peripheral is unique among the Microchip parts. So this function is only available
//	on devices of the switch mode power supply and motor control families of the dsPIC33F.
//
// =================================================================================================
#if defined (_P33SMPS_YGAR_) || defined (_P33SMPS_UEAG_) || defined (_P33SMPS_UEAA_) || \
    defined (_P33SMPS_TLAL_) || defined (_P33SMPS_TLAH_) || defined (_P33SMPS_TLAY_)

uint16_t init_ACLK( AUXOSC_CONFIG_t aux_clock_config )
{

    volatile unsigned int i=0, lRes=1;


// The dsPIC33F-GS Family provides an Auxiliary Clock module to boost the basic
// system frequency for specific peripherals such as PWM and ADC to enable high resolution
// on these modules
//
// The input clock of this ACLK module is limited to 120 MHz. You can either choose
// the internal FRC oscillator, boosted by a fixed 16x PLL or select the intermediary
// frequency FVCO of the general PLL module (value M)
//
// Selecting FVCO as input clock may result in a decrease of the maximum system clock to 60MHz (=30MIPS)
//
// Example:
// Setup the ADC and PWM auxiliary clock for 117.92 MHz operation, using the internal FRC
// with the fixed 16x Auxiliary PLL.
//
//    FACLK = ((FRC     * 16) / APSTSCLR ) 
// => FACLK = ((7.37MHz * 16) / 1          = 117.92 MHz
//
// => Minimum PWM Resolution = 1.06 ns
//
// => Use the OSCTUN register to increase the speed of the FRC when required 

	if (aux_clock_config.clock_source == OSC_AUX_CLOCK_FRC)
	{ // Internal RC-Oscillator provides source clock for the Auxiliary PLL module)

		ACLKCONbits.FRCSEL		= 1;	// Internal RC provides input for Auxiliary PLL (x16)
		ACLKCONbits.ASRCSEL 	= 0;	// Primary Oscillator does not ;-)
		ACLKCONbits.SELACLK 	= 1;	// Auxiliary Oscillator provides clock source for
										// Auxiliary PLL Divider 
	}
	else if (aux_clock_config.clock_source == OSC_AUX_CLOCK_PRI)
	{ // External Oscillator provides source clock for the Auxiliary PLL module)

		ACLKCONbits.FRCSEL		= 0;	// Primary Oscillator provides input for Auxiliary PLL (x16)
		ACLKCONbits.ASRCSEL 	= 1;	// Internal RC does not ;-)
		ACLKCONbits.SELACLK 	= 1;	// Auxiliary Oscillator provides clock source for 
										// Auxiliary PLL Clock Divider

	}
	else if (aux_clock_config.clock_source == OSC_AUX_CLOCK_FVCO)
	{ // If PLL FVCO-Output is used as ACLK input, 
		
		ACLKCONbits.SELACLK 	= 0;	// PLL FVCO Output provides the source clock for 
										// Auxiliary PLL Clock Divider
	
	}

	// Setting ACLK Post Scaler 
	ACLKCONbits.APSTSCLR 		= aux_clock_config.divider;		// Divide Auxiliary clock by n 

	if (((aux_clock_config.clock_source == OSC_AUX_CLOCK_PRI) ||(aux_clock_config.clock_source == OSC_AUX_CLOCK_FRC)) && (aux_clock_config.enableAUXPLL))
	{ // If primary Oscillator or internal RC oscillator is used as input clock
	  // initialize the 16x APLL and wait until it locks in

		ACLKCONbits.ENAPLL 		= aux_clock_config.enableAUXPLL;	// Enable 16x Auxiliary PLL 

		while((ACLKCONbits.APLLCK != 1) && (i<OSC_CLKSW_TIMEOUT)) 	// Wait for Auxiliary PLL to lock
		{ i++; }
		
		if ((ACLKCONbits.APLLCK != 1) && (i>=OSC_CLKSW_TIMEOUT))	// Timeout occurred ?
		{
			lRes = OSCERR_APLL_LCK;				// set error code, but continue
		}
		
	}

	return(lRes);								// Return Auxiliary PLL Status 
												// (1=Success, 0=Failure or error code)
	
}
#endif

// =================================================================================================
//
//	Function: void InitRefClockOutput(void)
//
// =================================================================================================
//	Initializes the reference clock output - this is the system- or crystal clock, divided by
//  a post scaler from 1:1 to 1:32768
// =================================================================================================
#ifdef REFOCON
void init_RefClockOutput( OSC_REFCLK_SOURCE_e RefClkSource, OSC_REFCLK_DIVIDER_e RefClkDivider, OSC_REFCLK_SLEEP_CFG_e RunInSleep)
{
// This enables the Clock Reference Output, driven by the primary Oscillator

// The Reference Clock Output is remappable. So the first thing here is to map this
// function to specific pin.

// The Reference Clock Output is shared with the OSC2 output. Therefore this function 
// can only be used when no external crystal is used.

	if ((OSCCONbits.COSC != OSC_PRI) && (OSCCONbits.COSC != OSC_PRIPLL))
	{ // Configure the Reference Clock Output

		REFOCONbits.RODIV	= RefClkDivider;	// System Clock will be devided by 32.768
												// See data sheet page 144 for more options
	
		REFOCONbits.ROSEL	= RefClkSource;		// System Clock or Primary Oscillator is used as Reference Clock
		REFOCONbits.ROSSLP	= RunInSleep;		// Reference Clock Output is enabled/disabled in Sleep Mode

		REFOCONbits.ROON	= 1;				// Enable Reference Clock Output
	
	}
	
	return;

}

#endif
 


