/*
 * UART.c
 *
 * Created: 10/28/2023 12:41:46 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "uart_int.h"

int main(void)
{
	USART_Init();
	USART_STRING_SYNC("PROJECT IS BUILT");
	/*
	USART_Transmit_SYNC('H');
	_delay_ms(100);
	USART_Transmit_SYNC('E');
	_delay_ms(100);
	USART_Transmit_SYNC('L');
	_delay_ms(100);
	USART_Transmit_SYNC('L');
	_delay_ms(100);
	USART_Transmit_SYNC('O');
	_delay_ms(100);
	USART_Transmit_SYNC(' ');
	_delay_ms(100);
	USART_Transmit_SYNC('W');
	_delay_ms(100);
	USART_Transmit_SYNC('O');
	_delay_ms(100);
	USART_Transmit_SYNC('R');
	_delay_ms(100);
	USART_Transmit_SYNC('L');
	_delay_ms(100);
	USART_Transmit_SYNC('D');
	_delay_ms(100);
	
	*/
	/* Replace with your application code */
    while (1) 
    {
    }
}

