#include <iostream>
#include "Category.h"


class BaseInput : public Category
{
public:
  BaseInput()
  {
    std::cout << "Base Input" << std::endl;
  };
  virtual void Input(std::istream& is);
};

class AliveInput : public BaseInput
{
public:
  AliveInput()
  {
    std::cout << "Alive Input" << std::endl;
  };
  void Input(std::istream& is);
};

class UnaliveInput : public BaseInput
{
public:
  UnaliveInput()
  {
    std::cout << "Unalive Input" << std::endl;
  };
  void Input(std::istream& is);
};


class BaseOutput : public Category
{
public:
  BaseOutput()
  {
    std::cout << "Base Output" << std::endl;
  };
  virtual void Output(std::ostream& os);
};

class AliveOutput : public BaseOutput
{
public:
  AliveOutput()
  {
    std::cout << "Alive Output" << std::endl;
  };
  void Output(std::ostream& os);
};

class UnaliveOutput : public BaseOutput
{
public:
  UnaliveOutput()
  {
    std::cout << "Unalive Output" << std::endl;
  };
  void Output(std::ostream& os);
};

