/*
 * Kernel_Ptivate.h
 *
 *  Created on: Nov 20, 2023
 *      Author: dell
 */

#ifndef KERNEL_PTIVATE_H_
#define KERNEL_PTIVATE_H_
#include "std_types.h"

typedef struct
{
	u16 priodicity;
	void(*pTaskFun)(void);

}Task_t;

static void private_voidscheduler(void);

#endif /* KERNEL_PTIVATE_H_ */
