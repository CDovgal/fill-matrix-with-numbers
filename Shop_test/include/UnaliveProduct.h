#ifndef UNALIVEPRODUCT_H
#define UNALIVEPRODUCT_H

#include "Product.h"


class UnaliveProduct : public Product
{
  int m_weight;
  friend class UnaliveOutput;
public:
  UnaliveProduct(const std::string& i_name, int i_count, int i_price, int i_weight);
  ~UnaliveProduct();
  void Input();
  void Output();
};

#endif //!UNALIVEPRODUCT_H