#include <stdio.h>
#include <stdint.h>
#include "led.h"
#include "clocks.h"

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
void delay (){
	for (int i=0; i < 150000; i++){
		asm volatile("nop");
	}
}

int main() {
	clocks_init();
	led_init();

	for (int i=0; i < 10; i++){
		led_g_on();
		delay();
		led_g_off();
		led(LED_YELLOW);
		delay();
		led(LED_BLUE);
		delay();
		led(LED_OFF);
	}	
	return 0;
}
