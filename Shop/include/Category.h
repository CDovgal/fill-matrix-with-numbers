#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <vector>
#include <string>
#include "BaseIO.h"
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
  void read_from_file();
  void write_to_file();
};


typedef Product* (*PF)();

class IoRegistryMap
{
public:
  void RegisterClasses();
};

#endif //CATEGORY_H