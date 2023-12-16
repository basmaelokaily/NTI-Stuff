/*
 * LCD.h
 *
 * Created: 8/12/2022 10:44:52 AM
 *  Author: safifi
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include <avr/delay.h>
#define INIT_LCD_PIN  DDRA |= 0b11111100; // PA4 to PB7 & PB2,PB3 output

#define EN(x) if(x == 1) SET_BIT(PORTA,2); else CLR_BIT(PORTA,2);
#define RS(x) if(x == 1) SET_BIT(PORTA,3); else CLR_BIT(PORTA,3);
#define D7(x) if(x == 1) SET_BIT(PORTA,7); else CLR_BIT(PORTA,7);
#define D6(x) if(x == 1) SET_BIT(PORTA,6); else CLR_BIT(PORTA,6);
#define D5(x) if(x == 1) SET_BIT(PORTA,5); else CLR_BIT(PORTA,5);
#define D4(x) if(x == 1) SET_BIT(PORTA,4); else CLR_BIT(PORTA,4);

void LCD_init(void);
void LCD_write_command(u8 data);
void LCD_write_data(u8 data);
void LCD_write_string(u8 *data);
void LCD_write_num(u32 data);


#endif /* LCD_H_ */