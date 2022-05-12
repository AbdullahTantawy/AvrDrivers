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

int main(void)
{
	u8 X=0;
	H_Ssd_Init();
	
	
	while (1)
	{
		H_Ssd_DisplayNum(X);
		X++;
	}
	return 0;
}

