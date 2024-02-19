

#ifndef ADC_INTERRUPT_H_
#define ADC_INTERRUPT_H_
#include <stdint.h>
void adc_interrupt_init();
void adc_conversion();
uint32_t conversion_read();

#endif /* ADC_INTERRUPT_H_ */
