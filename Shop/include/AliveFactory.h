#ifndef ALIVEFACTORY_H
#define ALIVEFACTORY_H


#include "BaseFactory.h"

class AliveFactory : public BaseFactory
{
public:
  AliveFactory(){}
  BaseInput* createInput();
  BaseOutput* createOutput();
};

#endif //ALIVEFACTORY_H