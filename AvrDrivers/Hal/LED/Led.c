/*
 * Led.c
 *
 * Created: 5/10/2022 12:53:20 PM
 *  Author: Tantawy
 */ 

#include "Led.h"
#include "Dio.h"

/*
this function to initialize the led
make the pin output
*/
void H_Led_Init(u8 local_u8_Led)
{
	M_Dio_PinMode(local_u8_Led,OUTPUT);
}

/*
function to turn the led on 
*/
void H_Led_On(u8 local_u8_Led)
{
	
	M_Dio_PinWrite(local_u8_Led,HIGH);
}	

/*
function to turn the led off
*/
void H_Led_Off(u8 local_u8_Led)
{
	M_Dio_PinWrite(local_u8_Led,LOW);
}
/*
function to turn the led off if it is on 
and turn it on if it is off
*/
void H_Led_Tog(u8 local_u8_Led)
{
	M_Dio_pinTog(local_u8_Led);
}

/*
turn the led on and hold it for a selected time and turn it on
*/
void H_Led_BlinkOnce(u8 local_u8_Led)
{
	M_Dio_PinWrite(local_u8_Led,HIGH);
	_delay_ms(BLINK_TIME);
	M_Dio_PinWrite(local_u8_Led,LOW);
}
/*
turn the led on and hold it for a selected time and turn it on
make it twice
*/
void H_Led_Blinktwice(u8 local_u8_Led)
{
	H_Led_BlinkOnce(local_u8_Led);
	_delay_ms(BLINK_TIME);
	H_Led_BlinkOnce(local_u8_Led);
}