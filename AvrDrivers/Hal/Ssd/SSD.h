/*
 * SSD.h
 *
 * Created: 5/11/2022 1:18:15 PM
 *  Author: Tantawy
 */ 


#ifndef SSD_H_
#define SSD_H_

//-------------------_INCLUDES_------------------------------------------
#include "SSDCfg.h"
#include "Dio.h"

#define F_CPU 16000000UL
#include "util/delay.h"

//-------------------_MACROS_--------------------------------------

#define  SSD_1		1
#define  SSD_2		2

//---------------------_PROTOTYPES_----------------

void H_Ssd_Init(void);
void H_Ssd_Display(u8 Local_u8_Ssd ,u8 Local_u8_num);
void H_Ssd_DisplayNum(u8 Local_u8_num);
void H_Ssd_CountUp(u8 Local_u8_num);
void H_Ssd_CountDown(s8 Local_u8_num);


#endif /* SSD_H_ */