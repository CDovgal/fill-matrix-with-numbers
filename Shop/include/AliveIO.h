#ifndef ALIVEIO_H
#define ALIVEIO_H
#include "BaseIO.h"
#include "AliveProduct.h"

class AliveInput : public BaseInput
{
  Alive *m_alive_product;
  Product* m_product;
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

#endif //ALIVEO_H