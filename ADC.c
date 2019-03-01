#include "ADC.h"

void ADCinit() {
	ADC1->CR2 = 0X00000001;
}
uint16_t readADC(uint32_t channel){
	ADC1->SQR3 |= channel;
	ADC1->CR2 |= 0X00000001;
	while(~(ADC1->SR & 0X00000002));
	
	return (ADC1->DR);
}