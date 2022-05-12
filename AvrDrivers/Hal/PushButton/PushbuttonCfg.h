/*
 * PushbuttonCfg.h
 *
 * Created: 5/11/2022 10:01:52 AM
 *  Author: Tantawy
 */ 


#ifndef PUSHBUTTONCFG_H_
#define PUSHBUTTONCFG_H_


//-------------------------_MACROS_----------------------

//-----------------------_PUSH_BUTTON_PINS_----------------------
#define PUSHBUTTON_PIN	PD2
//----------------------_PUSH_BUTTON_MODES_-----------------------
// OPTION 1- ACTIVE_LOW
// OPTION 2- ACTIVE_HIGH
#define   PUSHBUTTON_MODE  ACTIVE_LOW
//---------------_SELECT_THE_DEBOUNCING_TIME_-----------------
#define BLINK_TIME		100
#endif /* PUSHBUTTONCFG_H_ */