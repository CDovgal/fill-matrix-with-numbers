#include <iostream>
#include "Interface.h"


int main()
{
  
  Polyline* tr = new Triangle({2,3},{3,4},{4,5});// tri(2, 3, 4);
  Polyline* ell = new Ellipse({ 2, 3 }, { 3, 4 }, { 4, 5 });// ell;
  tr->Draw();
  //tr->Intersect(ell);
  //ell->Intersect(tr);
  std::cout << tr->getArea() << std::endl;
  std::cout << ell->getArea() << std::endl;


  return 0;
}