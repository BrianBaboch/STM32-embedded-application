#include <stdio.h>
#include <stdint.h>
#include "led.h"

//variables to test init.c
int fib;

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

int main() {
	led_init();
	led_g_on();

	for (int i=0; i < 5; i++)
		asm volatile("nop");
	
	led_g_off();
	return 0;
}
