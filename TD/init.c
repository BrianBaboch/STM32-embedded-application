#include <stdint.h>

extern char _bstart, _bend;

void init_bss(){
	uint8_t *dst = &_bstart;
	for (dst = &_bstart; dst < &_bend; dst++)
		*dst = 0;	
}
