/***************************************************************************************************
 * � 2006 Microchip Technology Inc.
 *
 * FileName:        traps.c
 * Dependencies:    Header file traps.h
 * Processor:       dsPIC33FJxxx/dsPIC33EPxxx
 * Compiler:        MPLAB� C30 v3.00 or MPLAB� X16 v1.20 or higher
 *
 * SOFTWARE LICENSE AGREEMENT:
 * Microchip Technology Incorporated ("Microchip") retains all ownership and intellectual property 
 * rights in the code accompanying this message and in all derivatives hereto.  You may use this 
 * code, and any derivatives created by any person or entity by or on your behalf, exclusively with 
 * Microchip's proprietary products.  Your acceptance and/or use of this code constitutes agreement 
 * to the terms and conditions of this notice.
 *
 * CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS, 
 * IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH 
 * MICROCHIP'S PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, 
 * WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY, INDEMNITY, 
 * CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL OR 
 * CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE, 
 * HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
 * FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP 
 * SPECIFICALLY TO HAVE THIS CODE DEVELOPED.
 *
 * You agree that you are solely responsible for testing the code and determining its suitability.  
 * Microchip has no obligation to modify, test, certify, or support the code.
 *
 * REVISION HISTORY:
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *	Date		Autor				Company	Version	Comments
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * 03/09/2006	D. Settu			MCHP	1.0		First Release
 * 10/07/2009	Andreas Reiter		HPC		1.1		added a header file and a default trap handler
 *													routine for better integration
 * 07/19/2016	Andreas Reiter		MCHP	1.2		Added data structure for trap monitoring
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * ADDITIONAL NOTES:
 *
 * 1. This file contains trap service routines (handlers) for hardware exceptions generated by 
 *	 the dsPIC33F device.
 *
 * 2. All trap service routines in this file simply ensure that device continuously executes code 
 *	 within the trap service routine. Users may modify the basic framework provided here to suit 
 *	 to the needs of their application.
 *
 ***************************************************************************************************/

#include <xc.h>
#include <stdint.h>
#include "traps.h"
#include "globals.h"

//uint16_t __attribute__((__persistent__))trap_counter;
//uint16_t __attribute__((__persistent__))trap_identifier;
volatile TRAP_LOGGER_t traplog;          // data structure used as buffer for trap monitoring

// =================================================================================================
//
// Save Last Trap Status
//
// =================================================================================================
//
// This routine saves the most recent trap information in persistent variables to make
// them available after a soft CPU reset.
//
// =================================================================================================
void SaveTrapStatus()
{
//    trap_identifier = traplog.trap_id;
//    traplog.count = trap_counter;
    return;
}

// =================================================================================================
//
// Get Last Trap Status
//
// =================================================================================================
//
// This routine recovers the most recent trap information from persistent variables to make
// them available after a soft CPU reset.
//
// =================================================================================================
void GetTrapStatus()
{
//    traplog.trap_id = trap_identifier;
//    trap_counter = traplog.count;
    return;
}

// =================================================================================================
//
// DefaultTrapHandler
//
// =================================================================================================
//
// This routine can be used as omnibus fault message for all traps. Each trap can be identified 
// by a unique trap ID.
//
// Users may modify the basic framework provided here to suit to the needs of their application.
//
// =================================================================================================

void DefaultTrapHandler(TRAP_ID_e trap_id) {

    volatile uint32_t i = 0;
    
    traplog.inttreg.reg_block = INTTREG;
    traplog.trap_id = trap_id;
    traplog.count++;
    SaveTrapStatus();

    /* ToDo: EXPERIMENTAL TEST CODE */
    
    _PTEN = 0;
    
    while(1)
    {
        Nop();
        Nop();
        Nop();

        for( i=500000; i>0; i-- );
        for( i=500000; i>0; i-- );
        for( i=500000; i>0; i-- );
        for( i=500000; i>0; i-- );

        DBGLED1_WR ^= 1;
        LED_GN_WR ^= 1;
        LED_RD_WR ^= 1;
    }
    /* ToDo: EXPERIMENTAL TEST CODE END */
    
    CPU_RESET;
    return;
}


