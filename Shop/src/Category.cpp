#include "Category.h"

Product::Product(const std::vector<Good>& i_products) : m_products(i_products)
{

}

void Product::Output(std::ostream& os)
{
  for (unsigned i = 0; i < m_products.size(); ++i)
    os << m_products.at(i);
}

void Alive::Output(std::ostream& os)
{
  Product::Output(os);
}

void Unalive::Output(std::ostream& os)
{
  Product::Output(os);
}