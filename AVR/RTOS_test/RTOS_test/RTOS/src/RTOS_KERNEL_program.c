/*
 * RTOS_KERNEL_program.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Kareem Hussein
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GI_interface.h"

/* RTOS */
#include "RTOS_TMR_interface.h"
#include "RTOS_KERNEL_interface.h"
#include "RTOS_KERNEL_config.h"
#include "RTOS_KERNEL_private.h"


static Task_t private_arrOfTasks[RTOS_KERNEL_TASK_NUM];

void RTOS_KERNEL_voidStartScheduling(void)
{
	GI_voidEnable();
	RTOS_TMR_voidInit();
	RTOS_TMR_voidSetCompareMatchValue(249); // RTOS Tick 1ms
	RTOS_TMR_voidSetCallBackCTC(&private_voidScheduler);
	RTOS_TMR_voidStart();
}


u8 RTOS_KERNEL_voidCreateTask(u8 copy_u8Priority,u16 copy_u16Periodicty,void(*ptrToFun)(void))
{
	u8 Local_u8ErrorState = PASS;
	if((copy_u8Priority<RTOS_KERNEL_TASK_NUM)&&(ptrToFun!=NULL)&&(private_arrOfTasks[copy_u8Priority].PTaskFun == NULL))
	{
		private_arrOfTasks[copy_u8Priority].TaskPeriodicty = copy_u16Periodicty;
		private_arrOfTasks[copy_u8Priority].PTaskFun       = ptrToFun;
	}
	else
	{
		Local_u8ErrorState = FAIL;
	}
	return Local_u8ErrorState;
}


static void private_voidScheduler(void)
{
	static u16 Local_u16TickCount = 0;
	Local_u16TickCount++;
	
	u8 Local_u8TaskCounter;
	for(Local_u8TaskCounter=0;Local_u8TaskCounter<RTOS_KERNEL_TASK_NUM;Local_u8TaskCounter++)
	{
		if((Local_u16TickCount%(private_arrOfTasks[Local_u8TaskCounter].TaskPeriodicty)==0)
			&&(private_arrOfTasks[Local_u8TaskCounter].PTaskFun!=NULL))
		{
           // Call Task
           private_arrOfTasks[Local_u8TaskCounter].PTaskFun();	
		}
		else
		{
			//Do Noting
		}
	}
}