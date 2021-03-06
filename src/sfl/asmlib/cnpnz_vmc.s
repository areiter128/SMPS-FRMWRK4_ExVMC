;LICENSE / DISCLAIMER
; **********************************************************************************
;  SDK Version: z-Domain Control Loop Designer v0.9.0.32
;  Author:      M91406
;  Date/Time:   08/30/18 02:36:29 PM
; **********************************************************************************
;  4P4Z Control Library File (Fast Floating Point Coefficient Scaling Mode)
; **********************************************************************************
	
;------------------------------------------------------------------------------
;file start
	.nolist
	.list
	
;------------------------------------------------------------------------------
;local inclusions.
	.section .data    ; place constant data in the data section
	
;------------------------------------------------------------------------------
; Define status flags bit positions
	.equ NPMZ16_STATUS_ENABLE,      15    ; bit position of the ENABLE bit
	.equ NPMZ16_STATUS_USAT,        1    ; bit position of the UPPER_SATURATION_FLAG_BIT
	.equ NPMZ16_STATUS_LSAT,        0    ; bit position of the LOWER_SATURATION_FLAG_BIT
	
;------------------------------------------------------------------------------
; Address offset declarations for data structure addressing
	.equ offStatus,                 0    ; status word at address-offset=0
	.equ offSourceRegister,         2    ; pointer to source memory address=2
	.equ offTargetRegister,         4    ; pointer to tasrget memory address=2
	.equ offControlReference,       6    ; pointer to control reference memory address=2
	.equ offACoefficients,          8    ; pointer to A-coefficients array start address=2
	.equ offBCoefficients,          10    ; pointer to B-coefficients array start address=2
	.equ offControlHistory,         12    ; pointer to control history array start address=2
	.equ offErrorHistory,           14    ; pointer to error history array start address=2
	.equ offACoeffArraySize,        16    ; size of the A-coefficients array
	.equ offBCoeffArraySize,        18    ; size of the B-coefficients array
	.equ offCtrlHistArraySize,      20    ; size of the control history array
	.equ offErrHistArraySize,       22    ; size of the error history array
	.equ offPreShift,               24    ; value of input value normalization bit-shift scaler
	.equ reserved_1,                26    ; (reserved)
	.equ reserved_2,                28    ; (reserved)
	.equ reserved_3,                30    ; (reserved)
	.equ offMinOutput,              32    ; minimum clamping value of control output
	.equ offMaxOutput,              34    ; maximum clamping value of control output
	.equ offADCTriggerRegister,     36    ; pointer to ADC trigger register memory address
	.equ offADCTriggerOffset,       38    ; value of ADC trigger offset
	
;------------------------------------------------------------------------------
;local inclusions.
	.section .text    ; place code in the code section
	
;------------------------------------------------------------------------------
; Global function declaration
; This function calls the z-domain controller processing the latest data point input
;------------------------------------------------------------------------------
	
	.global _cnpnz_vmc_Update
_cnpnz_vmc_Update:    ; provide global scope to routine
	push w12    ; save working register used for status flag tracking
	
