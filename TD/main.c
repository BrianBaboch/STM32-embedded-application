#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"
#include "irq.h"


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
	clocks_init();
	matrix_init();
	irq_init();
	deactivate_rows();
	static_image();
	return 0;
}
