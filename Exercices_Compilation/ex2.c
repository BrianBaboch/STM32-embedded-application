#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
In order to know the order of the different sections in the memory, I 
created pointers to different variables:
-Pointer to an uninitialized variable, its address will be in the BSS
-Pointer to a global variable (Data)
-Pointer to a constant global variable (ro Data)
-Pointer to a function (Text)
-Pointer to a dynamically allocated variable (Heap)
-Pointer to a local variable inside main (Stack1)
-Pointer to a local variable inside a function (Stack2)

By printing the value of all theses pointers I noticed that the sections are
implemented in the following order:
-Text
-ro Data
-Data
-BSS
-Heap 
-Stack

And the stack decreases since it starts at the end and the addresses goes 
down.

We can see this result when executing the code.
*/

int32_t x = 34;
int32_t y;
const int8_t w = 2;

int8_t const * rodata_ptr = &w;
int32_t * data_ptr = &x;
int32_t * bss_ptr = &y;

void test(){
	int8_t k = 5;
	int8_t * stack2_ptr = &k;
	printf ("Stack2: %p\n", stack2_ptr);
}

void *text_ptr = &test;

int main() {
	int8_t * heap_ptr;
	heap_ptr = (int8_t *) malloc(5);

	uint8_t t1 = 1;

	uint8_t * stack1_ptr = &t1;

	printf("BSS: %p\nData: %p\nRO Data: %p\nText: %p\nHeap: %p\n", 
	bss_ptr, data_ptr, rodata_ptr, text_ptr, heap_ptr);
	printf("Stack1: %p\n", stack1_ptr); 
	test();
	return 0;
}

