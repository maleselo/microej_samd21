/*
 * C
 *
 * Copyright 2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
 
#include "LLLEDS_impl.h"
#include <asf.h>
#include "extension_oled1.h"

/**
 * Initializes the LEDs.
 * Initializes OLED module
 * @return the number of LEDs in the group.
 */
int32_t LLLEDS_IMPL_initialize(void){	
		struct port_config pin_conf;
		port_get_config_defaults(&pin_conf);

		pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
		port_pin_set_config(LED_0_PIN, &pin_conf);
		port_pin_set_output_level(LED_0_PIN, LED_0_INACTIVE);	
		
		if(EXT_CONNECT == 0){
			return 1; //Only on board led
		}
		else return 4; //With oled extension
}

/**
 * Get the intensity of the LED.
 * @return the intensity of the LED
 */
int32_t LLLEDS_IMPL_getIntensity(int32_t ledID){
	switch(ledID){
		case 0: if(port_pin_get_output_level(LED_0_PIN)) return LLLEDS_MAX_INTENSITY;
				else return LLLEDS_MIN_INTENSITY;
				break;
		case 1: if(oled1_get_led_state(&oled1,OLED1_LED1_ID)) return LLLEDS_MAX_INTENSITY;
				else return LLLEDS_MIN_INTENSITY;
				break;
		case 2: if(oled1_get_led_state(&oled1,OLED1_LED2_ID)) return LLLEDS_MAX_INTENSITY;
				else return LLLEDS_MIN_INTENSITY;
				break;
		case 3: if(oled1_get_led_state(&oled1,OLED1_LED3_ID)) return LLLEDS_MAX_INTENSITY;
				else return LLLEDS_MIN_INTENSITY;
				break;	
		default : break;	
	}	
}

/**
 * Set the intensity of the LED.
 * A 0 intensity turns off the LED, intensity of 255 turns on the LED to max power.
 * @param intensity the intensity of the LED
 */
void LLLEDS_IMPL_setIntensity(int32_t ledID, int32_t intensity){
	
	switch(ledID){
		case 0: if(intensity > 0){
					port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
				}
				else port_pin_set_output_level(LED_0_PIN, LED_0_INACTIVE);
			break;
		case 1: if(intensity > 0){
					oled1_set_led_state(&oled1, OLED1_LED1_ID, !OLED1_LED_ACTIVE);
				}
				else oled1_set_led_state(&oled1, OLED1_LED1_ID, OLED1_LED_ACTIVE);
			break;
		case 2: if(intensity > 0){
					oled1_set_led_state(&oled1, OLED1_LED2_ID, !OLED1_LED_ACTIVE);
				}
				else oled1_set_led_state(&oled1, OLED1_LED2_ID, OLED1_LED_ACTIVE);
			break;
		case 3: if(intensity > 0){
					oled1_set_led_state(&oled1, OLED1_LED3_ID, !OLED1_LED_ACTIVE);
				}
				else oled1_set_led_state(&oled1, OLED1_LED3_ID, OLED1_LED_ACTIVE);
			break;
		default : break;
	}
}
