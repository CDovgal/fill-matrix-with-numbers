#include <iostream>
#include "Interface.h"


int main()
{
  //GraphInterface *graph = new Shape;

  Triangle tri(2, 3, 4);
  tri.Draw();
  std::cout << tri.getArea() << std::endl;

  return 0;
}