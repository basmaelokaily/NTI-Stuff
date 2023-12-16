/*
 * RTOS_KERNEL_interface.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Kareem Hussein
 */

#ifndef RTOS_INC_RTOS_KERNEL_INTERFACE_H_
#define RTOS_INC_RTOS_KERNEL_INTERFACE_H_


void RTOS_KERNEL_voidStartScheduling(void);
u8 RTOS_KERNEL_voidCreateTask     (u8 copy_u8Priority,u16 copy_u16Periodicty,void(*ptrToFun)(void));




#endif /* RTOS_INC_RTOS_KERNEL_INTERFACE_H_ */
