/*
 * C
 *
 * Copyright 2013-2016 IS2T. All rights reserved.
 * For demonstration purpose only.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */


#ifndef EXTENSION_OLED1_H_
#define EXTENSION_OLED1_H_

#define EXT_CONNECT 1 //change value for oled extension port : 1 for EXT1, 2 for EXT2 and 3 for EXT3

#if EXT_CONNECT == 1
	#define OLED1_EXT_HEADER  EXT1
#elif EXT_CONNECT == 2
	#define OLED1_EXT_HEADER  EXT2
#elif EXT_CONNECT == 3
	#define OLED1_EXT_HEADER  EXT3
#endif

static OLED1_CREATE_INSTANCE(oled1, OLED1_EXT_HEADER);

#endif