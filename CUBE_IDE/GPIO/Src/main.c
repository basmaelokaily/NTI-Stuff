/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "DIO_interface.h"
#include "rcc_int.h"
#include "SYSTICK.h"
#include "LCD.h"
void APP(void);

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SYSTICK_SetCallback (APP);
	SYSTICK_Init ();
	SYSTICK_SetTime_ms(1000, 8000000);
	SYSTICK_Start ();
	LCD_PIN_DI();
	LCD_init();
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	LCD_write_command(0x0C); // display on, cursor off
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	LCD_write_command(0x01);
	SYSTICK_SetTime_ms(500, 8000000);
	SYSTICK_Start ();
	LCD_write_num(100);

	/*MRCC_voidInit();
	MRCC_enumSetPeripheralClock(APB2 , IOPBEN_ID, RCC_ENABLE );
	DIO_voidSetPinDirection(PORTA, 5, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPortnDirection(PORTB, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinValue(PORTA, 5, GPIO_HIGH);
	//DIO_voidSetPORTValue(PORTB, 0b0000111111111100);*/

    /* Loop forever*/
	for(;;)
	{
		//DIO_voidTogglePin(PORTA, 5);
	}
}
void APP(void)
{
	SYSTICK_Stop();
}
