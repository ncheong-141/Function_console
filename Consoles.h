#pragma once
/* Console interface file*/

// Debug log system to display information only relevant for debug mode 
#define MC_DEBUG 0

#if MC_DEBUG==1
#define d_log(x) std::cout << x << std::endl;
#else
#define d_log(x)
#endif

#if 1
// External module
#include <iostream>

class Consoles
{
private:
	bool consolekey;	// Variable to control if console opens or closes ( true for open, false for close )

public:
	// Constructor 
	Consoles(bool open) : consolekey(open) { std::cout << "Console opened.\n"; }

	// Destructor 
	~Consoles() { std::cout << "Console closed.\n"; }

	/* Switch enum for different functions*/
	enum Function_index
	{
		close = 0,			// Close console 
		open,				// Open console
		STDvector_element,		// vector elemtwise multiplication using std::vector
		mathfun_max,			// mathfunction choice limit (-1) 
	};

	/* Switch enum for different datatypes*/
	enum Datatype_index { integer = 0, floatpt, doubles, dtype_max };

	/* Input flow control containers */
	int  dtypeswitch = 0;				// Control value for datatype selection
	int  input = 0;					// Control value for mathematical operation 

	/* Console member functions */

	// Get the consolekey (Open or closed?) 
	const bool getConsolekey() { return consolekey; }

	// Get the input value
	const int getInputvalue() { return input;  }

	// Set consolekey for closing the console (ternary operator for filtering input so its only true or false)
	void setConsolekey(const char input) { consolekey = input == close ? false : true; }


	/* Guard functions for input */

	// Template for datatype to compile multiple functions of this (i.e. with int, float and double) but only need to define once

	// Note, invalid inputs entail: Meaningless input, extraneous input, failed extraction and numeric value overflow. 
	// - std::cin.fail() while loop deals with failed extraction and numeric value overflow. 
	// - extraneous input is dealt with by clearing input buffer with std::cin.ignore(INT_MAX,'\n') 
	// - Meaningless input is dealt with with the while loop index condition.

	// Control guard for choosing datatype and mathematical functions 
	template<typename T>
	void input_controlguard(T& value, const int& choicelimit)
	{
		//		if invalid input         or   input exceeds index of choices (stops meaningless inputs to code) 
		while ((std::cin.fail() == true) || value >= choicelimit)
		{
			std::cin.clear();				// Restore cin to normal operation state from failure state
			std::cin.ignore(INT_MAX, '\n');   		// Ignore last input (clear upto INT_MAX characters until you reach an 'n')  
			std::cout << "Please enter a valid variable: ";
			std::cin >> value;
		}

		// Clear cin buffer if any additional input is truncated off extraction and left in buffer (remove extraneous input) 
		std::cin.ignore(INT_MAX, '\n');   // Ignore last input (clear upto INT_MAX characters until you reach an 'n')  
	}

	// Element guard to avoid invalid input of input data
	template<typename T>
	void input_elementguard(T& value)
	{
		while (std::cin.fail() == true)
		{
			std::cin.clear();				// Restore cin to normal operation state 
			std::cin.ignore(INT_MAX, '\n');  		// Ignore last input (clear upto INT_MAX characters until you reach an '\n'
			std::cout << "Please enter a valid variable: ";
			std::cin >> value;
		}

		if (dtypeswitch == integer)
		{
			// Look at first character in buffer
			if ((char)std::cin.peek() == '.') { std::cout << "Warning: double value entered and has been floored.\n"; }
		}

		// Clear cin buffer if any additional input is truncated off extraction and left in buffer (remove extraneous input) 
		std::cin.ignore(INT_MAX, '\n');   // Ignore last input (clear upto INT_MAX characters until you reach an 'n')  
	}

	// Vector size guard to ensure integer is passes and to warn if not. 
	void input_Vsizeguard(int& value)
	{
		while (std::cin.fail() == true)
		{
			std::cout << " std::cin.fail() called!)\n";
			std::cin.clear();				 // Restore cin to normal operation state 
			std::cin.ignore(INT_MAX, '\n'); 		 // Ignore last input (clear upto INT_MAX characters until you reach an '\n'
			std::cout << "Please enter a valid variable: ";
			std::cin >> value;
		}

		// cin.peek() retrieves next character in the buffer in integer form. If it is a decimal point, it means a double has been entererd
		// User should be warned. 
		if ((char)std::cin.peek() == '.')
		{
			std::cout << "Warning: double value entered and has been floored.\n";
		}

		// Clear cin buffer if any additional input is truncated off extraction and left in buffer (remove extraneous input) 
		std::cin.ignore(INT_MAX, '\n');   // Ignore last input (clear upto INT_MAX characters until you reach an 'n')  
	}
};
#endif
