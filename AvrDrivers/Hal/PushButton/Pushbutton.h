/*
 * Pushbutton.h
 *
 * Created: 5/11/2022 10:01:30 AM
 *  Author: Tantawy
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

//--------------------_INCLUDES_--------------------------
#include "Std.h"
#include "Dio.h"
#include "PushbuttonCfg.h"
#define F_CPU 16000000UL
#include "util/delay.h"

//---------------------_MACROS_-----------------------------
//push button modes MACROS
#define ACTIVE_LOW		0
#define ACTIVE_HIGH		1
// Conditions of PUSH buttons modes
#if PUSHBUTTON_MODE == ACTIVE_LOW

#define PRESSED			0
#define RELEASED		1

#elif PUSHBUTTON_MODE == ACTIVE_HIGH

#define PRESSED			1
#define RELEASED		0

#endif

//----------------_PROTOTYPES_---------------------------
void H_PushButton_Init(void);
u8 H_PushButton_Read(void);


#endif /* PUSHBUTTON_H_ */