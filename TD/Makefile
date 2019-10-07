CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
SOURCES = main.c init.c led.c uart.c
OBJS = main.o init.o crt0.o led.o uart.o
PRE_OBJS = clocks.o
TARGET_MACH = -mcpu=cortex-m4
TARGET_ARCH = -mcpu=cortex-m4
CFLAGS = -c -g -O1
CFLAGS += -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
#CFLAGS += -Wall -Wextra -Werror
CPPFLAGS = -ICMSIS/Device/ST/STM32L4xx/Include -ICMSIS/Include
LDFLAGS = -T ld_ram.lds -nostdlib


main: $(OBJS) $(PRE_OBJS)

-include $(subst .c,.d,$(SOURCES))

%.d : %.c
	$(CC) $(CPPFLAGS) -M -MF $@ -MP $<


gdb:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly
clean:
	rm -f main
	rm -f $(OBJS)
