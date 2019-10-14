MEMORY{
	flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
	SRAM1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
	SRAM2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
}

SECTIONS{
	.vtor : {	
		*(vtor)	
	} > SRAM1
	.text : {
		*(.text)
	} > SRAM1

	.rodata : {
		*(.rodata)

	} > SRAM1

	.data : {
		*(.data)
		_image_start = .;
		*(.image)
		_image_end = .;
	} > SRAM1

	.bss : {
		_bstart = .;
		*(.bss) *(COMMON)
		_bend = .;
	} > SRAM1
}
ENTRY(_start)

_stack = ORIGIN(SRAM2) + LENGTH(SRAM2);
