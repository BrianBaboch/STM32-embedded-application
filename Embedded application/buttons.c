#include "buttons.h"

void buttons_init(){
	//Activate clock of port C
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);
	//Puts PC13 in input mode	
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE13);
	//EXTI Configuration
	EXTI->IMR1 = (EXTI->IMR1 | EXTI_IMR1_IM13);
	EXTI->RTSR1 = (EXTI->RTSR1 & ~EXTI_RTSR1_RT13);
	EXTI->FTSR1 = (EXTI->FTSR1 | EXTI_FTSR1_FT13);
	//Activate GPIO interruption
	NVIC_EnableIRQ(40);
	//Choose PC13 as interruption source of EXTI13
	SYSCFG->EXTICR[3] = (SYSCFG->EXTICR[3] & ~SYSCFG_EXTICR4_EXTI13) 
	| (SYSCFG_EXTICR4_EXTI13_PC);
}

void EXTI15_10_IRQHandler(){
	//Acknowledge interruption
	SET_BIT(EXTI->PR1, EXTI_PR1_PIF13);
	if (GPIOB->ODR & GPIO_ODR_OD14){
		led_g_off();
	}
	else{
		led_g_on();
	}
}
