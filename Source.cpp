/* Main translation file (.cpp) for opening console*/

// External modules 
#include <iostream>
#include <string>
#include <vector>

// Namespace for static library (from static library folder) 
#include "SL_Comptime_Interface.h"
#include "SL_Runtime_Interface.h"

// Interface files 
#include "Consoles.h"
#include "INPUT.h"
#include "GFun.h"


int main() {

	// Static test

	// Establish console object and open (true)
	Consoles console(true);
	
	while (console.getConsolekey() == true) {
		std::cout << "What datatype are you using?\n"
			<< "	0 -> Integer\n"
			<< "	1 -> Float\n"
			<< "	2 -> Double\n"
			<< "Input: ";

		/* Input user defined data type */
		std::cin >> console.dtypeswitch;					// Define input for datatype
		console.input_controlguard(console.dtypeswitch, console.dtype_max);	// Check if input is valid and re-assign value if required. 

		/* Dynamic polymorphism for input data structure */
		INPUT* IN = dtype_derivedclasstype(console);

		/* User defined mathetmatical operation*/
		std::cout << "Console commands:" << std::endl
			<< "	0 -> Close console" << std::endl
			<< "	1 -> Open console" << std::endl
			<< "	2 -> STD style elementwise vector multiplication" << std::endl
			<< "Command: ";

		std::cin >> console.input;						// Define input for mathematical operation
		console.input_controlguard(console.input, console.mathfun_max);		// Check if input is valid and re-assign value if required.


		/* Get function using a switch with enum integer values */
		switch (console.input)
		{
			case (console.close):
			{
				// Close console
				console.setConsolekey(console.input);
				break;
			}
			case (console.STDvector_element):
			{
				/* Input vector function */
				IN->input_vect(console);

				/* Switch statement for calling a function with each data type
				Note, 0 inputted as function overload dependent on input parameter */
				switch (console.dtypeswitch)
				{
					// Call std vector elementwise multiplication function in static library  
				case (console.integer):
				{
					std::vector<int> output_int;
					RMF::elementwise(output_int, IN->getData(0)->std_array1, IN->getData(0)->std_array2);
					output_int.~vector();
					break;
				}
				case (console.floatpt):
				{

					RMF::all(IN->getData(0.0f)->std_array1);

					std::vector<float> output_float;
					RMF::elementwise(output_float, IN->getData(0.0f)->std_array1, IN->getData(0.0f)->std_array2);
					output_float.~vector();
					break;
				}
				case (console.doubles):
				{
					std::vector<double> output_double;
					RMF::elementwise(output_double, IN->getData(0.0)->std_array1, IN->getData(0.0)->std_array2);
					output_double.~vector();
					break;
				}
				};
				break;
			}

		}
		// Call destructor for INPUT object. This deletes both derived class and its base class parameters. 
		IN->~INPUT();
	}
	return 0;
}
