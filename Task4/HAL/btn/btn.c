/*
 * bbtn.c
 *
 * Created: 4/9/2023 9:10:35 AM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "btn.h"
/*
 Name: BUTTON_init
 Input: str_gpio_config_t st_gpio_config
 Output: u8
 Description: Function to toggle Pin value.
*/
u8 BUTTON_init (str_gpio_config_t st_gpio_config)
{
	u8 u8_l_ret;
	st_gpio_config.enm_gpio_pinAmpere = R8;
	st_gpio_config.enm_gpio_pinDirection = IN;
	st_gpio_config.enm_gpio_pullUP		=	ENABLE;
		if(GPIO_OKAY == GPIO_init ( st_gpio_config ))
	{
		u8_l_ret = BTN_OKAY;
	}
	else
	{
		u8_l_ret = BTN_INIT_ERROR;
	}
	return u8_l_ret;
}
/*
 Name: BUTTON_read
 Input: str_gpio_config_t st_gpio_config
 Output: boolean
 Description: Function to toggle Pin value.
*/
boolean BUTTON_read (str_gpio_config_t st_gpio_config)
{
	
	boolean bool_l_return;
	bool_l_return = GPIO_read ( st_gpio_config );
	return bool_l_return;
}
