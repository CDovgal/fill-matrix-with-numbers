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
  virtual void Input(std::istream& is);
};

class BaseOutput
{
public:
  BaseOutput()
  {
    std::cout << "Base Output" << std::endl;
  };
  virtual void Output(std::ostream& os);
};

class AliveInput : public BaseInput
{
  //Alive *alive_product;
public:
  AliveInput()
  {
    std::cout << "Alive Input" << std::endl;
  };
  void Input(std::istream& is);
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

class UnaliveInput : public BaseInput
{
  //Unalive *unalive_product;
public:
  UnaliveInput()
  {
    std::cout << "Unalive Input" << std::endl;
  };
  void Input(std::istream& is);
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

