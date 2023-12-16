/*
 * TIMER0.h
 *
 * Created: 9/5/2022 3:38:21 AM
 *  Author: lenovo 520
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "std_macros.h"

#define PORTD0_output DDRD |=0b00000001;
/*extern void (*timer0_ovf_isr)(void);
extern void (*timer0_ctc_isr)(void);*/


void TIMER0_NORMMOD_INIT(void);
void TIMER0_CTCMOD_INIT(uint8_t ocr);
void TIMER_START(void);
void TIMER0_FREQ_GEN_INIT(uint8_t ocr);





#endif /* TIMER0_H_ */