#include "SYSTICK.h"


systickcbf_t APPcbf ;

ErrorStatus SYSTICK_Init (void)
{
	/* CLK sourvce and interrupt enable */
	STK_CTRL &= SYSTICK_CLK_AHB;
	STK_VAL = SYSTICK_CLR_CNT;
	SET_BIT(STK_CTRL, 1);
	CLEAR_BIT(STK_CTRL, 2);
	return ES_OK;
}
ErrorStatus SYSTICK_Start (void)
{
	/* enable counter */
	SET_BIT(STK_CTRL, 0);
	return ES_OK;
}
ErrorStatus SYSTICK_Stop (void)
{
	/* disable counter */
	CLEAR_BIT(STK_CTRL, 0);
	return ES_OK;
}
ErrorStatus SYSTICK_SetCallback (systickcbf_t cbf)
{
	/* callback function */

	APPcbf = cbf;
	return ES_OK;
}
ErrorStatus SYSTICK_SetTime_ms (u32 timems, u32 clk)
{
	/* add value to STK LOAD */ 
	STK_LOAD = (timems/1000) * (clk);
	return ES_OK;

}
ErrorStatus SYSTICK_SetTime_s (u32 time_s,u32 clk)
{
	/* add value to STK LOAD */
	STK_LOAD = (time_s) * (clk);
	return ES_OK;

}

void SysTick_Handler(void)
{
	if(APPcbf != 0)
	{
		APPcbf();
	}
	//SYSTICK_Stop ();
}
