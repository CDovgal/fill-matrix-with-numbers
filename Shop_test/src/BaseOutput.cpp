#include "BaseOutput.h"
#include <iostream>

BaseOutput::BaseOutput()
{
  std::cout << "Base Output Constructor" << std::endl;
}

BaseOutput::~BaseOutput()
{
  std::cout << "Base Output Destructor" << std::endl;
}