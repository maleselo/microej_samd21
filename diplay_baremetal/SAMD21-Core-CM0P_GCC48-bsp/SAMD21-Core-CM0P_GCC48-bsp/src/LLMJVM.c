/*
 * Copyright 2013-2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/*
 * This implementation uses a dedicated hardware timer for time implementation,
 * instead of internal FreeRTOS timer which is a 32bits timer.
 */

/* Includes ------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <asf.h>

#include "LLMJVM_impl.h"
#include "microej.h"
#include "time_hardware_timer.h"
#include "interrupts.h"

/* Defines -------------------------------------------------------------------*/

/*
 * Useful macros and definitions
 */

/* Globals -------------------------------------------------------------------*/

/*
 * Shared variables
 */
// Application time offset
static int64_t LLMJVM_application_time_offset = 0;

//Absolute time (in ?) at which timer will be launched
static int64_t LLMJVM_next_wake_up_time = INT64_MAX;

struct tc_module tc_schedule;

/* Private functions ---------------------------------------------------------*/

// Since LLMJVM_schedule() prototype does not match the timer callback prototype,
// we create a wrapper around it and check the ID of the timer.
static void wake_up_timer_callback()
{
	LLMJVM_schedule();
}

/*
* Init a timer that counts (down) and fires a call-back when it reaches 
* a specified value
*/
static void LLMJVM_init_timer(void){

	struct tc_config config_tc;
	tc_get_config_defaults(&config_tc);
	config_tc.oneshot = true;
	config_tc.count_direction = TC_COUNT_DIRECTION_DOWN;

	tc_init(&tc_schedule, TC5 ,&config_tc);

	tc_enable(&tc_schedule);
	
	tc_register_callback(&tc_schedule, wake_up_timer_callback, TC_CALLBACK_CC_CHANNEL0);
	tc_enable_callback(&tc_schedule, TC_CALLBACK_CC_CHANNEL0);
	
}
/* Public functions ----------------------------------------------------------*/

/*
 * Implementation of functions from LLMJVM_impl.h
 * and other helping functions.
 */
 
// Creates the timer used to callback the LLMJVM_schedule() function.
// After its creation, the timer is idle.
int32_t LLMJVM_IMPL_initialize()
{   
   
	LLMJVM_init_timer();
	time_hardware_timer_initialize();

	return LLMJVM_OK;
}

// Once the task is started, save a handle to it.
int32_t LLMJVM_IMPL_vmTaskStarted()
{
	return LLMJVM_OK;
}

// Schedules requests from the VM
int32_t LLMJVM_IMPL_scheduleRequest(int64_t absoluteTime)
{
    int64_t relativeTime;//Time to reach absoluteTime

	//First check if absolute time is lower than current schedule time
	if(absoluteTime < LLMJVM_next_wake_up_time)
    {

        // Save new alarm absolute time
        LLMJVM_next_wake_up_time = absoluteTime;
        
        // Stop current timer (no delay)
        tc_stop_counter(&tc_schedule);

        // Determine relative time/tick
		relativeTime = absoluteTime - LLMJVM_IMPL_getCurrentTime(MICROEJ_TRUE);
		
		if(relativeTime > 0)
		{	
            // Schedule the new alarm
			tc_set_top_value(&tc_schedule, relativeTime * 8);//uP clock : 8MHz
			tc_start_counter(&tc_schedule);
               
            return LLMJVM_OK;
		}
        else
        {
            // 'absoluteTime' has been reached already, notify the VM now
            return LLMJVM_schedule();
        }
	}
    // else : nothing to do. An sooner alarm is scheduled.
	
	return LLMJVM_OK;
}

// Suspends the VM task if the pending flag is not set
int32_t LLMJVM_IMPL_idleVM()
{
	//portBASE_TYPE res = xSemaphoreTake(LLMJVM_FREERTOS_Semaphore, portMAX_DELAY);

	return LLMJVM_OK;
}

// Wakes up the VM task and reset next wake up time
int32_t LLMJVM_IMPL_wakeupVM()
{
	/*portBASE_TYPE res;
	if(interrupt_is_in() == MICROEJ_TRUE){
		portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
		res = xSemaphoreGiveFromISR(LLMJVM_FREERTOS_Semaphore, &xHigherPriorityTaskWoken);
		if( xHigherPriorityTaskWoken != pdFALSE ){
			// Force a context switch here.
			portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		}
	}
	else {
		res = xSemaphoreGive(LLMJVM_FREERTOS_Semaphore);
	}
    
	LLMJVM_FREERTOS_next_wake_up_time = INT64_MAX;*/

	return LLMJVM_OK;
}

// Clear the pending wake up flag
int32_t LLMJVM_IMPL_ackWakeup()
{
	return LLMJVM_OK;
}

int32_t LLMJVM_IMPL_getCurrentTaskID()
{
	return 0;//!!
}

// Sets application time
void LLMJVM_IMPL_setApplicationTime(int64_t t)
{
    int64_t currentTime = LLMJVM_IMPL_getCurrentTime(MICROEJ_TRUE);
	LLMJVM_application_time_offset = t - currentTime;
}

// Gets the system or the application time in milliseconds
int64_t LLMJVM_IMPL_getCurrentTime(uint8_t system)
{      
    int64_t systemTime = time_hardware_timer_getCurrentTime();
    return system ? systemTime : systemTime + LLMJVM_application_time_offset;
}

// Gets the current system time in nanoseconds
int64_t LLMJVM_IMPL_getTimeNanos(){
	return time_hardware_timer_getTimeNanos();
}

int32_t LLMJVM_IMPL_shutdown(void){
	// nothing to do
	return LLMJVM_OK;
}

