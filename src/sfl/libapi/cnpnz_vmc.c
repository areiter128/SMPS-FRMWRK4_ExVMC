/* ***************************************************************************************
 * Digital Control Loop Designer Version 0.9.0.25.
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
 * ***************************************************************************************/

#include "cnpnz_vmc.h"

/* ***************************************************************************************
 * Data Arrays:
 * The cNPNZ_t data structure contains a pointer to derived coefficients in X-space and
 * other pointers to controller and error history in Y-space.
 * This source file declares the default parameters of the z-domain compensation filter.
 * These declarations are made publicly accessible through defines in cnpnz_vmc.h
 * ***************************************************************************************/

	volatile CNPNZ_VMC_CONTROL_LOOP_COEFFICIENTS_t __attribute__((space(xmemory), near)) cnpnz_vmc_coefficients; // A/B-Coefficients 
	volatile uint16_t cnpnz_vmc_ACoefficients_size = (sizeof(cnpnz_vmc_coefficients.ACoefficients)/sizeof(cnpnz_vmc_coefficients.ACoefficients[0])); // A-coefficient array size
	volatile uint16_t cnpnz_vmc_BCoefficients_size = (sizeof(cnpnz_vmc_coefficients.BCoefficients)/sizeof(cnpnz_vmc_coefficients.BCoefficients[0])); // B-coefficient array size

	volatile CNPNZ_VMC_CONTROL_LOOP_HISTORIES_t __attribute__((space(ymemory), far)) cnpnz_vmc_histories; // Control/Error Histories 
	volatile uint16_t cnpnz_vmc_ControlHistory_size = (sizeof(cnpnz_vmc_histories.ControlHistory)/sizeof(cnpnz_vmc_histories.ControlHistory[0])); // Control history array size
	volatile uint16_t cnpnz_vmc_ErrorHistory_size = (sizeof(cnpnz_vmc_histories.ErrorHistory)/sizeof(cnpnz_vmc_histories.ErrorHistory[0])); // Error history array size

/* ***************************************************************************************
 * 	Pole&Zero Placement:
 * ***************************************************************************************
 *
 * 	fP0:	200 Hz 
 * 	fP1:	40000 Hz 
 * 	fZ1:	2000 Hz 
 * 	fP2:	120000 Hz 
 * 	fZ2:	6000 Hz 
 *
 * ***************************************************************************************
 * 	Filter Coefficients and Parameters:
 * ***************************************************************************************/

	volatile fractional cnpnz_vmc_ACoefficients [3] = 
	{
		0x4839,	// Coefficient A1 will be multiplied with controller output u(n-1)
		0xFC13,	// Coefficient A2 will be multiplied with controller output u(n-2)
		0xFBB6	// Coefficient A3 will be multiplied with controller output u(n-3)
	};

	volatile fractional cnpnz_vmc_BCoefficients [4] = 
	{
		0x12D3,	// Coefficient B0 will be multiplied with error input e(n)
		0xF0BE,	// Coefficient B1 will be multiplied with error input e(n-1)
		0xED4F,	// Coefficient B2 will be multiplied with error input e(n-2)
		0x0F64	// Coefficient B3 will be multiplied with error input e(n-3)
	};


	volatile int16_t cnpnz_vmc_pre_scaler = 3;
	volatile int16_t cnpnz_vmc_post_shift_A = -1;
	volatile int16_t cnpnz_vmc_post_shift_B = 0;
	volatile fractional cnpnz_vmc_post_scaler = 0x0000;

	volatile cNPNZ16b_t cnpnz_vmc; // user-controller data object

/* ***************************************************************************************/

uint16_t cnpnz_vmc_Init(void)
{
	volatile uint16_t i = 0;

	// Initialize controller data structure at runtime with pre-defined default values
	cnpnz_vmc.status.flags = CONTROLLER_STATUS_CLEAR;  // clear all status flag bits (will turn off execution))

	cnpnz_vmc.ptrACoefficients = &cnpnz_vmc_coefficients.ACoefficients[0]; // initialize pointer to A-coefficients array
	cnpnz_vmc.ptrBCoefficients = &cnpnz_vmc_coefficients.BCoefficients[0]; // initialize pointer to B-coefficients array
	cnpnz_vmc.ptrControlHistory = &cnpnz_vmc_histories.ControlHistory[0]; // initialize pointer to control history array
	cnpnz_vmc.ptrErrorHistory = &cnpnz_vmc_histories.ErrorHistory[0]; // initialize pointer to error history array
	cnpnz_vmc.normPostShiftA = cnpnz_vmc_post_shift_A; // initialize A-coefficients/single bit-shift scaler
	cnpnz_vmc.normPostShiftB = cnpnz_vmc_post_shift_B; // initialize B-coefficients/dual/post scale factor bit-shift scaler
	cnpnz_vmc.normPostScaler = cnpnz_vmc_post_scaler; // initialize control output value normalization scaling factor
	cnpnz_vmc.normPreShift = cnpnz_vmc_pre_scaler; // initialize A-coefficients/single bit-shift scaler

	cnpnz_vmc.ACoefficientsArraySize = cnpnz_vmc_ACoefficients_size; // initialize A-coefficients array size
	cnpnz_vmc.BCoefficientsArraySize = cnpnz_vmc_BCoefficients_size; // initialize A-coefficients array size
	cnpnz_vmc.ControlHistoryArraySize = cnpnz_vmc_ControlHistory_size; // initialize control history array size
	cnpnz_vmc.ErrorHistoryArraySize = cnpnz_vmc_ErrorHistory_size; // initialize error history array size


	// Load default set of A-coefficients from user RAM into X-Space controller A-array
	for(i=0; i<cnpnz_vmc.ACoefficientsArraySize; i++)
	{
		cnpnz_vmc_coefficients.ACoefficients[i] = cnpnz_vmc_ACoefficients[i];
	}

	// Load default set of B-coefficients from user RAM into X-Space controller B-array
	for(i=0; i<cnpnz_vmc.BCoefficientsArraySize; i++)
	{
		cnpnz_vmc_coefficients.BCoefficients[i] = cnpnz_vmc_BCoefficients[i];
	}

	// Clear error and control histories of the 3P3Z controller
	cnpnz_vmc_Reset(&cnpnz_vmc);

	return(1);
}


