#include "matrix.h"
extern uint8_t _binary_image_raw_start;

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
	//Puts PA2, PA3, PA4, PA5, PA6, PA7 and PA15 in very high speed mode
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR) | (GPIO_OSPEEDR_OSPEED2)
	| (GPIO_OSPEEDR_OSPEED3) | (GPIO_OSPEEDR_OSPEED4)
	| (GPIO_OSPEEDR_OSPEED5) | (GPIO_OSPEEDR_OSPEED6)
	| (GPIO_OSPEEDR_OSPEED7) | (GPIO_OSPEEDR_OSPEED15);
	//Puts PB0, PB1 and PB2 in very high speed mode
	GPIOB->OSPEEDR = (GPIOB->OSPEEDR) | (GPIO_OSPEEDR_OSPEED0) 
	| (GPIO_OSPEEDR_OSPEED1) | (GPIO_OSPEEDR_OSPEED2);
	//Puts PC3, PC4 and PC5 in very high speed mode
	GPIOC->OSPEEDR = (GPIOC->OSPEEDR) | (GPIO_OSPEEDR_OSPEED3) 
	| (GPIO_OSPEEDR_OSPEED4) | (GPIO_OSPEEDR_OSPEED5);
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
	//Delay of at least 100 ms
	for (int i=0; i < 2000000; i++){
		asm volatile("nop");
	}
	//Set RST to 1
	SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS3);
	//Puts 1 in bank0
	init_bank0();
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

void send_byte(uint8_t val, int bank){
	SB(bank);
	int msk = (1 << 8);
	for (int i = 1; i <= 8; ++i){
		if(val & msk){
			SDA(1);
		}
		else{
			SDA(0);
		}
		pulse_SCK;
		msk = (1 << (8-i));
	}
}

void mat_set_row(int row, const rgb_color *val){
	int i = 7;
	while (i >= 0){
		send_byte(val[i].b, 1);
		send_byte(val[i].g, 1);
		send_byte(val[i].r, 1);
		--i;
	}
	deactivate_rows();
	for (int i=0; i < 200; i++){
		asm volatile("nop");
	}
	pulse_LAT;
	activate_row(row);
}

void init_bank0(){
	send_byte(0xFF, 0);
	pulse_LAT;
}

void delay (){
	for (int i=0; i < 2000000; i++){
		asm volatile("nop");
	}
}

void test_pixels(){
	deactivate_rows();
	rgb_color red[8];
	rgb_color green[8];
	rgb_color blue[8];
	for (int i = 0; i < 8; ++i){
		red[i].r = green[i].g = blue[i].b = 255 - i*32;
		red[i].g = red[i].b = 0;
		green[i].r = green[i].b = 0;
		blue[i].r = blue[i].g = 0;
	}

	for (int j =0; j < 8; ++j){
		mat_set_row(j , red);
		delay();
		mat_set_row(j , green);
		delay();
		mat_set_row(j , blue);
		delay();
		deactivate_rows();
	}
}

void static_image(){
	uint8_t *ptr = &_binary_image_raw_start;
	rgb_color row0[8];
	rgb_color row1[8];
	rgb_color row2[8];
	rgb_color row3[8];
	rgb_color row4[8];
	rgb_color row5[8];
	rgb_color row6[8];
	rgb_color row7[8];
	rgb_color * rows[8] = {row0, row1, row2, row3, row4, row5, row6, row7};
	for (int j = 0; j < 8; ++j){
		for(int i = 0; i < 8; ++i){
			(rows[j])[i].r = *ptr;
			++ptr;
			(rows[j])[i].g = *ptr;
			++ptr;
			(rows[j])[i].b = *ptr;
			++ptr;
		}
	}

	while (1){
		for(int i = 0; i < 8; ++i){
			mat_set_row(i, rows[i]);
		}
	}
}
