    .syntax unified
    .global _start 
    .thumb_func
	.section ".flash"
_start:
	ldr sp, =_stack
	bl init_text
	bl init_data	
	bl init_bss
	ldr r0, =main 
	blx r0	
_exit:
	bl _exit
