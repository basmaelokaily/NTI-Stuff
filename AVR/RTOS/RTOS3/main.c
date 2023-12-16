/*
 * main.c
 *
 *  Created on: Nov 26, 2023
 *      Author: dell
 */

/*MCAL*/

/*FreeRTOS*/
#include "FREERTOS/FreeRTOS.h"
#include "FREERTOS/task.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD.h" 
#include "FREERTOS/semphr.h"

SemaphoreHandle_t xSemaphore;

void vTask1(void* pvParameters);
void vTask2(void* pvParameters);
void vTask3(void* pvParameters);
void vTask4(void* pvParameters);

#define TASK1_PRIORITY 0
#define TASK2_PRIORITY 1
#define TASK3_PRIORITY 2
#define TASK4_PRIORITY 3

/*TASK HANDLES*/
TaskHandle_t xTask1_H = NULL;
TaskHandle_t xTask2_H = NULL;
TaskHandle_t xTask3_H = NULL;
TaskHandle_t xTask4_H = NULL;


int main()
{
	LCD_INIT();
	_delay_ms(100);
	LCD_write_command(0x0C); // display on, cursor off
	/*_delay_ms(100);
	LCD_write_command(0x01);
	_delay_ms(100);*/
	//LCD_write_num(100);


	//DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, 0xff);
	//DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN6, 0x00);
	/*
	 SET_BIT(DDRB,7);//Red
	 SET_BIT(DDRA,4);//Green
	 SET_BIT(DDRA,5);
	 CLR_BIT(DDRA,6);*/

	vSemaphoreCreateBinary(xSemaphore);
	xTaskCreate(vTask1,(const char*)"RED",300,NULL,TASK2_PRIORITY,&xTask1_H);
	xTaskCreate(vTask2,(const char*)"GREEN",300,NULL,TASK2_PRIORITY,&xTask2_H);
	// xTaskCreate(vTask3,(const char*)"BLUE",75,NULL,TASK3_PRIORITY,&xTask3_H);
	// xTaskCreate(vTask4,(const char*)"YELL",75,NULL,TASK4_PRIORITY,&xTask4_H);

	 vTaskStartScheduler();
	 /* Never Enters Here */
    while(1)
    {

    }

 return 0;
}

void vTask1(void* pvParameters)       //called every 1 sec...through callback concept
{
	vTaskDelay(500);
	while(1)
	{
		if(pdTRUE==xSemaphoreTake(xSemaphore,0))
		{
			LCD_write_string("Task 1");
			xSemaphoreGive(xSemaphore);
			vTaskDelay(50);
		}
	
	}

}
void vTask2(void* pvParameters)
{
	vTaskDelay(500);
	while(1)
	{
		if(pdTRUE==xSemaphoreTake(xSemaphore,0))
		{
			LCD_write_number("Task 2");
			xSemaphoreGive(xSemaphore);
			vTaskDelay(50);
		}
	}
}
void vTask3(void* pvParameters)
{
	while(1)
	{
	TOG_BIT(PORTA,5);
	vTaskDelay(1000);
	}
}

void vTask4(void* pvParameters)
{
	while(1)
	{
	TOG_BIT(PORTA,6);
	vTaskDelay(1500);
	}
}