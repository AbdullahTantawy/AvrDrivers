/*
 * Lcd.c
 *
 * Created: 5/12/2022 11:04:03 AM
 *  Author: Tantawy
 */ 


#include "Lcd.h"

//=================================_BODIES_===================
void H_Lcd_Init(void)
{
	// make the port of data  in OUTPUT Mode
	// Port_A 
	M_Dio_PortMode(LCD_DATA_PORT,OUTPUT);
	//make the control pins  in OUTPUT Mode
	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
	// wait until the other MC wake up
	_delay_ms(50); 
	
	// some commands to initialize the LCD
	H_Lcd_writeCommand(_8_BIT_MODE);   // 8 bit mode
	// turn the display on and turn the CRSR off
	H_Lcd_writeCommand(LCD_DIS_ON_CRS_OFF);
	// CLEAR THE PREVIOUS DATA
	H_Lcd_writeCommand(LCD_CLR);
	// Start from the first bit on LCSD
	H_Lcd_writeCommand(LCD_RETURN_HOME);
	
}

//==============================================================
void H_Lcd_WriteChar(u8 Local_u8_Char)
{
	//1- When send command make the RS 0 LOW || for data RS 1 HIGH
	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
	//2  put the data in the register of data
	LCD_DATA_REG = Local_u8_Char;
	//3- Enable the pin of LCD to read the data 
	// after reading disable the Enable pin after a delay
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	//_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	//_delay_ms(5);
}

//============================================================
void H_Lcd_WriteStr(u8 *Local_u8_PrtArr)
{
	u8 Local_u8_Counter = 0;
	while((*(Local_u8_PrtArr+Local_u8_Counter)) != _NULL_)
	{
		H_Lcd_WriteChar(*(Local_u8_PrtArr+Local_u8_Counter));
		Local_u8_Counter++;
	}
}
//=============================================
void H_Lcd_writeCommand(u8 Local_u8_Command)
{
	//1- When send command make the RS 0 || for data RS 1
		M_Dio_PinWrite(LCD_RS_PIN,LOW);
	//2 put the data in the register of data
	LCD_DATA_REG = Local_u8_Command;
	//3- Enable the pin of LCD to read the data 
	// after reading disable the Enable pin after a delay	
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
}

//=========================================================================
// function to print digits numbers

void  H_Lcd_WriteNum(u64 Local_u64_Num)
{
	u64 Local_u64_counter=1;        // variable to count the digits of the number  u64 store 20 digit
	// variable to save the original value of the number inside loops
	// and make changing on the temporary variable 
	u64 Local_u64_VarLoop = Local_u64_Num;
	// variable to get the required digit and print it
	u8 Local_u8_Num2 = 0 ;
	
	if (Local_u64_Num == 0)
	{
		H_Lcd_WriteChar('0');
	}
	// loop to count the digits of the number
	while(Local_u64_VarLoop != 0)
	{
		// with each digit multiply *10 to divide the number to digits
		// if number (12345) after loop the count will 100000
		Local_u64_counter *= 10;
		// to end the loop when match zero 
		Local_u64_VarLoop /= 10;
	}
	
	// loop to print the number in digits 
	while(Local_u64_counter != 0 )
	{
		// divide the counter to get the next digit
		// if the counter 10000 after divide will 1000
		Local_u64_counter/=10; 
		// divide the number / count --> 12345/10000 = 1 in first iteration
		Local_u8_Num2 = Local_u64_Num/Local_u64_counter;
		
		switch(Local_u8_Num2)
		{
			case  0:	H_Lcd_WriteChar('0');		break;
			case  1:	H_Lcd_WriteChar('1');		break;
			case  2:	H_Lcd_WriteChar('2');		break;
			case  3:	H_Lcd_WriteChar('3');		break;
			case  4:	H_Lcd_WriteChar('4');		break;
			case  5:	H_Lcd_WriteChar('5');		break;
			case  6:	H_Lcd_WriteChar('6');		break;
			case  7:	H_Lcd_WriteChar('7');		break;
			case  8:	H_Lcd_WriteChar('8');		break;
			case  9:	H_Lcd_WriteChar('9');		break;
			default:								break;
		}
		// delete the digit printed and number become 2345/1000 = 2 in the second iteration 
		Local_u64_Num %= Local_u64_counter;
		
	}
	
}

//========================================================================

