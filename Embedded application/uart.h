#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdio.h>
#include "matrix.h"

enum colors {RED = 0, GREEN = 1, BLUE = 2};

extern rgb_color frame [8][8];
extern int matrix_row;
extern int matrix_col;
extern int matrix_color; 


void uart_init(int baudrate);
void uart_putchar(uint8_t c);
uint8_t uart_getchar();
void uart_puts(const uint8_t *s);
void uart_gets(uint8_t *s, size_t size);
uint32_t uart_checksum( uint8_t *s, size_t size);
void USART1_IRQHandler();
void increment_counters(int *r, int *c);

#endif
