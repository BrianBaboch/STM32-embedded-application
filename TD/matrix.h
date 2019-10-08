#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdint.h>
#include "stm32l475xx.h"
#include "stm32l4xx.h"

#define RST(X) do { if(X==0) SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR3); \
	else SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS3); } while(0)  
#define SB(X) do { if(X==0) SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR5); \
	else SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS5); } while(0)
#define LAT(X) do { if(X==0) SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR4); \
	else SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS4); } while(0)
#define SCK(X) do { if(X==0) SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR1); \
	else SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS1); } while(0)
#define SDA(X) do { if (X==0) SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR4); \
	else SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS4); } while(0)
#define ROW0(X) do { if (X==0) SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR2); \
	else SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS2); } while(0)
#define ROW1(X) do { if (X==0) SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR15); \
	else SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS15); } while(0)
#define ROW2(X) do { if (X==0) SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR2); \
	else SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS2); } while(0)
#define ROW3(X) do { if (X==0) SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR7); \
	else SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS7); } while(0)
#define ROW4(X) do { if (X==0) SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR6); \
	else SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS6); } while(0)
#define ROW5(X) do { if (X==0) SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR5); \
	else SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS5); } while(0)
#define ROW6(X) do { if (X==0) SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR0); \
	else SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS0); } while(0)
#define ROW7(X) do { if (X==0) SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR3); \
	else SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS3); } while(0)  
#define pulse_SCK do { SCK(0); for(int i=0; i < 3; ++i) asm volatile ("nop"); \
	SCK(1); for(int i=0; i < 3; ++i) asm volatile ("nop"); \
	SCK(0); for(int i=0; i < 3; ++i) asm volatile ("nop"); } while(0)
#define pulse_LAT do { LAT(1); for(int i=0; i < 3; ++i) asm volatile ("nop"); \
	LAT(0); for(int i=0; i < 3; ++i) asm volatile ("nop"); \
	LAT(1); for(int i=0; i < 3; ++i) asm volatile ("nop"); } while(0)

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb_color;

void matrix_init();
void deactivate_rows();
void activate_row(int row);
void send_byte(uint8_t val, int bank);
void mat_set_row(int row, const rgb_color *val);
void init_bank0();
void test_pixels();
void delay();

#endif
