#include "adc_interrupt.h"
#include "stm32f407xx.h"

//PB0 ==> ADC2 CH8
//the interrupt occurs when the conversion ends

void adc_interrupt_init() {

	/***** GPIO INIT *****/
	RCC->AHB1ENR |=(1<<1); //clock for GPIOB

	//PB0 as analog mode
	GPIOB->MODER |=(1<<0);
	GPIOB->MODER |=(1<<1);




	/***** ADC CONFIG *****/
	RCC->APB2ENR |=(1<<9);   //enable the clock for the ADC2
	ADC2->CR1 |=(1<<5);      //enable the end of conversion interrupt
	NVIC_EnableIRQ(ADC_IRQn);//enable the ADC2 interrupt in the NVIC

	//sequence start : from which channel the conversion starts (CH8)
	ADC2->SQR3   |=(1<<3);

	ADC2->SQR1   =0x0000; //how many channels we are gonna use in the conversion (1 channel in this case)
	ADC2->CR2    |=(1<<0);//enable the ADC2
}


void adc_conversion() {
	ADC2->CR2 |=(1<<1);  //enable continous conversion
	ADC2->CR2 |=(1<<30); //start the conversion
};

uint32_t conversion_read() {
	//while( !(ADC2->SR & (1<<1)) );//wait until the conversion is completed
	return ADC2->DR;//read the result of the conversion
}
