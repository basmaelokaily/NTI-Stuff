/* AVR
 *  Timer0_Driver.h
 *  This driver for timer 0 and supports two modes compare mode and normal mode
 *  Created on: Oct 31, 2021
 *  Author: Menna Sayed
 **********************************************************************************************************/

#ifndef TIMER0_DRIVER_H_
#define TIMER0_DRIVER_H_
#include "std_types.h"
/***********************************************DEFINITIONS************************************************/
#define F_CPU         16000000

typedef enum
{
	normal,compare
}Mode;

typedef enum
{
   no_clock,F_1,F_8,F_64,F_256,F_1024
}Prescaler;
typedef struct
{

	Mode mode;
	uint8 initial_val;
	uint8 compare_val;
	Prescaler presc;
}config_struc;

typedef struct
{

	Mode mode;
	uint8 initial_val;
	uint8 compare_val;
//	Prescaler presc;  //specify it in start_synch
}config_struc_sync;


/************************************************PROTOTYPES************************************************/
void Timer0_init_Async(config_struc*);

void Timer0_init_sync(config_struc_sync*);

void Timer0_setCallBack(void(*ptr_func)(void));

void Timer0_DeInit(void);

void start_synch(uint8 presc);

void Delay_ms_sync(uint32 time);

#endif /* TIMER0_DRIVER_H_ */
