// Shop_Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
  HMODULE Hmod = LoadLibrary(L"TestLib.dll");
  if (Hmod == NULL)
  {
    std::cout << "Cannot load library" << std::endl;
    return 0;
  }


	return 0;
}

