#Makefile at top of application tree
TOP = .
include $(TOP)/configure/CONFIG
DIRS := $(DIRS) $(filter-out $(DIRS), configure)
DIRS := $(DIRS) $(filter-out $(DIRS), $(wildcard *App))
DIRS := $(DIRS) $(filter-out $(DIRS), $(wildcard *app))
DIRS := $(DIRS) $(filter-out $(DIRS), $(wildcard iocBoot))
DIRS := $(DIRS) $(filter-out $(DIRS), $(wildcard iocboot))
# Comment out the following line to creation of example iocs and documentation
DIRS := $(DIRS) $(filter-out $(DIRS), $(wildcard etc))
include $(TOP)/configure/RULES_TOP

ioctests:
	.\system_tests\run_tests.bat
