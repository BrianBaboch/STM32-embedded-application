CC = arm-none-eabi-gcc
SOURCES = t1.c t2.c main.c
OBJS = t1.o t2.o main.o stubs.o
CFLAGS = -Wall -Werror -g -Og
TARGET_ARCH = -mthumb
VPATH = libs
EXE = hello

$(EXE) : $(OBJS)
	$(CC) -L/opt/mylibs $(TARGET_ARCH) $(OBJS) -lm -o $@

-include $(subst .c,.d,$(SOURCES))

%.d : %.c
	$(CC) -M -MF $@ -MP $<

stubs.o : stubs.c 
	$(CC) -g -O2 $(TARGET_ARCH) -c -o $@ $<

clean:
	rm -f hello
	rm -f *.o
	rm -f *.d
