/*
* Keypad.h
*
* Created: 17/09/2020 
*  Author: Ahmed LNiwehy
*/

#include "DIO.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KPAD_PRT  PORTD_REG
#define KPAD_DDR  DDRD_REG
#define KPAD_PIN  PIND_REG

#define C1 ChannelD0
#define C2 ChannelD1
#define C3 ChannelD2
#define C4 ChannelD3
#define R1 ChannelD4
#define R2 ChannelD5
#define R3 ChannelD6
#define R4 ChannelD7

void Keypad_Init(void);
void CheckRow1(sint8 *button, STD_Level *state);
void CheckRow2(sint8 *button, STD_Level *state);
void CheckRow3(sint8 *button, STD_Level *state);
void CheckRow4(sint8 *button, STD_Level *state);
sint8 KPAD_Scan(void);

#endif /* KEYPAD_H_ */