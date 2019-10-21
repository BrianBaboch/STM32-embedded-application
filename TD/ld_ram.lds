MEMORY{
	flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
	SRAM1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
	SRAM2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
}

SECTIONS{
	.vtor : {	
		_vstart = .;
		*(vtor)	
	} > SRAM1 AT > flash
	.text : {
		*(.text)
		_tend = .;
	} > SRAM1 AT > flash

	.rodata : {
		*(.rodata)
		_roend = .;
	} > flash

	.data : {
		_dstart = .;
		*(.data)
		_dend = .;
	} > SRAM1 AT > flash 

	.bss : {
		_bstart = .;
		*(.bss) *(COMMON)
		_bend = .;
	} > SRAM1
	
	.flash : {
		*(.flash)
	} > flash
}
ENTRY(_start)

_stack = ORIGIN(SRAM2) + LENGTH(SRAM2);
_flash = ORIGIN(flash);
