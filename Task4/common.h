/*
 * COMMON.h
 *
 *  Created on: june 06, 2023
 *  Author: Mohamed Abdelsalam - https://github.com/m3adel

 */

#ifndef COMMON_H_
#define COMMON_H_
/*----------------------------------------------------------/
/- INCLUDES -----------------------------------------------/
/----------------------------------------------------------*/

#include "stdint.h"

/*----------------------------------------------------------/
/- type definations-----------------------------------------/
/----------------------------------------------------------*/
typedef unsigned char u8;				/* 1 byte , 0 -> 255 */
typedef unsigned short int u16;			/* 2 bytes, 0 -> 65,535 */
typedef unsigned long  int u32;			/* 4 bytes, 0 -> 4,294,967,295 */
typedef unsigned long long int u64;		/* 8 bytes, 0 -> 18,446,744,073,709,551,615 */

typedef signed char s8;					/* 1 byte , -128 -> 127 */
typedef signed short int s16;			/* 2 bytes, -32,768 -> 32,767 */
typedef signed long  int s32;			/* 4 bytes, -2,147,483,648 -> 2,147,483,647 */
typedef signed long long int s64;		/* 8 bytes, -9,223,372,036,854,775,807 -> 9,223,372,036,854,775,807 */

typedef float  f32;						/* 4 bytes, 3.4e-38 -> 3.4e+38 */
typedef double f64;						/* 8 bytes, 1.7e-308 -> 1.7e+308 */

typedef void vd;
typedef _Bool boolean;
/*----------------------------------------------------------/
/- MACROS --------------------------------------------------/
/----------------------------------------------------------*/
#define  FALSE 0
#define  TRUE 1
#define SUCCESS (0)
#define ERROR (-1)
#define INVALID_INPUT (-2)
#define NULL ((void*)0)
/*----------------------------------------------------------/
/- BIT MAINPULATION ----------------------------------------/
/----------------------------------------------------------*/

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1UL<<BIT))

/* Clear a certain bit in any register */
#define CLR_BIT(REG,BIT) (REG&=(~(1UL<<BIT)))

/* get value of a certain bit in any register */
//#define GET_BIT_STATUS(REGISTER,BIT_NUMBER)		(0UL != ((REGISTER) & (1UL << (BIT_NUMBER))))
#define TOG_BIT( REGISTER, BIT_NUMBER )		REGISTER = ( REGISTER ^ ( 1 << BIT_NUMBER ) )
#define GET_BIT_STATUS( REGISTER, BIT_NUMBER )		( ( REGISTER & ( 1 << BIT_NUMBER ) ) >> BIT_NUMBER ) // ( ( REGISTER >> BIT_NUMBER ) & 1 )
#define UPPER_NIBBLE( REGISTER, DATA )		( REGISTER = ( REGISTER & 0x0F)  | ( DATA & 0xF0 ) )
#define LOWER_NIBBLE( REGISTER, DATA )		( REGISTER = ( REGISTER & 0x0F ) | ( DATA << 4 ) )
#endif /* COMMON_H_ */

