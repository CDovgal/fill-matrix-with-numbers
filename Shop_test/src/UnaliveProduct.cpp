#include "UnaliveProduct.h"

UnaliveProduct::UnaliveProduct(const std::string& i_name, int i_count, int i_price) : 
Product(i_name, i_count, i_price)
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