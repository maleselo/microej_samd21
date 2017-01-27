/*
 * C
 *
 * Copyright 2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Includes ------------------------------------------------------------------*/

#include "LLINPUT_impl.h"
#include "microej.h"
#include "buttons_manager.h"
//#include "io_task.h"
//#include "os_support.h"

/* API -----------------------------------------------------------------------*/

void LLINPUT_IMPL_initialize(void)
{
	BUTTONS_MANAGER_initialize();
}

int32_t LLINPUT_IMPL_getInitialStateValue(int32_t stateMachinesID, int32_t stateID)
{
	// no state on this BSP
	return 0;
}

void LLINPUT_IMPL_enterCriticalSection()
{
	//OS_SUPPORT_disable_context_switching();
	BUTTONS_MANAGER_disable_interrupts();
}

void LLINPUT_IMPL_leaveCriticalSection()
{
	BUTTONS_MANAGER_enable_interrupts();
	//OS_SUPPORT_enable_context_switching();
}
