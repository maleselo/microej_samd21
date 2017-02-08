/*
 * S
 *
 * Copyright 2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

 	RSEG    CODE:CODE(2)
	thumb

	EXTERN printer

	PUBLIC print_stacked_registers

print_stacked_registers
	/*tst lr, #4
	ite eq
	mrseq r0, msp
	mrsne r0, psp
	mrs r1, msp
	mrs r2, psp
	mov r3, lr
	bl printer
	*/
	bx lr
	END
