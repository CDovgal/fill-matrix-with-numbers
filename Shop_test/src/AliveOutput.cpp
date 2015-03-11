#include "AliveOutput.h"
#include <iostream>
#include "Category.h"

AliveOutput::AliveOutput()
{
  //std::cout << "Alive Output Constructor" << std::endl;
}

AliveOutput::~AliveOutput()
{
  //std::cout << "Alive Output Destructor" << std::endl;
}

void AliveOutput::Output(std::vector<Product*>& i_prod_vec)
{
  /*if (!i_prod_vec.empty())
  for (unsigned i = 0; i < i_prod_vec.size(); ++i)
  {
    std::string type = typeid(*i_prod_vec.at(i)).name();
    if (type == "class AliveProduct")
      i_prod_vec.at(i)->Output();
  }*/
  BaseOutput::Output(i_prod_vec);
}