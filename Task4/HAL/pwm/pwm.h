/*
 * pwm.h
 *
 * Created: 6/24/2023 11:17:52 PM
 *  Author: MOHAMED ABDELSALAM
 */ 




#ifndef PWM_H_
#define PWM_H_
#include "../../LIB/common.h"
#include "../../MCAL/gpio/gpio.h"
#include "../../MCAL/gpt/gpt.h"

/*****************************************************************************/
/* Macros */
/*****************************************************************************/
#define MILIISECOND_500	500000
#define MILIISECOND_ZERO	0
/*****************************************************************************/
/* Error list */
/*****************************************************************************/
typedef enum 
{
	PWM_INIT_ERROR	=	0XC0,
	PWM_START_ERROR				,
	PWM_STOP_ERROR				,
	PWM_OKAY
} enm_pwm_errors_t;
/*****************************************************************************/
/*APIs*/
u8 PWM_Stop (void);
u8 PWM_init (void);
u8 PWM_start (uint8_t duty_percent);
//void PWM_gen(void);


#endif /* PWM_H_ */
