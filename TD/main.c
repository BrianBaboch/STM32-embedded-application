#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"

//variables to test init.c
int fib;
uint8_t rx = 0;
uint8_t str[10000];
uint32_t check = 0;

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
/*
void delay (){
	for (int i=0; i < 80000000; i++){
		asm volatile("nop");
	}
}
*/
int main() {
	clocks_init();
	matrix_init();
	deactivate_rows();
	//test_pixels();
	static_image();
	return 0;
}


