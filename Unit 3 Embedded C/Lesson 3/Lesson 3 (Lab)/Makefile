#@Copyright: Aly Maamoun
		
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) 
As =  $(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=learn_in_depth_cortex_m3

all: $(Project_name).bin
	@echo "==========Build is Done============="

%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe  $(CFLAGS)  -c  $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) $(LIBS) -o $@ -Map=output.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.elf *.bin 

clean-all:
	rm *.elf *.bin *.o 