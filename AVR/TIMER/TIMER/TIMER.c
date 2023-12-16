/*
 * TIMER.c
 *
 * Created: 10/29/2023 11:56:58 AM
 *  Author: LENOVO
 */ 
#include "TIMER.h"

void TIMER_INIT_NORMAL()
{
	TCCR0 = 0;
	CLRBIT(TCCR0, WGM00);		//normal mode
	CLRBIT(TCCR0, WGM01);
	SETBIT(TCCR0, CS00);			//1024 pre-scaler
	SETBIT(TCCR0, CS02);
	SETBIT(TCCR0, FOC0);
	
}
void TIMER_INIT_CTC()
{
	
}
void TIMER_START()
{
	SETBIT(TCCR0, CS00);			//1024 pre-scaler
	SETBIT(TCCR0, CS02);
	TCNT0 = 0;
}
void TIMER_STOP()
{
	CLRBIT(TCCR0, CS00);
	CLRBIT(TCCR0, CS01);
	CLRBIT(TCCR0, CS02);
}
void TIMER_DELAY_SEC(int s)
{	
	uint8_t overflow = (s*8000000)/ (1024*256);
	uint8_t counter = 0;
	TIMER_START();
	while(counter != overflow)
	{
		while(READBIT(TIFR, TOV0) == 0);
		counter++;
	}
}

void TIMER_DELAY_MLSEC(int ms)
{
	uint16_t overflow = (ms*8000)/ (1024*256);
	TIMER_START();
	while(overflow != 0)
	{
		while(READBIT(TIFR, TOV0) == 0);
		overflow--;
	}
}
