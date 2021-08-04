Some infos about all relevant topics
====================================


AVR controller
--------------

t.b.d.


FUSES
-----

Calculator: http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega168pa

Defaults for m168pa (internal@1MHz)

	LFUSE=0x62
	HFUSE=0xdf
	EFUSE=0x00

My changes:

	HFUSE=0xd7  (preserve EEPROM across flashes)

For high-speed (internal@8MHz):

	LFUSE=0xE2


Display
-------

https://cdn-shop.adafruit.com/datasheets/HD44780.pdf
https://de.wikipedia.org/wiki/HD44780



I2C topics and linux
--------------------

t.b.d.


BMP180 modul
------------

t.b.d.


RTC (real time clock) module
----------------------------

I add the module like https://www.elecrow.com/wiki/index.php?title=Tiny_RTC to the board.
