#ifndef CATEGORY_H
#define CATEGORY_H

#include <vector>
#include "Product.h"
#include "BaseFactory.h"

class Category
{
  std::string m_category_name;
  std::vector<Product*> m_product_container;
  BaseFactory* m_base_factory;
  void clear_data();
  friend class AliveInput;
public:
  Category();
  Category(const std::string& i_name);
  ~Category();
  std::string& name();
  void show_product();
  void Input();
  void Output();
  //void Generate();
};

#endif //!CATEGORY_H