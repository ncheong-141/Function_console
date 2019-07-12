#pragma once
/* General function interface*/
// Required as I cannot have an INPUT return type function in the console implementation as INPUT relates to console.. ? 
#if 1
// External modules
#include <iostream>

// Internal modules
#include "INPUT.h"
#include "Consoles.h"

// Function to establish derived class based on data type. 
INPUT* dtype_derivedclasstype(Consoles& console);

#endif