#
# check for all exports of the avr_env file
#

ifeq "${M168_BB_HOME}" ""
    $(error error: please source a *_env file first!)
endif


# cpu topics
ifeq "${MCU}" ""
    $(error error: please source a *_env file first!)
endif

ifeq "${F_CPU}" ""
    $(error error: please source a *_env file first!)
endif


# communication topics
ifeq "${BAUD}" ""
    $(error error: please source a *_env file first!)
endif


# fuses
ifeq "${LFUSE}" ""
    $(error error: please source a *_env file first!)
endif

ifeq "${HFUSE}" ""
    $(error error: please source a *_env file first!)
endif

ifeq "${EFUSE}" ""
    $(error error: please source a *_env file first!)
endif


# programmer topics
ifeq "${PROGRAMMER}" ""
    $(error error: please source a *_env file first!)
endif

ifeq "${PROGRAMMER_HW}" ""
    $(error error: please source a *_env file first!)
endif

ifeq "${PROGRAMMER_ARGS}" ""
    $(error error: please source a *_env file first!)
endif
