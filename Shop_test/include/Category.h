#ifndef CATEGORY_H
#define CATEGORY_H

#include <vector>
#include "Product.h"
#include "BaseFactory.h"

class Category
{
  std::vector<Product*> m_product_container;
  BaseFactory* m_base_factory;
  void clear_data();
public:
  Category();
  ~Category();
  void Input();
  void Output();
  void Generate();
};

#endif //!CATEGORY_H