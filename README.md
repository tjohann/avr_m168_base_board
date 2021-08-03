My ambient tracking modul with raspi
====================================

This is all content around my AVR ATMega168 base board.

[Related links](Documentation/links.md).

The basic user interface are make targets, which then start the corresponding scripts or directly activate something:

	+-----------------------------------------------------------+
	|                                                           |
	|                  Nothing to build                         |
	|                                                           |
	+-----------------------------------------------------------+
	| Example:                                                  |
	| make build              -> build all code subfolders      |
	| make clean              -> clean all dir/subdirs          |
	| make distclean          -> clean + kernel folder          |
	| make install            -> install all to $(HOME)/...     |
	| make uninstall          -> remove all from $(HOME)/...    |
	| make deploy             -> install bin's to /usr/bin      |
	+-----------------------------------------------------------+

If you face a bug, then pls use https://github.com/tjohann/avr_m168_base_board/issues to create an ticket.


State
-----

WARNING: This is work in progress! Don't expect things to be complete in any dimension.

	environment -> open/works
	lcd -> ...
	serial -> ...
	PB0 -> ...

	I2C -> open
	LCD xxx -> open
	BMP180 temperature/pressure -> open


Requirement
-----------

...


To use my scripts, you need to source the pi-env_env file, wich sets some shell values:

	. ./m168bb_env



Versioninfo
-----------

I use a standard version scheme via git tags based on 3 numbers:

	AVR-M168-BB_V0.0.1

The first number is the mayor number which reflect bigger changes. The second number (minor) will change because of

	- new scripts
	- image updates
	- new releases of sensor_pi/lcd2004_i2c

So a simple version update of the kernel will not increase the minor number, instead it will increase the third number (age number):

	- bugfixes
	- update kernel version
	- all smaller changes

[Integration-Checklist](Documentation/integration_checklist.md).


Schematics
----------

See folder schematics for more info.

[Schematics](schematics/README.md).


Additional libraries/tools
--------------------------

t.b.d.


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

t.b.d.


I2C topics
----------

t.b.d.


BMP180 topics
-------------

t.b.d.


LCD topics
----------

t.b.d.


Display
-------

t.b.d.


The code
--------

See [The code](src/README.md).