// =================================================================================================
//
// PRIMARY EXCEPTION VECTOR HANDLERS
//
// =================================================================================================
//
// These routines are used if INTCON2bits.ALTIVT = 1. All trap service routines in this file 
// simply ensure that device continuously executes code within the trap service routine. 
//
// Users may modify the basic framework provided here to suit to the needs of their application.
//
// =================================================================================================

void __attribute__((interrupt, no_auto_psv)) _ReservedTrap5(void) {
    
#if __DEBUG
    Nop();
    Nop();
    Nop();
#endif

    traplog.trap_flags.SGHT = 1; // Capture flag bit
    INTCON4bits.SGHT = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_RESERVED_TRAP_5_ERROR); // Call default trap handler
    
    return;
}

void __attribute__((interrupt, no_auto_psv)) _ReservedTrap7(void) {
    
#if __DEBUG
    Nop();
    Nop();
    Nop();
#endif

    traplog.trap_flags.SGHT = 1; // Capture flag bit
    INTCON4bits.SGHT = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_RESERVED_TRAP_7_ERROR); // Call default trap handler
    
    return;
}

// =================================================================================================
// Hard Trap Error is captured
// =================================================================================================

void __attribute__((interrupt, no_auto_psv)) _HardTrapError(void) {

#if __DEBUG
    Nop();
    Nop();
    Nop();
#endif
    
    traplog.trap_flags.SGHT = 1; // Capture flag bit
    INTCON4bits.SGHT = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_HARD_TRAP_ERROR); // Call default trap handler

    return;
}

// =================================================================================================
// Soft Trap Error is captured
// =================================================================================================

void __attribute__((interrupt, no_auto_psv)) _SoftTrapError(void) {
    
#if __DEBUG
    Nop();
    Nop();
    Nop();
#endif
    
    traplog.trap_flags.NAE = INTCON3bits.NAE; // Capture flag bit
    INTCON3bits.NAE = 0; // Clear the trap flag
    traplog.trap_flags.DOOVR = INTCON3bits.DOOVR; // Capture flag bit
    INTCON3bits.DOOVR = 0; // Clear the trap flag
    traplog.trap_flags.APLL = INTCON3bits.APLL; // Capture flag bit
    INTCON3bits.APLL = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_SOFT_TRAP_ERROR);

    return;
}

// =================================================================================================
// Oscillator Failure Trap is captured, when the system clock becomes unstable
// =================================================================================================

void __attribute__((interrupt, no_auto_psv)) _OscillatorFail(void) {

#if __DEBUG
    Nop();
    Nop();
    Nop();
#endif
    
    traplog.trap_flags.OSCFAIL = INTCON1bits.OSCFAIL; // Capture flag bit    
    INTCON1bits.OSCFAIL = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_OSCILLATOR_FAIL);

    return;
}

// =================================================================================================
// Address Error Trap is captured, when a routine tries to access unknown memory addresses
// in RAM or Flash via PSV.
// =================================================================================================

void __attribute__((interrupt, no_auto_psv)) _AddressError(void) {

#if __DEBUG
        Nop();
        Nop();
        Nop();
#endif
    
    traplog.trap_flags.ADDRERR = INTCON1bits.ADDRERR; // Capture flag bit    
    INTCON1bits.ADDRERR = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_ADDRESS_ERROR);

    return;
}
// =================================================================================================
// Stack Error Trap is captured, when a stack address error occurred
// =================================================================================================

void __attribute__((interrupt, no_auto_psv)) _StackError(void) {

#if __DEBUG
    Nop();
    Nop();
    Nop();
#endif
    
    traplog.trap_flags.STKERR = INTCON1bits.STKERR; // Capture flag bit    
    INTCON1bits.STKERR = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_STACK_ERROR);

    return;
}
// =================================================================================================
// Math Error Trap is captured, when a math operation cannot be solved (e.g. division by zero)
// =================================================================================================

