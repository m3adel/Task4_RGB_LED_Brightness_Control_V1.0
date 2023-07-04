
#ifndef GPIO_H_
#define GPIO_H_
#include "../../LIB/common.h"
//#include "TM4C123.h"

/* Port Numbers */
typedef enum 
{
	A, B, C, D,	E,	F
} enm_gpio_portNumber_t;

/* Pin Numbers */
typedef enum 
{
	P0,	P1,	P2,	P3,	P4,	P5,	P6,	P7
} enm_gpio_pinNumber_t;

/* Pin Directions */
typedef enum 
{
	IN = FALSE,	
	OUT = TRUE
} enm_gpio_pinDirection_t;


/* Pin Values */
typedef enum 
{
	LOW = FALSE,
	HIGH = TRUE
} enm_gpio_pinWritevalue_t;

/* Pin GPIO mA Drive Select */
typedef enum 
{
	R2,
	R4,
	R8
} enm_gpio_pinAmpere_t;

/* Pin GPIO Pull Down resistor */
typedef enum 
{
	ENABLE,
	DISABLE
} enm_gpio_pullUP_t;
/*****************************************************************************/
/* Error list */
typedef enum 
{
	GPIO_PIN_INIT_ERROR	=		0XF0,
	GPIO_PIN_WRITE_ERROR				,
	GPIO_PIN_TOGGLE_ERROR				,
	GPIO_PORT_INIT_ERROR				,
	GPIO_PORT_READ_ERROR				,
	GPIO_PORT_WRITE_ERROR				,
	GPIO_PIN_DINIT_ERROR				,
	GPIO_HIGHER_NIPPLE_ERROR		,
	GPIO_LOWER_NIPPLE_ERROR			,
	GPIO_OKAY
} enm_gpio_errors_t;
/*****************************************************************************/
typedef struct
{
	enm_gpio_portNumber_t	enm_gpio_portNumber;
	enm_gpio_pinNumber_t		enm_gpio_pinNumber;
	enm_gpio_pinDirection_t	enm_gpio_pinDirection;
	enm_gpio_pinAmpere_t						enm_gpio_pinAmpere;
	enm_gpio_pullUP_t						enm_gpio_pullUP;
}str_gpio_config_t;
/*APIs*/
u8 GPIO_init ( str_gpio_config_t str_gpio_config );
u8 GPIO_write ( str_gpio_config_t str_gpio_config, enm_gpio_pinWritevalue_t	enm_gpio_pinWritevalue );
u8 GPIO_read ( str_gpio_config_t str_gpio_config );
u8 GPIO_tog ( str_gpio_config_t str_gpio_config );
u8 GPIO_dinit ( str_gpio_config_t str_gpio_config );

#endif /*GPIO_H_*/
