CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
SOURCES = main.c init.c led.c
OBJS = main.o init.o crt0.o led.o
PRE_OBJS = clocks.o
ASFLAGS = -mcpu=cortex-m4
CFLAGS = -c -g -O1 -mcpu=cortex-m4
CPPFLAGS = -ICMSIS/Device/ST/STM32L4xx/Include -ICMSIS/Include 
FPU = -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS = -T ld_ram.lds -nostdlib
TARGET_ARCH = -mthumb

main: $(OBJS) $(PRE_OBJS)

-include $(subst .c,.d,$(SOURCES))

%.d : %.c
	$(CC) $(CPPFLAGS) -M -MF $@ -MP $<


gdb:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly
clean:
	rm -f main
	rm -f $(OBJS)
