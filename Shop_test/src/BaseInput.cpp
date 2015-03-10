#include "BaseInput.h"
#include <iostream>
#include <string>

BaseInput::BaseInput()
{
  std::cout << "Base Input Constructor" << std::endl;
}

BaseInput::~BaseInput()
{
  std::cout << "Base Input Destructor" << std::endl;
}

Product* BaseInput::Input()
{
  return nullptr;
  std::cout << "Base Input Input" << std::endl;
}