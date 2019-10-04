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
	enum values {LED_OFF = 0, LED_YELLOW = 1, LED_BLUE = 2};
	led_init();

	for (int i=0; i < 5; i++){
		led_g_on();
		led_g_off();
		led(LED_YELLOW);
		led(LED_BLUE);
		led(LED_OFF);
	}	
	return 0;
}
