/*
 * LCD_FOR_PROT.c
 *
 * Created: 11/3/2023 3:51:37 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "LCD.h"
#define F_CPU 8000000


int main(void)
{
    /* Replace with your application code */
	LCD_init();
	_delay_ms(100);
	LCD_write_command(0x0C); // display on, cursor off
	_delay_ms(100);
	LCD_write_command(0x01);
	_delay_ms(100);
	LCD_write_num(100);
    while (1) 
    {
		
    }
}

