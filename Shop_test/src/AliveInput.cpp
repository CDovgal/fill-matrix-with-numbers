#include "AliveInput.h"
#include <iostream>

AliveInput::AliveInput()
{
  std::cout << "Alive Input Constructor" << std::endl;
}

AliveInput::~AliveInput()
{
  std::cout << "Alive Input Destructor" << std::endl;
}

void AliveInput::Input()
{
  BaseInput::Input();
}