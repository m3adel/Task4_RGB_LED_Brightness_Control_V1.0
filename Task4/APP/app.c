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
		static u8 app_u8_l_Counter = STATE_1;
		while (BUTTON_read(SW1)== TRUE );
		while (BUTTON_read(SW1)== FALSE );
		(app_u8_l_Counter)++;
	
	if (app_u8_l_Counter == STATE_NUMBER)
		{
			app_u8_l_Counter = STATE_1;
		}
		else
		{
			//do nothing
		}
		switch(app_u8_l_Counter)
		{
			case STATE_1:
			PWM_start(PERCENT_30);
			case STATE_2:
			PWM_start(PERCENT_60);	
			case STATE_3: 
			PWM_start(PERCENT_90);
			case STATE_4:
			PWM_start(PERCENT_ZERO);	
			break;
			default:
			//
			break;					
		}

}

