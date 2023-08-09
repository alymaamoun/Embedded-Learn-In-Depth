#@Copyright: Aly Maamoun
		
CC=arm-none-eabi-
CFLAGS= -g -mcpu=arm926ej-s
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) 
As =  $(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=learn-in-depth

all: $(Project_name).bin
	@echo "==========Build is Done============="

%.o: %.c
	$(CC)gcc.exe  $(CFLAGS)  -c  $(INCS) $< -o $@

startup.o: startup.s
	$(CC)as.exe  $(CFLAGS)  $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld -Map=output.map $(OBJ) $(AsOBJ) $(LIBS) -o $(Project_name).elf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.elf *.bin

clean-all:
	rm *.elf *.bin *.o