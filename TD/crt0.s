    .syntax unified
    .global _start 
	.global _image
    .thumb
_start:
	ldr sp, =0x10008000
	bl init_bss
    bl main
_exit:
	bl _exit

_image:
	.section .image
	.incbin "image.raw"
