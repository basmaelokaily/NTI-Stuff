/*
 * Kernel_interface.h
 *
 *  Created on: Nov 20, 2023
 *      Author: dell
 */

#ifndef KERNEL_INTERFACE_H_
#define KERNEL_INTERFACE_H_
#include "Kernel_Ptivate.h"


void RTOS_KERNEL_voidStartScheduling(void);
u8 RTOS_KERNEL_voidCreateTask(u8 TaskPriority,u16 TaskPriodicity,void(*ptrToFun)(void));
void RTOS_KERNEL_voidDeleteTask(u8 TaskPriority);

#endif /* KERNEL_INTERFACE_H_ */
