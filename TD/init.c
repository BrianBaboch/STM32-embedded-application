extern char _bstart, _bend;

uint8_t *dst = &_data;

void init_bss(){
	for (dst = &_bstart; dst < &_bend; dst++)
		*dst = 0;	
}
