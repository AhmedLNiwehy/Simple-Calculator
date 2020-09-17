/*
* Calculate.c
*
* Created: 16/09/2020
*  Author: Ahmed LNiwehy
*/

#include "Calculate.h"

void calculate(sint8 num1[], sint8 num2[], sint8 operator)
{
	sint32  operand1, operand2, result=0;
	sint8 buffer[10];
	
	operand1 = convert_To_Int(num1);
	operand2 = convert_To_Int(num2);
	
	switch(operator)
	{
		case '+':
		result = operand1 + operand2;
		break;
		case '-':
		result = operand1 - operand2;
		break;
		case '/':
		result = operand1 / operand2;
		break;
		case '*':
		result = operand1 * operand2;
		break;
	}
	
	convert_To_String(buffer,result);
	LCD_Gotoxy(1,2);
	LCD_DisplayString(buffer);
	LCD_CursorBlinkOff();
}