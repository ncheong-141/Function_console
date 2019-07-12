/* Input data structure implementation*/

#include <iostream>
#include "INPUT.h"


void INPUT_int::input_vect(Consoles& console)
{

	std::cout << "Size of vector 1 and 2: ";
	std::cin >> Vsize;

	//  Guard for Vsize (ensure its an int) 
	console.input_Vsizeguard(Vsize);

	// Reserve size to avoid constant copying 
	data_array.	std_array1.reserve(Vsize);
	data_array.	std_array2.reserve(Vsize);
	

	for (int i = 0; i < Vsize; i++)
	{
		if (i == 0)
			std::cout << "Vector 1 -> Element " << i << ": ";
		else
			std::cout << "         -> Element " << i << ": ";

		// Input element (element_input is a double type to not break if double entered)  
		std::cin >> data_array.element_input;

		// Guard incase an integer is not inputed
		console.input_elementguard(data_array.element_input);

		// Input element
		data_array.	std_array1.push_back(data_array.element_input);
	}

	for (int i = 0; i < Vsize; i++)
	{
		if (i == 0)
			std::cout << "Vector 2 -> Element " << i << ": ";
		else
			std::cout << "         -> Element " << i << ": ";

		// Input element (element_input is a double type to not break if double entered)  
		std::cin >> data_array.element_input;

		// Guard incase an integer is not inputed
		console.input_elementguard(data_array.element_input);

		// Input element
		data_array.std_array2.push_back(data_array.element_input);
	}
}

void INPUT_float::input_vect(Consoles& console)
{

	std::cout << "Size of vector 1 and 2: ";
	std::cin >> Vsize;

	//  Guard for Vsize (ensure its an int) 
	console.input_Vsizeguard(Vsize);

	data_array.std_array1.reserve(Vsize);
	data_array.std_array2.reserve(Vsize);
	

	/* Loop for vector 1 input */ 
	for (int i = 0; i < Vsize; i++)
	{
		if (i == 0)
			std::cout << "Vector 1 -> Element " << i << ": ";
		else
			std::cout << "         -> Element " << i << ": ";

		// Input element (element_input is a double type to not break if double entered)  
		std::cin >> data_array.element_input;

		// Guard incase an float is not inputed
		console.input_elementguard(data_array.element_input);

		// Flow control for C-style or std::vector input 
		data_array.std_array1.push_back(data_array.element_input);
	}

	/* Loop for vector 2 input */
	for (int i = 0; i < Vsize; i++)
	{
		if (i == 0)
			std::cout << "Vector 2 -> Element " << i << ": ";
		else
			std::cout << "         -> Element " << i << ": ";

		// Input element (element_input is a double type to not break if double entered)  
		std::cin >> data_array.element_input;

		// Guard incase an float is not inputed
		console.input_elementguard(data_array.element_input);

		// Input element
		data_array.std_array2.push_back(data_array.element_input);
	}
}

void INPUT_double::input_vect(Consoles& console)
{

	std::cout << "Size of vector 1 and 2: ";
	std::cin >> Vsize;

	//  Guard for Vsize (ensure its an int) 
	console.input_Vsizeguard(Vsize);

	// Reserve size to avoid constant copying 
	data_array.std_array1.reserve(Vsize);
	data_array.std_array2.reserve(Vsize);
	

	/* Loop for vector 1 input */
	for (int i = 0; i < Vsize; i++)
	{
		if (i == 0)
			std::cout << "Vector 1 -> Element " << i << ": ";
		else
			std::cout << "         -> Element " << i << ": ";

		// Input element (element_input is a double type to not break if double entered)  
		std::cin >> data_array.element_input;

		// Guard incase an float is not inputed
		console.input_elementguard(data_array.element_input);

		// Flow control for C-style or std::vector input 
		data_array.std_array1.push_back(data_array.element_input);
	}

	/* Loop for vector 2 input */
	for (int i = 0; i < Vsize; i++)
	{
		if (i == 0)
			std::cout << "Vector 2 -> Element " << i << ": ";
		else
			std::cout << "         -> Element " << i << ": ";

		// Input element (element_input is a double type to not break if double entered)  
		std::cin >> data_array.element_input;

		// Guard incase an float is not inputed
		console.input_elementguard(data_array.element_input);

		// Input element
		data_array.std_array2.push_back(data_array.element_input);
	}
}
