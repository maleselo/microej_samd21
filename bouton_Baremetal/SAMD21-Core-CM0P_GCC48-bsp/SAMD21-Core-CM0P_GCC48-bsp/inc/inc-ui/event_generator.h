/* 
 * Copyright 2015-2016 IS2T. All rights reserved.
 * Modification and distribution is permitted under certain conditions.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/*
 * This header files groups several APIs to notify to a or several events handlers an
 * event has occured on an input driver (buttons, touch etc.).
 *
 * The idea is to disconnect the management of the inputs drivers (how to initialize an
 * input driver, how to get/read an input event, how to clear it, etc.) and how to
 * send these inputs events to the MicroUI application using the MicroUI EventGenerators.
 *
 * The MicroUI framework is using an internal buffer to store the inputs events. The event
 * will not be added if the internal events buffer is full. In this case the input driver
 * has to adapt itself in order to not send a future invalid event. For instance, if a
 * PRESSED event is not sent, the input driver has not to send a REPEAT or RELEASE event.
 * So it may have a distinction between the real input state and the "software" input
 * state.
 */
#ifndef _EVENT_GENERATOR
#define _EVENT_GENERATOR

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>

/* API -----------------------------------------------------------------------*/

/*
 * Notify to the event generator a button has been pressed.
 * @param buttonId the button ID, between 0 and 255
 * @return {@link LLINPUT_OK} if all events have been added, {@link LLINPUT_NOK} otherwise
 */
int32_t EVENT_GENERATOR_button_pressed(int32_t buttonId);

/*
 * Notify to the event generator a button has been repeated.
 * @param buttonId the button ID, between 0 and 255
 * @return {@link LLINPUT_OK} if all events have been added, {@link LLINPUT_NOK} otherwise
 */
int32_t EVENT_GENERATOR_button_repeated(int32_t buttonId);

/*
 * Notify to the event generator a button has been released.
 * @param buttonId the button ID, between 0 and 255
 * @return {@link LLINPUT_OK} if all events have been added, {@link LLINPUT_NOK} otherwise
 */
int32_t EVENT_GENERATOR_button_released(int32_t buttonId);

/*
 * Notify to the event generator a pointer button has been pressed.
 * @param buttonId the button ID, between 0 and 255
 * @param x the pointer X coordinate
 * @param y the pointer Y coordinate
 * @param type {@link LLINPUT_ABSOLUTE} when (x,y) coordinates are absolute, {@link LLINPUT_RELATIVE} when
 * there are relative to the previous pointer position
 * @return {@link LLINPUT_OK} if all events have been added, {@link LLINPUT_NOK} otherwise
 */
int32_t EVENT_GENERATOR_pointer_pressed(int32_t buttonID, int32_t x, int32_t y, int32_t type);

/*
 * Notify to the event generator a pointer has moved.
 * @param x the pointer X coordinate
 * @param y the pointer Y coordinate
 * @param absolute {@link LLINPUT_ABSOLUTE} when (x,y) coordinates are absolute, {@link LLINPUT_RELATIVE} when
 * there are relative to the previous pointer position
 * @return {@link LLINPUT_OK} if all events have been added, {@link LLINPUT_NOK} otherwise
 */
int32_t EVENT_GENERATOR_pointer_moved(int32_t x, int32_t y, int32_t type);

/*
 * Notify to the event generator a pointer button has been released.
 * @param buttonId the button ID, between 0 and 255
 * @return {@link LLINPUT_OK} if the event has been added, {@link LLINPUT_NOK} otherwise
 */
int32_t EVENT_GENERATOR_pointer_released(int32_t buttonID);

/*
 * Notify to the event generator a state has changed.
 * @param stateID the state machine identifier, between 0 and 255
 * @param stateValue the new state if the state machine, between 0 and 255
 * @return {@link LLINPUT_OK} if all events have been added, {@link LLINPUT_NOK} otherwise
 */
int32_t EVENT_GENERATOR_state_changed(int32_t stateID, int32_t stateValue);

#endif
