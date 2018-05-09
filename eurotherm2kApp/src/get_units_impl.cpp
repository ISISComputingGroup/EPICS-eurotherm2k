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
#include <fstream>
#include <sstream>
#include <string>

#include "get_units.h"


std::string get_units_from_file(std::string filepath) 
{
    std::string units_prefix = "# units:";
    std::string default_units = "K";
    std::string units = default_units;
    
    std::cout << "Reading filepath: " << filepath << std::endl;
    std::ifstream infile(filepath);
    std::string line;
    while (std::getline(infile, line))
    {
        if (line.substr(0, units_prefix.size()) == units_prefix) {
            try {
                units = line.substr(units_prefix.size(), line.size());
            } catch (std::out_of_range) {
                std::cerr << "Caught out of range error processing line: " << line << std::endl;
            }
        }
    }
    return units;
}


std::string str_from_epics(void* rec)
{
    char buffer[sizeof(epicsOldString)+1];  // +1 for null terminator in the case where epics str is exactly 40 chars (unterminated)
    buffer[sizeof(epicsOldString)] = '\0';
    return std::string(strncpy(buffer, *((epicsOldString*)(rec)), sizeof(epicsOldString)));
}


int get_units_impl(aSubRecord *prec)
{
    std::string base_dir = str_from_epics(prec->a);
    std::string sensor_dir = str_from_epics(prec->b);
    std::string sensor_file = str_from_epics(prec->c);
    
    std::string units = get_units_from_file(base_dir + "/" + sensor_dir + "/" + sensor_file);
    
    std::cout << "Base dir is " << base_dir << std::endl;
    std::cout << "Sensor dir is " << sensor_dir << std::endl;
    std::cout << "Sensor file is " << sensor_file << std::endl;
    std::cout << "Units are " << units << std::endl;
    
    strcpy(*(epicsOldString*) prec->vala, units.c_str());
    return 0;
}
