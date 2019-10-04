#include "led.h"
#include <stdint.h>
#include <stm32l475xx.h>

#define AHB2_RCC (*(volatile uint32_t *) (0x4c + 0x40021000))
#define GPIOB_BSRR (*(volatile uint32_t *) (0x18 + 0x48000400))
#define GPIOB_MODER (*(volatile uint32_t *) (0x00 + 0x48000400))
#define GPIOC_MODER (*(volatile uint32_t *) (0x00 + 0x48000800))
#define GPIOC_BSRR (*(volatile uint32_t *) (0x18 + 0x48000800))



void led_init(){
	//Activate clock for for ports B and C
	AHB2_RCC = AHB2_RCC | (3<<1);
	//Puts PB14 in output mode
	SET_BIT(GPIOB_MODER,GPIO_MODE_14_0);
	GPIOB_MODER = (GPIOB_MODER & ~(3<<28)) | (1<<28);
}

void led_g_on(){
	//Sets 1 on the output of PB14
	GPIOB_BSRR = GPIOB_BSRR | (1<<14);
}

void led_g_off(){
	//Sets 0 on the output of PB14
	GPIOB_BSRR = GPIOB_BSRR | (1<<30);
}

void led(int state){
	if (state == LED_YELLOW){
		//Puts PC9 in output mode and sets its output to 1 
		GPIOC_MODER = (GPIOC_MODER & ~(3<<18)) | (1<<18);
		GPIOC_BSRR = GPIOC_BSRR | (1<<9);
	}
	else if (state == LED_BLUE){
		//Puts PC9 in output mode and sets its output to 1 
		GPIOC_MODER = (GPIOC_MODER & ~(3<<18)) | (1<<18);
		GPIOC_BSRR = GPIOC_BSRR | (1<<25);
	}
	else if (state == LED_OFF){
		//Puts PC9 in input mode
		GPIOC_MODER = (GPIOC_MODER & ~(3<<18));
	}
}

