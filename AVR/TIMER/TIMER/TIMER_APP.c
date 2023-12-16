/*
 * TIMER.c
 *
 * Created: 10/29/2023 11:54:23 AM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "TIMER.h"
#define F_CPU 8000000

int main(void)
{
    TIMER_INIT_NORMAL();
	SETBIT(DDRA, 5);
	SETBIT(DDRB, 7);
	SETBIT(PORTB, 7);
	
    while (1) 
    {
		TIMER_DELAY_MLSEC(200);
		//_delay_ms(1000);
		TOGBIT(PORTA, 5);	
    }
}

