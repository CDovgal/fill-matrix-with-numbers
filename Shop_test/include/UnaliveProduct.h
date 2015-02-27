#ifndef UNALIVEPRODUCT_H
#define UNALIVEPRODUCT_H

#include "Product.h"


class UnaliveProduct : public Product
{
  //std::string type;
public:
  UnaliveProduct(const std::string& i_name, int i_count);
  ~UnaliveProduct();
  void Input();
  void Output();
};

#endif //!UNALIVEPRODUCT_H