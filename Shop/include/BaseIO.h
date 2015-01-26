#ifndef BASEIO_H
#define BASEIO_H

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

#endif //BASEIO_H