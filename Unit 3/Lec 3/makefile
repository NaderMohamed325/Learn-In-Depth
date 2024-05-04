CC = arm-none-eabi-gcc
ACH = cortex-m3
CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb -g -gdwarf-2

LDFLAGS = -T linkerscript.ld -nostdlib -Wl,-Map=executable.map



startup.o: startup.c
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

stm32f103.elf: main.o startup.o
	$(CC) $(LDFLAGS) $^ -o $@
	cp stm32f103.elf stm32f103.axf

all: main.o startup.o stm32f103.elf

clean:
	rm -f *.elf *.o *.map
