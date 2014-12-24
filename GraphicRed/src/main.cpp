#include <iostream>
#include <memory>
#include "Interface.h"


int main()
{
  {
    std::shared_ptr<Triangle> tr(new Triangle({ 2, 3 }, { 3, 4 }, { 4, 5 }));
    std::shared_ptr<Ellipse> ell(new Ellipse({ 2, 3 }, { 3, 4 }, { 4, 5 }));
    std::weak_ptr<Ellipse> el2;
    //ell = el2.lock();
    
    //Triangle* tr = new Triangle({ 2, 3 }, { 3, 4 }, { 4, 5 });// tri(2, 3, 4);
    //Polyline* ell = new Ellipse({ 2, 3 }, { 3, 4 }, { 4, 5 });// ell;
    //std::vector<Segment> seg_list;
    /*Polyline* pl = new Polyline(seg_list);
    pl->Intersect(tr->Intersect(ell));*/
    tr->Draw();
    tr->Intersect(ell);//???
    //ell->Intersect(tr);
    //tr->Intersect(ell);
    //ell->Intersect(tr);
    std::cout << tr->getArea() << std::endl;
    std::cout << ell->getArea() << std::endl;
    /*delete tr;
    delete ell;*/
  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "OLOLO!!!!! Leaks.... :(\n";

  return 0;
}