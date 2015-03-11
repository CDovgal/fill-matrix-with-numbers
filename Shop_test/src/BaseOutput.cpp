#include "BaseOutput.h"
#include <iostream>
#include <vector>
#include "Product.h"

BaseOutput::BaseOutput()
{
  std::cout << "Base Output Constructor" << std::endl;
}

BaseOutput::~BaseOutput()
{
  std::cout << "Base Output Destructor" << std::endl;
}

void BaseOutput::Output(std::vector<Product*>& i_prod_vec)
{
  if (!i_prod_vec.empty())
  for (unsigned i = 0; i < i_prod_vec.size(); ++i)
  {
    std::string out_type = typeid(*this).name();
    std::string prod_type = typeid(*i_prod_vec.at(i)).name();
    if (out_type == "class AliveOutput" && prod_type == "class AliveProduct")
      i_prod_vec.at(i)->Output();
    else if (out_type == "class UnaliveOutput" && prod_type == "class UnaliveProduct")
      i_prod_vec.at(i)->Output();
  }
}