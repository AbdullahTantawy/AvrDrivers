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
#include "ADC.h"


int main(void)
{
	u16 x=0;
	H_Buzzer_Init();
	H_Lcd_Init();
	M_Adc_Init();
	
	 
	while (1)
	{
		x= M_Adc_Read();
		H_Lcd_PrintNum(x);
		_delay_ms(300);
		H_Lcd_Clr();
	}
	return 0;
}

