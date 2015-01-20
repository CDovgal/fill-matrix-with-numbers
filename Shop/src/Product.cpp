#pragma once
#include <iostream>
#include "Product.h"
#include "Category.h"

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
  Good alive_good = good;
  unalive_vec.push_back(alive_good);
  return unalive_vec;
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