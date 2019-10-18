    .syntax unified
    .global _start 
	.global _image
    .thumb
_start:
	ldr sp, =_stack
	bl init_bss
    bl main
_exit:
	bl _exit
