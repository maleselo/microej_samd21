/*
 * C99
 *
 * Copyright 2014-2015 IS2T.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/**
 * @file fault_handlers.c
 *
 * @brief This file contains the fault exception handlers for Cortex-M3 and M4.
 *
 * @details The CMSIS names are used.
 *
 * There are two modes:
 * - verbose
 * - lite
 *
 * In verbose mode, each fault exception handler will:
 * - print the stack frame,
 * - print its name,
 * - print the associated fault status register,
 * - try to make an analysis of the fault cause,
 * - make an infinite loop.
 *
 * In lite mode, each fault exception handler will:
 * - print its name,
 * - make an infinite loop.
 *
 * Define the @ref VERBOSE_MODE macro to activate verbose mode.
 *
 * For more information about fault handling, see Joseph Yiu's "The Definitive Guide
 * to ARM Cortex-M3 and ARM Cortex-M4 processors". Some comments in the following
 * refer to this book.
 */

/* Includes ______________________________________________________________________*/
#include <stdbool.h>
#include <stdio.h>

#include "fault_handlers_cpu.h"

#include "fault_handlers.h" // will check prototypes and import public types

/* Macros ________________________________________________________________________*/

/**
 * @brief Define this macro to enable verbose handlers. Verbose handlers will consume more flash memory than lite handlers.
 */
#define VERBOSE_MODE

/**
 * @brief Make an infinite while loop.
 */
#define INFINITE_LOOP()		{while(1);}

#ifdef VERBOSE_MODE
/**
 * @brief This macro is called as the beginning of each handlers to print the stack frame.
 *
 * @details There are two stack pointers in Cortex-M processors:
 * - MSP (Main Stack Pointer)
 * - PSP (Process Stack Pointer)
 * When handling faults, we need to know which one was used before entering the faults so that
 * we can retrieve interesting information.
 *
 * To do so, we need to test the value of EXC_RETURN, which is stored into LR during exception
 * (see Section 8.1.4 EXC_RETURN). Then, we can fetch the correct stack pointer with the MRS instruction
 * (MRS = Move from special register to general register).
 *
 * NOTE: IAR's compiler doesn't like when comments are interlaced with macro definition lines.
 * Here is what the macro does:
 * - Check if bit 2 (stack return) is set in EXC_RETURN / LR
 * - If-Then condition instruction
 * - If equals, store MSP in R0
 * - Else, store PSP in RO (1st parameter)
 * - MSP is stored in R1 (2nd parameter)
 * - PSP is stored in R2 (3rd parameter)
 * - LR is stored in R3 (4th parameter)
 * - Call C function for printing
 */
/**
 * Compiling with GCC.
 *
 */
void print_stacked_registers() {
}
/**
 * Compiling with Keil's ARMCC.
 *
 * With Keil, we do not use a macro but an assembly function.
 */
void printer(uint32_t current_sp, uint32_t msp, uint32_t psp, uint32_t exc_return);


// CMSIS doesn't provide macro to get bits from BFSR (which is the 2nd byte in CFSR), so we create our own macros
#define BFSR_IBUSERR_Pos        (0)
#define BFSR_IBUSERR_Msk        (1 << BFSR_IBUSERR_Pos)

#define BFSR_PRECISERR_Pos      (1)
#define BFSR_PRECISERR_Msk      (1 << BFSR_PRECISERR_Pos)

#define BFSR_IMPRECISERR_Pos    (2)
#define BFSR_IMPRECISERR_Msk    (1 << BFSR_IMPRECISERR_Pos)

#define BFSR_BFARVALID_Pos      (15)
#define BFSR_BFARVALID_Msk      (1 << BFSR_BFARVALID_Pos)

// CMSIS doesn't provide macro to get bits from UFSR (which is the upper half-word in CFSR), so we create our own macros
#define UFSR_UNDEFINSTR_Pos        (0)
#define UFSR_UNDEFINSTR_Msk        (1 << UFSR_UNDEFINSTR_Pos)

#define UFSR_INVSTATE_Pos          (1)
#define UFSR_INVSTATE_Msk          (1 << UFSR_INVSTATE_Pos)


/* Global variables  ___________________________________________________________*/


/* Private types and variables  ___________________________________________________*/


/* Private functions  ______________________________________________________________*/

/**
 * @brief C function to print the stacked registers (== the stack frame) along with EXEC_RETURN.
 *
 * @warning this function cannot be static because it won't be seen by assembly code during link edition.
 * You should not called this function directly.
 */
