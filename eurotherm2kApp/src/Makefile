TOP=../..
include $(TOP)/configure/CONFIG
#=======================================

DBD += EurothermSup.dbd

LIBRARY_IOC += EurothermSup

# EurothermSup_DBD += asyn.dbd
# EurothermSup_DBD += utilities.dbd

EurothermSup_DBD += asubFunctions.dbd
EurothermSup_DBD += get_units.dbd

EurothermSup_LIBS += $(EPICS_BASE_IOC_LIBS)
EurothermSup_LIBS += asyn utilities
EurothermSup_LIBS += asubFunctions

EurothermSup_SRCS += get_units_impl.cpp get_units.c

#=======================================
include $(TOP)/configure/RULES
