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
  Category();
  ~Category();
  Category(const Category&) = delete;
  Category& operator=(const Category&) = delete;

  std::vector<Product*> m_prod_vec;
  BaseFactory *bf;
  void clear_data();
  Product* get_product(std::istream& is);
public:
  static Category& instance()
  {
    static Category instance;
    return instance;
  }
  void Generate();
  void Input();
  void Output();
};


typedef Product* (*PF)();

class IoRegistryMap
{
public:
  void RegisterClasses();
};

