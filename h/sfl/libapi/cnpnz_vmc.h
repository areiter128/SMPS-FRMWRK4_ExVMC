/* ***************************************************************************************
 * Digital Control Loop Designer Version 0.9.0.15.
 * ***************************************************************************************
 * 3p3z compensation filter coefficients derived for following operating conditions:
 * ***************************************************************************************
 *
 * 	Controller Type:	3P3Z - Basic Voltage Mode Compensator
 * 	Sampling Frequency:	250000 Hz 
 * 	Fixed Point Format:	15
 * 	Scaling Mode:		1 - Single Bit-Shift Scaling
 * 	Input Gain:			1
 * 
 * ***************************************************************************************
 * Data Arrays:
 * The cNPNZ_t data structure contains a pointer to derived coefficients in X-space and
 * other pointers to controller and error history in Y-space.

 * This header file holds public declarations for variables and arrays defined in 
 * cnpnz_vmc.c
 * ***************************************************************************************/

#ifndef _SPECIAL_FUNCTION_LAYER_CNPNZ_VMC_H_
#define _SPECIAL_FUNCTION_LAYER_CNPNZ_VMC_H_

#include "npnz16b.h"

#include <xc.h>
#include <dsp.h>
#include <stdint.h>


/* ****************************************************************************************
* Type definition for A- and B- coefficient arrays and error- and control-hostory arrays, 
* which are aligned in memory for optimized addressing during DSP computations.           
* These data structures need to be placed in specific memory locations to allow direct    
* X/Y-access from the DSP. (coefficients in x-space, histories in y-space)                
 * ***************************************************************************************/

	typedef struct
	{
		fractional ACoefficients[3]; // A-Coefficients
		fractional BCoefficients[4]; // B-Coefficients
	} __attribute__((packed))cnpnz_vmc_CONTROL_LOOP_COEFFICIENTS_t;

	typedef struct
	{
		fractional ControlHistory[3];  // Control History
		fractional ErrorHistory[4];    // Error History
	} __attribute__((packed))cnpnz_vmc_CONTROL_LOOP_HISTORIES_t;


	extern cNPNZ16b_t cnpnz_vmc; // user-controller data object

/* ***************************************************************************************/

// Function call prototypes for initialization routines and control loops

extern uint16_t cnpnz_vmc_Init(void); // Loads default coefficients into 3P3Z controller and resets histories to zero

extern void cnpnz_vmc_Reset( // Resets the 3P3Z controller histories
	volatile cNPNZ16b_t* controller // Pointer to nPnZ data structure
	);

extern void cnpnz_vmc_Precharge( // Pre-charges histories of the 3P3Z with defined steady-state data
	volatile cNPNZ16b_t* controller, // Pointer to nPnZ data structure
	volatile uint16_t ctrl_input, // user-defined, constant error history value
	volatile uint16_t ctrl_output // user-defined, constant control output history value
	);

extern void cnpnz_vmc_Update( // Calls the 3P3Z controller
	volatile cNPNZ16b_t* controller // Pointer to nPnZ data structure
	);

//#endif	// end of __CNPNZ_VMC__ global controller type identifier definition section
#endif	// end of _SPECIAL_FUNCTION_LAYER_CNPNZ_VMC_H_ header file section
