#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Input.h"
#include "BaseFactory.h"

class Good
{
  std::string name;
  int count;
public:
  Good(){}
  Good(const std::string i_name, int i_count): name(i_name), count(i_count){}
  friend std::ostream& operator<<(std::ostream& output, const Good& i_good);
  friend std::istream& operator>>(std::istream& input, Good& i_good);
};

class Product;

class Category
{
  std::vector<Product*> m_prod_cont;
  BaseFactory *bf;
public:
  Category();
  ~Category();
};

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