/*
 * GPIO.c
 *
 * Created: 10/21/2023 9:38:11 AM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "std_types.h"


int main(void)
{
    /* Replace with your application code */
	SetPinDirection(DIO_PORTB,PIN0,OUTPUT);
		
		
    while (1) 
    {
		TogglePinValue(DIO_PORTB, PIN0);
		Delay_ms(200);
    }
}

