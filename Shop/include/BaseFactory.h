#pragma once
#include <iostream>
#include <Input.h>

class BaseFactory
{
public:
  virtual ~BaseFactory(){};
  virtual BaseInput* createInput() = 0;
  virtual BaseOutput* createOutput() = 0;
};



