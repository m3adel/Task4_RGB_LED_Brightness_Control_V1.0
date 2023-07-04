


/*----------------------------------------------------------/
/- INCLUDES -----------------------------------------------/
/----------------------------------------------------------*/
#include "gpio.h"
/*---------------------------------------------------------/
/- LOCAL MACROS ------------------------------------------/
/---------------------------------------------------------*/
/*Module Registers*/
#define GPIO_Port_APB(x)		(x<4?((0x40004000)+((x)*(0x1000))):((0x40024000)+((x-4)*(0x1000))))
/*
#define GPIO_Port_APB_A			(*((volatile uint32_t*)(0x40004000)))
#define GPIO_Port_APB_B			(*((volatile uint32_t*)(0x40005000)))
#define GPIO_Port_APB_C			(*((volatile uint32_t*)(0x40006000)))
#define GPIO_Port_APB_D			(*((volatile uint32_t*)(0x40007000)))
#define GPIO_Port_APB_E			(*((volatile uint32_t*)(0x40024000)))
#define GPIO_Port_APB_F			(*((volatile uint32_t*)(0x40025000)))
*/

#define RCGCGPIO				(*((volatile uint32_t*)((0x400FE000)+(0x608))))
#define GPIODATA(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x3FC))))
#define GPIODIR(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x400))))
#define GPIOIS(x)				(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x404))))
#define GPIOIBE(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x408))))
#define GPIOIEV(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x40C))))
#define GPIOIM(x)			``(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x410))))
#define GPIORIS(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x414))))
#define GPIOMIS(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x418))))
#define GPIOICR(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x41C))))
#define GPIOAFSEL(x)		(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x420))))
#define GPIODR2R(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x500))))
#define GPIODR4R(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x504))))
#define GPIODR8R(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x508))))
#define GPIOODR(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x50C))))
#define GPIOPUR(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x510))))
#define GPIOPDR(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x514))))
#define GPIOSLR(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x518))))
#define GPIODEN(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x51C))))
#define GPIOLOCK(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x520))))
#define GPIOCR(x)				(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x524))))
#define GPIOAMSEL(x)			(*((volatile uint32_t*)((GPIO_Port_APB(x))+(0x52C))))
/*Macros*/
#define Port_F_Run_Mode_Clock				(5)
#define Port_E_Run_Mode_Clock				(4)
#define Port_D_Run_Mode_Clock				(3)
#define Port_C_Run_Mode_Clock				(2)
#define Port_B_Run_Mode_Clock				(1)
#define Port_A_Run_Mode_Clock				(0)
#define UNLOCK			(0x4C4F434B)
#define RESEN_IDX			(1)
#define INTEN_IDX			(0)
#define WDTRIS_IDX			(0)
#define STALL_IDX			(8)

/*----------------------------------------------------------/
/- STRUCTS AND UNIONS -------------------------------------/
/----------------------------------------------------------*/

/*---------------------------------------------------------/
/- GLOBAL STATIC VARIABLES -------------------------------/
/---------------------------------------------------------*/



/*---------------------------------------------------------/
/- LOCAL FUNCTIONS IMPLEMENTATION ------------------------/
/---------------------------------------------------------*/


/*******************************************************************************************************************************************************************/
/*
 Name: GPIO_init
 Input: str_gpio_config_t str_gpio_config
 Output: u8
 Description: Function to initialize Pin direction.
*/

