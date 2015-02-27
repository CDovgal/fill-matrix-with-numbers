#include "AliveProduct.h"

AliveProduct::AliveProduct(const std::string& i_name, int i_count) : Product(i_name, i_count)
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