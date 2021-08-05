My ambient tracking modul with raspi
====================================

This is all content around my AVR ATMega168PA base board.

[Related links](Documentation/links.md).

The basic user interface are make targets, which then activate something:

	+-----------------------------------------------------------+
	|                                                           |
	|                  Nothing to build                         |
	|                                                           |
	+-----------------------------------------------------------+
	| Example:                                                  |
	| make build              -> build src code subfolders      |
	| make clean              -> clean all dir/subdirs          |
	| make distclean          -> clean + external folder        |
	| make install            -> install some scripts to        |
	|                            $(HOME)/bin                    |
	| make uninstall          -> remove scripts from            |
	|                            $(HOME)/bin                    |
	+-----------------------------------------------------------+

WARNING: This is work in progress! So it's possible that something is not working or possibly not implemented yet.

If you face a bug, then pls use https://github.com/tjohann/avr_m168_base_board/issues to create an ticket.


State
-----

WARNING: This is work in progress! Don't expect things to be complete in any dimension.

	environment -> works
	serial -> works
	PB0 -> works

	I2C -> open
	LCD xxx -> open
	BMP180 temperature/pressure -> open


Requirement
-----------

The AVR compiler, AVRDude and a serial terminal like moserial (https://wiki.gnome.org/action/show/Apps/Moserial?action=show&redirect=moserial)

To use my scripts, you need to source the avr_env file, wich sets some shell values:

	. ./avr_env

This is normally only a link to the different base configurations.

	avr_high_speed_env (internal OSC at 8MHz)
	avr_low_speed_env (internal OSC at 1MHz)


Versioninfo
-----------

I use a standard version scheme via git tags based on 3 numbers:

	AVR-M168-BB_V0.0.1

The first number is the major number which reflect bigger changes. The second number (minor) will change because of

	- new scripts
	- new hw like SPI or I2C

Minor number change because of

	- bugfixes
	- all smaller changes

[Integration-Checklist](Documentation/integration_checklist.md).


Schematics
----------

See folder schematics for more info.

[Schematics](schematics/README.md).


Development board
-----------------

![Alt text](pics/base_board_full.jpg?raw=true "Overview")

![Alt text](pics/base_board_detail.jpg?raw=true "Detailed view")

![Alt text](pics/base_board_top.jpg?raw=true "Top view")

![Alt text](pics/base_board_bottom.jpg?raw=true "Bottom view")


Additional scripts
------------------

In the scripts folder you find the used helper tools to ....

xxxx:

	+--------------------------------------------------------+
	|                                                        |
	| Usage: xxx.sh
	|        [-v] -> print version info                      |
	|        [-h] -> this help                               |
	|                                                        |
	+--------------------------------------------------------+


Serial topics
-------------

Base config:

	Baudrate: 9600
	Config: 8N1


I2C topics
----------

t.b.d.


BMP180 topics
-------------

t.b.d.


LCD topics (2004/1602)
---------------------

t.b.d.


Displays
--------

I2C based displays

	...


The code
--------

See [The code](src/README.md).

