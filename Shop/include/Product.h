#pragma once
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

class Alive : public Product
{
  std::vector<Good> make_alive_list(const Good& good);
public:
  Alive() : Product(make_alive_list({ "", 0 })){};
  Alive(const Good& good) : Product(make_alive_list(good)){};
  void write_to_file(std::ostream& os);
  void read_from_file(std::istream& is);
  static Product* new_alive()
  {
    return new Alive();
  }
};

class Unalive : public Product
{
  std::vector<Good> make_unalive_list(const Good& good);
public:
  Unalive() : Product(make_unalive_list({ "", 0 })){};
  Unalive(const Good& good) : Product(make_unalive_list(good)){}
  void write_to_file(std::ostream& os);
  void read_from_file(std::istream& is);
  static Product* new_unalive()
  {
    return new Unalive();
  }
};