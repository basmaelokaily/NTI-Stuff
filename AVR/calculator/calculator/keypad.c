/*
 * keypad.c
 *
 *  Created on: Oct 23, 2023
 *      Author: eslam
 */

#include "keypad.h"

static const uint8 KPD_Au8Key[4][4]=KPD_u8_KEYS;

static const uint8 KPD_Au8RowsPins[4]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};

static const uint8 KPD_Au8ColsPins[4]={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};

uint8 KPD_u8GetKeyState(uint8* Copy_pu8ReturnedKey)
{

	uint8 Local_u8RowCounter;
	uint8 Local_u8ColCounter;
	uint8 Local_u8PinValue;
	uint8 Local_u8Flag = 0;
	if(Copy_pu8ReturnedKey != NULL)
	{
		*Copy_pu8ReturnedKey =KPD_u8_KEY_NOT_PRESSED;
		for(Local_u8RowCounter=0 ;Local_u8RowCounter<=3 ;Local_u8RowCounter++)
		{
			GPIO_Writepin(KPD_u8_ROW_PORT,KPD_Au8RowsPins[Local_u8RowCounter],DIO_u8_LOW);
			for(Local_u8ColCounter=0 ;Local_u8ColCounter<=3 ;Local_u8ColCounter++)
			{
				Local_u8PinValue=GPIO_Readpin(KPD_u8_COL_PORT,KPD_Au8ColsPins[Local_u8ColCounter]);
				if(Local_u8PinValue == DIO_u8_LOW)
				{
					_delay_ms(20);

					Local_u8PinValue=GPIO_Readpin(KPD_u8_COL_PORT,KPD_Au8ColsPins[Local_u8ColCounter]);
					while(Local_u8PinValue == DIO_u8_LOW)
					{
					Local_u8PinValue=GPIO_Readpin(KPD_u8_COL_PORT,KPD_Au8ColsPins[Local_u8ColCounter]);
					}
					*Copy_pu8ReturnedKey = KPD_Au8Key[Local_u8RowCounter][Local_u8ColCounter];
					Local_u8Flag = 1;
					break;
				}
			}
			GPIO_Writepin(KPD_u8_ROW_PORT,KPD_Au8RowsPins[Local_u8RowCounter],DIO_u8_HIGH);
			if(Local_u8Flag == 1)
			{
			    break;
			}
		}
	}

	return STD_TYPES_NOK;

}

