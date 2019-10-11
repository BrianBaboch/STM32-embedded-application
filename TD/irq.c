#include "irq.h"

uint32_t _stack = 0x00

void *vector_table[] = {
    // Stack and Reset Handler
    &_stack,            /* Top of stack */
    _start,             /* Reset handler */

}

void irq_init(void){
	//SCB->VTOR = vector_table;
	SCB->VTOR = (uint8_t)vector_table;
}
