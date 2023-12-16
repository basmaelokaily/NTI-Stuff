/*
 * spi_slave.c
 *
 * Created: 11/3/2023 3:23:00 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "SPI_INT.h"
#include "LCD.h"

int main(void)
{
    /* Replace with your application code */
	LCD_init();
	_delay_ms(100);
	LCD_write_command(0x0C); // display on, cursor off
	_delay_ms(100);
	LCD_write_command(0x01);
	_delay_ms(100);
	SPI_init_slave();
	
	
    while (1) 
    {
		_delay_ms(100);
		 LCD_write_command(0x80);
		LCD_write_num(SPI_slave_input());
		_delay_ms(100);
		
    }
}

