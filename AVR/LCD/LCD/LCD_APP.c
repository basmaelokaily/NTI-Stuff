/*
 * LCD.c
 *
 * Created: 10/22/2023 9:59:59 AM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "LCD.h"
#include "KEYPAD.h"

unsigned char op = ' ';

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
	uint8_t zeros1 = 1;
	uint8_t zeros2 = 1;
	uint8_t gotosec = 0;
	uint8_t op_flag = 0;
	printf("hello\n");
	
	while (1)
	{
		x = KEYPAD_READ();
		if(x != 0)
		{/*
			_delay_ms(1);
			lCD_write_char(x);
			whiple(x == KEYPAD_READ());
			_delay_ms(1);*/
			if (x == 'C')
			{
				zeros1 = 1;
				zeros2 = 1;
				gotosec = 0;
				op_flag = 0;
				op = ' ';
				KEYPAD_CLR_NUM1();
				KEYPAD_CLR_NUM2();
				LCD_CLEAR();
				_delay_ms(10);
				LCD_write_string("Clear ........");
				_delay_ms(500);
				LCD_CLEAR();
			}
			else
			{
				_delay_ms(1);
				lCD_write_char(x);
				while(x == KEYPAD_READ());
				_delay_ms(1);
				if (IS_A_DIGIT(x))
				{
					uint16_t num1;
					uint16_t num2;
					if(gotosec == 0)
					{
						num1 = x*zeros1;
						zeros1*=10;
						
					}
					else {
						num2 = x*zeros2;
						zeros2*=10;
						
					}
					KEYPAD_SET_NUM1(num1); 
					KEYPAD_SET_NUM2(num2); 
				}
				else if (x == '=')
				{
					if ((gotosec == 1) && (op != 0))
					{
						if (op == '+')
						{
							LCD_CLEAR();
							_delay_ms(1);
							LCD_write_number(KEYPAD_ADD(KEYPAD_GET_NUM1(), KEYPAD_GET_NUM1()));
							_delay_ms(5000);
						}
						else if (op == '-')
						{
							LCD_CLEAR();
							_delay_ms(1);
							LCD_write_number(KEYPAD_GET_NUM1()-KEYPAD_GET_NUM1());
							_delay_ms(5000);
						}
						else if (op == '*')
						{
							LCD_CLEAR();
							_delay_ms(1);
							LCD_write_number(KEYPAD_TIME(KEYPAD_GET_NUM1(), KEYPAD_GET_NUM1()));
							_delay_ms(5000);
						}
					}
					
				}
				else
				{
					if (op_flag == 0)
					{
						op = x;
						gotosec = 1;
						op_flag = 1;
					}
				}
			}
		}
		/*else
		{
			_delay_ms(1);
			lCD_write_char('0');
			while(x == KEYPAD_READ());
			_delay_ms(1);
		}*/
		
		
	}
	
}


