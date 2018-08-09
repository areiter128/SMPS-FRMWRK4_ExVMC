/* ***************************************************************************************
 * Digital Control Loop Designer Version 0.9.0.26.
 * ***************************************************************************************
 * 3p3z compensation filter coefficients derived for following operating conditions:
 * ***************************************************************************************
 *
 * 	Controller Type:	3P3Z - Basic Voltage Mode Compensator
 * 	Sampling Frequency:	350000 Hz 
 * 	Fixed Point Format:	15
 * 	Scaling Mode:		4 - Fast Floating Point Coefficient Scaling
 * 	Input Gain:			1
 * 
 * ***************************************************************************************/

#ifndef __SPECIAL_FUNCTION_LAYER_CNPNZ_VMC_H__
#define __SPECIAL_FUNCTION_LAYER_CNPNZ_VMC_H__

#include <xc.h>
#include <dsp.h>
#include <stdint.h>

#include "npnz16b.h"

/* ***************************************************************************************
 * Data Arrays:
 * The cNPNZ_t data structure contains a pointer to derived coefficients in X-space and
 * other pointers to controller and error history in Y-space.
 * This header file holds public declarations for variables and arrays defined in 
 * cnpnz_vmc.c
 * 
 * Type definition for A- and B- coefficient arrays and error- and control-history arrays, 
 * which are aligned in memory for optimized addressing during DSP computations.           
 * These data structures need to be placed in specific memory locations to allow direct    
 * X/Y-access from the DSP. (coefficients in x-space, histories in y-space)                
 * ***************************************************************************************/

	typedef struct
	{
		volatile int32_t ACoefficients[3]; // A-Coefficients
		volatile int32_t BCoefficients[4]; // B-Coefficients
	} __attribute__((packed))CNPNZ_VMC_CONTROL_LOOP_COEFFICIENTS_t;

	typedef struct
	{
		volatile fractional ControlHistory[3];  // Control History
		volatile fractional ErrorHistory[4];    // Error History
	} __attribute__((packed))CNPNZ_VMC_CONTROL_LOOP_HISTORIES_t;


	extern volatile cNPNZ16b_t cnpnz_vmc; // user-controller data object

/* ***************************************************************************************/

// Function call prototypes for initialization routines and control loops

extern inline uint16_t cnpnz_vmc_Init(void); // Loads default coefficients into 3P3Z controller and resets histories to zero

extern inline void cnpnz_vmc_Reset( // Resets the 3P3Z controller histories
	volatile cNPNZ16b_t* controller // Pointer to nPnZ data structure
	);

extern inline void cnpnz_vmc_Precharge( // Pre-charges histories of the 3P3Z with defined steady-state data
	volatile cNPNZ16b_t* controller, // Pointer to nPnZ data structure
	volatile uint16_t ctrl_input, // user-defined, constant error history value
	volatile uint16_t ctrl_output // user-defined, constant control output history value
	);

extern inline void cnpnz_vmc_Update( // Calls the 3P3Z controller
	volatile cNPNZ16b_t* controller // Pointer to nPnZ data structure
	);

#endif	// end of __SPECIAL_FUNCTION_LAYER_CNPNZ_VMC_H__ header file section
