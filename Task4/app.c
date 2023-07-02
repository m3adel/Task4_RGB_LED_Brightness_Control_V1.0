/*
 * APP
 * Created: 6/22/2023 11:14:30 PM
 * Author : MOHAMED ABDELSALAM
 */ 
/*- INCLUDES
----------------------------------------------*/
#include "app.h"

/*- LOCAL MACROS
------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-------------------------------*/

str_gpio_config_t GREEN_LED;
str_gpio_config_t SW1;

/*- GLOBAL EXTERN VARIABLES
-------------------------------*/


/*- APIs IMPLEMENTATION
-----------------------------------*/
void APP_init(void)
{

	GREEN_LED.enm_gpio_pinNumber = P3;
	GREEN_LED.enm_gpio_portNumber = F;
	SW1.enm_gpio_pinNumber = P0;
	SW1.enm_gpio_portNumber = F;
	LED_init(GREEN_LED);
	BUTTON_init (SW1);
	LED_off(GREEN_LED);
	PWM_init();
}
void APP_start(void)
{
		static u8 Counter = 0;
		while (BUTTON_read(SW1)== TRUE );
		while (BUTTON_read(SW1)== FALSE );
		(Counter)++;
	
	if (Counter==4)
		{
			Counter = 0;
		}
		else
		{
			//nothing
		}
		switch(Counter)
		{
			case 0:
			PWM_start(30);
			break;
			case 1:
			PWM_start(60);	
			break;
			case 2: 
			PWM_start(90);
			break;
			case 3:
			PWM_start(0);	
			break;
			default:
			//
			break;					
		}

}

