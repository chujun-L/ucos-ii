CC           = arm-linux-gcc
LD           = arm-linux-ld
AR           = arm-linux-ar
OBJCOPY      = arm-linux-objcopy
OBJDUMP      = arm-linux-objdump

VPATH        = source:cpu
INCLUDEDIR 	:= $(shell pwd)/include
CFLAGS 		:= -Wall -O2 -fno-builtin
CPPFLAGS   	:= -g -nostdlib -nostdinc -I$(INCLUDEDIR)

export 	CC AR LD OBJCOPY OBJDUMP INCLUDEDIR CFLAGS CPPFLAGS VPATH



objs :=  os_cpu_a.o os_cpu_c.o \
		 os_core.o ucos_ii.o os_time.o os_task.o os_sem.o \
		 test.o s5pv210_init.o \


ucos.bin:$(objs)
	${LD} -Ttext=0x30000000 -o ucos.elf $^
	${OBJCOPY} -O binary -S ucos.elf $@
	${OBJDUMP} -D ucos.elf > ucos.dis

%.o:%.c
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.o:%.S
	${CC} $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

.PHONY:clean
clean:
	-rm -f *.bin *.elf *.dis *.o

