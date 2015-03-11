#include "UnaliveOutput.h"
#include <iostream>
#include "Category.h"

UnaliveOutput::UnaliveOutput()
{
  //std::cout << "Unalive Output Constructor" << std::endl;
}

UnaliveOutput::~UnaliveOutput()
{
  //std::cout << "Unalive Output Destructor" << std::endl;
}

void UnaliveOutput::Output(std::vector<Product*>& i_prod_vec)
{
  /*if (!i_prod_vec.empty())
  for (unsigned i = 0; i < i_prod_vec.size(); ++i)
  {
    std::string type = typeid(*i_prod_vec.at(i)).name();
    if (type == "class UnaliveProduct")
      i_prod_vec.at(i)->Output();
  }*/
  BaseOutput::Output(i_prod_vec);
}