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
	buttons_init();
	static_image();
	return 0;
}
