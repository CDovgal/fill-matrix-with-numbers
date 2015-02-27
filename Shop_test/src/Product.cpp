#include "Product.h"
#include <iostream>

Product::Product(const std::string& i_name, int i_count) : m_name(i_name), m_count(i_count)
{

}


Product::~Product()
{

}

void Product::Input()
{
  std::cout << "Product Input" << std::endl;
}

void Product::Output()
{
  std::cout << "Product Output" << std::endl;
}