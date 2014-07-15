TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = eurotherm
# eurotherm.dbd will be created and installed
DBD += eurotherm.dbd

# eurotherm.dbd will be made up from these files:
eurotherm_DBD += base.dbd

eurotherm_DBD += stream.dbd
eurotherm_DBD += asyn.dbd
eurotherm_DBD += drvAsynSerialPort.dbd
eurotherm_DBD += drvAsynIPPort.dbd
eurotherm_DBD += devIocStats.dbd
eurotherm_DBD += cvtRecord.dbd
eurotherm_DBD += sseqRecord.dbd
eurotherm_DBD += calcSupport.dbd
eurotherm_DBD += pvdump.dbd 

eurotherm_LIBS += stream pcre cvtRecord csmbase std calc sscan
eurotherm_LIBS += asyn devIocStats pvdump easySQLite sqlite utilities icpconfig

# eurotherm_registerRecordDeviceDriver.cpp derives from eurotherm.dbd
eurotherm_SRCS += eurotherm_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
eurotherm_SRCS_DEFAULT += eurothermMain.cpp
eurotherm_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#eurotherm_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
eurotherm_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

