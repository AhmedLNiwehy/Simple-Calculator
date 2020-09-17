/*
* Keypad.c
*
* Created: 17/09/2020
*  Author: Ahmed LNiwehy
*/

#include "Keypad.h"

void Keypad_Init(void)
{
	KPAD_DDR = 0xF0;
	KPAD_PRT = 0xFF;
}

void CheckRow1(sint8 *button, STD_Level *state)       //Scan row 1 of the keypad to detect any pressed key
{
	KPAD_PRT = 0xEF;
	if (DIO_ReadChannel(C1) == 0){
		while(DIO_ReadChannel(C1) == 0);
		*button = '7';
		*state = LOW;
	}
	if (DIO_ReadChannel(C2) == 0){
		while(DIO_ReadChannel(C2) == 0);
		*button =  '8';
		*state = LOW;
	}
	if (DIO_ReadChannel(C3) == 0){
		while(DIO_ReadChannel(C3) == 0);
		*button =  '9';
		*state = LOW;
	}
	if (DIO_ReadChannel(C4) == 0){
		while(DIO_ReadChannel(C4) == 0);
		*button =  '/';
		*state = LOW;
	}
}

void CheckRow2(sint8 *button, STD_Level *state)
{
	KPAD_PRT = 0xDF;
	if (DIO_ReadChannel(C1) == 0){
		while(DIO_ReadChannel(C1) == 0);
		*button =  '4';
		*state = LOW;
	}
	if (DIO_ReadChannel(C2) == 0){
		while(DIO_ReadChannel(C2) == 0);
		*button =  '5';
		*state = LOW;
	}
	if (DIO_ReadChannel(C3) == 0){
		while(DIO_ReadChannel(C3) == 0);
		*button =  '6';
		*state = LOW;
	}
	if (DIO_ReadChannel(C4) == 0){
		while(DIO_ReadChannel(C4) == 0);
		*button =  '*';
		*state = LOW;
	}
}
void CheckRow3(sint8 *button, STD_Level *state)
{
	KPAD_PRT = 0xBF;
	if (DIO_ReadChannel(C1) == 0){
		while(DIO_ReadChannel(C1) == 0);
		*button =  '1';
		*state = LOW;
	}
	if (DIO_ReadChannel(C2) == 0){
		while(DIO_ReadChannel(C2) == 0);
		*button =  '2';
		*state = LOW;
	}
	if (DIO_ReadChannel(C3) == 0){
		while(DIO_ReadChannel(C3) == 0);
		*button =  '3';
		*state = LOW;
	}
	if (DIO_ReadChannel(C4) == 0){
		while(DIO_ReadChannel(C4) == 0);
		*button =  '-';
		*state = LOW;
	}
}

void CheckRow4(sint8 *button, STD_Level *state)
{
	KPAD_PRT = 0x7F;
	if (DIO_ReadChannel(C1) == 0){
		while(DIO_ReadChannel(C1) == 0);
		*button =  '!';
		*state = LOW;
	}
	if (DIO_ReadChannel(C2) == 0){
		while(DIO_ReadChannel(C2) == 0);
		*button =  '0';
		*state = LOW;
	}
	if (DIO_ReadChannel(C3) == 0){
		while(DIO_ReadChannel(C3) == 0);
		*button =  '=';
		*state = LOW;
	}
	if (DIO_ReadChannel(C4) == 0){
		while(DIO_ReadChannel(C4) == 0);
		*button =  '+';
		*state = LOW;
	}
}

sint8 KPAD_Scan(void)
{
	STD_Level state = HIGH;
	sint8 button=0;
	while(state){
		CheckRow1(&button,&state);
		CheckRow2(&button,&state);
		CheckRow3(&button,&state);
		CheckRow4(&button,&state);
	}
	return button;
}