void __attribute__((interrupt, no_auto_psv)) _MathError(void) {

#if __DEBUG
    Nop();
    Nop();
    Nop();
#endif
    
    traplog.trap_flags.MATHERR = INTCON1bits.MATHERR; // Capture flag bit    
    INTCON1bits.MATHERR = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_MATH_ERROR);
    
    return;
}

#if (TRAP_DMA_SUPPORT == 1)
#if defined (_DMACError)
// =================================================================================================
// DMA Error Trap is captured, when an access error of the dual ported RAM occurred
// =================================================================================================

void __attribute__((interrupt, no_auto_psv)) _DMACError(void) {

#if __DEBUG
    Nop();
    Nop();
    Nop();
#endif
    
    INTCON1bits.DMACERR = 0; //Clear the trap flag
    DefaultTrapHandler(TRAP_DMA_ERROR);

    return;
}
#endif
#endif

// =================================================================================================
//
// ALTERNATE EXCEPTION VECTOR HANDLERS
//
// =================================================================================================
//
// These routines are used if INTCON2bits.ALTIVT = 1. All trap service routines in this file 
// simply ensure that device continuously executes code within the trap service routine. 
//
// Users may modify the basic framework provided here to suit to the needs of their application.
//
// =================================================================================================
#if __XC16_VERSION < 1030

void __attribute__((interrupt, no_auto_psv)) _AltHardTrapError(void) {
    traplog.trap_flags.SGHT = 1; // Capture flag bit
    INTCON4bits.SGHT = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_ALT_HARD_TRAP_ERROR); // Call default trap handler
}

void __attribute__((interrupt, no_auto_psv)) _AltSoftTrapError(void) {
    traplog.trap_flags.NAE = INTCON3bits.NAE; // Capture flag bit
    INTCON3bits.NAE = 0; // Clear the trap flag
    traplog.trap_flags.DOOVR = INTCON3bits.DOOVR; // Capture flag bit
    INTCON3bits.DOOVR = 0; // Clear the trap flag
    traplog.trap_flags.APLL = INTCON3bits.APLL; // Capture flag bit
    INTCON3bits.APLL = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_ALT_SOFT_TRAP_ERROR);
}

void __attribute__((interrupt, no_auto_psv)) _AltOscillatorFail(void) {
    traplog.trap_flags.OSCFAIL = INTCON1bits.OSCFAIL; // Capture flag bit    
    INTCON1bits.OSCFAIL = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_ALT_OSCILLATOR_FAIL);
}

void __attribute__((interrupt, no_auto_psv)) _AltAddressError(void) {
    traplog.trap_flags.ADDRERR = INTCON1bits.ADDRERR; // Capture flag bit    
    INTCON1bits.ADDRERR = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_ALT_ADDRESS_ERROR);
}

void __attribute__((interrupt, no_auto_psv)) _AltStackError(void) {
    traplog.trap_flags.STKERR = INTCON1bits.STKERR; // Capture flag bit    
    INTCON1bits.STKERR = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_ALT_STACK_ERROR);
}

void __attribute__((interrupt, no_auto_psv)) _AltMathError(void) {
    traplog.trap_flags.MATHERR = INTCON1bits.MATHERR; // Capture flag bit    
    INTCON1bits.MATHERR = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_ALT_MATH_ERROR);
}

#if (TRAP_DMA_SUPPORT == 1)

void __attribute__((interrupt, no_auto_psv)) _AltDMACError(void) {
    traplog.trap_flags.DMACERR = INTCON1bits.DMACERR; // Capture flag bit    
    INTCON1bits.DMACERR = 0; // Clear the trap flag
    DefaultTrapHandler(TRAP_ALT_DMA_ERROR);
}
#endif

#endif


// EOF
