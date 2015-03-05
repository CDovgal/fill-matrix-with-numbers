#ifndef ALIVEPRODUCT_H
#define ALIVEPRODUCT_H

#include "Product.h"
#include <string>

class AliveProduct : public Product
{
  //std::string type;
public:
  AliveProduct(const std::string& i_name, int i_count, int i_price);
  ~AliveProduct();
  void Input();
  void Output();
};

#endif //!ALIVEPRODUCT_H