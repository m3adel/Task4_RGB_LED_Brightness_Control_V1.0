/*
 * btn.h
 *
 * Created: 6/22/2023 9:10:06 AM
 *  Author: MOHAMED ABDELSALAM
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_
/*MCAL*/
#include "gpio.h"
void BUTTON_init (str_gpio_config_t st_gpio_config);
boolean BUTTON_read (str_gpio_config_t str_gpio_config);
#endif /* BUTTON_H_ */
