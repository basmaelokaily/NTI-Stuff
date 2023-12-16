/*
 * INTERRUPT.c
 *
 * Created: 10/28/2023 10:37:19 AM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "std_macros.h"

int main(void)
{
    /* Replace with your application code */
	SETBIT(DDRD, 2);
	CLRBIT(DDRA, 5);
	SETBIT(MCUCR, ISC00);
	SETBIT(GICR, INT0);
	sei();
	
	
	
	
    while (1) 
    {
		TOGBIT(PORTD, 2);
		_delay_ms(1000);
    }
}
ISR(INT0_vect)
{
	TOGBIT(PORTA, 5);
}

