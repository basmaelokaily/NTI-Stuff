/*
 * RTOS_KERNEL_private.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Kareem Hussein
 */

#ifndef RTOS_INC_RTOS_KERNEL_PRIVATE_H_
#define RTOS_INC_RTOS_KERNEL_PRIVATE_H_


typedef struct
{
	void(*PTaskFun)(void);
	u16 TaskPeriodicty;
}Task_t;


static void private_voidScheduler(void);


#endif /* RTOS_INC_RTOS_KERNEL_PRIVATE_H_ */
