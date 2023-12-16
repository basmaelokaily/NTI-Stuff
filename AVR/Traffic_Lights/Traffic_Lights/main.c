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
#include "FREERTOS/semphr.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "seven_segment.h" 
#include "LCD.h"
#define F_CPU 16000000

void COUNTER_States(void* pvParameters);
void RED_LIGHT(void* pvParameters);
void YELLOW_LIGHT(void* pvParameters);
void GREEN_LIGHT(void* pvParameters);

#define TASK1_PRIORITY 0
#define TASK2_PRIORITY 1
#define TASK3_PRIORITY 2
#define TASK4_PRIORITY 3

/*TASK HANDLES*/
TaskHandle_t xTask1_H = NULL;
TaskHandle_t xTask2_H = NULL;
TaskHandle_t xTask3_H = NULL;
TaskHandle_t xTask4_H = NULL;

u8 Reverse_flag = 0;
u8 seconds = 0;
u8 Total_sec_counter = 0;
u8 state = 'R';

SemaphoreHandle_t xSemaphore_Seconds = NULL;
int main()
{
	//BaseType_t xError_Status;
	/*DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, 0xff);//Red
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN4, 0xff);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN5, 0xff);*/
	
	SET_BIT(DDRB, 7);
	SET_BIT(DDRA, 4);
	SET_BIT(DDRA, 5);
	
	SevenSegmentCommonAnode_INIT();
	LCD_init();
	_delay_ms(100);
	LCD_write_command(0x0C); // display on, cursor off
	_delay_ms(100);
	LCD_write_command(0x01);
	vSemaphoreCreateBinary( xSemaphore_Seconds );
	
	xTaskCreate(COUNTER_States,(const char*)"COUNT",300,NULL,TASK1_PRIORITY,&xTask1_H);
	xTaskCreate(RED_LIGHT,(const char*)"RED",200,NULL,TASK2_PRIORITY,&xTask2_H);
	xTaskCreate(YELLOW_LIGHT,(const char*)"YELLO",200,NULL,TASK4_PRIORITY,&xTask3_H);
	xTaskCreate(GREEN_LIGHT,(const char*)"GREEN",200,NULL,TASK3_PRIORITY,&xTask4_H);

	 vTaskStartScheduler();
	 /* Never Enters Here */
    while(1)
    {

    }

 return 0;
}


void COUNTER_States(void* pvParameters)
{	
	while(1)
	{
		if(Total_sec_counter == 0)
		{
			seconds=90; //RED STATE
			state = 'R';
		}
		if(Total_sec_counter == 91)
		{
			seconds=60; //GREEN STATE
			state = 'G';
		}
		if(Total_sec_counter == 151)
		{
			seconds=10; //Yellow STATE
			state = 'Y';
		}
		if(Total_sec_counter == 161)
		{
			seconds=90; //RED STATE---re enter
			Total_sec_counter = 0;
			state = 'R';
		}
		seconds = seconds - 1;
		Total_sec_counter ++;
		LCD_write_num(Total_sec_counter);
		vTaskDelay(1000);
	}
}

void RED_LIGHT(void* pvParameters)       //called every 1 sec...through callback concept
{   //Task Periodicity
	while(1)
	{
		if( xSemaphore_Seconds != NULL )
		{
			if( xSemaphoreTake(xSemaphore_Seconds, ( TickType_t ) 10 ) == pdTRUE )
			{

				if(0 <= Total_sec_counter && Total_sec_counter < 91 && state == 'R')
				{
					//DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, 1);
					SET_BIT(PORTB, 7);
					for (u8 i = 0; i < 50; i++)
					{
						SevenSegmentCommonAnode(seconds/10, 2);
						vTaskDelay(100);
						SevenSegmentCommonAnode(seconds%10, 1);
						vTaskDelay(100);
					}
				}
				else
				{
					//DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, 0);
					CLR_BIT(PORTB, 7);
					vTaskDelay(50);
				}
				xSemaphoreGive(xSemaphore_Seconds);
			}
			else
			{
				
			}
		}
		vTaskDelay(200);
	}
}

void YELLOW_LIGHT(void* pvParameters)
{
	while(1)
	{
		if( xSemaphore_Seconds != NULL )
		{
			if( xSemaphoreTake(xSemaphore_Seconds, ( TickType_t ) 10 ) == pdTRUE )
			{

				if(91 <= Total_sec_counter && Total_sec_counter < 151 && state == 'Y')
				{
					//DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, 1);
				//	SET_BIT(PORTA, 4);
					for (u8 i = 0; i < 50; i++)
					{
						SevenSegmentCommonAnode(seconds/10, 2);
						vTaskDelay(100);
						SevenSegmentCommonAnode(seconds%10, 1);
						vTaskDelay(100);
					}
				}
				else
				{
					//DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, 0);
					CLR_BIT(PORTA, 4);
					vTaskDelay(50);
				}
				xSemaphoreGive(xSemaphore_Seconds);
			}
			else
			{
				
			}
		}
		vTaskDelay(300);
	}
}
void GREEN_LIGHT(void* pvParameters)
{
	while(1)
	{
		if( xSemaphore_Seconds != NULL )
		{
			if( xSemaphoreTake(xSemaphore_Seconds, ( TickType_t ) 10 ) == pdTRUE )
			{

				if(91 <= Total_sec_counter && Total_sec_counter < 151 && state == 'G')
				{
					//DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, 1);
					//SET_BIT(PORTA, 5);
					for (u8 i = 0; i < 50; i++)
					{
						SevenSegmentCommonAnode(seconds/10, 2);
						vTaskDelay(100);
						SevenSegmentCommonAnode(seconds%10, 1);
						vTaskDelay(100);
					}
				}
				else
				{
					//DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, 0);
					CLR_BIT(PORTA, 5);
					vTaskDelay(50);
				}
				xSemaphoreGive(xSemaphore_Seconds);
			}
			else
			{
				
			}
		}
	
		vTaskDelay(400);
	}
}
