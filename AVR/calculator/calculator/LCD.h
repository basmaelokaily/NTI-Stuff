/*
 * LCD.h
 *
 * Created: 10/22/2023 10:17:43 AM
 *  Author: LENOVO
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "std_macros.h"
#define LCD_DATA_PINS DDRB |= 0b00010111
#define LCD_CONTROL_PINS DDRA |= 0b00001100
 
// LCD pins rs, en, d7---d4 
#define RS(x)		if (x == 1) SETBIT(PORTA, 3); else CLRBIT(PORTA, 3)
#define EN(x)		if (x == 1) SETBIT(PORTA, 2); else CLRBIT(PORTA, 2)
#define D7(x)		if (x == 1) SETBIT(PORTB, 4); else CLRBIT(PORTB, 4)
#define D6(x)		if (x == 1) SETBIT(PORTB, 2); else CLRBIT(PORTB, 2)
#define D5(x)		if (x == 1) SETBIT(PORTB, 1); else CLRBIT(PORTB, 1)
#define D4(x)		if (x == 1) SETBIT(PORTB, 0); else CLRBIT(PORTB, 0)

void LCD_INIT(void);
void LCD_write_command(uint8_t data);
void lCD_write_char(uint8_t data);
void LCD_write_number(uint32_t data);


#endif /* LCD_H_ */