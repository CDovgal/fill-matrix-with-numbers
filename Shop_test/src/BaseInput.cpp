#include "BaseInput.h"
#include <iostream>

BaseInput::BaseInput()
{
  std::cout << "Base Input Constructor" << std::endl;
}

BaseInput::~BaseInput()
{
  std::cout << "Base Input Destructor" << std::endl;
}

void BaseInput::Input()
{
  std::cout << "BaseInput Input Function" << std::endl;
}