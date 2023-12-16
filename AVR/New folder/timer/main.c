/*
 * main.c
 *
 *  Created on: Oct 29, 2023
 *      Author: dell
 */
#include <time.h>
#include "Timer0_Driver.h"
#include  "dio.h"
#include "GIE.h"
#include "seven_segment.h"

void App(void);
int main()
{
//	DIO_setupPinDirection(PORTA_ID,PIN5_ID,PIN_OUTPUT);
//	DIO_writePin(PORTA_ID,PIN5_ID,LOGIC_LOW);


	Timer0_setCallBack(App);
//	config_struc_sync config ={normal,5,0};
	config_struc config ={normal,5,0,F_64};
	Global_InterruptEnable();

//	Timer0_init_sync(&config);

	Timer0_init_Async(&config);

	while(1)
	{


	}

	return 0;
}

void App(void)
{
//	DIO_togglePin(PORTA_ID,PIN5_ID);   //called every 1 sec

	static uint8 seconds =0;
	static uint8 minutes=39;
	static uint8 hours=3;


	seconds++;

	if(seconds >=60)
	{
		seconds=0;
		minutes++;
	}

	if(minutes >=60)
	{
		minutes=0;
		hours++;
	}

	if(minutes>9)
	{
		SevenSegmentCommonAnode( minutes/10,2);
		SevenSegmentCommonAnode((minutes-((minutes/10) *10)),1);
	}
	else
	{
		SevenSegmentCommonAnode( minutes,1);
		_delay_ms(1000);
	}

	if(hours>9)
	{
		SevenSegmentCommonAnode(hours/10,4);
		SevenSegmentCommonAnode((hours-((hours/10) *10)),3);
	}
	else
	{
		SevenSegmentCommonAnode( hours,3);
	}

}