void H_Lcd_PrintNum(f64 Local_f64_Num)
{
	u8 flag = 0;
	u64 Locla_u64_CheckFloat=0;
	// check if the number is negative
	if (Local_f64_Num <= 0)
	{
		//if the number ==0 print it here
		//because the while condition of printing the numbers will not see it
		if (Local_f64_Num == 0)
		{
			H_Lcd_WriteChar('0');
		}
		else
		{
			// *-1 to take the number without the sign (-)
			Local_f64_Num*= -1;
			//print the sign
			H_Lcd_WriteChar('-');
		}
	}
	
	// put the number coming in a integer variable to check if it is float or not
    Locla_u64_CheckFloat = Local_f64_Num;
	// if the number is floating (35.67) the integer value = 35
	// if the number coming !=  the integer value --> so it is floating number
	if (Locla_u64_CheckFloat != Local_f64_Num)
	{
		flag = 1; // set the flag to enter the fraction loop
		//subtract the integer value from the the number --> (0.67)
		Local_f64_Num -= Locla_u64_CheckFloat;
		//multiply the number *100 to get the fraction number (to digit after the decimal point)
		Local_f64_Num*=100;
	}
	// print the integer value
	H_Lcd_WriteNum(Locla_u64_CheckFloat);
	// if the is floating print the number after (.)
	if (flag == 1)
	{
		H_Lcd_WriteChar('.');
		H_Lcd_WriteNum(Local_f64_Num);
	}
}

//============================================================

void H_Lcd_Clr(void)
{
	H_Lcd_writeCommand(LCD_CLR);
}

//================================================
void H_Lcd_GoTo(u8 Local_u8_Row ,u8 Local_u8_Col)
{
	// the two rows in the array
	u8 Local_u8_Arr[2] = {0x80 , 0xC0};
   // after select the row add the number of column on it
	H_Lcd_writeCommand(Local_u8_Arr[Local_u8_Row] + Local_u8_Col);
}

//===========================================
void H_Lcd_ClockDisplay(u8 Hour,u8 Min,u8 Sec)
{
	// Display the digits of numbers in the middle 
        //and to print the hours and minutes and secods in to digits

	H_Lcd_GoTo(0,4);
	// if two digits print them in only
	if (Hour>9)
	{
		H_Lcd_GoTo(0,4);
		H_Lcd_WriteNum(Hour);
	}
	// if onr digit print zero before the digit
	else
	{
		H_Lcd_GoTo(0,4);
		H_Lcd_WriteNum(0);
		H_Lcd_WriteNum(Hour);
	}
	H_Lcd_WriteChar(':');
	if (Min>9)
	{
		H_Lcd_GoTo(0,7);
		H_Lcd_WriteNum(Min);
	}
	else
	{
		H_Lcd_GoTo(0,7);
		H_Lcd_WriteNum(0);
		H_Lcd_WriteNum(Min);
	}
	H_Lcd_WriteChar(':');
	if (Sec>9)
	{
		H_Lcd_GoTo(0,10);
		H_Lcd_WriteNum(Sec);
	}
	else
	{
		H_Lcd_GoTo(0,10);
		H_Lcd_WriteNum(0);
		H_Lcd_WriteNum(Sec);
	}
	
}
//==========================================================
void H_Lcd_ClockCouterMin(u8 Local_u8_MaxMin)
{
	u8 Local_u8_Sec  =0;
	u8 Local_u8_Min  =0;
	u8 Local_u8_Hour =0;
	
	// loop to increase the time until the required mins
	for (Local_u8_Sec=0 ; Local_u8_Min < Local_u8_MaxMin ; Local_u8_Sec++)
	{
		H_Lcd_ClockDisplay(Local_u8_Hour,Local_u8_Min,Local_u8_Sec);
		//_delay_ms(20);
		// when the seconds complete 59 start from zero and increase the minutes
		if (Local_u8_Sec == 59)
		{
			Local_u8_Min++;
			Local_u8_Sec= 0;
		}
		// when the minutes complete 59 start from zero and increase the hours
		if (Local_u8_Min == 59)
		{
			Local_u8_Hour++;
			Local_u8_Sec=0;
			Local_u8_Min=0;
		}
		
	}
	// after the counter finish print the the time
	H_Lcd_ClockDisplay(Local_u8_Hour,Local_u8_Min,Local_u8_Sec-1);
}


//============================================================
void H_Lcd_Shift(u8 * Local_u8_PtrArr)
{
	while(1)
	{
		// loop to shift the string 
		for(u8 i=0;i<16;i++)
		{
			// loop to print white spaces before the string
			for (u8 j=0;j<i;j++)
			{
			   H_Lcd_WriteChar('\0');
			}
			//print the string 
			H_Lcd_WriteStr(Local_u8_PtrArr);
			_delay_ms(20);
			H_Lcd_Clr();
		}
	}
	
}
