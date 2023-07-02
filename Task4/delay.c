/*
 * delay.c
 *
 * Created: 6/26/2023 8:16:02 PM
 *  Author: Mohamed Abdelsalam
 */ 
 /*Includes*/
#include "delay.h"
extern GPTM_stTimerLinkConfig_t ast_gs_timersLinkConfig[2];
void Delay( u64 u64_a_delay, GPTM_enTimeUnit_t en_a_Unit)
{
	GPTM_initialization( ast_gs_timersLinkConfig[1]);
	GPTM_setTimer( GPTM_EN_TIMER_1, GPTM_EN_CONCATUNATED, u64_a_delay, en_a_Unit );
	GPTM_enableTimer( GPTM_EN_TIMER_1, GPTM_EN_CONCATUNATED );
	while(0x0 == GPTM_getStatus( GPTM_EN_TIMER_1, GPTM_EN_CONCATUNATED ));
	GPTM_clearInt( GPTM_EN_TIMER_1, GPTM_EN_CONCATUNATED  );
	GPTM_disableTimer( GPTM_EN_TIMER_1, GPTM_EN_CONCATUNATED );
}

