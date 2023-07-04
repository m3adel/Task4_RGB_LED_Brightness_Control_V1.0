/*
 * led.c
 *
 * Created: 4/9/2023 8:55:14 AM
 *  Author: MOHAMED ABDELSALAM
 */ 
 
#include "led.h"
/*
 Name: LED_init
 Input: str_gpio_config_t st_gpio_config
 Output: u8
 Description: Function to initialize Pin value.
*/
u8 LED_init (str_gpio_config_t st_gpio_config)
{
	u8 u8_l_ret;
	st_gpio_config.enm_gpio_pinAmpere = R8;
	st_gpio_config.enm_gpio_pinDirection = OUT;
	st_gpio_config.enm_gpio_pullUP		=	DISABLE;
	if(GPIO_OKAY == GPIO_init ( st_gpio_config ))
	{
		u8_l_ret = LED_OKAY;
	}
	else
	{
		u8_l_ret = LED_INIT_ERROR;
	}
	return u8_l_ret;
}
u8 LED_on (str_gpio_config_t st_gpio_config){
	u8 u8_l_ret;
		if(GPIO_OKAY == GPIO_write (  st_gpio_config, HIGH ))
	{
		u8_l_ret = LED_OKAY;
	}
	else
	{
		u8_l_ret = LED_INIT_ERROR;
	}
	return u8_l_ret;
}
u8 LED_off (str_gpio_config_t st_gpio_config)
{
		u8 u8_l_ret;
		if(GPIO_OKAY == GPIO_write (  st_gpio_config, LOW ))
	{
		u8_l_ret = LED_OKAY;
	}
	else
	{
		u8_l_ret = LED_INIT_ERROR;
	}
	return u8_l_ret;
}
u8  LED_toggle (str_gpio_config_t st_gpio_config)
{
			u8 u8_l_ret;
		if(GPIO_OKAY == GPIO_tog ( st_gpio_config ))
	{
		u8_l_ret = LED_OKAY;
	}
	else
	{
		u8_l_ret = LED_INIT_ERROR;
	}
	return u8_l_ret;
}
