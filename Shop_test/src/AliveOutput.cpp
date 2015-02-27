#include "AliveOutput.h"
#include <iostream>

AliveOutput::AliveOutput()
{
  std::cout << "Alive Output Constructor" << std::endl;
}

AliveOutput::~AliveOutput()
{
  std::cout << "Alive Output Destructor" << std::endl;
}

void AliveOutput::Output()
{
  BaseOutput::Output();
}