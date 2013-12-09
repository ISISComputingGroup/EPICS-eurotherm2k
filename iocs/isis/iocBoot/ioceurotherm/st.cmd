#!../../bin/windows-x64/eurotherm

## You may have to change eurotherm to something else
## everywhere it appears in this file

< envPaths

epicsEnvSet "IOCNAME" "$(P=$(MYPVPREFIX))EUROTHERM"
epicsEnvSet "IOCSTATS_DB" "$(DEVIOCSTATS)/db/iocAdminSoft.db"
epicsEnvSet "STREAM_PROTOCOL_PATH" "$(TOP)/../../eurotherm2kApp/protocol"
epicsEnvSet "TTY" "$(TTY=\\\\\\\\.\\\\COM19)"

cd ${TOP}

## Register all support components
dbLoadDatabase "dbd/eurotherm.dbd"
eurotherm_registerRecordDeviceDriver pdbbase

drvAsynSerialPortConfigure("L0", "$(TTY)", 0, 0, 0, 0)
asynSetOption("L0", -1, "baud", "9600")
asynSetOption("L0", -1, "bits", "7")
asynSetOption("L0", -1, "parity", "even")
asynSetOption("L0", -1, "stop", "1")

## Load record instances
## GAD = Greater Eurtotherm address part
## LAD = Lesser Eurotherm address part
## For example: eurotherm address 1 => GAD = 0 and LAD = 1
## For example: eurotherm address 10 => GAD = 1 and LAD = 0
dbLoadRecords("$(TOP)/db/devEurotherm.db","P=$(IOCNAME)1, GAD=0, LAD=1, PORT=L0")
dbLoadRecords("$(TOP)/db/devEurotherm.db","P=$(IOCNAME)2, GAD=0, LAD=2, PORT=L0")
#dbLoadRecords("$(IOCSTATS_DB)","IOC=$(IOCNAME)")

cd ${TOP}/iocBoot/${IOC}
iocInit

