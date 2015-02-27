#include "UnaliveOutput.h"
#include <iostream>

UnaliveOutput::UnaliveOutput()
{
  std::cout << "Unalive Output Constructor" << std::endl;
}

UnaliveOutput::~UnaliveOutput()
{
  std::cout << "Unalive Output Destructor" << std::endl;
}

void UnaliveOutput::Output()
{
  BaseOutput::Output();
}