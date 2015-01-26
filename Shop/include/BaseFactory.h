#ifndef BASEFACTORY_H
#define BASEFACTORY_H

#include <iostream>
#include "BaseIO.h"

class BaseFactory
{
public:
  virtual ~BaseFactory(){};
  virtual BaseInput* createInput() = 0;
  virtual BaseOutput* createOutput() = 0;
};

#endif //BASEFACTORY_H

