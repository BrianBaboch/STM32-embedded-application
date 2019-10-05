#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init();
void uart_putchar(uint8_t c);
uint8_t uart_getchar();
void uart_puts(const uint8_t *s);

#endif
