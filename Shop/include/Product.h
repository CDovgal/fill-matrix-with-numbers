#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <vector>
//#include "Category.h"

class Good
{
  std::string name;
  int count;
public:
  Good(){}
  Good(const std::string i_name, int i_count) : name(i_name), count(i_count){}
  friend std::ostream& operator<<(std::ostream& output, const Good& i_good);
  friend std::istream& operator>>(std::istream& input, Good& i_good);
};

class Product
{
  std::vector<Good> m_products;
public:
  Product() : m_products(0){};
  Product(const std::vector<Good>& i_products);
  virtual void write_to_file(std::ostream& os);
  virtual void read_from_file(std::istream& is);
};

#endif //PRODUCT_H