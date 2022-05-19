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
#include "TempSensor.h"
#include "ADC.h"

int main(void)
{
	u16 x=0;
	H_Buzzer_Init();
	H_Lcd_Init();
	M_Adc_Init();
	H_TempSensor_Init();
	
	 
	while (1)
	{
		x = H_TempSensor_Read();
		H_Lcd_GoTo(0,0);
		H_Lcd_WriteStr((u8*)"Temp :");
		H_Lcd_PrintNum(x);
		H_Lcd_GoTo(1,0);
		H_Lcd_WriteStr((u8*)"ADC  :");
		x = M_Adc_Read();
		H_Lcd_PrintNum(x);
		_delay_ms(1000);
		//H_Lcd_Clr();
	}
	return 0;
}

