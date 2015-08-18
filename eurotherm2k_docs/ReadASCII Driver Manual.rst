****************
ReadASCII Manual
****************

The purpose of this driver is to linearly ramp output values whilst simultaneously looking up other outputs from a file. The driver was originally intended to be used with a Eurotherm2K device to ramp set points whilst looking up PID values. However, the driver should be adaptable to other ramping or File I/O tasks.

--------------
The Driver PVs
--------------

The ramp and lookup are controlled through the RAMPON and LUTON PVs respectively. These are independent controls and so enable 4 different modes:

#. Ramp Off, Lookup Off: Normal operation, the user sets values manually and they are immediately set
#. Ramp Off, Lookup On: User sets set point values manually, PID values are automatically changed accordingly. PID values can also be set manually
#. Ramp On, Lookup Off: The set point is ramped towards the value set by the user. PID values do not changed automatically.
#. Ramp On, Lookup On: The set point is ramped towards the value set by the user. PID values automatically change accordingly.

Prior to using the lookup table the file directory must be set. This consists of a 'base' directory, which should be set at start up through the st.cmd, and a target directory to swap between files within the base folder. The base folder is currently set to "C:\InstrumentSettings".

Ramp rate is controlled by the RATE PV and is set to a default of 1 K/s, this can be changed during the ramp by the user. Whilst ramping the RAMPING PV is set to high.

Ramps begin from the current temperature as read from the CURRENT_TEMP PV and end at the temperature set by TEMP:SP.

The output of the ramp is given by OUT_SP, OUT_P, OUT_I, OUT_D and OUT_MAX.

-------------------------------------
Using the Driver with the Eurotherm2K
-------------------------------------

Within the Eurotherm2K IOC there are a number of other PVs which route the ReadASCII PVs to the Eurotherm controller, none of which should be accessed by the user. Amongst these are PVs that use a lookup located at "C:\InstrumentSettings\calib\sensors" to convert between sensor reading and actual temperature. This means that all inputs to the ReadASCII PVs are real temperatures.

The Eurotherm IOC may control a number of devices. For each device a new driver must be configured and passed to the .db, an example of this can be seen in the st.cmd of the Eurotherm.