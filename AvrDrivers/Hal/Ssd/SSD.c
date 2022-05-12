/*
 * SSD.c
 *
 * Created: 5/11/2022 1:18:30 PM
 *  Author: Tantawy
 */ 

#include "SSD.h"


// make the All SSD (7)pins output 
void H_Ssd_Init(void)
{
	M_Dio_PinMode(SSD_A_PIN,OUTPUT);
	M_Dio_PinMode(SSD_B_PIN,OUTPUT);
	M_Dio_PinMode(SSD_C_PIN,OUTPUT);
	M_Dio_PinMode(SSD_D_PIN,OUTPUT);
	M_Dio_PinMode(SSD_E_PIN,OUTPUT);
	M_Dio_PinMode(SSD_F_PIN,OUTPUT);
	M_Dio_PinMode(SSD_G_PIN,OUTPUT);
	
	M_Dio_PinMode(SSD1_EN,OUTPUT);
	M_Dio_PinMode(SSD2_EN,OUTPUT);
	
}

//-----------------__-------------------------------

void H_Ssd_Display(u8 Local_u8_Ssd ,u8 Local_u8_num)
{
	switch(Local_u8_Ssd)
	{
		case SSD_1:
		M_Dio_PinWrite(SSD1_EN,HIGH);
		M_Dio_PinWrite(SSD2_EN,LOW);
		break;
		case SSD_2:
		M_Dio_PinWrite(SSD1_EN,LOW);
		M_Dio_PinWrite(SSD2_EN,HIGH);
		break;
		default:
		M_Dio_PinWrite(SSD1_EN,LOW);
		M_Dio_PinWrite(SSD2_EN,LOW);
		break;
	}
#if SSD_DIRECT
	switch(Local_u8_num)
	{
		case 0:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,HIGH);
		M_Dio_PinWrite(SSD_E_PIN,HIGH);
		M_Dio_PinWrite(SSD_F_PIN,HIGH);
		M_Dio_PinWrite(SSD_G_PIN,LOW);
		break;
		case 1:
		M_Dio_PinWrite(SSD_A_PIN,LOW);
		M_Dio_PinWrite(SSD_B_PIN,LOW);
		M_Dio_PinWrite(SSD_C_PIN,LOW);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		M_Dio_PinWrite(SSD_E_PIN,HIGH);
		M_Dio_PinWrite(SSD_F_PIN,HIGH);
		M_Dio_PinWrite(SSD_G_PIN,LOW);
		break;
		case 2:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,LOW);
		M_Dio_PinWrite(SSD_D_PIN,HIGH);
		M_Dio_PinWrite(SSD_E_PIN,HIGH);
		M_Dio_PinWrite(SSD_F_PIN,LOW);
		M_Dio_PinWrite(SSD_G_PIN,HIGH);
		break;
		case 3:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,HIGH);
		M_Dio_PinWrite(SSD_E_PIN,LOW);
		M_Dio_PinWrite(SSD_F_PIN,LOW);
		M_Dio_PinWrite(SSD_G_PIN,HIGH);
		break;
		case 4:
		M_Dio_PinWrite(SSD_A_PIN,LOW);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		M_Dio_PinWrite(SSD_E_PIN,LOW);
		M_Dio_PinWrite(SSD_F_PIN,HIGH);
		M_Dio_PinWrite(SSD_G_PIN,HIGH);
		break;
		case 5:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,LOW);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,HIGH);
		M_Dio_PinWrite(SSD_E_PIN,LOW);
		M_Dio_PinWrite(SSD_F_PIN,HIGH);
		M_Dio_PinWrite(SSD_G_PIN,HIGH);
		break;
		case 6:
		M_Dio_PinWrite(SSD_A_PIN,LOW);
		M_Dio_PinWrite(SSD_B_PIN,LOW);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,HIGH);
		M_Dio_PinWrite(SSD_E_PIN,HIGH);
		M_Dio_PinWrite(SSD_F_PIN,HIGH);
		M_Dio_PinWrite(SSD_G_PIN,HIGH);
		break;
		case 7:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		M_Dio_PinWrite(SSD_E_PIN,LOW);
		M_Dio_PinWrite(SSD_F_PIN,LOW);
		M_Dio_PinWrite(SSD_G_PIN,LOW);
		break;
		case 8:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,HIGH);
		M_Dio_PinWrite(SSD_E_PIN,HIGH);
		M_Dio_PinWrite(SSD_F_PIN,HIGH);
		M_Dio_PinWrite(SSD_G_PIN,HIGH);
		break;
		case 9:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		M_Dio_PinWrite(SSD_E_PIN,LOW);
		M_Dio_PinWrite(SSD_F_PIN,HIGH);
		M_Dio_PinWrite(SSD_G_PIN,HIGH);
		break;
	}
#elif SSD_DECODER

		PORTA &= 0X0F;
		PORTA |= (Local_u8_num<<4);
/*
	switch(Local_u8_num)
	{
		case 0: PORTA = 0x00 ;	break;
		case 1: PORTA = 0x10 ;	break;
		case 2: PORTA = 0x20 ;	break;
		case 3: PORTA = 0x30 ;	break;
		case 4: PORTA = 0x40 ;	break;
		case 5: PORTA = 0x50 ;	break;
		case 6: PORTA = 0x60 ;	break;
		case 7: PORTA = 0x70 ;	break;
		case 8: PORTA = 0x80 ;	break;
		case 9: PORTA = 0x90 ;	break;
		default:				break;
	}
*/	
#endif
}


void H_Ssd_DisplayNum(u8 Local_u8_num)
{
	u16 x=0;
	u8 Local_u8_uist = Local_u8_num%10;
	u8 Local_u8_tens = Local_u8_num/10;
	
	while(x<200)
	{
		H_Ssd_Display(SSD_1,Local_u8_uist);
		_delay_ms(1);
		H_Ssd_Display(SSD_2,Local_u8_tens);
		_delay_ms(1);
		x++;
	}
	
	M_Dio_PinWrite(SSD1_EN,LOW);
	M_Dio_PinWrite(SSD2_EN,LOW);
}


void H_Ssd_CountUp(u8 Local_u8_num)
{
	u8 Local_u8_Counter = 0;
	for(Local_u8_Counter=0;Local_u8_Counter<=Local_u8_num;Local_u8_Counter++)
	{
		H_Ssd_DisplayNum(Local_u8_Counter);
	}
}

//-------------------------------------------------=======
void H_Ssd_CountDown(s8 Local_u8_num)
{
	for(;Local_u8_num>=0;Local_u8_num--)
	{
		H_Ssd_DisplayNum(Local_u8_num);
	}
}