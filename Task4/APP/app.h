
/*
 * app.h
 *
 * Created: 6/22/2023 8:54:47 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef APP_H_
#define APP_H_
#include "../HAL/led/led.h"
#include "../HAL/btn/btn.h"
#include "../HAL/pwm/pwm.h"
#include "../SERVICE/delay/delay.h"
/*****************************************************************************/
/*Macros*/
#define STATE_1	0
#define STATE_2	1
#define STATE_3	2
#define STATE_4	3
#define STATE_NUMBER	4
#define PERCENT_30		30
#define PERCENT_60		60
#define PERCENT_90		90
#define PERCENT_ZERO	0
/*****************************************************************************/
/*APIs*/
void APP_init(void);
void APP_start(void);
/*****************************************************************************/

#endif
