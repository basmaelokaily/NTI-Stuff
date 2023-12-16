/*
 * lcd.c
 *
 * Created: 10/22/2023 10:19:12 AM
 *  Author: LENOVO
 */ 
#include "LCD.h"
#include "stdio.h"
#include "avr/delay.h"

/***********************
funcName: LCD_write_command
InType:
OutType:
Description:
************************/
void LCD_write_command(uint8_t data)
{
	RS(0);
	D7(READBIT(data, 7));
	D6(READBIT(data, 6));
	D5(READBIT(data, 5));
	D4(READBIT(data, 4));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	D7(READBIT(data, 3));
	D6(READBIT(data, 2));
	D5(READBIT(data, 1));
	D4(READBIT(data, 0));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}


/***********************
funcName: LCD_INIT
InType:
OutType:
Description:
************************/
void LCD_INIT(void)
{
	LCD_CONTROL_PINS;
	LCD_DATA_PINS;
	
	LCD_write_command(0x28); // initialization in 8bit mode of 16X2 LCD
	_delay_ms(1);

	LCD_write_command(0x01); // make clear LCD
	_delay_ms(1);

	LCD_write_command(0x02); // return home
	_delay_ms(1);

	LCD_write_command(0x06); // make increment in cursor
	_delay_ms(1);

	LCD_write_command(0x80); // "8" go to first line and "0" is for 0th position
	_delay_ms(1);
	/*
	LCD_write_command(0x0E);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x2);
	_delay_ms(4);
	LCD_write_command(0x28);
	_delay_ms(4);
	LCD_write_command(0x01);
	_delay_ms(4);
	LCD_write_command(0x06);
	_delay_ms(4);
	LCD_write_command(0xc);
	_delay_ms(4);*/
}

/***********************
funcName: LCD_write_number
InType:
OutType:
Description:
************************/
void LCD_write_number(uint32_t data)
{
	int8_t i =8 ;
	uint8_t arr[10];

	if (data == 0)
	{
		lCD_write_char('0');
	}

	for(i = 0 ; data != 0; i++)
	{
		arr[i] = data % 10 + 48;
		data /= 10;
	}
	i--;
	while (i >= 0)
	{
		lCD_write_char (arr[i]);
		i--;
	}
}

/***********************
funcName: LCD_write_number
InType:
OutType:
Description:
************************/
void lCD_write_char(uint8_t data)
{
	RS(1);
	D7(READBIT(data, 7));
	D6(READBIT(data, 6));
	D5(READBIT(data, 5));
	D4(READBIT(data, 4));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	D7(READBIT(data, 3));
	D6(READBIT(data, 2));
	D5(READBIT(data, 1));
	D4(READBIT(data, 0));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
}

/***********************
funcName: LCD_write_string
InType:
OutType:
Description:
************************/

void LCD_write_string(uint8_t *data)
{
	uint8_t i = 0;
	while (data[i] != 0)
	{
		lCD_write_char(data[i]);
		i++;
	}
}
