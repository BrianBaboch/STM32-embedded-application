#include <stdio.h>
#include <stdint.h>
#include "led.h"
#include "clocks.h"
#include "uart.h"

//variables to test init.c
int fib;
uint8_t rx = 0;

int fibo(int n){
	if (n == 0){
		return 0;
	}
	else if (n == 1){
		return 1;
	}
	else{
		return (fibo(n-1) + fibo(n-2));
	}
}
void delay (){
	for (int i=0; i < 8000000; i++){
		asm volatile("nop");
	}
}

int main() {
	fib = 1;
	clocks_init();
	uart_init();
	uart_putchar('a');
	rx = uart_getchar();
	return 0;
}
