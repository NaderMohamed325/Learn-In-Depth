CC = arm-none-eabi-gcc
ACH = cortex-m3
CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb

LDFLAGS = -T linkerscript.ld -nostdlib -Wl,-Map=executable.map



startup.o: startup.c
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

output.elf: main.o startup.o
	$(CC) $(LDFLAGS) $^ -o $@

all: main.o startup.o output.elf

clean:
	rm -f *.elf *.o *.map
