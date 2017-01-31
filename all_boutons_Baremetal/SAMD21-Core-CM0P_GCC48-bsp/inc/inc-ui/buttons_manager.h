/*
 * C
 *
 * Copyright 2015-2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#ifndef _BUTTONS_MANAGER
#define _BUTTONS_MANAGER

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>
#include "buttons_helper.h"
#include "extension_oled1.h"
/* Define --------------------------------------------------------------------*/

// EXT_CONNECT defined in extension_oled1.h file
#if EXT_CONNECT == 1
	
	#define BUTTON_1_EIC_MUX MUX_PB04A_EIC_EXTINT4
	#define BUTTON_2_EIC_MUX MUX_PB00A_EIC_EXTINT0
	#define BUTTON_3_EIC_MUX MUX_PB01A_EIC_EXTINT1
	
	#define BUTTON_1_PIN PIN_PB04A_EIC_EXTINT4
	#define BUTTON_2_PIN PIN_PB00A_EIC_EXTINT0
	#define BUTTON_3_PIN PIN_PB01A_EIC_EXTINT1
	
	#define OLED_BUTTON1_EIC_LINE 4
	#define OLED_BUTTON2_EIC_LINE 0
	#define OLED_BUTTON3_EIC_LINE 1

#elif EXT_CONNECT == 2

	#define BUTTON_1_EIC_MUX MUX_PB14A_EIC_EXTINT14
	#define BUTTON_2_EIC_MUX MUX_PA10A_EIC_EXTINT10
	#define BUTTON_3_EIC_MUX MUX_PA11A_EIC_EXTINT11
	
	#define BUTTON_1_PIN PIN_PB14A_EIC_EXTINT14
	#define BUTTON_2_PIN PIN_PA10A_EIC_EXTINT10
	#define BUTTON_3_PIN PIN_PA11A_EIC_EXTINT11
	
	#define OLED_BUTTON1_EIC_LINE 14
	#define OLED_BUTTON2_EIC_LINE 10
	#define OLED_BUTTON3_EIC_LINE 11

#elif EXT_CONNECT == 3

	#define BUTTON_1_EIC_MUX MUX_PA28A_EIC_EXTINT8
	#define BUTTON_2_EIC_MUX MUX_PA02A_EIC_EXTINT2
	#define BUTTON_3_EIC_MUX MUX_PA03A_EIC_EXTINT3
	
	#define BUTTON_1_PIN PIN_PA28A_EIC_EXTINT8
	#define BUTTON_2_PIN PIN_PA02A_EIC_EXTINT2
	#define BUTTON_3_PIN PIN_PA03A_EIC_EXTINT3
	
	#define OLED_BUTTON1_EIC_LINE 8
	#define OLED_BUTTON2_EIC_LINE 2
	#define OLED_BUTTON3_EIC_LINE 3
	
#endif

/* API -----------------------------------------------------------------------*/

void oled_button1_detection_callback(void);
void oled_button2_detection_callback(void);
void oled_button3_detection_callback(void);
void button0_detection_callback(void);
void BUTTONS_MANAGER_init(int button);
void BUTTONS_MANAGER_initialize(void);
void BUTTONS_MANAGER_interrupt(Button_TypeDef Button);
void BUTTONS_MANAGER_enable_interrupts(void);
void BUTTONS_MANAGER_disable_interrupts(void);

#endif
