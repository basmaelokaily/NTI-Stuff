/*
 * RTOS_KERNEL_PRIV.h
 *
 * Created: 11/20/2023 10:55:19 AM
 *  Author: LENOVO
 */ 


#ifndef RTOS_KERNEL_PRIV_H_
#define RTOS_KERNEL_PRIV_H_

typedef struct
{
	u16 periodcity; 
	void (*ptr_to_task_func)(void);	
}Task_t;

static void private_void_scheduler(void);




#endif /* RTOS_KERNEL_PRIV_H_ */