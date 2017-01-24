/**
 * Copyright 2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Includes ------------------------------------------------------------------*/
#include "microjvm_main.h"
#include "FreeRTOS.h"
#include "task.h"
#include <string.h>

#include <asf.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MICROJVM_STACK_SIZE (5 * 1024)
#define JAVA_TASK_PRIORITY      ( 11 ) /** Should be > tskIDLE_PRIORITY & < configTIMER_TASK_PRIORITY */
#define JAVA_TASK_STACK_SIZE     MICROJVM_STACK_SIZE/4

__attribute__((weak)) void LLCOMM_stack_initialize(void)
{
	// does nothing by default, overrided when ECOM-COMM is used
}

void xJavaTaskFunction(void * pvParameters)
{
	microjvm_main();
	vTaskDelete( xTaskGetCurrentTaskHandle() );
	
}

struct usart_module usart_instance;

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/



int main(void)
{
	system_init();
	fputc('1', stdout);
	printf("Start program\n");
	xTaskCreate( xJavaTaskFunction, "MicroJvm", JAVA_TASK_STACK_SIZE, NULL, JAVA_TASK_PRIORITY, NULL );
	printf("Tasks created \r\n");
	vTaskStartScheduler();
}