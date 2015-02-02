// Shop_Lib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Shop_Lib.h"


// This is an example of an exported variable
SHOP_LIB_API int nShop_Lib=0;

// This is an example of an exported function.
SHOP_LIB_API int fnShop_Lib(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Shop_Lib.h for the class definition
CShop_Lib::CShop_Lib()
{
	return;
}
