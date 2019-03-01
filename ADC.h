#include "stm32f10x.h"
#include <stdint.h>

void ADCinit(void);
uint16_t readADC(uint32_t channel);