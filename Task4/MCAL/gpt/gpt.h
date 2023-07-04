/*
 * GPT.h
 *  Created on: june 20, 2023
 *  Author: Mohamed Abdelsalam - https://github.com/m3adel

 */

#ifndef GPT_H_
#define GPT_H_

/*******************************************************************************************************************************************************************/
/* GPTM Includes */

/* STD LIB */
#include "TM4C123.h"
#include "math.h"

/* LIB */
#include "../../LIB/common.h"
#include "../../LIB/mcu_config.h"

/* MCAL */
#include "gpt_lcfg.h"
#include "gpt_private.h"
/*******************************************************************************************************************************************************************/
/* GPTM Enumerations */

/* GPTM Error States */
typedef enum
{
	GPTM_EN_NOK = 0, 
	GPTM_EN_OK
	
} GPTM_enErrorState_t;

/* GPTM Time Units */
typedef enum
{
	GPTM_EN_TIME_US,
	GPTM_EN_TIME_MS,
	GPTM_EN_TIME_SEC,
	GPTM_EN_INVALID_TIME_UNIT
	
} GPTM_enTimeUnit_t;

/*******************************************************************************************************************************************************************/
/* GPTM Functions' Prototypes */

/*
 Name: GPTM_initialization
 Input: Struct of TimerLinkConfig
 Output: en Error or No Error
 Description: Function to initialize GPTM peripheral using Linking Configurations.
*/
extern GPTM_enErrorState_t GPTM_initialization( GPTM_stTimerLinkConfig_t past_a_timersLinkConfig );

/*
 Name: GPTM_setTimer
 Input: en TimerId, en TimerUse, u64 Time, and en TimeUnit
 Output: en Error or No Error
 Description: Function to set GPTM peripheral to count in microseconds( us ), milliseconds ( ms ), and seconds ( sec ).
*/
extern GPTM_enErrorState_t GPTM_setTimer( GPTM_enTimerId_t en_a_timerId, GPTM_enTimerUse_t en_a_timerUse, u64 u64_a_time, GPTM_enTimeUnit_t en_a_timeUnit );

/*
 Name: GPTM_enableTimer
 Input: en TimerId and en TimerUse
 Output: en Error or No Error
 Description: Function to enable GPTM.
*/
extern GPTM_enErrorState_t GPTM_enableTimer( GPTM_enTimerId_t en_a_timerId, GPTM_enTimerUse_t en_a_timerUse );

/*
 Name: GPTM_disableTimer
 Input: en TimerId and en TimerUse
 Output: en Error or No Error
 Description: Function to disable GPTM.
*/
extern GPTM_enErrorState_t GPTM_disableTimer( GPTM_enTimerId_t en_a_timerId, GPTM_enTimerUse_t en_a_timerUse );
extern u8 GPTM_getStatus( GPTM_enTimerId_t en_a_timerId, GPTM_enTimerUse_t en_a_timerUse );
extern void GPTM_clearInt( GPTM_enTimerId_t en_a_timerId, GPTM_enTimerUse_t en_a_timerUse );
/*
 Name: GPTM_enableInterrupt
 Input: en TimerInterruptNumber
 Output: en Error or No Error
 Description: Function to enable GPTM Interrupt.
*/
extern GPTM_enErrorState_t GPTM_enableInterrupt( GPTM_enTimerInterruptNumber_t en_a_timerInterruptNumber );

/*
 Name: GPTM_disableInterrupt
 Input: en TimerInterruptNumber
 Output: en Error or No Error
 Description: Function to disable GPTM Interrupt.
*/
extern GPTM_enErrorState_t GPTM_disableInterrupt( GPTM_enTimerInterruptNumber_t en_a_timerInterruptNumber );

/*
 Name: GPTM_setCallback
 Input: en TimerId, en TimerUse, and Pointer to Function that takes void and returns void
 Output: en Error or No Error
 Description: Function to receive an address of a function ( in an Upper Layer ) to be called back in IRQ function of the passed Timer ( TimerId ),
							the address is passed through a pointer to function ( TimerInterruptAction ), and then pass this address to IRQ function.
*/
extern GPTM_enErrorState_t GPTM_setCallback( GPTM_enTimerId_t en_a_timerId, GPTM_enTimerUse_t en_a_timerUse, void ( *vpf_a_timerInterruptAction ) ( void ) );

/*******************************************************************************************************************************************************************/



#endif /* GPT_H_ */
