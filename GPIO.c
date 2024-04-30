/**
	\file
	\brief
		This is the source file for the GPIO device driver for Kinetis K64.
		It contains all the implementation for configuration functions and runtime functions.
		i.e., this is the application programming interface (API) for the GPIO peripheral.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	19/02/2021
	\todo
	    Interrupts are not implemented in this API implementation.
 */
#include "MK64F12.h"
#include "GPIO.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_clock.h"
#include <stdbool.h>


uint8_t g_flag_port_C = false;
uint8_t g_flag_port_A = false;


void PORTC_IRQHandler(void)
{
	g_flag_port_C = true;
	GPIO_PortClearInterruptFlags(GPIOC, 0xFFFF);

}


void PORTA_IRQHandler(void)
{
	while(1);

}

void GPIO_init(void)
{
	gpio_pin_config_t gpio_input_config = {
			        kGPIO_DigitalInput,
			        0,
			    };

	gpio_pin_config_t gpio_output_config = {
			        kGPIO_DigitalOutput,
			        1,
			    };

	const port_pin_config_t button_config = {
			kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
			kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
			kPORT_PassiveFilterEnable,                              /* Passive filter is disabled */
			kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
			kPORT_HighDriveStrength,                                 /* High drive strength is configured */
			kPORT_MuxAsGpio,                                         /* Pin is configured as PTA4 */
			kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
		  };


	CLOCK_EnableClock(kCLOCK_PortA);
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortC);

	GPIO_PinInit(GPIOC, 6u, &gpio_input_config);
	PORT_SetPinConfig(PORTC, 6u, &button_config);
	PORT_SetPinInterruptConfig(PORTC, 6u, kPORT_InterruptFallingEdge);

	GPIO_PinInit(GPIOA, 4u, &gpio_input_config);
	PORT_SetPinConfig(PORTA, 4u, &button_config);
	PORT_SetPinInterruptConfig(PORTA, 4u, kPORT_InterruptFallingEdge);

	PORT_SetPinMux(PORTB, 22u, kPORT_MuxAsGpio);
	GPIO_PinInit(GPIOB, 22u, &gpio_output_config);

	PORT_SetPinMux(PORTB, 21u, kPORT_MuxAsGpio);
	GPIO_PinInit(GPIOB, 21u, &gpio_output_config);



}
