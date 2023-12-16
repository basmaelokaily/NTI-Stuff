/*
 * RTOS_KERNEL_PROG.c
 *
 * Created: 11/20/2023 11:06:09 AM
 *  Author: LENOVO
 */ 
#include "RTOS_KERNEL_INT.h"
#include "RTOS_KERNEL_PRIV.h"
#include "RTOS_KERNEL_CFG.h"
#include "RTOS_TMR_register.h"
#include "GI_interface.h"



static Task_t private_arroftasks[RTOS_KERNEL_TASK_NUM];

void RTOS_KERNEL_startScheduling(void)
{
	
	RTOS_TMR_voidInit();
	RTOS_TMR_voidSetCompareMatchValue(249);
	RTOS_TMR_voidSetCallBackCTC(private_void_scheduler);
	GI_voidEnable();
	RTOS_TMR_voidStart();	
}
void RTOS_KERNEL_voidCreateTask(u8 taskpriority, u16 copy_task_periodcity, void(*ptr_to_func)(void))
{
	if((taskpriority < RTOS_KERNEL_TASK_NUM) && (ptr_to_func != nullptr_t) && (private_arroftasks[taskpriority].ptr_to_task_func == nullptr_t))
	{
		private_arroftasks[taskpriority].periodcity = copy_task_periodcity;
		private_arroftasks[taskpriority].ptr_to_task_func = ptr_to_func;
	}	
	else
	{
		return fail;
	}
}

static void private_void_scheduler(void)
{
	static u16 Local_TickCount = 0;
	Local_TickCount ++;
	u8 Local_taskcount;
	for(Local_taskcount = 0; Local_taskcount < RTOS_KERNEL_TASK_NUM; Local_taskcount++)
	{
		if(Local_TickCount % (private_arroftasks[Local_taskcount].periodcity == 0) && (private_arroftasks[Local_taskcount].ptr_to_task_func != nullptr_t))
		{
			private_arroftasks[Local_taskcount].ptr_to_task_func();
		}
		else
		{
			
		}
	}
	
}