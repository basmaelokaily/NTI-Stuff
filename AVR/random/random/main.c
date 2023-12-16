/*
 * random.c
 *
 * Created: 10/31/2023 12:18:11 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "TIMER0.h"

int main(void)
{
    /* Replace with your application code */
	TIMER0_CTCMOD_INIT(249);
	TIMER_START();
    while (1) 
    {
    }
}

