#include "uart.h"
#include "stm32l475xx.h"
#include "stm32l4xx.h"
void uart_init(){
	//Activate clock of port B
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN_Msk);
	//Disable USART
	CLEAR_BIT(USART1->CR1, USART_CR1_UE_Msk);
	//Set PB6 and PB7 to alternate mode
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE6_Msk) | GPIO_MODER_MODE6_1; 
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE7_Msk) | GPIO_MODER_MODE7_1;
	//Set PB6 as TX and PB7 as RX
	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL7_Msk) | GPIO_AFRL_AFSEL7_2;
//	GPIOB->AFR[0] |= 0x01 << (6 * 4);
//	GPIOB->AFR[0] |= 0x01 << (7 * 4);

	//Activate clock for USART1
	SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN_Msk);
	//Choose PCLK as clock for USART1
	RCC->CCIPR = (RCC->CCIPR & ~RCC_CCIPR_USART1SEL_Msk);
	//Reset the serial port
	SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST_Msk);
	//Set Baud rate to 115200 bauds
	USART1->BRR = (USART1->BRR & ~(USART_BRR_DIV_FRACTION_Msk + 
		USART_BRR_DIV_MANTISSA_Msk)) | 0x271;
//0x2b6
	//Configure mode 8N1 and oversampling to 16
	USART1->CR1 = (USART1->CR1 & ~USART_CR1_M_Msk);
	USART1->CR1 = (USART1->CR1 & ~USART_CR1_OVER8_Msk);
	USART1->CR1 = (USART1->CR1 & ~USART_CR1_PCE);
	//Activate USART, Transmitter and receiver
	SET_BIT(USART1->CR1, USART_CR1_TE_Msk);
	SET_BIT(USART1->CR1, USART_CR1_RE_Msk);
	SET_BIT(USART1->CR1, USART_CR1_UE_Msk);
}

void uart_putchar(uint8_t c){
	while(!(USART1->ISR & USART_ISR_TXE)){
	}
	USART1->TDR = (USART1->TDR & ~USART_TDR_TDR_Msk) | c;
}

uint8_t uart_getchar(){
	while(!(USART1->ISR & USART_ISR_RXNE)){
	}
	return (USART1->RDR & USART_RDR_RDR_Msk);
}
