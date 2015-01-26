#pragma once

#include "BaseFactory.h"

class UnaliveFactory : public BaseFactory
{
public:
  UnaliveFactory(){};
  BaseInput* createInput();
  BaseOutput* createOutput();
};