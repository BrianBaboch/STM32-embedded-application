#include "uart.h"
#include "stm32l475xx.h"
#include "stm32l4xx.h"

void uart_init(int baudrate){
	//Activate clock of port B
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);
	//Disable USART
	CLEAR_BIT(USART1->CR1, USART_CR1_UE);
	//Set PB6 and PB7 to alternate mode
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE6) | GPIO_MODER_MODE6_1; 
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE7) | GPIO_MODER_MODE7_1;
	//Set PB6 as TX and PB7 as RX
	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL7) | GPIO_AFRL_AFSEL7_2 | 
		GPIO_AFRL_AFSEL7_1 | GPIO_AFRL_AFSEL7_0;

	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL6) | GPIO_AFRL_AFSEL6_2 | 
		GPIO_AFRL_AFSEL6_1 | GPIO_AFRL_AFSEL6_0;
	//Activate clock for USART1
	SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);
	//Choose PCLK as clock for USART1
	RCC->CCIPR = (RCC->CCIPR & ~RCC_CCIPR_USART1SEL);
	//Reset the serial port
	SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST);
	CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST);
	//Set Baud rate
	USART1->BRR = (USART1->BRR & ~(USART_BRR_DIV_FRACTION + 
		USART_BRR_DIV_MANTISSA)) | ((80*1000000)/baudrate);
	//Configure mode 8N1 and oversampling to 16
	USART1->CR1 = (USART1->CR1 & ~USART_CR1_M);
	USART1->CR1 = (USART1->CR1 & ~USART_CR1_OVER8);
	USART1->CR1 = (USART1->CR1 & ~USART_CR1_PCE);
	USART1->CR2 = (USART2->CR2 & ~USART_CR2_STOP);
	//Activate USART, Transmitter and receiver
	SET_BIT(USART1->CR1, USART_CR1_TE);
	SET_BIT(USART1->CR1, USART_CR1_RE);
	SET_BIT(USART1->CR1, USART_CR1_UE);
	//Enable RXNE interruption
	SET_BIT(USART1->CR1, USART_CR1_RXNEIE);
	//Activate USART1 interruption
	NVIC_EnableIRQ(37);
}

void uart_putchar(uint8_t c){
	while(!(USART1->ISR & USART_ISR_TXE));
	USART1->TDR = (USART1->TDR & ~USART_TDR_TDR) | c;
}

uint8_t uart_getchar(){
	while (!(USART1->ISR & USART_ISR_RXNE));
	return (USART1->RDR & USART_RDR_RDR);
}

void uart_puts(const uint8_t *s){
	while (*s) { 
		uart_putchar(*s);
		s++;
	}
	uart_putchar('\n');
}

void uart_gets(uint8_t *s, size_t size){
	size_t i = 0;
	while (i < size){
		s[i] = uart_getchar();
		++i;
	}
}

uint32_t uart_checksum(uint8_t *s, size_t size){
	size_t i = 0;
	uint32_t checksum=0;
	while (i < size){
		checksum = checksum + s[i];
		++i;
	}
	return checksum;
}

void USART1_IRQHandler(){
	char c;
	c = uart_getchar();
	if (c == 0xff){
		matrix_row = 0;
		matrix_col = 0;
	}
	else {
		if (matrix_color == RED){
			frame[matrix_row][matrix_col].r = c;
			matrix_color = GREEN;
		}
		else if (matrix_color == GREEN){
			frame[matrix_row][matrix_col].g = c;
			matrix_color = BLUE;
		}
		else{
			frame[matrix_row][matrix_col].b = c;
			matrix_color = RED;
			increment_counters(&matrix_row, &matrix_col);
		}

	}
}

void increment_counters(int *row, int *col){
	if (*col < 7){
		*col += 1;
	}
	else if (*row == 7){
		*row = 0;
		*col = 0;
	}
	else{
		*col = 0;
		*row +=1;
	}
}
