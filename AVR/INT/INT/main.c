/*
 * INT.c
 *
 * Created: 10/21/2023 2:15:08 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "std_macros.h"


int main(void)
{
    /* Replace with your application code */
	CLRBIT(DDRC, 5);
	SETBIT(DDRA, 5);
	SETBIT(DDRA, 4);
	SETBIT(MCUCR, ISC00);
	SETBIT(GICR, INT0);
    while (1) 
    {
    }
}
ISR(INT0_vect)
{
	if (READBIT(PINA, 0))
	{
		TOGBIT(PORTA, 5);
		TOGBIT(PORTA, 4);
	}
}

