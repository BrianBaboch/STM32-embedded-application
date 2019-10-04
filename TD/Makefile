CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
SOURCES = main.c init.c led.c
OBJS = main.o init.o crt0.o led.o
ASFLAGS = -mcpu=cortex-m4
CPPFLAGS = -ICMSIS/Device/ST/STM32L4xx/Include -ICMSIS/Include 
CFLAGS = -Wall -Wextra -Werror -c -g -O1 -mcpu=cortex-m4
FPU = -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS = -T ld_ram.lds -nostdlib
TARGET_ARCH = -mthumb

main: $(OBJS)

-include $(subst .c,.d,$(SOURCES))

%.d : %.c
	$(CC) -M -MF $@ -MP $<


gdb:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly
clean:
	rm -f main
	rm -f *.o
