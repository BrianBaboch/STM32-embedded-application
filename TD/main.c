#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"
#include "irq.h"
#include "buttons.h"

rgb_color frame [8][8];
int matrix_row = 0;
int matrix_col = 0;
int matrix_color = 0; 

int main() {
	clocks_init();
	led_init();
	matrix_init();
	irq_init();
	uart_init(38400);
	buttons_init();
	while (1){
		for(int i = 0; i < 8; ++i){
			mat_set_row(i, frame[i]);
		}
	}
	return 0;
}
