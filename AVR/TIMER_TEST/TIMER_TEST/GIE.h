/*
 * GIE.h
 *
 *  Created on: Oct 27, 2023
 *  Author: Menna Sayed
 ***********************************************************************************/

#ifndef GIE_H_
#define GIE_H_

#include "dio.h"

#define Ibit    7

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
#define SREG           (*(volatile u8*)0x5F)
void Global_InterruptEnable(void);
void Global_InterruptDisable(void);


#endif /* GIE_H_ */
