#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Input.h"
#include "BaseFactory.h"



class Product;

class Category
{
  Category();
  ~Category();
  Category(const Category&) = delete;
  Category& operator=(const Category&) = delete;

  std::vector<Product*> m_prod_vec;
  BaseFactory *m_base_factory;
  BaseInput *m_base_input;
  BaseOutput *m_base_output;
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

