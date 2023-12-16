/*
 * LCD.h
 *
 *  Created on: Nov 7, 2023
 *      Author: LENOVO
 */

#ifndef LCD_H_
#define LCD_H_
#include "DIO_interface.h"

//#define INIT_LCD_PIN  DIRECTION |= 0b11111100; // PA4 to PB7 & PB2,PB3 output
//SET DIRECTION OF THE PORT

#define EN(x) if(x == 1) SET_BIT(GPIOA_ODR,2); else CLEAR_BIT(GPIOA_ODR,2);
#define RS(x) if(x == 1) SET_BIT(GPIOA_ODR,3); else CLEAR_BIT(GPIOA_ODR,3);
#define D7(x) if(x == 1) SET_BIT(GPIOA_ODR,7); else CLEAR_BIT(GPIOA_ODR,7);
#define D6(x) if(x == 1) SET_BIT(GPIOA_ODR,6); else CLEAR_BIT(GPIOA_ODR,6);
#define D5(x) if(x == 1) SET_BIT(GPIOA_ODR,5); else CLEAR_BIT(GPIOA_ODR,5);
#define D4(x) if(x == 1) SET_BIT(GPIOA_ODR,4); else CLEAR_BIT(GPIOA_ODR,4);

void LCD_init(void);
void LCD_write_command(u8 data);
void LCD_write_data(u8 data);
void LCD_write_string(u8 *data);
void LCD_write_num(u32 data);


#endif /* LCD_H_ */
