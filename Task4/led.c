/*
 * led.c
 *
 * Created: 4/9/2023 8:55:14 AM
 *  Author: MOHAMED ABDELSALAM
 */ 
 
#include "led.h"

void LED_init (str_gpio_config_t st_gpio_config)
{
	st_gpio_config.enm_gpio_pinAmpere = R8;
	st_gpio_config.enm_gpio_pinDirection = OUT;
	st_gpio_config.enm_gpio_pullUP		=	DISABLE;
	GPIO_init ( st_gpio_config );
}
void LED_on (str_gpio_config_t st_gpio_config){
	GPIO_write (  st_gpio_config, HIGH );
}
void LED_off (str_gpio_config_t st_gpio_config)
{
	GPIO_write (  st_gpio_config, LOW );
}
void LED_toggle (str_gpio_config_t st_gpio_config)
{
	GPIO_tog ( st_gpio_config );
}
