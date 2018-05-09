#include <string.h>
#include <stdlib.h>
#include <registryFunction.h>
#include <aSubRecord.h>
#include <menuFtype.h>
#include <errlog.h>
#include <epicsString.h>
#include <epicsExport.h>

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "get_units.h"


std::string get_units_from_file(std::string filepath) 
{
	
	return "units";
}


int get_units_impl(aSubRecord *prec)
{
	std::string base_dir = std::string(*((epicsOldString*)(prec->a)), sizeof(epicsOldString));
	std::string sensor_dir = std::string(*((epicsOldString*)(prec->b)), sizeof(epicsOldString));
	std::string sensor_file = std::string(*((epicsOldString*)(prec->c)), sizeof(epicsOldString));
	
	std::string units = get_units_from_file(base_dir + "/" + sensor_dir + "/" + sensor_file);
	
	std::cout << "Base dir is " << base_dir << std::endl;
	std::cout << "Sensor dir is " << sensor_dir << std::endl;
	std::cout << "Sensor file is " << sensor_file << std::endl;
	std::cout << "Units are " << units << std::endl;
	
	strcpy(*(epicsOldString*)prec->vala, units.c_str());
	return 0;
}
