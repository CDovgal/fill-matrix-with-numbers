#ifndef ALIVEPRODUCT_H
#define ALIVEPRODUCT_H

#include "Product.h"
#include <string>

class AliveProduct : public Product
{
  int m_suitability_time;
  friend class AliveOutput;
public:
  AliveProduct(const std::string& i_name, int i_count, int i_price, int suitability_time);
  ~AliveProduct();
  void Input();
  void Output();
};

#endif //!ALIVEPRODUCT_H