﻿/*
* Conversion_Functions.c
*
* Created: 16/09/2020
*  Author: Ahmed LNiwehy
*/

#include "Conversion_Functions.h"
#include "Std_Types.h"

sint32 convert_To_Int(sint8 str[])
{
	sint32 num=0, sign=1, i=-1;

	if(str[0] == '-')    //check if the string is -ve
	{
		sign = -1;
		i = 0;           //skip the -ve sign to the number
	}

	while(str[++i] != 0)
	{
		num = (num * 10) + (str[i] - '0');
	}

	num *= sign;
	return num;
}

void convert_To_String(sint8 str[], sint32 num)
{
	sint32 len=0, temp1, temp2, i, rem;

	temp2 = num;
	
	if(temp2 <=0)
	{
		len++;
		num *= -1;
	}
	
	temp1 = num;
	
	while(temp1 != 0)                 //finding length of the number
	{
		len++;
		temp1 /= 10;
	}

	for(i=0; i<len; i++)             //converting numbers to equivalent char
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i+1)] = rem + '0';
	}
	
	if(temp2 < 0)
	{
		str[0] = '-';
	}
	
	str[len] = '\0';
}