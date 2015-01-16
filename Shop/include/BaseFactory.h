#include <iostream>
#include <Input.h>

class BaseFactory
{
public:
  virtual ~BaseFactory(){};
  virtual BaseInput* createInput() = 0;
  virtual BaseOutput* createOutput() = 0;
};

class AliveFactory : public BaseFactory
{
public:
  AliveFactory(){}
  BaseInput* createInput()
  {
    return new BaseInput();
  }
  BaseOutput* createOutput()
  {
    return new BaseOutput();
  }
};

class UnaliveFactory : public BaseFactory
{
public:
  UnaliveFactory(){};
  BaseInput* createInput()
  {
    return new BaseInput();
  }
  BaseOutput* createOutput()
  {
    return new BaseOutput();
  }
};