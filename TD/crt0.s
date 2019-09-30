    .syntax unified
    .global _start
    .thumb
_start:
	ldr sp, =0x10000000
	bl init_bss
    bl main
