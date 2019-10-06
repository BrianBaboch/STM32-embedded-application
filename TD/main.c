#include <stdio.h>
#include <stdint.h>
#include "led.h"
#include "clocks.h"
#include "uart.h"

//variables to test init.c
int fib;
uint8_t rx = 0;
char str[11];

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
	//uint8_t * str_out = "hello world";
	clocks_init();
	uart_init();
	//uart_puts(str_out);
	//rx = uart_getchar();
	uart_gets(str, 11);
	uart_puts(str);
	//uart_puts(str);
	return 0;
}
