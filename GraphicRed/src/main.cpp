#include <iostream>
#include "Interface.h"


int main()
{
  {
    Polyline* tr = new Triangle({ 2, 3 }, { 3, 4 }, { 4, 5 });// tri(2, 3, 4);
    Polyline* ell = new Ellipse({ 2, 3 }, { 3, 4 }, { 4, 5 });// ell;
    std::vector<Segment> seg_list;
    Polyline* pl = new Polyline(seg_list);
    pl->Intersect(tr->Intersect(ell));
    tr->Draw();
    tr->Intersect(ell);
    //ell->Intersect(tr);
    //tr->Intersect(ell);
    //ell->Intersect(tr);
    std::cout << tr->getArea() << std::endl;
    std::cout << ell->getArea() << std::endl;
    delete tr;
    delete ell;
  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "OLOLO!!!!! Leaks.... :(\n";

  return 0;
}