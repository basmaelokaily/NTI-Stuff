/*
 * DIO_prog.c
 *
 *  Created on: Nov 6, 2023
 *      Author: LENOVO
 */
#include "DIO_interface.h"
void	DIO_voidSetPinDirection(u8 port, u8 pin, u8 Direction)
{
	switch (port)
	{
		case PORTA:
			if(pin < 8)
			{
				GPIOA_CRL &= MASK<<pin*4;
				GPIOA_CRL ^= (Direction<<pin*4);
			}
			else
			{
				GPIOA_CRH &= MASK<<pin*4;
				GPIOA_CRH ^= (Direction<<pin*4);
			}
			break;
		case PORTB:
			if(pin < 8)
			{
				GPIOB_CRL &= MASK<<pin*4;
				GPIOB_CRL ^= (Direction<<pin*4);
			}
			else
			{
				GPIOB_CRH &= MASK<<pin*4;
				GPIOB_CRH ^= (Direction<<pin*4);
			}
			break;
		case PORTC:
			if(pin < 8)
			{
				GPIOC_CRL &= MASK<<pin*4;
				GPIOC_CRL ^= (Direction<<pin*4);
			}
			else
			{
				GPIOC_CRH &= MASK<<pin*4;
				GPIOC_CRH ^= (Direction<<pin*4);
			}
			break;
	}

}
void	DIO_voidSetPortnDirection(u8 port, u8 Direction)
{
	switch (port)
		{
			case PORTA:
				GPIOA_CRL &= MASK_32BIT;
				GPIOA_CRL ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				GPIOA_CRH &= MASK_32BIT;
				GPIOA_CRH ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				break;

			case PORTB:
				GPIOB_CRL &= MASK_32BIT;
				GPIOB_CRL ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				GPIOB_CRH &= MASK_32BIT;
				GPIOB_CRH ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				break;

			case PORTC:
				GPIOC_CRL &= MASK_32BIT;
				GPIOC_CRL ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				GPIOC_CRH &= MASK_32BIT;
				GPIOC_CRH ^= ((Direction<<0) | (Direction<<1*4) | (Direction<<2*4) | (Direction<<3*4) | (Direction<<4*4)
						   | (Direction<<5*4) | (Direction<<6*4) | (Direction<<7*4));
				break;
		}
}

void DIO_voidSetPORTValue(u8 port, uint16 Value)
{
	switch(port)
	{
		case PORTA:
			GPIOA_ODR = 0;
			GPIOA_ODR |= Value;
			break;
		case PORTB:
			GPIOB_ODR = 0;
			GPIOB_ODR |= Value;
			break;
		case PORTC:
			GPIOC_ODR = 0;
			GPIOC_ODR |= Value;
			break;

	}
}


void DIO_voidSetPinValue(u8 port, u8 pin, u8 Value)
{
	switch(port)
	{
		case PORTA:
			switch(Value)
			{
				case GPIO_LOW:
					CLEAR_BIT(GPIOA_ODR, pin);
					break;
				case GPIO_HIGH:
					SET_BIT(GPIOA_ODR, pin);
					break;
			}
			break;
		case PORTB:
			switch(Value)
			{
				case GPIO_LOW:
					CLEAR_BIT(GPIOB_ODR, pin);
					break;
				case GPIO_HIGH:
					SET_BIT(GPIOB_ODR, pin);
					break;
			}
			break;
		case PORTC:
			switch(Value)
			{
				case GPIO_LOW:
					CLEAR_BIT(GPIOC_IDR, pin);
					break;
				case GPIO_HIGH:
					SET_BIT(GPIOC_IDR, pin);
					break;
			}
			break;

	}
}
u8 DIO_u8GetPinValue(u8 port, u8 pin)
{
	switch(port)
	{
		case PORTA:
			return GET_BIT(GPIOA_ODR, pin);
		case PORTB:
			return GET_BIT(GPIOB_ODR, pin);
		case PORTC:
			return GET_BIT(GPIOC_ODR, pin);
	}
	return -1;
}

void DIO_voidTogglePin(u8 port, u8 pin)
{
	switch(port)
		{
			case PORTA:
				TOGBIT(GPIOA_ODR, pin);
				break;
			case PORTB:
				TOGBIT(GPIOB_ODR, pin);
				break;
			case PORTC:
				TOGBIT(GPIOC_ODR, pin);
				break;
		}
}


