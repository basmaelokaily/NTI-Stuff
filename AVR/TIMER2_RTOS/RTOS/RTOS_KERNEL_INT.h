/*
 * RTOS_KERNEL_INT.h
 *
 * Created: 11/20/2023 10:52:50 AM
 *  Author: LENOVO
 */ 


#ifndef RTOS_KERNEL_INT_H_
#define RTOS_KERNEL_INT_H_
#include "std_types.h"
#include "std_macros.h"

void RTOS_KERNEL_startScheduling(void);
void RTOS_KERNEL_voidCreateTask(u8 taskpriority, u16 copy_task_periodcity, void(*ptr_to_func)(void));



#endif /* RTOS_KERNEL_INT_H_ */