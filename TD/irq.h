#ifndef IRQ_H
#define IRQ_H

#include <stdio.h>
#include <stdint.h>
//#include "cmsis_gcc.h"
//#include "core_cm4.h"
#include "stm32l475xx.h"
#include "stm32l4xx.h"

#define MAKE_DEFAULT_HANDLER(interruption) void __attribute__((weak)) \
	__attribute__((weak)) interruption(void){__disable_irq(void); while(1){}}

void irq_init(void);

#endif //IRQ_H
