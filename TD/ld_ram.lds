MEMORY{
	flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
	SRAM1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
	SRAM2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
}

SECTIONS{
	.vtor : {	
		*(vtor)	
	} > flash
	.text : {
		*(.text)
	} > flash

	.rodata : {
		*(.rodata)
		_roend = .;
	} > flash

	.data : {
		_dstart = .;
		*(.data)
		_dend = .;
	} > SRAM1 AT>flash 

	.bss : {
		_bstart = .;
		*(.bss) *(COMMON)
		_bend = .;
	} > SRAM1
}
ENTRY(_start)

_stack = ORIGIN(SRAM2) + LENGTH(SRAM2);
