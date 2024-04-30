/**
	\file
	\brief
		This is the source file for the GPIO device driver for Kinetis K64.
		It contains all the implementation for configuration functions and runtime functions.
		i.e., this is the application programming interface (API) for the GPIO peripheral.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	5/09/2021
	\todo
	    Interrupts are not implemented in this API implementation.
 */
#ifndef GPIO_H_
#define GPIO_H_


#include "stdint.h"


/** Constant that represent the clock enable for GPIO A */
#define GPIO_CLOCK_GATING_PORTA 0x00000200
/** Constant that represent the clock enable for GPIO B */
#define GPIO_CLOCK_GATING_PORTB 0x00000400
/** Constant that represent the clock enable for GPIO C */
#define GPIO_CLOCK_GATING_PORTC 0x00000800
/** Constant that represent the clock enable for GPIO D  */
#define GPIO_CLOCK_GATING_PORTD 0x00001000
/** Constant that represent the clock enable for GPIO E */
#define GPIO_CLOCK_GATING_PORTE 0x00002000


/** Selects a pullup resistor */
#define GPIO_PS    0x00000001
/** Enables the pulldown or pullup resistors*/
#define GPIO_PE    0x00000002
/** Selects slow or fast slew rate */
#define GPIO_SRE   0x00000004
/** Enables the passive filter */
#define GPIO_PFE   0x00000010
/** Enables the open drain  */
#define GPIO_ODE   0x00000020
/** Selects between low drive strength and high drive strength */
#define GPIO_DSE   0x00000040
/** Selects alternative function 1 (GPIO) */
#define GPIO_MUX1  0x00000100
/** Selects alternative function 2 */
#define GPIO_MUX2  0x00000200
/** Selects alternative function 3 */
#define GPIO_MUX3  0x00000300
/** Selects alternative function 4 */
#define GPIO_MUX4  0x00000400
/** Selects alternative function 5 */
#define GPIO_MUX5  0x00000500
/** Selects alternative function 6 */
#define GPIO_MUX6  0x00000600
/** Selects alternative function 7 */
#define GPIO_MUX7  0x00000700
/** Sets DMA request on rising edge.*/
#define DMA_RISING_EDGE    0x00010000
/** Sets DMA request on falling edge.*/
#define DMA_FALLING_EDGE   0x00020000
/** Sets DMA request on either edge.*/
#define DMA_EITHER_EDGE    0x00030000
/** Sets Interrupt when logic 0.*/
#define INTR_LOGIC0        0x00080000
/** Sets Interrupt on rising-edge.*/
#define INTR_RISING_EDGE   0x00090000
/** Sets Interrupt on falling-edge.*/
#define INTR_FALLING_EDGE  0x000A0000
/** Sets Interrupt on either edge.*/
#define INTR_EITHER_EDGE   0x000B0000
/** Sets Interrupt when logic 1.*/
#define INTR_LOGIC1        0x000C0000



#define SW3_INT PORTA_IRQHandler

#define SW2_INT PORTC_IRQHandler


typedef struct
{
	uint8_t flag_port_a : 1;
	uint8_t flag_port_b : 1;
	uint8_t flag_port_c : 1;
	uint8_t flag_port_d : 1;
	uint8_t flag_port_e : 1;
} gpio_interrupt_flags_t;




/*! This definition is used to configure whether a pin is an input or an output*/
typedef enum {GPIO_INPUT,/*!< Definition to configure a pin as input */
			  GPIO_OUTPUT /*!< Definition to configure a pin as output */
			 }gpio_port_direction_t;


/*! These constants are used to select an specific port in the different API functions*/
typedef enum{GPIO_A, /*!< Definition to select GPIO A */
			 GPIO_B, /*!< Definition to select GPIO B */
			 GPIO_C, /*!< Definition to select GPIO C */
			 GPIO_D, /*!< Definition to select GPIO D */
			 GPIO_E, /*!< Definition to select GPIO E */
			 GPIO_F  /*!< Definition to select GPIO F */
			} gpio_port_name_t;

/*! This data type is used to configure the pin control register*/
typedef const uint32_t gpio_pin_control_register_t;



uint8_t GPIO_clear_irq_status(gpio_port_name_t gpio);

uint8_t GPIO_get_irq_status(gpio_port_name_t gpio);

void GPIO_init(void);

#endif /* GPIO_H_ */
