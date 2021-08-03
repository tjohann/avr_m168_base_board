#
# my simple makefile act as something like a user interface
#

ifeq "${M168_BB_HOME}" ""
    $(error error: please source avr_env first!)
endif

MODULES = pics Documentation schematics pcb
MODULES_BUILD = src
MODULES_EXTRA = external

all::
	@echo "+-----------------------------------------------------------+"
	@echo "|                                                           |"
	@echo "|                  Nothing to build                         |"
	@echo "|                                                           |"
	@echo "+-----------------------------------------------------------+"
	@echo "| Example:                                                  |"
	@echo "| make build              -> build all code subfolders      |"
	@echo "| make clean              -> clean all dir/subdirs          |"
	@echo "| make distclean          -> clean + kernel folder          |"
	@echo "| make install            -> install some scripts to        |"
	@echo "|                            $(HOME)/bin                     "
	@echo "| make uninstall          -> remove scripts from            |"
	@echo "|                            $(HOME)/bin                     "
	@echo "+-----------------------------------------------------------+"

clean::
	rm -f *~ .*~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done
	for dir in $(MODULES_BUILD); do (cd $$dir && $(MAKE) $@); done

distclean: clean
	for dir in $(MODULES_EXTRA); do (cd $$dir && $(MAKE) $@); done

install::
        #(install $(M168_BB_HOME)/scripts/xxx.sh $(HOME)/bin/xxx.sh)

uninstall::
        #(rm -rf $(HOME)/bin/xxx.sh)


#
# build code subfolders
#
build::
	@echo "+----------------------------------------------------------+"
	@echo "|                                                          |"
	@echo "|              Build all code subfolder                    |"
	@echo "|                                                          |"
	@echo "+----------------------------------------------------------+"
	for dir in $(MODULES_BUILD); do (cd $$dir && $(MAKE)); done

#
# to make things easier
#
update: clean
	(git pull)

lazy: update build
