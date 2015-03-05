#include "AliveProduct.h"

AliveProduct::AliveProduct(const std::string& i_name, int i_count, int i_price) : 
Product(i_name, i_count, i_price)
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
}