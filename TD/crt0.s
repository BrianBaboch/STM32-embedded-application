    .syntax unified
    .global _start 
    .thumb_func
_start:
	ldr sp, =_stack
	bl init_bss
	bl init_data	
    bl main
_exit:
	bl _exit
