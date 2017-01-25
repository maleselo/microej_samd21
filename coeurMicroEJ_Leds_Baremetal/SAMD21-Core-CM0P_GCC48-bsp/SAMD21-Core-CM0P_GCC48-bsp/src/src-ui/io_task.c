/*
 * C
 *
 * Copyright 2013-2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Includes ------------------------------------------------------------------*/

#include "io_task.h"
#include "buttons_manager.h"
#include "buttons_helper.h"
#include "microej.h"
#include "interrupts.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

#include "time_hardware_timer.h"

/* Defines -------------------------------------------------------------------*/

#define IO_TASK_PRIORITY ( 12 )
#define IO_TASK_STACK_SIZE (256)

/* Global --------------------------------------------------------------------*/

static xSemaphoreHandle io_task_sem = NULL;

/* Private API ---------------------------------------------------------------*/

static void vIoTaskFunction(void *p_arg) {
	do {
		osDelay(IO_TASK_POLL_DELAY);
		TOUCH_MANAGER_update();
	} while (1);
}

/* Interrupt function --------------------------------------------------------*/

void PORTA_IRQHandler(void) {
	BUTTONS_MANAGER_interrupt(SW2);
	BUTTONS_MANAGER_interrupt(SW3);
}

/* API -----------------------------------------------------------------------*/

uint8_t IO_TASK_create_task(void) {
	if (io_task_sem == NULL) {
		// Hardware timer should be initialized but check anyway
		if (!time_hardware_timer_isInitialized()) {
			time_hardware_timer_initialize();
		}

		// create ioe task
		xTaskCreate(vIoTaskFunction, NULL, IO_TASK_STACK_SIZE, NULL,
				IO_TASK_PRIORITY, NULL);
	}

	return MICROEJ_TRUE;
}
