
#-------------------------------------------------------------------------------
#
# Maintainer:   jeffskinnerbox@yahoo.com / www.jeffskinnerbox.me
# Version:      0.5.0
#
# USAGE
#	To build the executable and flash the device
#		make
#		make all
#
#	To build the executable
#	    make build
#
#	To flash the device
#	    make upload
#
#	makefile syntax
#	    = set the variable
#	    ?= set the variable only if it's not set/doesn't have a value
#	    := set variable as the output an executed shell script
#	    += is used for appending more text to variables
#
# SOURCES
#   The Makefile was created with the help of this website:
#   https://learn.sparkfun.com/tutorials/efficient-arduino-programming-with-arduino-cli-and-visual-studio-code/all
#
# DOCUMENTATION
#   https://create.arduino.cc/projecthub/B45i/getting-started-with-arduino-cli-7652a5
#   https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html
#   https://stackoverflow.com/questions/52437728/bash-what-is-the-difference-between-pwd-and-curdir
#
#-------------------------------------------------------------------------------

# name of program being created
PROG = approximate

# FQBN: type of package, architecture, and board in use
# list all known boards and their corresponding FQBN via 'arduino-cli board listall'
PACKAGE = esp8266
ARCH =    esp8266
BOARD =   generic
#BOARD =   nodemcuv2

# serial port used by the board
PORT = /dev/ttyUSB0

# optional verbose compile/upload flag
#VERBOSE = -v

#-------------------------------------------------------------------------------

# fully qualified board name (FQBN)
FQBN = $(PACKAGE):$(ARCH):$(BOARD)

# location of the esptool used for flashing
ESPTOOL = /home/jeff/.arduino15/packages/esp32/tools/esptool_py/2.6.1/esptool.py

# string within names given to .bin and .elf files
VAR = $(shell echo $(FQBN) | tr ':' '.')

# path for temp-storage of binary, object, and core.a files
BUILD = /tmp/$(PROG)
BUILD_PATH = $(BUILD)/build

# paths to libraries and include files
LIBS = "/home/jeff/src/arduino/sketchbooks/libraries"

# compiler and compiler flags
CC = arduino-cli compile
CC_FLAGS = $(VERBOSE) --fqbn $(FQBN) --build-path=$(BUILD_PATH) --build-cache-path=$(BUILD) --libraries $(LIBS)

# firmware flasher and flags
UPLOAD = arduino-cli upload
UPLOAD_FLAGS = $(VERBOSE) --fqbn $(FQBN) --port $(PORT)

#-------------------------------------------------------------------------------

.PHONY: build upload clean erase size           # explicitly declare these target to be phony

all: build upload                               # build and then upload

build: 											# build the binary executable
#	$(CC) $(CC_FLAGS) $(CURPWD)

upload: 										# up load the binary executable
#	$(UPLOAD) $(UPLOAD_FLAGS) $(CURPWD)

erase:                                          # erase the entire flash
	$(ESPTOOL) erase_flash --port $(PORT)

size:                                           # determine the flash size
	$(ESPTOOL) flash_id --port $(PORT)

clean:                                          # delete all binaries and object files
	rm -r --force $(BUILD)
	rm --force *.bin *.elf *.hex
