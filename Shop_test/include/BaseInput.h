#ifndef BASEINPUT_H
#define BASEINPUT_H
#include "Product.h"

class BaseInput
{
public:
  BaseInput();
  virtual ~BaseInput();
  virtual Product* Input();
};


#endif //!BASEINPUT_H