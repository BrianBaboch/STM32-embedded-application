#include "led.h"
#include "stm32l475xx.h"
#include "stm32l4xx.h"
#include <stdint.h>

void led_init(){
	//Activate clock for for ports B and C
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN_Msk);
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN_Msk);
	//Puts PB14 in output mode
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE14_Msk) | GPIO_MODER_MODE14_0;
}

void led_g_on(){
	//Sets 1 on the output of PB14
	SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS14_Msk);
}

void led_g_off(){
	//Sets 0 on the output of PB14
	SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR14_Msk);
}

void led(int state){
	if (state == LED_YELLOW){
		//Puts PC9 in output mode and sets its output to 1 
		GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | GPIO_MODER_MODE9_0;
		SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS9_Msk);
	}
	else if (state == LED_BLUE){
		//Puts PC9 in output mode and sets its output to 1 
		GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | GPIO_MODER_MODE9_0;
		SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR9_Msk);
	}
	else if (state == LED_OFF){
		//Puts PC9 in input mode
		GPIOC->MODER = GPIOC->MODER & ~GPIO_MODER_MODE9_Msk;
	}
}

