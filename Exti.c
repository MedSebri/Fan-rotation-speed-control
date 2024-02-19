#include "stm32f407xx.h"


void pa0_exti_init() {
	RCC->AHB1ENR |=(1<<0);       //enable clock access for GPIOA
	RCC->APB2ENR |=(1<<14);      //enable clock for syscfg
	//configure PA0 as input :   Done by default
	//select portA for EXTI0 :   Done by default : check SYSCFG_EXTICR1
	EXTI->IMR  |=(1<<0);         //unmask EXTI0
	EXTI->FTSR |=(1<<0);         //select risng edge
	NVIC_EnableIRQ(EXTI0_IRQn);  //enable EXTI line in NVIC
}
