#include "AliveProduct.h"
#include <iostream>

AliveProduct::AliveProduct(const std::string& i_name, int i_count, int i_price, int suitability_time) :
Product(i_name, i_count, i_price), m_suitability_time(suitability_time)
{

}

AliveProduct::~AliveProduct()
{

}

void AliveProduct::Input()
{
  Product::Input();
}

void AliveProduct::Output()
{
  Product::Output();
  std::cout << m_suitability_time << std::endl;
}