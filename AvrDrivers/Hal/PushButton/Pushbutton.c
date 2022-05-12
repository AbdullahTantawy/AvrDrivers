/*
 * Pushbutton.c
 *
 * Created: 5/11/2022 10:01:05 AM
 *  Author: Tantawy
 */ 

#include "Pushbutton.h"

void H_PushButton_Init(void)
{
	M_Dio_PinMode(PUSHBUTTON_PIN , INPUT);
}

//--------------------------------------------------------------------------
u8 H_PushButton_Read(void)
{
	u8 Local_u8_Reading = RELEASED;
	if(M_Dio_PinGet(PUSHBUTTON_PIN) == PRESSED)
	{
		_delay_ms(BLINK_TIME); // to solve the bouncing problem
		if ( M_Dio_PinGet(PUSHBUTTON_PIN) == PRESSED)
		{
			Local_u8_Reading = PRESSED;
			//if the button still pressed hold until released
			while( M_Dio_PinGet(PUSHBUTTON_PIN) == PRESSED);
		}
	}
	return Local_u8_Reading;
}
