#include "std_types.h"
#include "DIO_private.h"
#include "DIO_INT.h"
#include "BitMath.h"

void INIT(void)
{
 DDRA = PORT_INPUT;
 DDRB = PORT_INPUT;
 DDRC = PORT_INPUT;
 DDRD = PORT_INPUT;
}

uint_8 SETPINDIrection(uint_8 PORT,uint_8 PIN,STATE ST)
{ 
	uint_8 loc_variable = E_OK;
	if(PORT>=PORT_A && PORT <=PORT_D)
	{
		switch(PORT){
				case PORT_A: 
						{	switch(ST)
							{
								case OUTPUT:
									SETBIT(DDRA,PIN);
									break;
								case INPUT:
									CLEARBIT(DDRA,PIN);
									break;
								default: loc_variable = E_NOK;
							}
						}
				  break;
				case PORT_B:
				{
				switch(ST)
							{
								case OUTPUT:
									SETBIT(DDRB,PIN);
									break;
								case INPUT:
									CLEARBIT(DDRB,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				}break;			
				case PORT_C:
				{
				switch(ST)
							{
								case OUTPUT:
									SETBIT(DDRC,PIN);
									break;
								case INPUT:
									CLEARBIT(DDRC,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				}break;			
				case PORT_D:
				{
				switch(ST)
							{
								case OUTPUT:
									SETBIT(DDRD,PIN);
									break;
								case INPUT:
									CLEARBIT(DDRD,PIN);
									break;
								default: loc_variable = E_NOK;
							}
				}break;			
			  default : loc_variable = E_NOK;
	      }
	 }   
	else 
	{
		 loc_variable = E_NOK;
	}
   return loc_variable;
}

uint_8 setpinvalue(uint_8 PORT,uint_8 PIN,int value)
{
 uint_8 loc_variable = E_OK;
	if(PORT>=PORT_A && PORT <=PORT_D)
	{
		switch(PORT){
		
				case PORT_A: 
					switch(value)
					{
						case HIGH:
						SETBIT(PORTA,PIN);
						break;
						case LOW:
						CLEARBIT(PORTA,PIN);
						break;
						default: loc_variable = E_NOK;
					}
					break;
					
				case PORT_B:
					switch(value)
					{
						case HIGH:
						SETBIT(PORTB,PIN);
						break;
						case LOW:
						CLEARBIT(PORTB,PIN);
						break;
						default: loc_variable = E_NOK;
					}
				           
				case PORT_C:
					switch(value)
					{
						case HIGH:
						SETBIT(PORTC,PIN);
						break;
						case LOW:
						CLEARBIT(PORTC,PIN);
						break;
						default: loc_variable = E_NOK;
					}
				case PORT_D:
					switch(value)
					{
						case OUTPUT:
						SETBIT(PORTD,PIN);
						break;
						case INPUT:
						CLEARBIT(PORTD,PIN);
						break;
						default: loc_variable = E_NOK;
					}
					
	           default : loc_variable = E_NOK;
	   } 
	}         
	else 
	{
		 loc_variable = E_NOK;
	}
return loc_variable;

}


uint_8 getpinvalue(uint_8 PORT,uint_8 PIN,int*value)
{
uint_8 loc_variable = E_OK;
	if(PORT>=PORT_A && PORT <=PORT_D)
	{
		switch(PORT)
		{
			case PORT_A:
				*value=GET_BIT(PINB,PIN);
				break;
			case PORT_B:
				*value=GET_BIT(PINB,PIN);
				break;
			case PORT_C:
				*value=GET_BIT(PINC,PIN);
				break;
			case PORT_D:
				*value=GET_BIT(PIND,PIN);
				break;
			default : loc_variable = E_NOK;
	    }
	}			   
	else 
	{
		 loc_variable = E_NOK;
	}
       return loc_variable;
}

uint_8 togglepinvalue(uint_8 PORT,uint_8 PIN)
{
    uint_8 loc_variable = E_OK;
	if(PORT>=PORT_A && PORT <=PORT_D)
	{
		switch(PORT){
		
				case PORT_A: 
						TOGGLE(PORT,PIN);
						break;
				case PORT_B:
			            TOGGLE(PORT,PIN);
						break;
				case PORT_C:
					    TOGGLE(PORT,PIN);
						break;
				case PORT_D:
				       TOGGLE(PORT,PIN);
				       break;
				default : loc_variable = E_NOK;
	          }
	}			
	else 
	{
		 loc_variable = E_NOK;
	}
   return loc_variable;
}

uint_8 ControlPortDIR(uint_8 PORT,uint_8 STATE)
{
 uint_8 loc_variable = E_OK;
	if(PORT>=PORT_A && PORT <=PORT_D)
	{
		switch(PORT){
		
				case PORT_A: 
						DDRA = STATE;		
						break;
				case PORT_B:
			            DDRB = STATE;		
						break;
				case PORT_C:
						DDRC = STATE;		
						break;
				case PORT_D:
				        DDRD = STATE;						
						break;
				default : loc_variable = E_NOK;
		}		
	}
	else 
	{
		 loc_variable = E_NOK;
	}
   return loc_variable;
}
uint_8 controlPortValue(uint_8 PORT,int Value)
{
   uint_8 loc_variable = E_OK;
	if(PORT>=PORT_A && PORT <=PORT_D)
	{
		switch(PORT){
		
				case PORT_A: 
						PORTA = Value;			
						break;
				case PORT_B:
			            PORTB = Value;		
						break;
				case PORT_C:
						PORTC = Value;					
						break;
				case PORT_D:
				        PORTD = Value;		
						break;
				default : loc_variable = E_NOK;
		    }		
	}
	else 
	{
		 loc_variable = E_NOK;
	}
   return loc_variable;
}