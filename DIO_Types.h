/*
* DIO_Types.h
*
* Created: 17/09/2020
*  Author: Ahmed LNiwehy
*/


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum {
	ChannelA0=0,
	ChannelA1,
	ChannelA2,
	ChannelA3,
	ChannelA4,
	ChannelA5,
	ChannelA6,
	ChannelA7,
	
	ChannelB0,
	ChannelB1,
	ChannelB2,
	ChannelB3,
	ChannelB4,
	ChannelB5,
	ChannelB6,
	ChannelB7,
	
	ChannelC0,
	ChannelC1,
	ChannelC2,
	ChannelC3,
	ChannelC4,
	ChannelC5,
	ChannelC6,
	ChannelC7,
	
	ChannelD0,
	ChannelD1,
	ChannelD2,
	ChannelD3,
	ChannelD4,
	ChannelD5,
	ChannelD6,
	ChannelD7
	
}DIO_ChannelTypes;

typedef enum{
	DIO_PORTA=0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DIO_PortTypes;

typedef enum{
	INPUT=0,
	OUTPUT
}DIO_Dir;



#endif /* DIO_TYPES_H_ */