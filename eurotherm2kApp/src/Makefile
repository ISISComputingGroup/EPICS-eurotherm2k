TOP=../..
include $(TOP)/configure/CONFIG
#=======================================

LIBRARY_IOC += EurothermSup

# EurothermSup_DBD += asyn.dbd
# EurothermSup_DBD += utilities.dbd

EurothermSup_LIBS += $(EPICS_BASE_IOC_LIBS)
EurothermSup_LIBS += asyn utilities
EurothermSup_LIBS += asubFunctions

#=======================================
include $(TOP)/configure/RULES
