#include "AliveFactory.h"
#include "AliveInput.h"
#include "AliveOutput.h"
#include <iostream>

AliveFactory::AliveFactory()
{
  //std::cout << "Alive Factory Constructor" << std::endl;
}

AliveFactory::~AliveFactory()
{
  //std::cout << "Alive Factory Destructor" << std::endl;
}

BaseInput* AliveFactory::createInput()
{
  return new AliveInput();
}

BaseOutput* AliveFactory::createOutput()
{
  return new AliveOutput();
}