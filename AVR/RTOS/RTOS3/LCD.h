/*
 * LCD.h
 *
 * Created: 10/22/2023 10:17:43 AM
 *  Author: LENOVO
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "avr/io.h"
#include "avr/delay.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#define LCD_DATA_PINS DDRB |= 0b00010111
#define LCD_CONTROL_PINS DDRA |= 0b00001100
 
// LCD pins rs, en, d7---d4 
#define RS(x)		if (x == 1) SET_BIT(PORTA, 3); else CLR_BIT(PORTA, 3)
#define EN(x)		if (x == 1) SET_BIT(PORTA, 2); else CLR_BIT(PORTA, 2)
#define D7(x)		if (x == 1) SET_BIT(PORTB, 4); else CLR_BIT(PORTB, 4)
#define D6(x)		if (x == 1) SET_BIT(PORTB, 2); else CLR_BIT(PORTB, 2)
#define D5(x)		if (x == 1) SET_BIT(PORTB, 1); else CLR_BIT(PORTB, 1)
#define D4(x)		if (x == 1) SET_BIT(PORTB, 0); else CLR_BIT(PORTB, 0)

void LCD_INIT(void);
void LCD_write_command(u8 data);
void lCD_write_char(u8 data);
void LCD_write_number(u32 data);
void LCD_CLEAR(void);


#endif /* LCD_H_ */