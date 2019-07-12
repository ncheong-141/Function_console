/* Console translation file (implementation*/
#if 1
#include "GFun.h" 

INPUT* dtype_derivedclasstype(Consoles& console)
{

	switch (console.dtypeswitch)
	{
	case (console.integer):
		{
			INPUT* IN_Ptr = new INPUT_int;
			return IN_Ptr;	// Return the memory address of heap-allocated object
		}					// IN_Ptr is stack allocated so it dies by the end of this frame
		break;
	case (console.floatpt):
		{
			INPUT* IN_Ptr = new INPUT_float;
			return IN_Ptr;
		}
		break;
	case (console.doubles):
		{
			INPUT* IN_Ptr = new INPUT_double;
			return IN_Ptr;
		}
		break;
	}
}
#endif