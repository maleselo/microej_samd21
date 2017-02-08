/*
 * C
 *
 * Copyright 2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/*Includes*/
#include "time_hardware_timer.h"
#include <asf.h>

/*Globals*/
// this value is updated at each interrupt
static int64_t software_counter;
struct tc_module tc_instance;

/*Interrupt functions*/
void tc_IRQHander(){
	software_counter++;
}

/*Public functions*/
void time_hardware_timer_initialize(void){
	//reset software counter
	software_counter = 0;
	
	//tc configuration
	struct tc_config config_tc;
	tc_get_config_defaults(&config_tc);
	//compare capture channel when T=1ms (uP clock:8Mhz)
	//config_tc.counter_16_bit.compare_capture_channel[0] = 0x1F3F;
	//T = 100us
	config_tc.counter_16_bit.compare_capture_channel[0] = 0x31F;
	//when compared value is captured, reset counter
	config_tc.wave_generation = TC_WAVE_GENERATION_MATCH_FREQ;
	
	//initialization module TC3 with config_tc
	tc_init(&tc_instance, TC3 ,&config_tc);
	
	//start counting
	tc_enable(&tc_instance);
	
	//enable callback
	tc_register_callback(&tc_instance, tc_IRQHander, TC_CALLBACK_CC_CHANNEL0);
	tc_enable_callback(&tc_instance, TC_CALLBACK_CC_CHANNEL0);
	
}
int64_t time_hardware_timer_getCurrentTime(void){
	return software_counter/10;
}
int64_t time_hardware_timer_getTimeNanos(void){
	return software_counter*100000;
}