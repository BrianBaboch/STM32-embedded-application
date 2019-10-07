#include "matrix.h"

void matrix_init(){
	//Activate clock of port B
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);
	//Activate clock of port A
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN);
	//Activate clock of port C
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);
	//Puts PA2, PA3, PA4, PA5, PA6, PA7 and PA15 in output mode
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE2) | GPIO_MODER_MODE2_0;
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE3) | GPIO_MODER_MODE3_0;
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE4) | GPIO_MODER_MODE4_0;
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE5) | GPIO_MODER_MODE5_0;
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE6) | GPIO_MODER_MODE6_0;
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE7) | GPIO_MODER_MODE7_0;
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE15) | GPIO_MODER_MODE15_0;
	//Puts PB0, PB1 and PB2 in output mode
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE0) | GPIO_MODER_MODE0_0;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE1) | GPIO_MODER_MODE1_0;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE2) | GPIO_MODER_MODE2_0;
	//Puts PC3, PC4 and PC5 in output mode
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE3) | GPIO_MODER_MODE3_0;
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE4) | GPIO_MODER_MODE4_0;
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE5) | GPIO_MODER_MODE5_0;
	//Puts PA2, PA3, PA4, PA5, PA6, PA7 and PA15 in high speed mode
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED2) | GPIO_OSPEEDR_OSPEED2_1;
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED3) | GPIO_OSPEEDR_OSPEED3_1;
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED4) | GPIO_OSPEEDR_OSPEED4_1;
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED5) | GPIO_OSPEEDR_OSPEED5_1;
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED6) | GPIO_OSPEEDR_OSPEED6_1;
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED7) | GPIO_OSPEEDR_OSPEED7_1;
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED15) | GPIO_OSPEEDR_OSPEED15_1;
	//Puts PB0, PB1 and PB2 in high speed mode
	GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED0) | GPIO_OSPEEDR_OSPEED0_1;
	GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED1) | GPIO_OSPEEDR_OSPEED1_1;
	GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED2) | GPIO_OSPEEDR_OSPEED2_1;
	//Puts PC3, PC4 and PC5 in high speed mode
	GPIOC->OSPEEDR = (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED3) | GPIO_OSPEEDR_OSPEED3_1;
	GPIOC->OSPEEDR = (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED4) | GPIO_OSPEEDR_OSPEED4_1;
	GPIOC->OSPEEDR = (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED5) | GPIO_OSPEEDR_OSPEED5_1;
	//Set RST to 0
	CLEAR_BIT(GPIOC->BSRR, GPIO_BSRR_BS3);
	//Set LAT to 1
	SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS4);
	//Set SB to 1
	SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS5);
	//Set SCK SDA to 0
	CLEAR_BIT(GPIOB->BSRR, GPIO_BSRR_BS1);
	CLEAR_BIT(GPIOA->BSRR, GPIO_BSRR_BS4);
	//Set C0-C7 to 0
	CLEAR_BIT(GPIOB->BSRR, GPIO_BSRR_BS2);
	CLEAR_BIT(GPIOA->BSRR, GPIO_BSRR_BS15);
	CLEAR_BIT(GPIOA->BSRR, GPIO_BSRR_BS2);
	CLEAR_BIT(GPIOA->BSRR, GPIO_BSRR_BS7);
	CLEAR_BIT(GPIOA->BSRR, GPIO_BSRR_BS6);
	CLEAR_BIT(GPIOA->BSRR, GPIO_BSRR_BS5);
	CLEAR_BIT(GPIOB->BSRR, GPIO_BSRR_BS0);
	CLEAR_BIT(GPIOA->BSRR, GPIO_BSRR_BS3);
	//Delay of 100 ms
	for (int i=0; i < 8000000; i++){
		asm volatile("nop");
	}
	//Set RST to 1
	SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS3);
}

void deactivate_rows(){
	ROW0(0);
	ROW1(0);
	ROW2(0);
	ROW3(0);
	ROW4(0);
	ROW5(0);
	ROW6(0);
	ROW7(0);
}

void activate_row(int row){
	switch(row){
		case 0:
			ROW0(1);
			break;
		case 1:
			ROW1(1);
			break;
		case 2:
			ROW2(1);
			break;
		case 3:
			ROW3(1);
			break;
		case 4:
			ROW4(1);
			break;
		case 5:
			ROW5(1);
			break;
		case 6:
			ROW6(1);
			break;
		case 7:
			ROW7(1);
			break;
	}
}
