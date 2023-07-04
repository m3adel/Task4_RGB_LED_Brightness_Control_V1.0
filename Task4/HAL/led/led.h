/*
 * led.h
 *
 * Created: 6/22/2023 8:54:47 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef LED_H_
#define LED_H_
/*****************************************************************************/
/*MCAL*/
/*****************************************************************************/
#include "../../MCAL/gpio/gpio.h"
/*****************************************************************************/
/* Error list */
/*****************************************************************************/
typedef enum 
{
	LED_INIT_ERROR	=	0XE0,
	LED_ON_ERROR				,
	LED_OFF_ERROR				,
	LED_TOGGLE_ERROR				,
	LED_OKAY
} enm_led_errors_t;
/*****************************************************************************/
//LED APIs:
/*****************************************************************************/
u8 LED_init (str_gpio_config_t st_gpio_config);
u8 LED_on (str_gpio_config_t st_gpio_config);
u8 LED_off (str_gpio_config_t st_gpio_config);
u8 LED_toggle (str_gpio_config_t st_gpio_config);
/*****************************************************************************/



#endif /* LED_H_ */
