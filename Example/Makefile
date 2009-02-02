# Example makefile for use with the command-line C32 compiler and newlib
# Taken from Phillip Burgess's c32-build script

HEX    = test.hex
DEVICE = 32MX360F512L
CC     = pic32mx-gcc -s -Wl,-Map,test.map -Os -mips16 -mprocessor=$(DEVICE)

all: $(HEX)

$(HEX): test.elf
	pic32mx-bin2hex -a test.elf

test.elf: test.c
	$(CC) test.c -o test.elf

