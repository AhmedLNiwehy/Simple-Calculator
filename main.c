/*
* Simple_Calculator.c
*
* Created: 16/09/2020
* Author : Ahmed LNiwehy
*/

#include "LCD.h"
#include "Keypad.h"
#include "DIO.h"
#include "Conversion_Functions.h"
#include "Calculate.h"
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	LCD_Init();
	Keypad_Init();
	
	while(1)
	{
		sint8 num1[7], num2[7], operator=0;
		uint8 i=0;

		LCD_Gotoxy(1,1);
		LCD_CursorBlinkOn();
		num1[i] = KPAD_Scan();
		LCD_DisplayChar(num1[i]);
		i++;
		
		while(1){
			
			num1[i] = KPAD_Scan();
			LCD_DisplayChar(num1[i]);
			
			if(num1[i] == '+')
			{
				operator = '+';
				num1[i] = '\0';
				break;
			}
			else if(num1[i] == '-')
			{
				operator = '-';
				num1[i] = '\0';
				break;
			}
			else if(num1[i] == '/')
			{
				operator = '/';
				num1[i] = '\0';
				break;
			}
			else if(num1[i] == '*')
			{
				operator = '*';
				num1[i] = '\0';
				break;
			}
			i++;
		}
		
		i = 0;
		
		num2[i] = KPAD_Scan();
		LCD_DisplayChar(num2[i]);
		i++;
		
		while(1){
			
			num2[i] = KPAD_Scan();
			LCD_DisplayChar(num2[i]);
			if(num2[i] == '='){
				num2[i] = '\0';
				break;
			}
			
			i++;
		}
		
		calculate(num1,num2,operator);
		
		if(KPAD_Scan())
		{
			LCD_Command(CLEAR);
		}
	}
}

