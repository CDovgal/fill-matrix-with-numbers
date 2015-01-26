#ifndef UNALIVEFACTORY_H
#define UNALIVEFACTORY_H

#include "BaseFactory.h"

class UnaliveFactory : public BaseFactory
{
public:
  UnaliveFactory(){};
  BaseInput* createInput();
  BaseOutput* createOutput();
};

#endif //UNALIVEFACTORY_H