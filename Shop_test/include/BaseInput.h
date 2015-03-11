#ifndef BASEINPUT_H
#define BASEINPUT_H
#include "Product.h"
#include <vector>

class BaseInput
{
public:
  BaseInput();
  virtual ~BaseInput();
  virtual void Input(std::vector<Product*>& i_prod_vec);
};


#endif //!BASEINPUT_H