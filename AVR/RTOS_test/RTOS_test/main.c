/*
 * main.c
 *
 *  Created on: Nov 19, 2023
 *      Author: Kareem Hussein
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */


/* RTOS */
#include "RTOS_KERNEL_interface.h"

/* Tasks protoTypes */
void rLed(void);
void gLed(void);
void bLed(void);
void yLed(void);

int main()
{
	DIO_voidInit();
	RTOS_KERNEL_voidCreateTask(0,500 ,&rLed);
	RTOS_KERNEL_voidCreateTask(1,1000,&gLed);
	RTOS_KERNEL_voidCreateTask(2,2000,&bLed);
	RTOS_KERNEL_voidCreateTask(3,3000,&yLed);

	RTOS_KERNEL_voidStartScheduling();


	while(1)
	{

	}

	return 0;
}


/* Tasks implementation */
void rLed(void)
{
	DIO_voidTogglePinValue(DIO_PORTB,DIO_PIN7);
}


void gLed(void)
{
	DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN4);
}


void bLed(void)
{
	DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN5);
}


void yLed(void)
{
	DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN6);
}
