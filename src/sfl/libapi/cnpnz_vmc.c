/* ***************************************************************************************
 * z-Domain Control Loop Designer Version 0.9.0.32.
 * ***************************************************************************************
 * 4p4z compensation filter coefficients derived for following operating conditions:
 * ***************************************************************************************
 *
 * 	Controller Type:	4P4Z - Advanced High-Q Compensator
 * 	Sampling Frequency:	300000 Hz 
 * 	Fixed Point Format:	15
 * 	Scaling Mode:		4 - Fast Floating Point Coefficient Scaling
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
 * 	fP0:	110 Hz 
 * 	fP1:	100000 Hz 
 * 	fZ1:	2000 Hz 
 * 	fP2:	150000 Hz 
 * 	fZ2:	5900 Hz 
 * 	fP3:	150000 Hz 
 * 	fZ3:	40000 Hz 
 *
 * ***************************************************************************************
 * 	Filter Coefficients and Parameters:
 * ***************************************************************************************/

	volatile int32_t cnpnz_vmc_ACoefficients [4] = 
	{
		0x44360000,	// Coefficient A1 will be multiplied with controller output u(n-1)
		0x68580001,	// Coefficient A2 will be multiplied with controller output u(n-2)
		0x779A0004,	// Coefficient A3 will be multiplied with controller output u(n-3)
		0x4A7D0009	// Coefficient A4 will be multiplied with controller output u(n-4)
	};

	volatile int32_t cnpnz_vmc_BCoefficients [5] = 
	{
		0x4FE80000,	// Coefficient B0 will be multiplied with error input e(n)
		0x9BF40000,	// Coefficient B1 will be multiplied with error input e(n-1)
		0x981C0001,	// Coefficient B2 will be multiplied with error input e(n-2)
		0x64470000,	// Coefficient B3 will be multiplied with error input e(n-3)
		0x91150002	// Coefficient B4 will be multiplied with error input e(n-4)
	};


	volatile int16_t cnpnz_vmc_pre_scaler = 3;
	volatile int16_t cnpnz_vmc_post_shift_A = 0;
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

	// Clear error and control histories of the 4P4Z controller
	cnpnz_vmc_Reset(&cnpnz_vmc);

	return(1);
}


