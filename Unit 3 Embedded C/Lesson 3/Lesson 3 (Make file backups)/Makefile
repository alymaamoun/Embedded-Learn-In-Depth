#@Copyright: Aly Maamoun
		
CC=arm-none-eabi-
CFLAGS= -g -mcpu=arm926ej-s
INCS= -I .
LIBS=

all: learn-in-depth.bin
	@echo "==========Build is Done============="

app.o: app.c
	$(CC)gcc.exe  $(CFLAGS)  -c  $(INCS) app.c -o app.o

uart.o: uart.c
	$(CC)gcc.exe  $(CFLAGS) -c $(INCS) uart.c -o uart.o

startup.o: startup.s
	$(CC)as.exe  $(CFLAGS)  startup.s -o startup.o

learn-in-depth.elf: app.o uart.o startup.o
	$(CC)ld -T linker_script.ld -Map=output.map app.o uart.o startup.o $(LIBS) -o learn-in-depth.elf

learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary learn-in-depth.elf learn-in-depth.bin

clean:
	rm *.elf *.bin

clean-all:
	rm *.elf *.bin *.o