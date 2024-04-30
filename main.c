#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "fsl_gpio.h"
#include "GPIO.h"
#include "NVIC.h"
#include "MK64F12.h"



extern uint8_t g_flag_port_C;
extern uint8_t g_flag_port_A;


int main(void) {


	uint8_t state_port_C = 0;
	uint8_t state_port_A = 0;

	GPIO_init();

	/**Sets the threshold for interrupts, if the interrupt has higher priority constant that the BASEPRI, the interrupt will not be attended*/
	NVIC_set_basepri_threshold(PRIORITY_10);
	/**Enables and sets a particular interrupt and its priority*/
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ,PRIORITY_5);
	/**Enables and sets a particular interrupt and its priority*/
	NVIC_enable_interrupt_and_priotity(PORTA_IRQ,PRIORITY_4);

	NVIC_global_enable_interrupts;


    while(1) {
    	if(true == g_flag_port_C){
			if(state_port_C)
			{
				GPIO_PortSet(GPIOB, 1 << 22);/**Blue led off*/
			}
			else
			{
				GPIO_PortClear(GPIOB, 1 << 22);/**Blue led on*/
			}
			state_port_C = !state_port_C;
			g_flag_port_C = false;
		}


		if(true == g_flag_port_A){
			if(state_port_A)
			{
				GPIO_PortSet(GPIOB, 1 << 21);/**Read led off*/
			}
			else
			{
				GPIO_PortClear(GPIOB, 1 << 21);/**Read led on*/
			}
			state_port_A = !state_port_A;
			g_flag_port_A = false;
		}
    }
    return 0 ;
}
