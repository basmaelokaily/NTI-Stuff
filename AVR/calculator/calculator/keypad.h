/*
 * keypad.h
 *
 *  Created on: Oct 23, 2023
 *      Author: eslam
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "PORT.h"
#include "STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include<util/delay.h>

#define KPD_u8_KEYS      {{'7','8','9','/'},\
	                      {'4','5','6','*'},\
	                      {'1','2','3','-'},\
	                      {'E','0','=','+'}}

#define KPD_u8_KEY_NOT_PRESSED   ('q')
uint8 KPD_u8GetKeyState(uint8 * Copy_pu8ReturnedKey);

#endif /* KEYPAD_H_ */
