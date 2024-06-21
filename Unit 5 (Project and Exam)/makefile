CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb -g -gdwarf-2

LDFLAGS = -T linkerscript.ld -nostdlib -Wl,-Map=executable.map

ACH = cortex-m3

main.o: main.c
	@$(CC) $(CFLAGS) $^ -o $@

driver.o: driver.c
	@$(CC) $(CFLAGS) $^ -o $@

startup.o: startup.c
	@$(CC) $(CFLAGS) $^ -o $@

executable.elf: startup.o main.o driver.o
	@$(CC) $(LDFLAGS) $^ -o $@

all: main.o driver.o startup.o executable.elf

clean:
	@rm -f *.o *elf
