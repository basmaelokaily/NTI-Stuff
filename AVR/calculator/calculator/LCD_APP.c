/*
 * LCD.c
 *
 * Created: 10/22/2023 9:59:59 AM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "LCD.h"
#include "KEYPAD.h"


int main(void)
{
    /* Replace with your application code */
	LCD_INIT();
	KEYPAD_INIT();
	
	_delay_ms(100);
	LCD_write_command(0x0C); // display on, cursor off
	_delay_ms(100);
	LCD_write_command(0x01); // make clear LCD
	_delay_ms(1);
	LCD_write_string("one building target in project");
	_delay_ms(500);
	//KEYPAD_INIT();
	unsigned char x;
	LCD_write_command(0x01); // make clear LCD
	_delay_ms(10);
	LCD_write_string("KEYPAD 1 .. 2 .. 3");
	_delay_ms(500);
	LCD_write_command(0x01); // make clear LCD
	_delay_ms(10);
	
	while (1)
	{
		x = KEYPAD_READ();
		lCD_write_char(x);
		_delay_ms(500);
		while(x == KEYPAD_READ());
		LCD_write_command(0x01);
		
	}
	
}

