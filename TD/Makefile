CC = arm-none-eabi-gcc
SOURCES = main.c
OBJS = main.o
CFLAGS = -c -g -O1 -mcpu=cortex-m4
FPU = -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS = -T ld_ram.lds -nostdlib
TARGET_ARCH = -mthumb

main: $(OBJS)

gdb:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly
clean:
	rm -f main
	rm -f *.o
