/*
 * C
 *
 * Copyright 2013-2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Includes ------------------------------------------------------------------*/

#include "microej.h"
#include <asf.h>
#include "interrupts.h"
#include "LLMJVM.h"
#include "extension_oled1.h"
#include "buttons_manager.h"
#include "buttons_helper_configuration.h"


/* Global --------------------------------------------------------------------*/
static const uint8_t BUTTON_MUX[NUMBER_OF_BUTTONS] = {BUTTON_0_EIC_MUX,BUTTON_1_EIC_MUX,BUTTON_2_EIC_MUX,BUTTON_3_EIC_MUX};
static const uint8_t BUTTON_PIN[NUMBER_OF_BUTTONS] = {BUTTON_0_PIN,BUTTON_1_PIN,BUTTON_2_PIN,BUTTON_3_PIN};
static const uint8_t BUTTON_LINE[NUMBER_OF_BUTTONS] = {BUTTON_0_EIC_LINE,OLED_BUTTON1_EIC_LINE,OLED_BUTTON2_EIC_LINE,OLED_BUTTON3_EIC_LINE};
static const uint8_t BUTTON_ID[NUMBER_OF_BUTTONS] = {SW0,SW1,SW2,SW3};
static const uint8_t BUTTON_REVERSE[NUMBER_OF_BUTTONS] = {MICROEJ_TRUE,MICROEJ_TRUE,MICROEJ_TRUE,MICROEJ_TRUE};
static const extint_callback_t BUTTON_CALLBACK[NUMBER_OF_BUTTONS] = {button0_detection_callback,oled_button1_detection_callback,oled_button2_detection_callback,oled_button3_detection_callback};

/* Private API ---------------------------------------------------------------*/

static void BUTTONS_MANAGER_event(Button_TypeDef Button)
{
	uint8_t button_pressed;
		uint32_t readValue = port_pin_get_input_level(BUTTON_PIN[Button]);

        if (readValue == 1U)
	{
		// GPIO == 1

		if (BUTTON_REVERSE[Button] == MICROEJ_TRUE)
		{
			// GPIO == 1 means "released"
			button_pressed = MICROEJ_FALSE;
		}
		else
		{
			// GPIO == 1 means "pressed"
			button_pressed = MICROEJ_TRUE;
		}
	}
	else
	{
		// GPIO == 0

		if (BUTTON_REVERSE[Button] == MICROEJ_TRUE)
		{
			// GPIO == 0 means "pressed"
			button_pressed = MICROEJ_TRUE;
		}
		else
		{
			// GPIO == 0 means "released"
			button_pressed = MICROEJ_FALSE;
		}
	}

	if (button_pressed == MICROEJ_TRUE)
	{
		BUTTONS_HELPER_pressed(BUTTON_ID[Button]);
		//LLMJVM_dump();
	}
	else
	{
		BUTTONS_HELPER_released(BUTTON_ID[Button]);
	}
}

/* API -----------------------------------------------------------------------*/

void BUTTONS_MANAGER_interrupt(Button_TypeDef Button)
{  
//    if(extint_chan_is_detected(BUTTON_LINE[Button]))
//    {
    uint8_t leave = interrupt_enter();
    BUTTONS_MANAGER_event(Button);
	//printf("Button pressed \r\n");
    interrupt_leave(leave);
//     extint_chan_clear_detected(BUTTON_LINE[Button]);
//   }
}

void BUTTONS_MANAGER_enable_interrupts(void)
{
  system_interrupt_enable(SYSTEM_INTERRUPT_MODULE_EIC);
}

void BUTTONS_MANAGER_disable_interrupts(void)
{
 system_interrupt_disable(SYSTEM_INTERRUPT_MODULE_EIC);
}


void BUTTONS_MANAGER_init(int button){
	struct extint_chan_conf config_extint_chan2;
	extint_chan_get_config_defaults(&config_extint_chan2);
	config_extint_chan2.gpio_pin = BUTTON_PIN[button];
	config_extint_chan2.gpio_pin_mux = BUTTON_MUX[button];
	config_extint_chan2.gpio_pin_pull = EXTINT_PULL_UP;
	config_extint_chan2.detection_criteria = EXTINT_DETECT_BOTH;
	extint_chan_set_config(BUTTON_LINE[button], &config_extint_chan2);
	
	extint_register_callback(BUTTON_CALLBACK[button],BUTTON_LINE[button],EXTINT_CALLBACK_TYPE_DETECT);
	
	extint_chan_enable_callback(BUTTON_LINE[button],EXTINT_CALLBACK_TYPE_DETECT);
}

void BUTTONS_MANAGER_initialize(void)
{
	BUTTONS_HELPER_initialize();
	
	BUTTONS_MANAGER_init(SW0);
	BUTTONS_MANAGER_init(SW1);
	BUTTONS_MANAGER_init(SW2);
	BUTTONS_MANAGER_init(SW3);
	
}

void button0_detection_callback(void){
	BUTTONS_MANAGER_interrupt(SW0);
	printf("Call back 0 \n");
}

void oled_button1_detection_callback(void){
	BUTTONS_MANAGER_interrupt(SW1);
}

void oled_button2_detection_callback(void){
	BUTTONS_MANAGER_interrupt(SW2);
}

void oled_button3_detection_callback(void){
	BUTTONS_MANAGER_interrupt(SW3);
}