/*
 * LCD.h
 *
 *  Created on: Nov 7, 2023
 *      Author: LENOVO
 */

#ifndef LCD_H_
#define LCD_H_
#include "DIO_interface.h"
#include "rcc_int.h"

//#define INIT_LCD_PIN  DIRECTION |= 0b11111100; // PA4 to PB7 & PB2,PB3 output
//SET DIRECTION OF THE PORT

#define EN(x) if(x == 1) DIO_voidSetPinValue(PORTB, 2, GPIO_HIGH); else DIO_voidSetPinValue(PORTB, 2, GPIO_LOW);
#define RS(x) if(x == 1) DIO_voidSetPinValue(PORTB, 3, GPIO_HIGH); else DIO_voidSetPinValue(PORTB, 3, GPIO_LOW);
#define D7(x) if(x == 1) DIO_voidSetPinValue(PORTB, 7, GPIO_HIGH); else DIO_voidSetPinValue(PORTB, 7, GPIO_LOW);
#define D6(x) if(x == 1) DIO_voidSetPinValue(PORTB, 6, GPIO_HIGH); else DIO_voidSetPinValue(PORTB, 6, GPIO_LOW);
#define D5(x) if(x == 1) DIO_voidSetPinValue(PORTB, 5, GPIO_HIGH); else DIO_voidSetPinValue(PORTB, 5, GPIO_LOW);
#define D4(x) if(x == 1) DIO_voidSetPinValue(PORTB, 4, GPIO_HIGH); else DIO_voidSetPinValue(PORTB, 4, GPIO_LOW);

void LCD_PIN_DI(void);
void LCD_init(void);
void LCD_write_command(u8 data);
void LCD_write_data(u8 data);
void LCD_write_string(u8 *data);
void LCD_write_num(u32 data);


#endif /* LCD_H_ */
