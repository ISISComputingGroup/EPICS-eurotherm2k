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


const char* get_units_impl(aSubRecord *prec)
{
	std::string a = std::string("");
	return a.c_str();
}
