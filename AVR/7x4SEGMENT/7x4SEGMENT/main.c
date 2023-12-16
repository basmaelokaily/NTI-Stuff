/*
 * 7x4SEGMENT.c
 *
 * Created: 11/5/2023 6:11:46 AM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "seven_segment.h"
#include "TIMER.h"

static uint8_t seconds = 0;
static uint8_t minutes = 5;
static uint8_t hours = 6;
uint8_t hours_minutes_control = 0;
void Seven_Segment_Display(void);

int main(void)
{
	SETBIT(DDRA, 5);
	//Seven_Seg_init();
	set_int0();
	set_int1();
	TIMER_INT_NORMAL();
	
    /* Replace with your application code */
    while (1) 
    {
		if(minutes>9)
		{
			SevenSegmentCommonAnode( minutes/10,3);
			_delay_ms(100);
			SevenSegmentCommonAnode((minutes-((minutes/10) *10)),4);
			_delay_ms(100);
		}
		else
		{
			SevenSegmentCommonAnode(0,3);
			_delay_ms(100);
			SevenSegmentCommonAnode( minutes,4);
			_delay_ms(100);
		}

		if(hours>9)
		{
			SevenSegmentCommonAnode(hours/10,1);
			_delay_ms(100);
			SevenSegmentCommonAnode((hours-((hours/10) *10)),2);
			_delay_ms(100);
		}
		else
		{
			SevenSegmentCommonAnode(0,1);
			_delay_ms(100);
			SevenSegmentCommonAnode( hours,2);
			_delay_ms(100);
		}
		
    }
}
ISR(INT0_vect)
{
	_delay_ms(100);
	if(hours_minutes_control == 0)
	{
		hours_minutes_control = 1; //hours
	}
	else if(hours_minutes_control == 1) 
	{
		hours_minutes_control = 0; //minutes
	}
}
ISR(INT1_vect)
{
	TIMER_STOP();
	if(hours_minutes_control == 1)
	{
		_delay_ms(50);
		if(hours_minutes_control == 1)
		{	
			hours++;
		}
	}
	else if(hours_minutes_control == 0)
	{
		_delay_ms(50);
		if(hours_minutes_control == 0)
		{
			minutes++;
		}
	}
	TIMER_START();
}
ISR(TIMER0_OVF_vect)
{
	static uint32_t counts = 0;
	counts++;
	if (counts == 30)
	{
		counts = 0;
		Seven_Segment_Display();
	}
}

void Seven_Segment_Display(void)
{
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
	
	if (hours >= 12)
	{
		hours = 0;
	}
}
/*if(minutes>9)
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
*/