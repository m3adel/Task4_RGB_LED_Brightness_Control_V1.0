/*
 * pwm.h
 *
 * Created: 6/24/2023 11:17:52 PM
 *  Author: MOHAMED ABDELSALAM
 */ 




#ifndef PWM_H_
#define PWM_H_
#include "common.h"
#include "gpio.h"
#include "gpt.h"
/*APIs*/
void PWM_Stop (void);
void PWM_init (void);
void PWM_start (uint8_t duty_percent);
//void PWM_gen(void);


#endif /* PWM_H_ */
