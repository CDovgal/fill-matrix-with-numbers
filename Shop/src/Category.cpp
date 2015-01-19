#include "Category.h"
#include "Shop.h"

Product::Product(const std::vector<Good>& i_products) : m_products(i_products)
{

}

void Product::Input(std::istream& is)
{
  std::string line;
  size_t product_count;
  is >> product_count;
  m_products.resize(product_count);
  for (unsigned i = 0; i < product_count; ++i)
    is >> m_products.at(i);
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


void Alive::Input(std::istream& is)
{
  Product::Input(is);
}

void Unalive::Input(std::istream& is)
{
  Product::Input(is);
}