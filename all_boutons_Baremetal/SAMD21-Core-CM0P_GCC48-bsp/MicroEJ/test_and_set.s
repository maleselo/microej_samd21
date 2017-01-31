@ ASM
@
@ Copyright 2016 IS2T. All rights reserved.
@ IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
.syntax unified

.section .text.__sync_lock_test_and_set_4, "ax"
.global __sync_lock_test_and_set_4
.type __sync_lock_test_and_set_4, %function
.align 2 @function alignment on 4 bytes: 1<<2
__sync_lock_test_and_set_4:
	@ r0 : address of the 32 bits global
	@ r1 : value to set in memory
	@ return the previous value in r0
	MRS r3, PRIMASK @ Save PRIMASK value
	CPSID i @ Disable interrupts and configurable fault handlers (set PRIMASK)
	LDR r2, [r0]
	STR r1, [r0]
	MOV r0, r2
	MSR PRIMASK, r3 @ Restore PRIMASK
	BX lr

