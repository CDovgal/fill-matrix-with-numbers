#include "UnaliveProduct.h"

UnaliveProduct::UnaliveProduct(const std::string& i_name, int i_count) : Product(i_name, i_count)
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
}