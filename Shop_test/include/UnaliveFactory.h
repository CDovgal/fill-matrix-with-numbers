#ifndef UNALIVEFACTORY_H
#define UNALIVEFACTORY_H

#include "BaseFactory.h"
#include "BaseInput.h"
#include "BaseOutput.h"

class UnaliveFactory : public BaseFactory
{
public:
  UnaliveFactory();
  ~UnaliveFactory();
  BaseInput* createInput();
  BaseOutput* createOutput();
};

#endif //!UNALIVEFACTORY_H