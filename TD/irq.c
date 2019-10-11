#include "irq.h"

extern uint32_t _stack;
extern uint32_t _start;

BUTTONS_HANDLER(EXTI15_10);

void *vector_table[] = {
    // Stack and Reset Handler
    &_stack,            /* Top of stack */
    &_start,             /* Reset handler */
	
	//External interruption
	EXTI15_10
};

void irq_init(void){
	//SCB->VTOR = vector_table;
	SCB->VTOR = (uint32_t)vector_table;
}