;------------------------------------------------------------------------------
; Check status word for Enable/Disable flag and bypass computation, if disabled
	mov [w0 + #offStatus], w12
	btss w12, #NPMZ16_STATUS_ENABLE
	bra CNPNZ_VMC_BYPASS_LOOP
	
;------------------------------------------------------------------------------
; Setup pointers to A-Term data arrays
	mov [w0 + #offACoefficients], w8    ; load pointer to first index of A coefficients array
	
;------------------------------------------------------------------------------
; Load pointer to first element of control history array
	mov [w0 + #offControlHistory], w10    ; load pointer address into wreg
	
;------------------------------------------------------------------------------
; Compute compensation filter term
	clr b, [w8]+=2, w5    ; clear both accumulators and prefetch first operands
	clr a, [w8]+=4, w4, [w10]+=2, w6
	mpy w4*w6, a, [w8]+=4, w4, [w10]+=2, w6    ; multiply control output (n-%INDEX%) from the delay line with coefficient X%INDEX%
	sftac a, w5
	add b
	mov [w8 - #6], w5    ; multiply control output (n-1) from the delay line with coefficient X1
	mpy w4*w6, a, [w8]+=4, w4, [w10]+=2, w6
	sftac a, w5
	add b
	mov [w8 - #6], w5    ; multiply control output (n-2) from the delay line with coefficient X2
	mpy w4*w6, a, [w8]+=4, w4, [w10]+=2, w6
	sftac a, w5
	add b
	mov [w8 - #6], w5    ; multiply & accumulate last control output with coefficient of the delay line (no more prefetch)
	mpy w4*w6, a
	sftac a, w5
	add b
	
;------------------------------------------------------------------------------
; Read data from input source and calculate error input to transfer function
	mov [w0 + #offSourceRegister], w2    ; load pointer to input source register
	mov [w2], w1    ; move value from input source into working register
	mov [w0 + #offControlReference], w2    ; move pointer to control reference into working register
	subr w1, [w2], w1    ; calculate error (= reference - input)
	mov [w0 + #offPreShift], w2    ; move error input scaler into working register
	sl w1, w2, w1    ; normalize error result to fractional number format
	
;------------------------------------------------------------------------------
; Setup pointers to B-Term data arrays
	mov [w0 + #offBCoefficients], w8    ; load pointer to first index of B coefficients array
	
;------------------------------------------------------------------------------
; Setup pointer to first element of error history array
	mov [w0 + #offErrorHistory], w10    ; load pointer address into wreg
	
;------------------------------------------------------------------------------
; Update error history (move error one tick along the delay line)
	mov [w10 + #6], w6    ; move entry (n-4) into buffer
	mov w6, [w10 + #8]    ; move buffered value one tick down the delay line
	mov [w10 + #4], w6    ; move entry (n-3) into buffer
	mov w6, [w10 + #6]    ; move buffered value one tick down the delay line
	mov [w10 + #2], w6    ; move entry (n-2) into buffer
	mov w6, [w10 + #4]    ; move buffered value one tick down the delay line
	mov [w10 + #0], w6    ; move entry (n-1) into buffer
	mov w6, [w10 + #2]    ; move buffered value one tick down the delay line
	mov w1, [w10]    ; add most recent error input to history array
	
;------------------------------------------------------------------------------
; Compute compensation filter term
	movsac b, [w8]+=2, w5    ; clear accumulator A, leave contents of accumulator B unchanged and prefetch first operands
	clr a, [w8]+=4, w4, [w10]+=2, w6
	mpy w4*w6, a, [w8]+=4, w4, [w10]+=2, w6    ; multiply control output (n-%INDEX%) from the delay line with coefficient X%INDEX%
	sftac a, w5
	add b
	mov [w8 - #6], w5    ; multiply control output (n-0) from the delay line with coefficient X0
	mpy w4*w6, a, [w8]+=4, w4, [w10]+=2, w6
	sftac a, w5
	add b
	mov [w8 - #6], w5    ; multiply control output (n-1) from the delay line with coefficient X1
	mpy w4*w6, a, [w8]+=4, w4, [w10]+=2, w6
	sftac a, w5
	add b
	mov [w8 - #6], w5    ; multiply control output (n-2) from the delay line with coefficient X2
	mpy w4*w6, a, [w8]+=4, w4, [w10]+=2, w6
	sftac a, w5
	add b
	mov [w8 - #6], w5    ; multiply & accumulate last control output with coefficient of the delay line (no more prefetch)
	mpy w4*w6, a
	sftac a, w5
	add b
	
; Backwards normalization of the controller output
	sac.r b, w4    ; store most recent accumulator result in working register
	
;------------------------------------------------------------------------------
; Controller Anti-Windup (control output value clamping)
	mov [w0 + #offMaxOutput], w6
	cpslt w6, w4
	bra CNPNZ_VMC_CLAMP_MAX_EXIT
	mov w6, w4
	bset w12, #NPMZ16_STATUS_USAT
	CNPNZ_VMC_CLAMP_MAX_EXIT:
	mov [w0 + #offMinOutput], w6
	cpsgt w6, w4
	bra CNPNZ_VMC_CLAMP_MIN_EXIT
	mov w6, w4
	bset w12, #NPMZ16_STATUS_LSAT
	CNPNZ_VMC_CLAMP_MIN_EXIT:
	
;------------------------------------------------------------------------------
; Write control output value to target
	mov [w0 + #offTargetRegister], w8    ; move pointer to target in to working register
	mov w4, [w8]    ; move control output into target address
	
;------------------------------------------------------------------------------
; Update ADC trigger position
	asr w4, #1, w6
	mov [w0 + #offADCTriggerOffset], w8
	add w6, w8, w6
	mov [w0 + #offADCTriggerRegister], w8
	mov w6, [w8]
	
;------------------------------------------------------------------------------
; Load pointer to first element of control history array
	mov [w0 + #offControlHistory], w10    ; load pointer address into wreg
	
;------------------------------------------------------------------------------
; Update control output history
	mov [w10 + #4], w6    ; move entry (n-3) one tick down the delay line
	mov w6, [w10 + #6]
	mov [w10 + #2], w6    ; move entry (n-2) one tick down the delay line
	mov w6, [w10 + #4]
	mov [w10 + #0], w6    ; move entry (n-1) one tick down the delay line
	mov w6, [w10 + #2]
	mov w4, [w10]    ; add most recent control output to history
	
;------------------------------------------------------------------------------
; Update status flag bitfield
	mov w12, [w0 + #offStatus]
	
;------------------------------------------------------------------------------
; Enable/Disable bypass branch target
	CNPNZ_VMC_BYPASS_LOOP:
	pop w12    ; restore working register used for status flag tracking
	
;------------------------------------------------------------------------------
; End of routine
	return
;------------------------------------------------------------------------------
	
;------------------------------------------------------------------------------
; Global function declaration _cnpnz_vmc_Reset
; This function clears control and error histories enforcing a reset
;------------------------------------------------------------------------------
	
	.global _cnpnz_vmc_Reset
_cnpnz_vmc_Reset:
	
;------------------------------------------------------------------------------
; Clear control history array
	push w0    ; Set pointer to the base address of control history array
	mov  [w0 + #offControlHistory], w0
	clr [w0++]    ; Clear next address of control history array
	clr [w0++]    ; Clear next address of control history array
	clr [w0++]    ; Clear next address of control history array
	clr [w0]    ; Clear last address of control history array
	pop w0
	
;------------------------------------------------------------------------------
; Clear error history array
	push w0    ; Set pointer to the base address of error history array
	mov [w0 + #offErrorHistory], w0
	clr [w0++]    ; Clear next address of error history array
	clr [w0++]    ; Clear next address of error history array
	clr [w0++]    ; Clear next address of error history array
	clr [w0++]    ; Clear next address of error history array
	clr [w0]    ; Clear last address of error history array
	pop w0
	
;------------------------------------------------------------------------------
; End of routine
	return
;------------------------------------------------------------------------------
	
;------------------------------------------------------------------------------
; Global function declaration _cnpnz_vmc_Precharge
; This function loads user-defined default values into control and error histories
;------------------------------------------------------------------------------
	
	.global _cnpnz_vmc_Precharge
_cnpnz_vmc_Precharge:
	
;------------------------------------------------------------------------------
; Charge error history array with defined value
	push w0    ; Set pointer to the base address of error history array
	push w1
	mov  [w0 + #offErrorHistory], w0
	mov w1, [w0++]    ; Load user value into next address of error history array
	mov w1, [w0++]    ; Load user value into next address of error history array
	mov w1, [w0++]    ; Load user value into next address of error history array
	mov w1, [w0++]    ; Load user value into next address of error history array
	mov w1, [w0]    ; Load user value into last address of error history array
	pop w1
	pop w0
	
;------------------------------------------------------------------------------
; Charge control history array with defined value
	push w0    ; Set pointer to the base address of control history array
	push w2
	mov  [w0 + #offControlHistory], w0
	mov w2, [w0++]    ; Load user value into next address of control history array
	mov w2, [w0++]    ; Load user value into next address of control history array
	mov w2, [w0++]    ; Load user value into next address of control history array
	mov w2, [w0]    ; Load user value into last address of control history array
	pop w2
	pop w0
	
;------------------------------------------------------------------------------
; End of routine
	return
;------------------------------------------------------------------------------
	
;------------------------------------------------------------------------------
; End of file
	.end
;------------------------------------------------------------------------------
	