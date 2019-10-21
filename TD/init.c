#include <stdint.h>

extern uint8_t _bstart, _bend, _dstart, _dend, _roend, _vstart, _tend, 
	_flash;

__attribute__((section (".flash"))) void init_text(){
	uint8_t *src = &_flash;
	uint8_t *dst = &_vstart;
	while (dst < &_tend)
 		*dst++ = *src++;
}

__attribute__((section (".flash")))void init_data(){
	uint8_t *src = &_roend;
	uint8_t *dst = &_dstart;
	while (dst < &_dend)
 		*dst++ = *src++;
}

__attribute__((section (".flash")))void init_bss(){
	uint8_t *dst = &_bstart;
	for (dst = &_bstart; dst < &_bend; dst++)
		*dst = 0;	
}
