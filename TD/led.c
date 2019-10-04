#include "led.h"
#include <stdint.h>

#define AHB2_RCC (*(volatile uint32_t *) (0x4c + 0x40021000))
#define GPIOB_BSRR (*(volatile uint32_t *) (0x18 + 0x48000400))
#define GPIOB_MODER (*(volatile uint32_t *) (0x00 + 0x48000400))
#define GPIOC_MODER (*(volatile uint32_t *) (0x00 + 0x48000800))
#define GPIOC_BSRR (*(volatile uint32_t *) (0x18 + 0x48000800))

void led_init(){
	AHB2_RCC = AHB2_RCC | (3<<1);
	GPIOB_MODER = (GPIOB_MODER & ~(3<<28)) | (1<<28);
}

void led_g_on(){
	GPIOB_BSRR = GPIOB_BSRR | (1<<14);
}

void led_g_off(){
	GPIOB_BSRR = GPIOB_BSRR | (1<<30);
}

void led(char state){
	enum values {LED_OFF = 0, LED_YELLOW = 1, LED_BLUE = 2};
	if (state == LED_YELLOW){
		GPIOC_MODER = (GPIOC_MODER & ~(3<<18)) | (1<<18);
		GPIOC_BSRR = GPIOC_BSRR | (1<<9);
	}
	else if (state == LED_BLUE){
		GPIOC_MODER = (GPIOC_MODER & ~(3<<18)) | (1<<18);
		GPIOC_BSRR = GPIOC_BSRR | (1<<25);
	}
	else if (state == LED_OFF){
		GPIOC_MODER = (GPIOC_MODER & ~(3<<18));
	}
}

