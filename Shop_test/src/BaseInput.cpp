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

void BaseInput::Input(std::vector<Product*>& i_prod_vec)
{
  std::cout << "Base Input Input" << std::endl;
}