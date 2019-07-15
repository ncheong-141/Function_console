# Function_console
Console app to allow the user to select a numerical function with a desired data type for execution.

Program objectives: 

          - Allow the user to select a numerical function
          
          - Allow the user to execute the function with any data type. 
          
          - Guard inputs for any invalidities such as meaningless input, extraneous input, failed extraction, and numeric value overflow. 
                    
                    
Notes on code structure: 
          - Console linked to static library of numerical functions.
          
          - Console data structure created as a class to group all information about the console together such as:
          
              -> Flow control paramaters.
              
              -> Enums for verbose lists which can be used for flow control of the console. 
              
              -> Control guards as member functions for invalid input 
              
          - Flow control of console (which function it selects due to input etc) controlled using primarily switches.  
          
          - Inputs are put inside an INPUT class where the data type selection using runtime dynamic polymorphism (inherited classes).

          
          
Learning objectives:

          - Code safety 
          
          - Use of inherted classes and dynamic polymorphism 
          
          - Practising object oriented style of programming. 
          
