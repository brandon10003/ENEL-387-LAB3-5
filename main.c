#include "setupclock.h"
#include "LCD.h"
#include "delay.h"
#include "ADC.h"

int main() {
	uint16_t value;
	
	clockinit();
	LCDinit();
	ADCinit();
	
	while(1){
		value = readADC(0x00000001);
		printVal(value,0);
	}
}