Some infos about all relevant topics
====================================


AVR controller
--------------

t.b.d.


FUSES
-----

Calculator: http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega168pa or https://www.engbedded.com/fusecalc/

Defaults for m168pa (internal@1MHz)

	LFUSE=0x62
	HFUSE=0xdf
	EFUSE=0xf9

or

	EFUSE=0x01

Note: 0xf9 and 0x01 are equal (depends on your the device, so read out and set the same value)

My changes:

	HFUSE=0xd7  (preserve EEPROM across flashes)

For high-speed (internal@8MHz):

	LFUSE=0xE2


M168*
-----

Readout of default values (of my example controllers) via AVRDUDE:

	avrdude: Device signature = 0x1e940b (probably m168p)
	avrdude: safemode: hfuse reads as DF
	avrdude: safemode: efuse reads as F9

	avrdude: safemode: hfuse reads as DF
	avrdude: safemode: efuse reads as F9
	avrdude: safemode: Fuses OK (E:F9, H:DF, L:62)


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


Serial console
--------------

Base config:

	Baudrate: 9600
	Config: 8N1

Moserial -> https://wiki.gnome.org/action/show/Apps/Moserial?action=show&redirect=moserial

My configuration for moserial -> ./Documentation/moserial_config
