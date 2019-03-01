 #include "stm32f10x.h"
 
 void clockinit(void) {
	 uint32_t temp = 0x00;
    //If you hover over the RCC you can go to the definition and then
    //see it is a structure of all the RCC registers.  Then you can
    //simply assign a value.
    RCC->CFGR = 0x07050002;     // Output PLL/2 as MCO,
                                // PLLMUL X3, PREDIV1 is PLL input

    RCC->CR =  0x01010081;      // Turn on PLL, HSE, HSI

    while (temp != 0x02000000)  // Wait for the PLL to stabilize
    {
        temp = RCC->CR & 0x02000000; //Check to see if the PLL lock bit is set
    }

    //Enable peripheral clocks for various ports and subsystems
    //Bit 4: Port C Bit3: Port B Bit 2: Port A
    RCC->APB2ENR |=  RCC_APB2ENR_IOPAEN ;
		RCC->APB2ENR |=  RCC_APB2ENR_IOPBEN ;
		RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN ;
		RCC->APB2ENR |=  RCC_APB2ENR_AFIOEN	;
		RCC->APB2ENR |=  RCC_APB2ENR_ADC1EN ;

    // Write a 0xB ( 1011b ) into the configuration and mode bits for PA8 (AFIO)
    //GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0 ;
    //GPIOA->CRH &= ~GPIO_CRH_CNF8_0 ;
		
		//CNF FOR LCD
		
		GPIOB->CRL |= GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0 ;
		GPIOB->CRL &= ~GPIO_CRL_CNF0_0 & ~GPIO_CRL_CNF0_1 ;
		
		GPIOB->CRL |= GPIO_CRL_MODE1_1 | GPIO_CRL_MODE1_0 ;
		GPIOB->CRL &= ~GPIO_CRL_CNF1_0 & ~GPIO_CRL_CNF1_1 ;
		
		GPIOB->CRL |= GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0 ;
		GPIOB->CRL &= ~GPIO_CRL_CNF5_0 & ~GPIO_CRL_CNF5_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF0_0 & ~GPIO_CRL_CNF0_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE1_1 | GPIO_CRL_MODE1_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF1_0 & ~GPIO_CRL_CNF1_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE2_1 | GPIO_CRL_MODE2_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF2_0 & ~GPIO_CRL_CNF2_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE3_1 | GPIO_CRL_MODE3_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF3_0 & ~GPIO_CRL_CNF3_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE4_1 | GPIO_CRL_MODE4_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF4_0 & ~GPIO_CRL_CNF4_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF5_0 & ~GPIO_CRL_CNF5_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF6_0 & ~GPIO_CRL_CNF6_1 ;
		
		GPIOC->CRL |= GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0 ;
		GPIOC->CRL &= ~GPIO_CRL_CNF7_0 & ~GPIO_CRL_CNF7_1 ;
		
		//CNF FOR ADC
		
		GPIOA->CRL |= GPIO_CRL_MODE1_1 | GPIO_CRL_MODE1_0 | GPIO_CRL_CNF1_0 | GPIO_CRL_CNF1_1 ;
		GPIOA->CRL &= GPIO_CRL_CNF1_0 & GPIO_CRL_CNF1_1 ;
		
		GPIOA->CRL |= GPIO_CRL_MODE2_1 | GPIO_CRL_MODE2_0 ;
		GPIOA->CRL &= ~GPIO_CRL_CNF2_0 & ~GPIO_CRL_CNF2_1 ;
 }