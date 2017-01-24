/*
 * C
 *
 * Copyright 2012-2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/* Includes ------------------------------------------------------------------*/

#include <asf.h>
#include <stdio_serial.h>
#include <stdio.h>

/* Defines -------------------------------------------------------------------*/

/* Globals -------------------------------------------------------------------*/

uint8_t putchar_initialized = 0;
struct usart_module usart_instance;

/* Private functions ---------------------------------------------------------*/

static void uart_init(void){
	
	struct usart_config config_usart;
	
	usart_get_config_defaults(&config_usart);
	
	//config_usart.baudrate = 115200;
	config_usart.baudrate = 9600;
	//config_usart.receiver_enable = true; // only use to send data
	
	config_usart.mux_setting = EDBG_CDC_SERCOM_MUX_SETTING;
	config_usart.pinmux_pad0 = EDBG_CDC_SERCOM_PINMUX_PAD0;
	config_usart.pinmux_pad1 = EDBG_CDC_SERCOM_PINMUX_PAD1;
	config_usart.pinmux_pad2 = EDBG_CDC_SERCOM_PINMUX_PAD2;
	config_usart.pinmux_pad3 = EDBG_CDC_SERCOM_PINMUX_PAD3;
	
	stdio_serial_init(&usart_instance, EDBG_CDC_MODULE, &config_usart); // Ok with printf
	/*
	while (usart_init(&usart_instance,
	EDBG_CDC_MODULE, &config_usart) != STATUS_OK) {
	}*/
	
	usart_enable(&usart_instance);
	
}

/* Public functions ----------------------------------------------------------*/


int fputc(int ch, FILE *f){
	if(!putchar_initialized)
		{
			uart_init();
			putchar_initialized = 1;
		}
	usart_write_wait(&usart_instance, (uint16_t) ch);
	return ch;
}
