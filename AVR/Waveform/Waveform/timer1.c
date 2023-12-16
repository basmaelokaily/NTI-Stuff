/*
 * timer1.c
 *
 * Created: 11/28/2022 4:45:16 PM
 *  Author: lenovo 520
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer1.h"

#define TIMER_1_OVERFLOW_TIME_US 8192

static volatile isrFn timer1OVFISR;


uint32_t timer1Threshold_us = 0;

ISR(TIMER1_OVF_vect)
{
	static volatile uint32_t overflow_cnt = 0;
	overflow_cnt += 1;
	if(overflow_cnt > timer1Threshold_us)
	{
		overflow_cnt = 0;
		// Execute timer1 overflow routine.
		timer1OVFISR();
	}
}

ISR(TIMER1_COMPA_vect)
{
	timer1OVFISR();
}

void Timer1_CallFnEveryHz(uint16_t frequency,isrFn funciton)
{
	// Set ISR rountine.
	timer1OVFISR = funciton;
	
	// Set timer overflow.
	// Wave generation mode set to CTC.
	TCCR1A = 0;
	
	uint8_t timer_clk_src = 0;
	uint16_t clk_prescaler = 1;
	float required_frequency = frequency;
	// TODO: Based on the input value we need to select which prescaler to use,
	// and the OCR value to set to.
	{
		if((required_frequency > 3900) || (required_frequency < 0))             {timer_clk_src = 5; clk_prescaler = 1024;}
		else if ((required_frequency >= 15625) || (required_frequency <= 0))    {timer_clk_src = 4; clk_prescaler = 256; }
		else if ((required_frequency >= 62500) || (required_frequency <= 1))    {timer_clk_src = 3; clk_prescaler = 64;  }
		else if ((required_frequency >= 500000) || (required_frequency <= 8))   {timer_clk_src = 2; clk_prescaler = 8;   }
		else if ((required_frequency >= 4000000) || (required_frequency <= 61)) {timer_clk_src = 1; clk_prescaler = 1;   }
		else {timer_clk_src = 0;}
		
		OCR1A = ((F_CPU)/(2*clk_prescaler*required_frequency)) - 1;
	}
	
	// To have a one second delay we need to have a prescaler of 64
	TCCR1B = (1 << WGM12) | (timer_clk_src << 0);
	// Enable interrupt.
	TIMSK |= (1 << OCIE1A);
}