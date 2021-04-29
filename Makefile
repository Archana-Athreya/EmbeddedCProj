PROJ_NAME = Embeddedc_Activity
ELFFILE = $(PROJ_NAME).elf
BUILD_DIR = Build

# All Source code files
SRC = main.c\
src/activity1.c\
src/activity2.c\
src/activity3.c

# All header file paths
INC = -I inc

# Find out the OS and configure the variables accordingly
ifdef OS	# All configurations for Windwos OS
   # Delete command 
   RM = rm -rf
   # Correct the path based on OS
   FixPath = $(subst /,\,$1)
   # Name of the compiler used
   CC = avr-gcc.exe
   # Name of the elf to hex file converter used
   AVR_OBJ_CPY = avr-objcopy
else #All configurations for Linux OS
   ifeq ($(shell uname), Linux)
   	  # Delete command
      RM = rm -rf			
	  # Correct the path based on OS
      FixPath = $1				
	  # Name of the compiler used
	  CC = avr-gcc
	  # Name of the elf to hex file converter used
	  AVR_OBJ_CPY = avr-objcopy 
   endif
endif

# Command to make to consider these names as targets and not as file names in folder
.PHONY:all analysis clean doc

all:$(BUILD_DIR)
	$(CC) -g -Wall -Os -mmcu=atmega328  $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)
	
# Create directory to store the built files
$(BUILD_DIR):
	mkdir $(BUILD_DIR)
# To generate hexfile from elf file
hex:
	$(AVR_OBJ_CPY) -O ihex $(BUILD_DIR)/$(ELFFILE) $(BUILD_DIR)/$(PROJ_NAME).hex
# To do static analysis
analysis: $(SRC)
	cppcheck --enable=all $^
#Build the code code documentation using Doxygen command line utility
doc:
	make -C documentation

clean:
	$(RM) $(call FixPath,$(BUILD_DIR))
	make -C documentation clean
