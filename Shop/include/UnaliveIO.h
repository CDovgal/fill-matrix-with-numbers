#ifndef UNALIVEIO_H
#define UNALIVEIO_H

#include "BaseIO.h"

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

#endif //UNALIVEIO_H