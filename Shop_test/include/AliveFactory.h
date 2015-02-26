#ifndef ALIVEFACTORY_H
#define ALIVEFACTORY_H

#include "BaseFactory.h"
#include "BaseInput.h"
#include "BaseOutput.h"

class AliveFactory : public BaseFactory
{
public:
  AliveFactory();
  ~AliveFactory();
  BaseInput* createInput();
  BaseOutput* createOutput();
};

#endif //!ALIVEFACTORY_H