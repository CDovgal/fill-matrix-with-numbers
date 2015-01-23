#pragma once
#include <iostream>
#include "Product.h"
#include "Category.h"

std::ostream& operator<<(std::ostream& output, const Good& i_good)
{
  output << i_good.name.c_str() << std::endl << i_good.count << std::endl;
  return output;
}

std::istream& operator>>(std::istream& input, Good& i_good)
{
  input >> i_good.name >> i_good.count;
  return input;
}

Product::Product(const std::vector<Good>& i_products) : m_products(i_products)
{

}

void Product::read_from_file(std::istream& is)
{
  std::string line;
  size_t product_count;
  is >> product_count;
  m_products.resize(product_count);
  for (unsigned i = 0; i < product_count; ++i)
    is >> m_products.at(i);
}

void Product::write_to_file(std::ostream& os)
{
  os << m_products.size() << std::endl;
  for (unsigned i = 0; i < m_products.size(); ++i)
    os << m_products.at(i);
}

std::vector<Good> Alive::make_alive_list(const Good& good)
{
  std::vector<Good> alive_vec;
  Good alive_good = good;
  alive_vec.push_back(alive_good);
  return alive_vec;
}

std::vector<Good> Unalive::make_unalive_list(const Good& good)
{
  std::vector<Good> unalive_vec;
  Good unalive_good = good;
  unalive_vec.push_back(unalive_good);
  return unalive_vec;
}


void Alive::write_to_file(std::ostream& os)
{
  Product::write_to_file(os);
}

void Unalive::write_to_file(std::ostream& os)
{
  Product::write_to_file(os);
}


void Alive::read_from_file(std::istream& is)
{
  Product::read_from_file(is);
}

void Unalive::read_from_file(std::istream& is)
{
  Product::read_from_file(is);
}