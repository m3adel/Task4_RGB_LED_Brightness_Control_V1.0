/*
 * led.h
 *
 * Created: 4/9/2023 8:54:47 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef LED_H_
#define LED_H_
/*****************************************************************************/
#include "gpio.h"

/*****************************************************************************/
//LED APIs:
/*****************************************************************************/
void LED_init (str_gpio_config_t st_gpio_config);
void LED_on (str_gpio_config_t st_gpio_config);
void LED_off (str_gpio_config_t st_gpio_config);
void LED_toggle (str_gpio_config_t st_gpio_config);
/*****************************************************************************/



#endif /* LED_H_ */