/*static*/ void printer(uint32_t current_sp, uint32_t msp, uint32_t psp, uint32_t exc_return)
{
    printf("---------------------------------------------------------------------\n");
    // Show stack pointers
    printf("Current SP = %.8X\n", current_sp);
    printf("MSP = %.8X\n", msp);
    printf("PSP = %.8X\n", psp);
    putchar('\n');

    // Show stacked registers == stack frame (see section 8.1.3 and figure 12.4)
    uint32_t *sp = (uint32_t*) current_sp;
    printf("Stack frame:\n");
    printf("R0 =\t%.8X\n", *sp++);
    printf("R1 =\t%.8X\n", *sp++);
    printf("R2 =\t%.8X\n", *sp++);
    printf("R3 =\t%.8X\n", *sp++);
    printf("R12 =\t%.8X\n", *sp++);
    printf("LR =\t%.8X\n", *sp++);
    printf("PC =\t%.8X\n", *sp++);
    printf("xPSR =\t%.8X\n", *sp++);
    putchar('\n');

    printf("EXC_RETURN (LR) = %.8X\n", exc_return);

    printf("---------------------------------------------------------------------\n");
}

/* Public functions  _______________________________________________________________*/

/*
 * @brief Hard Fault exception handler.
 */
void HardFault_Handler(void)
{
    //print_stacked_registers();
    //printf("%s\n", __func__);

 //  uint32_t hfsr = SCB->HFSR;
 //   printf("Hard Fault Status Register =\t%X\n", hfsr);
/*
    if(hfsr & SCB_HFSR_FORCED_Msk)
    {
    	printf("FORCED");
    }
*/
    INFINITE_LOOP();
}


/*
 * @brief Memory Management Fault exception handler.
 */
void MemFault_Handler (void)
{
    print_stacked_registers();
    printf("%s\n", __func__);

    INFINITE_LOOP();
}


/*
 * @brief Bus Fault exception handler.
 */
void BusFault_Handler (void)
{
    print_stacked_registers();
    printf("%s\n", __func__);
/*
    uint32_t cfsr = SCB->CFSR;
    printf("Configurable Fault Status Register =\t%.8X\n", cfsr);

    uint8_t bfsr = (cfsr & SCB_CFSR_BUSFAULTSR_Msk) >> SCB_CFSR_BUSFAULTSR_Pos;
    printf("Bus Fault Status Register =\t%.2X\n", bfsr);

    if(bfsr & BFSR_IBUSERR_Msk)
    {
        printf("Instruction access error\n");
        // This case has not been experimented yet
    }

    if(bfsr & BFSR_PRECISERR_Msk)
    {
        printf("Precise data access error\n");

        // Faulting instruction
        // --> see the PC of the printed stack frame

        // Address of faulting data access
        uint32_t bfar = SCB->BFAR;
        printf("Address of faulting data access (BFAR) = %.8X\n", bfar);

        bool still_valid = (cfsr & BFSR_BFARVALID_Msk);
        if(!still_valid)
        {
            printf("WARNING: BFAR is no longer valid!\n");
        }
    }

    if(bfsr & BFSR_IMPRECISERR_Msk)
    {
        printf("Imprecise data access error\n");
    }
*/
    INFINITE_LOOP();
}


/*
 * @brief Usage Fault exception handler.
 */
void UsageFault_Handler (void)
{
	// TODO Activate usage for for division by 0 and unaligned access? (see page 384)

    print_stacked_registers();
    printf("%s\n", __func__);
/*
    uint32_t cfsr = SCB->CFSR;
    printf("Configurable Fault Status Register =\t%X\n", cfsr);

    uint16_t ufsr = (cfsr & SCB_CFSR_USGFAULTSR_Msk) >> SCB_CFSR_USGFAULTSR_Pos;
    printf("Usage Fault Status Register =\t%X\n", ufsr);

    if(ufsr & UFSR_UNDEFINSTR_Msk)
    {
        printf("Attempt to execute an undefined instruction\n");
    }

    if(ufsr & UFSR_INVSTATE_Msk)
    {
        printf("Attempt to switch to invalid mode (like ARM state)\n");
    }
*/
    INFINITE_LOOP();
}
#else
/*
 * @brief Hard Fault exception handler.
 */
void HardFault_Handler (void)
{
	printf("%s\n", __func__);
	INFINITE_LOOP();
}


/*
 * @brief Memory Management Fault exception handler.
 */
void MemFault_Handler (void)
{
	printf("%s\n", __func__);
	INFINITE_LOOP();
}


/*
 * @brief Bus Fault exception handler.
 */
void BusFault_Handler (void)
{
	printf("%s\n", __func__);
	INFINITE_LOOP();
}


/*
 * @brief Usage Fault exception handler.
 */
void UsageFault_Handler (void)
{
	printf("%s\n", __func__);
	INFINITE_LOOP();
}
#endif
