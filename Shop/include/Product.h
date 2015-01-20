#include <iostream>
#include <vector>
#include "Category.h"

class Product
{
  std::vector<Good> m_products;
public:
  Product() : m_products(0){};
  Product(const std::vector<Good>& i_products);
  virtual void Output(std::ostream& os);
  virtual void Input(std::istream& is);
};

class Alive : public Product
{
  std::vector<Good> make_alive_list(const Good& good);
public:
  Alive() : Product(make_alive_list({ "", 0 })){};
  Alive(const Good& good) : Product(make_alive_list(good)){};
  void Output(std::ostream& os);
  void Input(std::istream& is);
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
  void Output(std::ostream& os);
  void Input(std::istream& is);
  static Product* new_unalive()
  {
    return new Unalive();
  }
};