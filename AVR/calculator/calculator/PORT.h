/*
 * PORT.h
 *
 *  Created on: Oct 21, 2023
 *      Author: eslam
 */

#ifndef PORT_H_
#define PORT_H_

#include "MEGA.h"
/* LCD */
///FOR DATA
#define LCD_DATA_PORT_DR         (GPIO_PORTB_DATA)
#define LCD_DATA_PORT_CR         (GPIO_PORTB_CONTROL)
#define LCD_DATABIN_D4           (GPIO_PIN_0)
#define LCD_DATABIN_D5           (GPIO_PIN_1)
#define LCD_DATABIN_D6           (GPIO_PIN_2)
#define LCD_DATABIN_D7           (GPIO_PIN_3)

///////FOR ENABLE
#define LCD_ENABLE_DR       (GPIO_PORTA_DATA)
#define LCD_ENABLE_CR       (GPIO_PORTA_CONTROL)
#define LCD_ENABLE_PIN      (GPIO_PIN_2)
///////FOR REGISTER SELECTION
#define LCD_RS_DR            (GPIO_PORTA_DATA)
#define LCD_RS_CR            (GPIO_PORTA_CONTROL)
#define LCD_RS_PIN           (GPIO_PIN_3)

/////////////////////////////////////////////////////////////


#define KPD_u8_ROW_PORT      GPIO_PORTC_DATA
#define KPD_u8_COL_PORT      GPIO_PORTD_DATA

#define KPD_u8_R1_PIN     GPIO_PIN_5
#define KPD_u8_R2_PIN     GPIO_PIN_4
#define KPD_u8_R3_PIN     GPIO_PIN_3
#define KPD_u8_R4_PIN     GPIO_PIN_2

#define KPD_u8_C1_PIN     GPIO_PIN_7
#define KPD_u8_C2_PIN     GPIO_PIN_6
#define KPD_u8_C3_PIN     GPIO_PIN_5
#define KPD_u8_C4_PIN     GPIO_PIN_3

/////////////////////////////////////////////////////////////
//ports for SW

#define SW_1_PORT_DINR   (GPIO_PORTD_DATAin)
#define SW_1_PORT_CR     (GPIO_PORTD_CONTROL)
#define SW_1_PIN         (GPIO_PIN_0)


#define SW_2_PORT_DINR   (GPIO_PORTD_DATAin)
#define SW_2_PORT_CR     (GPIO_PORTD_CONTROL)
#define SW_2_PIN         (GPIO_PIN_1)


#define SW_3_PORT_DINR   (GPIO_PORTD_DATAin)
#define SW_3_PORT_CR     (GPIO_PORTD_CONTROL)
#define SW_3_PIN         (GPIO_PIN_2)

#define SW_4_PORT_DINR   (GPIO_PORTD_DATAin)
#define SW_4_PORT_CR     (GPIO_PORTD_CONTROL)
#define SW_4_PIN         (GPIO_PIN_3)


#endif /* PORT_H_ */
