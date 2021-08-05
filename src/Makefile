#
# base_board makefile
#

include validate_makefile.mk


DEBUG = -g -ggdb

TARGET = base_board
LINK_TARGET = $(TARGET).o usart.o

SRC = base_board.c usart.c
HEADER = base_board.h usart.h

CFLAGS = -ffunction-sections -fdata-sections -Os
LDFLAGS = -Wl,--relax,--gc-sections -Wl,-Map,$(TARGET).map

FUSES = -U lfuse:w:${LFUSE}:m -U hfuse:w:${HFUSE}:m -U efuse:w:${EFUSE}:m


#
# ---------  build all parts ----------
#
all: $(TARGET).elf $(TARGET).hex $(TARGET).srec $(TARGET).bin $(TARGET)_eeprom.hex $(TARGET)_eeprom.srec $(TARGET)_eeprom.bin $(TARGET).lst size
	@echo "|| "
	@echo "|| -->   Finished building $(TARGET).* of $(SRC) "
	@echo "|| "


#
# --------- programming topics ---------
#
program_all: program_flash program_eeprom
	@echo " "
	@echo "|| "
	@echo "|| --> Flash EEPROM and Code-Flash"
	@echo "|| "

program_flash: $(TARGET).hex
	$(PROGRAMMER) -c $(PROGRAMMER_HW) -p $(MCU) $(PROGRAMMER_ARGS) -U flash:w:$<

program_eeprom: $(TARGET)_eeprom.hex
	$(PROGRAMMER) -c $(PROGRAMMER_HW) -p $(MCU) $(PROGRAMMER_ARGS) -U eeprom:w:$<


#
# --------- fuse topics ---------
#
program_fuses::
	@echo " "
	@echo "|| "
	@echo "|| --> Program FUSES"
	@echo "|| "
	$(PROGRAMMER) -c $(PROGRAMMER_HW) -p $(MCU) $(PROGRAMMER_ARGS) $(FUSES)

read_fuses::
	@echo " "
	@echo "|| "
	@echo "|| --> Read FUSES"
	@echo "|| "
	$(PROGRAMMER) -c $(PROGRAMMER_HW) -p $(MCU) $(PROGRAMMER_ARGS) -nv


#
# --------- build topics ---------
#
%.elf: $(SRC) $(HEADER)
	@echo " "
	@echo "|| "
	@echo "|| -->  Building $(TARGET).elf "
	@echo "|| "
	avr-gcc -Wall -Wextra $(DEBUG) -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -DBAUD=${BAUD} $(CFLAGS) -save-temps -c $(SRC)
	avr-gcc -Wall -Wextra $(DEBUG) -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -DBAUD=${BAUD} $(LDFLAGS) $(LINK_TARGET) --output $@

%.hex: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Building $(TARGET).hex "
	@echo "|| "
	avr-objcopy -R .eeprom -O ihex $< $@

%.srec: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Building $(TARGET).srec "
	@echo "|| "
	avr-objcopy -R .eeprom -O srec $< $@

%.bin: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Building $(TARGET).bin "
	@echo "|| "
	avr-objcopy -R .eeprom -O binary $< $@

%_eeprom.hex: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Building $(TARGET).eeprom "
	@echo "|| "
	avr-objcopy -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@

%_eeprom.srec: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Building $(TARGET).srec "
	@echo "|| "
	avr-objcopy -j .eeprom --change-section-lma .eeprom=0 -O srec $< $@

%_eeprom.bin: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Building $(TARGET).bin "
	@echo "|| "
	avr-objcopy -j .eeprom --change-section-lma .eeprom=0 -O binary $< $@

%.lst: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Create $(TARGET).lst "
	@echo "|| "
	avr-objdump -h -S $< > $@

eeprom: $(TARGET).elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Building $(TARGET).* "
	@echo "|| "
	avr-objcopy -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $(TARGET)_eeprom.hex
	avr-objcopy -j .eeprom --change-section-lma .eeprom=0 -O srec $< $(TARGET)_eeprom.srec
	avr-objcopy -j .eeprom --change-section-lma .eeprom=0 -O binary $< $(TARGET)_eeprom.bin


#
# --------- show infos ---------
#
size: $(TARGET).elf
	@echo " "
	@echo "|| "
	@echo "|| --> Mem usage "
	@echo "|| "
	avr-size $(TARGET).elf
#	avr-size -C --mcu=$(MCU) $(TARGET).elf

readelf: $(TARGET).elf
	@echo " "
	@echo "|| "
	@echo "|| --> detailed elf infos "
	@echo "|| "
	readelf --all $(TARGET).elf

clean::
	rm -rf *~
	rm -rf *.i *.o *.s
	rm -rf *.elf
	rm -rf *.hex
	rm -rf *.bin
	rm -rf *.srec
	rm -rf *.obj
	rm -rf *.eeprom
	rm -rf *.lst
	rm -rf *.map

distclean: clean
