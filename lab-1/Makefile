CC	= arm-linux-gnueabihf-gcc
CFLAGS	= -O1 -Wall
LDFLAGS = -fno-stack-protector

objects	= fibseq.o fib.o

default: fibseq
	arm-linux-gnueabihf-objdump -d fibseq > fibseq.txt
.PHONY: default clean qemu

fibseq: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^

fib.o: fib.s
fibseq.o: fibseq.c

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) fibseq *.txt *.png

QEMU_CMD = qemu-arm -L /usr/arm-linux-gnueabihf ./fibseq &
qemu: fibseq
	@arm-linux-gnueabihf-objdump -d fibseq > fibseq.txt
	@number=0 ; while [ $$number -le 40 ] ; do \
	yes $$number | $(call QEMU_CMD) \
	sleep 1 ; \
	number=$$(($$number+1)); \
	done
	@gnuplot plot
