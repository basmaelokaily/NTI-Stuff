/**
 * @headerfile STD_TYPES.h
 */
#include "STD_TYPES.h"

/**
 * @headerfile DNVIC.h
 */
#include "NVIC.h"

typedef struct
{
	u32 ISER[8];
	u32 Reserved[24];
	u32 ICER[8];
	u32 Reserved1[24];
	u32 ISPR[8];
	u32 Reserved2[24];
	u32 ICPR[8];
	u32 Reserved3[24];
	u32 IABR[8];
	u32 Reserved4[56];
	u8 IPR[240];
}NVIC_t;

NVIC_t* NV = NVIC_BASE_ADDRESS;

u8 DNVIC_EnableIRQ(u8 IRQn)
{
	//or	NV->ISER[IRQn/32] |= 1<<IRQn%32; //better method
	u8 Local_u8ErrorState = ES_OK;
	if(IRQn<32)
	{

		NV->ISER[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		NV->ISER[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		NV->ISER[2] |= (1<<(IRQn-64));
	}else
	{
		Local_u8ErrorState = ES_NOK;
	}

  return Local_u8ErrorState;
}


u8 DNVIC_DisableIRQ(u8 IRQn)
{
	u8 Local_u8ErrorState = ES_OK;
	if(IRQn<32)
	{
		NV->ICER[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		NV->ICER[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		NV->ICER[2] |= (1<<(IRQn-64));
	}else
	{
		Local_u8ErrorState = ES_NOK;
	}

  return Local_u8ErrorState;
}

u8 DNVIC_SetPendingIRQ (u8 IRQn)
{
	u8 Local_u8ErrorState = ES_OK;
	if(IRQn<32)
	{
		NV->ISPR[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		NV->ISPR[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		NV->ISPR[2] |= (1<<(IRQn-64));
	}else
	{
		Local_u8ErrorState = ES_NOK;
	}

  return Local_u8ErrorState;
}

u8 DNVIC_ClearPendingIRQ (u8 IRQn)
{
	u8 Local_u8ErrorState = ES_OK;
	if(IRQn<32)
	{
		NV->ICPR[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		NV->ICPR[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		NV->ICPR[2] |= (1<<(IRQn-64));
	}else
	{
		Local_u8ErrorState = ES_NOK;
	}

  return Local_u8ErrorState;
}

u8 DNVIC_GetPendingIRQ (u8 IRQn, u8 *Val)
{
	u8 Local_u8ErrorState = ES_OK;
	if(IRQn<32)
	{
		*Val = GET_BIT(NV->ICPR[0],IRQn); //NV->ICPR[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		*Val = GET_BIT(NV->ICPR[1],(IRQn-32));//NV->ICPR[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		*Val = GET_BIT(NV->ICPR[2],(IRQn-64));//NV->ICPR[2] |= (1<<(IRQn-64));
	}
	else
	{
		Local_u8ErrorState = ES_NOK;
	}

  return Local_u8ErrorState;
}

u8 DNVIC_GetActive (u8 IRQn, u8 *Val)
{
	u8 Local_u8ErrorState = ES_OK;
	if(IRQn<32)
	{
		*Val = GET_BIT(NV->IABR[0],IRQn); //NV->ICPR[0] |= (1<<IRQn);
	}else if((31<IRQn)&&(IRQn<64))
	{
		*Val = GET_BIT(NV->IABR[1],(IRQn-32));//NV->ICPR[1] |= (1<<(IRQn-32));
	}else if((IRQn>64)&&(IRQn<67))
	{
		*Val = GET_BIT(NV->IABR[2],(IRQn-64));//NV->ICPR[2] |= (1<<(IRQn-64));
	}
	else
	{
		Local_u8ErrorState = ES_NOK;
	}


  return Local_u8ErrorState;
}

u8 DNVIC_SetPriorityGrouping(u32 priority_grouping)
{
	SCB_AIRCR = PASSWORD_MASK;     //To enable writing to this register
	SCB_AIRCR |= (priority_grouping);   //To write the no that indicates how many groups and subgroups we will have
    return ES_OK;
}

u8 DNVIC_SetPriority (u8 IRQn, u8 group, u8 subgroup)   //changed param for ease of use
{
	 NV->IPR[IRQn] = GET_IRQ_PRIORITY(group,subgroup);
	 return ES_OK;
}

u8 DNVIC_GetPriority (u8 IRQn, u8 *priority)
{
	*priority = ((NV->IPR[IRQn])>>4);
	return ES_OK;
}
/* must develop after reading ch7 and ending the task needed */
void DNVIC_voidDisableAllPeripherals(void)
{
	///NV->ISER[0] = DISABLE_ALL_INT;
	//NV->ISER[1] = DISABLE_ALL_INT;
}


void DNVIC_voidEnableAllPeripherals(void)
{
	//NV->ISER[0] = ENABLE_ALL_INT;
	//NV->ISER[1] = ENABLE_ALL_INT;
	
}

void DNVIC_voidDisableAllFaults(void)
{
	
}


void DNVIC_voidEnableAllFaults(void)
{
	
}

void DNVIC_voidSetBASEPRI(u8 priority)
{
	
}
void DNVIC_voidChangeVectorOffset (u32 offset)
{
	
}

void DNVIC_voidSysReset(void)
{

}
