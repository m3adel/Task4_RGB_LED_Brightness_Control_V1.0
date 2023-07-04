/*
 * btn.h
 *
 * Created: 4/9/2023 9:10:06 AM
 *  Author: MOHAMED ABDELSALAM
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_
/*MCAL*/
#include "../../MCAL/gpio/gpio.h"
/*****************************************************************************/
/* Error list */
typedef enum 
{
	BTN_INIT_ERROR	=	0XD0,
	BTN_OKAY
} enm_btn_errors_t;
/*APIs*/
u8 BUTTON_init (str_gpio_config_t st_gpio_config);
boolean BUTTON_read (str_gpio_config_t str_gpio_config);
#endif /* BUTTON_H_ */
