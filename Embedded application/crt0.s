    .section ".flash", "ax", %progbits
    .syntax unified
    .global _start 

.thumb_func
_start:
	ldr sp, =_stack
	bl init_data	
	bl init_bss
	bl init_text
	ldr r0, =main	
	blx r0
_exit:
	bl _exit
