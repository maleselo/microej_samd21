/* 
 * Copyright 2012 IS2T. All rights reserved.
 * Modification and distribution is permitted under certain conditions.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#include <asf.h>
#include "LLDISPLAY_impl.h"
#include "gfx_mono_ug_2832hsweg04.h"
#include "ssd1306.h"

/*Implementations*/
static uint8_t backbuffer[GFX_MONO_LCD_FRAMEBUFFER_SIZE];

/*Initialize the display*/
void LLDISPLAY_IMPL_initialize(void){
	gfx_mono_init();
}

int32_t LLDISPLAY_IMPL_getWidth(void){
	return GFX_MONO_LCD_WIDTH;
}
int32_t LLDISPLAY_IMPL_getHeight(void){
	return GFX_MONO_LCD_HEIGHT;
}

int32_t LLDISPLAY_IMPL_getGraphicsBufferAddress(void){
	return &backbuffer;
}

int32_t LLDISPLAY_IMPL_getWorkingBufferStartAddress(void){
	
}

int32_t LLDISPLAY_IMPL_getWorkingBufferEndAddress(void){
	
}

int32_t LLDISPLAY_IMPL_flush(int32_t sourceAddr, int32_t xmin, int32_t ymin, int32_t xmax, int32_t ymax){
	
	uint8_t y, page, column, decalage;
	uint8_t *pdata;
	uint8_t data;
	
	for (column = xmin; column < xmax; column++) { 
		
		for (y = ymin; y < ymax; y++) {
			
			page = y/8;
			pdata = (sourceAddr + (page * GFX_MONO_LCD_WIDTH) + column);
			
			decalage = y % 8;
			
			data = (*pdata >> decalage) & 0x1;
			
			if(data)gfx_mono_ssd1306_draw_pixel(column, y, GFX_PIXEL_SET);
			else gfx_mono_ssd1306_draw_pixel(column,  y , GFX_PIXEL_CLR);
		}
	}
}
void LLDISPLAY_IMPL_synchronize(void){
	
}