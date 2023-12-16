/*
 * RTOS.c
 *
 * Created: 11/20/2023 10:52:00 AM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "RTOS_KERNEL_INT.h"
#include "GI_interface.h"

void rled(void);
void gled(void);
void bled(void);



int main(void)
{
	SETBIT(DDRC, 0);
	SETBIT(DDRB, 7);
	SETBIT(DDRA, 4);
	SETBIT(DDRA, 5);
	RTOS_KERNEL_voidCreateTask(0, 1000, rled);
	RTOS_KERNEL_voidCreateTask(1, 2000, gled);
	RTOS_KERNEL_voidCreateTask(2, 3000, bled);
	RTOS_KERNEL_startScheduling();
    /* Replace with your application code */
    while (1) 
    {
    }
}

void rled(void)
{
	TOGBIT(PORTB, 7);
}
void gled(void)
{
	TOGBIT(PORTA, 4);
}
void bled(void)
{
	TOGBIT(PORTA, 5);
}
