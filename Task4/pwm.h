/*
 * pwm.h
 *
 * Created: 4/6/2023 11:17:52 PM
 *  Author: MOHAMED ABDELSALAM
 */ 




#ifndef PWM_H_
#define PWM_H_
#include "common.h"
#include "gpio.h"
#include "gpt.h"
//pwm output pin
#define percent_30 30
#define percent_50 50


//PWM Modes
#define NonInv_correct_phase 0x60
#define Normal 0x00
//intial values
#define no_clk 0x00
#define zero_intial 0x00
#define Intial_value_PWM 0x06
//prescaler values
#define pres_1 0x01
#define pres_8 0x02
#define pres_64 0x03
#define pres_256 0x04
#define pres_1024 0x05
#define clear_PWM 0x01
void PWM_Stop (void);
void PWM_init (void);
void PWM_start (uint8_t duty_percent);
//void PWM_gen(void);


#endif /* PWM_H_ */
