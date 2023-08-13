#@Copyright: Aly Maamoun
#CC will add the toolchain name, instead of typing everytime arm-none-eabi-gcc.exe for example , take this variable by typing $(CC)gcc.exe to make it generic just edit this option not all the rules 		
CC=arm-none-eabi-
##CFLAG is used to pass the compiling options like the processor arch type and debug info options
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
#INCS is used for the included pathes
INCS= -I .
#if you're using any external library add it here
LIBS=
#SRC and OBJ are used to include all src files to generate their object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) 
#As and OBJ are used to include all asembly files to generate their object files
As =  $(wildcard *.s)
AsOBJ=$(As:.s=.o)
#put your project name here
Project_name=unit3_lab4_cortexM4

all: $(Project_name).bin
	@echo "==========Build is Done============="

%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe  $(CFLAGS)  -c  $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) $(LIBS) -o $@ -Map=output.map
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.elf *.bin *.axf

clean-all:
	rm *.elf *.bin *.o  *.axf