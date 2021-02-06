/*
* DIO.c
*
* Created: 17/09/2020
*  Author: Ahmed LNiwehy
*/

#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes Ch,STD_Level Level)
{
	DIO_PortTypes portx = Ch / 8;
	uint8 pin = Ch % 8;
	
	switch(portx)
	{
		case DIO_PORTA:
		if (Level == HIGH)
		{
			SET_BIT(PORTA_REG,pin);
		}
		else
		{
			CLEAR_BIT(PORTA_REG,pin);
		}
		break;
		case DIO_PORTB:
		if (Level == HIGH)
		{
			SET_BIT(PORTB_REG,pin);
		}
		else
		{
			CLEAR_BIT(PORTB_REG,pin);
		}
		break;
		case DIO_PORTC:
		if (Level == HIGH)
		{
			SET_BIT(PORTC_REG,pin);
		}
		else
		{
			CLEAR_BIT(PORTC_REG,pin);
		}
		break;
		case DIO_PORTD:
		if (Level == HIGH)
		{
			SET_BIT(PORTD_REG,pin);
		}
		else
		{
			CLEAR_BIT(PORTD_REG,pin);
		}
		break;
	}	
}

STD_Level DIO_ReadChannel(DIO_ChannelTypes Ch)
{
	DIO_PortTypes portx = Ch / 8;
	uint8 pin = Ch % 8;
	uint8 Ret = 0;
	switch(portx)
	{
		case DIO_PORTA:
			Ret = GET_BIT(PINA_REG,pin);
		break;
		case DIO_PORTB:
			Ret = GET_BIT(PINB_REG,pin);
		break;
		case DIO_PORTC:
			Ret =  GET_BIT(PINC_REG,pin);
		break;
		case DIO_PORTD:
			Ret =  GET_BIT(PIND_REG,pin);
		break;
	}
	return Ret;
}
