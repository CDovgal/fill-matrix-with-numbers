#ifndef ALIVEIO_H
#define ALIVEIO_H
#include "BaseIO.h"
#include "AliveProduct.h"
#include "Category.h"

class AliveInput : public BaseInput
{
  Alive *m_alive_product;
  Category* m_category;
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