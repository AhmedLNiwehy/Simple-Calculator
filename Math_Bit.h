/*
* Math_Bit.h
*
* Created: 16/09/2020
*  Author: Ahmed LNiwehy
*/


#ifndef MATH_BIT_H_
#define MATH_BIT_H_

/* SET A CERTAIN BIT IN ANY REGISTER */
#define SET_BIT(REG,BIT)		(REG |= (1<<BIT))
/* CLEAR A CERTAIN BIT IN ANY REGISTER */
#define CLEAR_BIT(REG,BIT)		(REG &= (~(1<<BIT)))
/* TOGGLE A CERTAIN BIT IN ANY REGISTER */
#define TOGGLE_BIT(REG,BIT)		(REG ^= (1<<BIT))
/* GET A CERTAIN BIT IN ANY REGISTER */
#define GET_BIT(REG,BIT)		((REG>>BIT) & 1)

#endif /* MATH_BIT_H_ */