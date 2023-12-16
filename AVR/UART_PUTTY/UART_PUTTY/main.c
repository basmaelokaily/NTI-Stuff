/*
 * UART_PUTTY.c
 *
 * Created: 11/18/2023 2:23:29 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "uart_int.h"
#include "LCD.h"

void save_2digits(uint8_t value);
uint8_t num = 0;
uint8_t flag = 0;
uint8_t val = 0;

int main(void)
{
	/* Replace with your application code */
	LCD_init();
	_delay_ms(100);
	LCD_write_command(0x0C); // display on, cursor off
	_delay_ms(100);
	LCD_write_command(0x01);
	_delay_ms(100);
	USART_Init();
	LCD_write_string(USART_Receive_SYNC());
    /* Replace with your application code */
	uint8_t number = 0;
    while (1) 
    {
		val = USART_Receive_SYNC();
		save_2digits(val);
		number = num;
		if (number-48 == 31)
		{
			
		}
			
		
		LCD_write_string(USART_Receive_SYNC()-50);
		_delay_ms(10000);
		LCD_write_command(0x01);
		_delay_ms(100);
    }
}
void save_2digits(uint8_t value){
	while (value != 13)
	{
		if(flag == 0)
		{
			num = value*10;
			flag = 1;
		}
		else
		{
			num = num + value;
		}
	
	}
}