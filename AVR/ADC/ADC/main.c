/*
 * ADC.c
 *
 * Created: 10/24/2023 1:49:22 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "ADC (1).h"
#include "LCD.h"


int main(void)
{
    /* Replace with your application code */

	LCD_INIT();
	ADC_ConfigType ADC_CONFIG = {AVCC, F_8};
	ADC_init(&ADC_CONFIG);
	
	_delay_ms(100);
	LCD_write_command(0x0C); // display on, cursor off
	_delay_ms(100);
	LCD_write_command(0x01); // make clear LCD
	_delay_ms(1);
	LCD_write_string("ADC building in project......");
	_delay_ms(500);
	LCD_write_command(0x01); // make clear LCD
	_delay_ms(10);
	
    while (1) 
    {//(ADC_readChannel(0x01)*5*150/1024*.01*1.5);
		LCD_write_number(ADC_readChannel(0x00));
		_delay_ms(1000);
		LCD_write_command(0x01); // make clear LCD
		_delay_ms(1);
		
    }
}

