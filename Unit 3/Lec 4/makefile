CC = arm-none-eabi-gcc
ACH = cortex-m4
CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb -g -gdwarf-2

LDFLAGS = -T linkerscript.ld -nostdlib -Wl,-Map=executable.map



startup.o: startup.c
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

unit3_lab4_cortexM4.elf: main.o startup.o
	$(CC) $(LDFLAGS) $^ -o $@
	cp unit3_lab4_cortexM4.elf unit3_lab4_cortexM4.axf

all: main.o startup.o unit3_lab4_cortexM4.elf

clean:
	rm -f *.elf *.o *.map
