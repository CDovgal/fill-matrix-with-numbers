#include <iostream>
#include "Interface.h"


int main()
{
  //GraphInterface *graph = new Shape;
  GraphInterface *graph = new Rectangle(5, 6);
  
  std::cout << graph->getArea() << std::endl;;
  graph->Draw();

  Triangle tri(2, 3, 4);
  tri.Draw();
  std::cout << tri.getArea() << std::endl;

  return 0;
}