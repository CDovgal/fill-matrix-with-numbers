#pragma once
#include <iostream>
//#include "Category.h"


class BaseInput
{
public:
  BaseInput()
  {
    std::cout << "Base Input" << std::endl;
  };
  virtual void Input();
};

class BaseOutput
{
public:
  BaseOutput()
  {
    std::cout << "Base Output" << std::endl;
  };
  virtual void Output();
};

class AliveInput : public BaseInput
{
public:
  AliveInput()
  {
    std::cout << "Alive Input" << std::endl;
  };
  void Input();
};

class AliveOutput : public BaseOutput
{
public:
  AliveOutput()
  {
    std::cout << "Alive Output" << std::endl;
  };
  void Output();
};

class UnaliveInput : public BaseInput
{
public:
  UnaliveInput()
  {
    std::cout << "Unalive Input" << std::endl;
  };
  void Input();
};

class UnaliveOutput : public BaseOutput
{
public:
  UnaliveOutput()
  {
    std::cout << "Unalive Output" << std::endl;
  };
  void Output();
};

