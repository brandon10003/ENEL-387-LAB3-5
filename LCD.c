#include "LCD.h"
#include "delay.h"
void LCDinit() {
	delay(360000);
	commandToLCD(LCD_8B2L);
	delay(120000);
	commandToLCD(LCD_8B2L);
	delay(120000);
	commandToLCD(LCD_8B2L);
	delay(120000);
	commandToLCD(LCD_8B2L);
	delay(120000);
	commandToLCD(LCD_DCB);
	delay(120000);
	commandToLCD(LCD_CLR);
	delay(120000);
	commandToLCD(LCD_MCR);
	delay(240000);
}
void commandToLCD(uint8_t data) {
	GPIOB->BSRR = LCD_CM_ENA; //RS low, E high
	
	GPIOC->ODR &= 0xFF00; //GOOD: clears the low bits without affecting high bits
	GPIOC->ODR |= data; //GOOD: only affects lowest 8 bits of Port C
	delay(8000);
	GPIOB->BSRR = LCD_CM_DIS; //RS low, E low
	delay(80000);
}
void dataToLCD(uint8_t data) {
	GPIOB->BSRR = LCD_DM_ENA; //RS low, E high
	
	GPIOC->ODR &= 0xFF00; //GOOD: clears the low bits without affecting high bits
	GPIOC->ODR |= data; //GOOD: only affects lowest 8 bits of Port C
	delay(8000);
	GPIOB->BSRR = LCD_DM_DIS; //RS low, E low
	delay(80000);
}
uint8_t hexToAsc(uint8_t hex) {
	if (hex < 0xA)
		return (hex + 0x30);
	else
		return (hex + 0x37);
}
void printVal(uint32_t val, uint8_t line) {
	uint8_t current;
	int control;
	
	if (line == 0)
		commandToLCD(LCD_LN1);
	else
		commandToLCD(LCD_LN2);
	
	dataToLCD('0');
	dataToLCD('x');
	
	control= 7;
	while(control>=0)
	{
		current = ((val >> (4*control)) & 0x0000000F);
		current = hexToAsc(current);
		dataToLCD(current);
		control = control-1;
	}
}