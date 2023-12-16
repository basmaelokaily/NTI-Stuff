/*
 * Kernel_prog.c
 *
 *  Created on: Nov 20, 2023
 *      Author: dell
 */
#include"Kernel_interface.h"
#include"Kernel_config.h"
#include"Kernel_Ptivate.h"
#include "Timer2_Driver.h"
#include "GIE.h"

static Task_t private_arrayOfTasks[RTOS_KERNEL_NUM_TASKS];

void RTOS_KERNEL_voidStartScheduling(void)
{
	config_struc config ={compare_2,0,249,F_64};  //Rtos Tick 1ms
	Timer2_init_Async(&config);
	Timer2_setCallBack(private_voidscheduler);

	Global_InterruptEnable();
}
u8 RTOS_KERNEL_voidCreateTask(u8 TaskPriority,u16 TaskPriodicity,void(*ptrToFun)(void))
{
	u8 Locale_ErrorState = pass;
   if((TaskPriority < RTOS_KERNEL_NUM_TASKS)&&(ptrToFun != NULL)&&(private_arrayOfTasks[TaskPriority].pTaskFun == NULL))
   {
	   private_arrayOfTasks[TaskPriority].priodicity=TaskPriodicity;
	   private_arrayOfTasks[TaskPriority].pTaskFun = ptrToFun;
   }
   else
   {
	   Locale_ErrorState = fail;
   }
   return Locale_ErrorState;
}
static void private_voidscheduler(void)
{
   static u16 Locale_u16TickCount=0;
   Locale_u16TickCount++;
   u8 i;
   for(i=0;i<RTOS_KERNEL_NUM_TASKS;i++)
   {
      if((Locale_u16TickCount % (private_arrayOfTasks[i].priodicity)==0)&&(private_arrayOfTasks[i].pTaskFun!= NULL))  //mn moda3afatha (baky el kesma b zero
      {
           /*Call Task Func*/
    	  private_arrayOfTasks[i].pTaskFun();

      }else
      {

      }
   }
}

void RTOS_KERNEL_voidDeleteTask(u8 TaskPriority)
{
	if(TaskPriority < RTOS_KERNEL_NUM_TASKS )
	{
		private_arrayOfTasks[TaskPriority].pTaskFun= NULL;
	}
}
