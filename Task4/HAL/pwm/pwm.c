/*
 * pwm.c
 *
 * Created: 24/6/2023 11:18:12 PM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "pwm.h"
#define PWM_PERIOD       500        //the frequency in ms
str_gpio_config_t pin1;
#define PWM_Port1         F
#define PWM_Pin1          P3
volatile u64 PWM_count_ON=0;
volatile u64 PWM_count_OFF=0;
boolean PWM_Flag = FALSE;
extern GPTM_stTimerLinkConfig_t ast_gs_timersLinkConfig[2];
void PWM_gen(void)
{
	//PWM_time on
	if (PWM_Flag ==  TRUE )
	{
		GPIO_write(pin1,HIGH);
	//	GPIO_write(pin2,HIGH);
	GPTM_setTimer( GPTM_EN_TIMER_0, GPTM_EN_CONCATUNATED, PWM_count_ON, GPTM_EN_TIME_US );
		PWM_Flag = FALSE;
	}
	else if (PWM_Flag == FALSE)
	{
		GPIO_write(pin1,LOW);
		GPTM_setTimer( GPTM_EN_TIMER_0, GPTM_EN_CONCATUNATED, PWM_count_OFF, GPTM_EN_TIME_US );
		PWM_Flag = TRUE;
	}

	GPTM_clearInt( GPTM_EN_TIMER_0, GPTM_EN_CONCATUNATED  );

}
u8 PWM_init (void)
{
	u8 u8_l_ret;
	pin1.enm_gpio_pinAmpere = R8;
	pin1.enm_gpio_pinDirection = OUT;
	pin1.enm_gpio_pinNumber = PWM_Pin1;
	pin1.enm_gpio_portNumber = PWM_Port1;
	pin1.enm_gpio_pullUP		=	DISABLE;
	GPIO_init(pin1);
				
	if(GPTM_EN_OK == GPTM_initialization( ast_gs_timersLinkConfig[0]))
	{
		u8_l_ret = PWM_OKAY;
	}
	else
	{
		u8_l_ret = PWM_INIT_ERROR;
	}
	if(GPTM_EN_OK == GPTM_setCallback( GPTM_EN_TIMER_0, GPTM_EN_CONCATUNATED, &PWM_gen ))
	{
		u8_l_ret = PWM_OKAY;
	}
	else
	{
		u8_l_ret = PWM_INIT_ERROR;
	}
	return u8_l_ret;
}

u8 PWM_start (uint8_t duty_percent)
	{
	u8 u8_l_ret;
	u64 u64_temp = 0;
	u64_temp = (u64)((duty_percent*PWM_PERIOD)*10);
	PWM_count_ON = u64_temp;
	u64_temp = (u64)(((100-duty_percent)*PWM_PERIOD)*10);
	PWM_count_OFF = u64_temp;
	PWM_Flag=FALSE;
	
	if(PWM_count_ON == MILIISECOND_ZERO)
	{
		if(GPIO_OKAY == GPIO_write(pin1,LOW))
		{
			u8_l_ret = PWM_OKAY;
		}
		else
		{
			u8_l_ret = PWM_START_ERROR;
		}
		if(GPTM_EN_OK == GPTM_disableTimer( GPTM_EN_TIMER_0, GPTM_EN_CONCATUNATED ))
		{
			u8_l_ret = PWM_OKAY;
		}
		else
		{
			u8_l_ret = PWM_START_ERROR;
		}
	}
	else if(PWM_count_ON == MILIISECOND_500)
	{
		if(GPIO_OKAY == GPIO_write(pin1,HIGH))
		{
			u8_l_ret = PWM_OKAY;
		}
		else
		{
			u8_l_ret = PWM_START_ERROR;
		}
		if(GPTM_EN_OK == GPTM_disableTimer( GPTM_EN_TIMER_0, GPTM_EN_CONCATUNATED ))
		{
			u8_l_ret = PWM_OKAY;
		}
		else
		{
			u8_l_ret = PWM_START_ERROR;
		}
		
		
	}
	else
	{
		if(GPTM_EN_OK == GPTM_setTimer( GPTM_EN_TIMER_0, GPTM_EN_CONCATUNATED, PWM_count_ON, GPTM_EN_TIME_US ))
		{
			u8_l_ret = PWM_OKAY;
		}
		else
		{
			u8_l_ret = PWM_START_ERROR;
		}
		if(GPTM_EN_OK == GPTM_enableTimer( GPTM_EN_TIMER_0, GPTM_EN_CONCATUNATED ))
		{
			u8_l_ret = PWM_OKAY;
		}
		else
		{
			u8_l_ret = PWM_START_ERROR;
		}
		PWM_Flag = FALSE;
		if(GPIO_OKAY == GPIO_write(pin1,HIGH))
		{
			u8_l_ret = PWM_OKAY;
		}
		else
		{
			u8_l_ret = PWM_START_ERROR;
		}
	
	}
	return u8_l_ret;
}

u8 PWM_Stop (void)
{
	u8 u8_l_ret;
	//Timer Stop
	//no_clk;
	if(GPTM_EN_OK == GPTM_disableTimer( GPTM_EN_TIMER_0, GPTM_EN_CONCATUNATED ))
	{
		u8_l_ret = PWM_OKAY;
	}
	else
	{
		u8_l_ret = PWM_START_ERROR;
	}
	return u8_l_ret;
}
