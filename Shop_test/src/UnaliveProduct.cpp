#include "UnaliveProduct.h"
#include <iostream>

UnaliveProduct::UnaliveProduct(const std::string& i_name, int i_count, int i_price, int i_weight) : 
Product(i_name, i_count, i_price), m_weight(i_weight)
{

}

UnaliveProduct::~UnaliveProduct()
{

}

void UnaliveProduct::Input()
{
  Product::Input();
}

void UnaliveProduct::Output()
{
  Product::Output();
  std::cout << m_weight << std::endl;
}