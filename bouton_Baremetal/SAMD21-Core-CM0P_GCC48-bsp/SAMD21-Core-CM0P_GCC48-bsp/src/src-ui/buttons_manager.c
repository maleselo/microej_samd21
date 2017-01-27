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
#include "buttons_manager.h"

/* Global --------------------------------------------------------------------*/

//static GPIO_Type* BUTTON_GPIO[1] = {GPIOA,};
//static PORT_Type* BUTTON_PORT[1] = {PORTA};
static const uint16_t BUTTON_PIN[1] = {BUTTON_0_PIN};
static const uint8_t BUTTON_IRQn[1] = {BUTTON_0_EIC_LINE};
static const uint8_t BUTTON_ID[1] = {0};
static const uint8_t BUTTON_REVERSE[1] = {MICROEJ_TRUE};
	

/* Private API ---------------------------------------------------------------*/

static void BUTTONS_MANAGER_event(Button_TypeDef Button)
{
	uint8_t button_pressed;
        //uint32_t readValue = GPIO_ReadPinInput(BUTTON_GPIO[Button], BUTTON_PIN[Button]);
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
		LLMJVM_dump();
	}
	else
	{
		BUTTONS_HELPER_released(BUTTON_ID[Button]);
	}
}

/* API -----------------------------------------------------------------------*/

void BUTTONS_MANAGER_interrupt(Button_TypeDef Button)
{
  //uint32_t tmpFlags = extint_chan_is_detected(BUTTON_IRQn[Button]));
  
//   if(extint_chan_is_detected(BUTTON_IRQn[Button]))
//   {
    uint8_t leave = interrupt_enter();
    BUTTONS_MANAGER_event(Button);
	//printf("Button pressed \r\n");
    interrupt_leave(leave);
   // extint_chan_clear_detected(BUTTON_IRQn[Button]);
 // }
}

void BUTTONS_MANAGER_enable_interrupts(void)
{
  //EnableIRQ(PORTA_IRQn);
  system_interrupt_enable(SYSTEM_INTERRUPT_MODULE_EIC);
}

void BUTTONS_MANAGER_disable_interrupts(void)
{
 //DisableIRQ(PORTA_IRQn);
 system_interrupt_disable(SYSTEM_INTERRUPT_MODULE_EIC);
}

void BUTTONS_MANAGER_initialize(void)
{
	BUTTONS_HELPER_initialize();
	//BUTTONS_MANAGER_init(SW0);
	
	//Init button SW0 :
	struct extint_chan_conf config_extint_chan;
	extint_chan_get_config_defaults(&config_extint_chan);
	config_extint_chan.gpio_pin = BUTTON_0_EIC_PIN;
	config_extint_chan.gpio_pin_mux = BUTTON_0_EIC_MUX;
	config_extint_chan.gpio_pin_pull = EXTINT_PULL_UP;
	config_extint_chan.detection_criteria = EXTINT_DETECT_BOTH;
	extint_chan_set_config(BUTTON_0_EIC_LINE, &config_extint_chan);
	
	extint_register_callback(button_detection_callback,	BUTTON_0_EIC_LINE,EXTINT_CALLBACK_TYPE_DETECT);
	extint_chan_enable_callback(BUTTON_0_EIC_LINE,EXTINT_CALLBACK_TYPE_DETECT);
	
}

void button_detection_callback(void){
	
	printf("in callback \n");
	BUTTONS_MANAGER_interrupt(SW0);
}