u8 GPIO_init ( str_gpio_config_t str_gpio_config )
{
	u8 u8_l_ret = GPIO_OKAY;
	//step 1:
			SET_BIT( RCGCGPIO , str_gpio_config.enm_gpio_portNumber );    // 1) Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register
		//step 2:
			GPIOLOCK(str_gpio_config.enm_gpio_portNumber) = UNLOCK;	// 2) unlock GPIO Port
			SET_BIT( GPIOCR(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber );			// allow changes to the data being written to the corresponding bit of the GPIOAFSEL, GPIOPUR, GPIOPDR, or GPIODEN registers
		//step 3:
			if (str_gpio_config.enm_gpio_pinDirection == OUT)
			{
				SET_BIT( GPIODIR(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber );    //Set Initial PortA Direction
			}
			else if (str_gpio_config.enm_gpio_pinDirection == IN)
			{
				CLR_BIT( GPIODIR(str_gpio_config.enm_gpio_portNumber) ,str_gpio_config.enm_gpio_pinNumber);   //clear Initial PortA Direction
			}
			else
			{
				u8_l_ret = GPIO_PIN_INIT_ERROR;
			}
		//step 4:
		GPIOAFSEL(str_gpio_config.enm_gpio_portNumber) = 0x00;	// 4) disable alt funct on P7-0
		//step 5:
		/*
		5) Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R
			registers.
		*/
			if (str_gpio_config.enm_gpio_pinAmpere == R2)
			{
				SET_BIT( GPIODR2R(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber ); 			
			}
			else if (str_gpio_config.enm_gpio_pinAmpere == R4)
			{
				SET_BIT( GPIODR4R(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber );
			}
			else if (str_gpio_config.enm_gpio_pinAmpere == R8)
			{
				SET_BIT( GPIODR8R(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber );    
			}
			else
			{
				u8_l_ret = GPIO_PIN_INIT_ERROR;
			}
		//step 6:
			if (str_gpio_config.enm_gpio_pullUP == ENABLE)
			{
				SET_BIT( GPIOPUR(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber ); 			
			}
			else if (str_gpio_config.enm_gpio_pullUP == DISABLE)
			{
				CLR_BIT( GPIOPUR(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber );
			}
			else
			{
				u8_l_ret = GPIO_PIN_INIT_ERROR;
			}
			//step 7:
			GPIOAMSEL(str_gpio_config.enm_gpio_portNumber) = 0x00;	// 3) disable analog funct on P7-0
			//step 8:
			SET_BIT( GPIODEN(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber );
	
	

	return u8_l_ret;
}


/*******************************************************************************************************************************************************************/
/*
 Name: GPIO_write
 Input: str_gpio_config_t str_gpio_config
 Output: u8
 Description: Function to set Pin value.
*/
u8 GPIO_write ( str_gpio_config_t str_gpio_config, enm_gpio_pinWritevalue_t	enm_gpio_pinWritevalue )
{
	u8 u8_l_ret = GPIO_OKAY;
	if (enm_gpio_pinWritevalue == HIGH)
	{
		SET_BIT( GPIODATA(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber );	//Set value of pinNumber in PortA
	}
	else if (enm_gpio_pinWritevalue == LOW)
	{
		CLR_BIT( GPIODATA(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber );	//clear value of pinNumber in PortA
	}

	else
	{
	u8_l_ret = GPIO_PIN_WRITE_ERROR;
	}
	
	return u8_l_ret;
}
u8 GPIO_read ( str_gpio_config_t str_gpio_config)
{
	u8 u8_l_ret = GPIO_OKAY;	
	u8_l_ret = GET_BIT_STATUS(GPIODATA(str_gpio_config.enm_gpio_portNumber),str_gpio_config.enm_gpio_pinNumber);//(GPIODATA(str_gpio_config.enm_gpio_portNumber))&(1<<str_gpio_config.enm_gpio_pinNumber);
	return u8_l_ret;
}

/*
 Name: GPIO_tog
 Input: str_gpio_config_t str_gpio_config
 Output: u8
 Description: Function to toggle Pin value.
*/

u8 GPIO_tog ( str_gpio_config_t str_gpio_config )
{
	u8 u8_l_ret = GPIO_OKAY;
	TOG_BIT( GPIODATA(str_gpio_config.enm_gpio_portNumber) , str_gpio_config.enm_gpio_pinNumber ); 	//toggle value of pinNumber in PortA
	return u8_l_ret;
}
/*
 Name: GPIO_dinit
 Input: str_gpio_config_t str_gpio_config
 Output: u8
 Description: Function to dinitialize Pin value.
*/
u8 GPIO_dinit ( str_gpio_config_t str_gpio_config )
{
	u8 u8_l_ret = GPIO_OKAY;

		//step 1:
			CLR_BIT( RCGCGPIO , str_gpio_config.enm_gpio_portNumber );    // 1) Disable the clock to the port by setting the appropriate bits in the RCGCGPIO register
		//step 2:
			GPIOLOCK(A) = UNLOCK;	// 2) unlock GPIO Port
			SET_BIT( GPIOCR(A) , str_gpio_config.enm_gpio_pinNumber );			// allow changes to the data being written to the corresponding bit of the GPIOAFSEL, GPIOPUR, GPIOPDR, or GPIODEN registers
		//step 3:
				CLR_BIT( GPIODIR(str_gpio_config.enm_gpio_portNumber) ,str_gpio_config.enm_gpio_pinNumber);   //clear Initial PortA Direction
		//step 4:
		GPIOAFSEL(A) = 0x00;	// 4) disable alt funct on P7-0
		//step 5:
		/*
		5) Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R
			registers.
		*/
			if (str_gpio_config.enm_gpio_pinAmpere == R2)
			{
				CLR_BIT( GPIODR2R(A) , str_gpio_config.enm_gpio_pinNumber ); 			
			}
			else if (str_gpio_config.enm_gpio_pinAmpere == R4)
			{
				CLR_BIT( GPIODR4R(A) , str_gpio_config.enm_gpio_pinNumber );
			}
			else if (str_gpio_config.enm_gpio_pinAmpere == R8)
			{
				CLR_BIT( GPIODR8R(A) , str_gpio_config.enm_gpio_pinNumber );    
			}
			else
			{
				u8_l_ret = GPIO_PIN_DINIT_ERROR;
			}
		//step 6:
				CLR_BIT( GPIOPUR(A) , str_gpio_config.enm_gpio_pinNumber );
			//step 7:
			GPIOAMSEL(A) = 0x00;	// 3) disable analog funct on P7-0
			//step 8:
			CLR_BIT( GPIODEN(A) , str_gpio_config.enm_gpio_pinNumber );
			return u8_l_ret;
}
