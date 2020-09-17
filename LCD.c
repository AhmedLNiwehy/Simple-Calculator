/*
* LCD.c
*
* Created: 16/09/2020
*  Author: Ahmed LNiwehy
*/


#include "LCD.h"
#include "Conversion_Functions.h"

void LCD_Command(uint8 cmd)
{
	/* SEND HIGH NIBBLE TO (D4-D7) */
	LCD_PRT = (LCD_PRT & 0x0F) | (cmd & 0xF0);
	LCD_PRT &=~ (1<<LCD_RW);
	LCD_PRT &=~ (1<<LCD_RS);
	LCD_PRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_PRT &=~ (1<<LCD_EN);
	_delay_us(100);
	
	/* SEND LOW NIBBLE TO (D4-D7) */
	LCD_PRT = (LCD_PRT & 0x0F) | (cmd<<4);
	LCD_PRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_PRT &=~ (1<<LCD_EN);
	_delay_us(100);
}

void LCD_Init()
{
	LCD_DDR |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN);
	LCD_DDR |= 0xF0;
	LCD_PRT &=~ (1<<LCD_EN);
	_delay_us(2000);
	LCD_Command(FOUR_BIT_MODE);			          //Init command
	LCD_Command(TWO_LINE_LCD_FOUR_BIT_MODE);      //Init LCD. 2 line, 5 x 7 matrix 4 bit mode (D4-D7)
	LCD_Command(CURSOR_BLINKING_OFF);             //Display on, Cursor off
	LCD_Command(CLEAR);                           //Clear LCD
	_delay_us(2000);
}

void LCD_DisplayChar(uint8 data)
{
	//Send high nibble to (D4-D7)
	LCD_PRT = (LCD_PRT & 0x0F) | (data & 0xF0);
	LCD_PRT |= (1<<LCD_RS);
	LCD_PRT &=~ (1<<LCD_RW);
	LCD_PRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_PRT &=~ (1<<LCD_EN);
	_delay_us(100);
	
	//Send low nibble to (D4-D7)
	LCD_PRT = (LCD_PRT & 0x0F) | (data << 4);
	LCD_PRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_PRT &=~ (1<<LCD_EN);
	_delay_us(100);
}

void LCD_DisplayString(sint8 *str)
{
	uint8 i=0;
	
	while(str[i] != 0)
	{
		LCD_DisplayChar(str[i]);
		i++;
	}
}

void LCD_Gotoxy(uint8 x, uint8 y)
{
	uint8 firstCharAdd[] = {0x80,0xC0};
	LCD_Command(firstCharAdd[y-1] + x-1);
	_delay_us(100);
}

void LCD_Clear()
{
	LCD_Command(CLEAR);
}

void LCD_CursorOff (void)
{
	LCD_Command(CURSOR_OFF);
}

void LCD_CursorOn (void)
{
	LCD_Command(CURSOR_ON);
}

void LCD_CursorBlinkOn (void)
{
	LCD_Command(CURSOR_BLINKING_ON);
}

void LCD_CursorBlinkOff (void)
{
	LCD_Command(CURSOR_BLINKING_OFF);
}

void LCD_ShiftScreenLeft (void)
{
	LCD_Command(SHIFT_DISPLAY_LEFT);
}

void LCD_ShiftScreenRight(void)
{
	LCD_Command(SHIFT_DISPLAY_RIGHT);
}

void LCD_IntToString(uint32 data)
{
	sint8 str[16];
	convert_To_String(str,data);
	LCD_DisplayString(str);
}
