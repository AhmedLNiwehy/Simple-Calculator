/*
* Std_Types.h
*
* Created: 16/09/2020
*  Author: Ahmed LNiwehy
*/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char bool;

#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef char                  sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */

typedef enum {
	LOW=0,
	HIGH
}STD_Level;


#endif /* STD_TYPES_H_ */