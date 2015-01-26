#include "BaseFactory.h"

class AliveFactory : public BaseFactory
{
public:
  AliveFactory(){}
  BaseInput* createInput();
  BaseOutput* createOutput();
};