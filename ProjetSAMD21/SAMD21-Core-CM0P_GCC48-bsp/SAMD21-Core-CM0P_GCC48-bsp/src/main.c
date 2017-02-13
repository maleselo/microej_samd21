/**
 * Copyright 2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Includes ------------------------------------------------------------------*/
#include "microjvm_main.h"
#include <string.h>

#include <asf.h>
#include "extension_oled1.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

__attribute__((weak)) void LLCOMM_stack_initialize(void)
{
	// does nothing by default, overrided when ECOM-COMM is used
}

struct usart_module usart_instance;

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/


int main(void)
{
	system_init();
	if(EXT_CONNECT !=0) oled1_init(&oled1); //Initialize oled Extension
	
	fputc('S', stdout);
	printf("tart program\n");
	microjvm_main();
}