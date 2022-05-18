/*
 * AvrDrivers.c
 *
 * Created: 5/12/2022 8:00:33 AM
 * Author : Tantawy
 */ 




#define F_CPU 16000000UL
#include "util/delay.h"
#include "Dio.h"
#include "Led.h"
#include "Pushbutton.h"
#include "SSD.h"
#include "Lcd.h"
#include "Puzzer.h"
#include "KeyPad.h"
#include "EXT_INT.h"


int main(void)
{
	u8 x=0;
	
	H_Buzzer_Init();
	H_KeyPad_Init();
	H_Lcd_Init();
	H_Ssd_Init();
	
	 H_Lcd_PrintNum(x);
	while (1)
	{
		x = H_KeyPad_Read();
		if (x != 0)
		{
			H_Lcd_WriteChar(x);
			H_Ssd_DisplayNum(x-48);
		}
		
	}
	return 0;
}

