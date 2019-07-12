#pragma once
/* Input data structure */

// External modules
#include <iostream>
#include <vector>

// Internal interfaces 
#include "Consoles.h"

struct INPUT
{
	/* Data types data structure "blueprint"*/
	struct data_structure_int
	{
		// Element input 
		int element_input;	// Container for user input 

		// Data for C style vector calculations 
		int* C_array1;
		int* C_array2;
		std::vector<int> std_array1;
		std::vector<int> std_array2;

		data_structure_int() : element_input(0), C_array1 { nullptr }, C_array2{ nullptr }
		{
			d_log("data_structure structure created")
		}
		~data_structure_int() 
		{
			// De-allocate dynamic memory 
			delete[] C_array1, C_array2, std_array1, std_array2;
			d_log("data_structure structure destroyed")
		}
	};

	struct data_structure_float
	{
		// Element input 
		float element_input;	// Container for user input 

		// Data for C style vector calculations 
		float* C_array1;
		float* C_array2;
		std::vector<float>	std_array1;
		std::vector<float>	std_array2;

		data_structure_float() : element_input(0.0f), C_array1{ nullptr }, C_array2{ nullptr }
		{
			d_log("data_structure structure created")
		}
		~data_structure_float()
		{
			// De-allocate dynamic memory 
			delete[] C_array1, C_array2, std_array1, std_array2;
			d_log("data_structure structure destroyed")
		}
	};

	struct data_structure_double
	{
		// Element input 
		double element_input;	// Container for user input 

		// Data for C style vector calculations 
		double* C_array1;
		double* C_array2;
		std::vector<double>	std_array1;
		std::vector<double>	std_array2;

		data_structure_double() : element_input(0.0),C_array1{ nullptr }, C_array2{ nullptr }
		{
			d_log("data_structure structure created")
		}
		~data_structure_double()
		{
			// De-allocate dynamic memory 
			delete[] C_array1, C_array2, std_array1, std_array2;
			d_log("data_structure structure destroyed")
		}
	};

public:

	int Vsize;	// Vector length

	// Constructor and Destructor (Virtual destructor to allow for derived class destructors to be called) 
	INPUT() : Vsize(0){d_log("Input data structure established")}

	virtual ~INPUT(){d_log("Input data structure destroyed")};

	/* Member functions of base class to be overwritten by derived classes (dependent on user defined data type)*/
	
	virtual void input_vect(Consoles& console) { std::cout << "Warning: Using base class input function!\n"; }

	// Function overloading. Input integer to get correct corresponding data type structure. 
	// (i.e. function parameter is the user input (int, float or double..) 
	virtual data_structure_int*		 getData(int input)		{ std::cout << "Warning: Using base class input function!\n -> Exitting..."; exit(-1);  }
	virtual data_structure_float*	 getData(float input)	{ std::cout << "Warning: Using base class input function!\n -> Exitting..."; exit(-1);  }
	virtual data_structure_double*	 getData(double input)	{ std::cout << "Warning: Using base class input function!\n -> Exitting..."; exit(-1);  }
};


struct INPUT_int : public INPUT
{
private: 
	// Name the array data structure 
	data_structure_int data_array;

public:
	// Derived class constructor and destructor 
	INPUT_int(){d_log("INPUT_int object created")}
	~INPUT_int() override{d_log("INPUT_int object destroyed")}; 

	// Overriding derived class functions 
	void input_vect(Consoles& console) override;
	data_structure_int* getData(int input) override {return &data_array; }
};


struct INPUT_float : public INPUT
{
private:
	// Name the array data structure 
	data_structure_float data_array;

public:

	// Derived class constructor and destructor 
	INPUT_float(){	d_log("INPUT_float object created")}
	~INPUT_float() override{d_log("INPUT_float object destroyed")};

	void input_vect(Consoles& console) override;
	data_structure_float* getData(float input) override { return &data_array; }
};


struct INPUT_double : public INPUT
{
private:
	// Name the array data structure 
	data_structure_double data_array;

public:

	// Derived class constructor and destructor 
	INPUT_double(){d_log("INPUT_double object created")}
	~INPUT_double() override{d_log("INPUT_double object destroyed")};

	void input_vect(Consoles& console) override;
	data_structure_double* getData(double input) override { return &data_array; }
};	
