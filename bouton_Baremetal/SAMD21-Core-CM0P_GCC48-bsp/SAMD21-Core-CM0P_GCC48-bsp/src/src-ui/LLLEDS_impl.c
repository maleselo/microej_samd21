/*
 * LLLEDS_impl.c
 *
 * Created: 17/01/2017 14:06:11
 *  Author: Simon
 */ 
#include "LLLEDS_impl.h"
#include <asf.h>
#define OLED1_EXT_HEADER  EXT1
static OLED1_CREATE_INSTANCE(oled1, OLED1_EXT_HEADER);

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
		
		oled1_init(&oled1);
		
	return 4; //One LED on the board
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
