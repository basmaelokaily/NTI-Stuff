#ifndef _SYSTICK_INT_H_
#define _SYSTICK_INT_H_

#include "Systick_priv.h"
#include "SYSTICK_config.h"
#include "std_macros.h"
#include "std_types.h"
#include "rcc_int.h"

#define SYSTICK_ENABLE   0x00000001
#define SYSTICK_DISABLE  0xFFFFFFFE

#define OK       0
#define NOT_OK   1

#define SYSTICK_CLK_AHB  	   0x00000004
#define SYSTICK_CLK_AHB_DIV_8  0x00000000
#define SYSTICK_CLR_CNT 0x000000


#define SYSTICK_TICK_INT_ENABLE  0x00000002
#define SYSTICK_TICK_INT_DISABLE 0x00000000

typedef void (*systickcbf_t) (void);
ErrorStatus SYSTICK_Init (void);
ErrorStatus SYSTICK_Start (void);
ErrorStatus SYSTICK_Stop (void);
ErrorStatus SYSTICK_SetCallback (systickcbf_t cbf);
ErrorStatus SYSTICK_SetTime_ms (u32 timems,u32 clk);
ErrorStatus SYSTICK_SetTime_s (u32 time_s,u32 clk);
ErrorStatus SYSTICK_SetPrescale (u32 prescale);

#endif 
