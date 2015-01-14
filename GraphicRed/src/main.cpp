#include <iostream>
#include <memory>
#include "Interface.h"


int main()
{
  { 
    //Triangle* tr = new Triangle({ 2, 3 }, { 3, 4 }, { 4, 5 });// tri(2, 3, 4);
    //Polyline* ell = new Ellipse({ 2, 3 }, { 3, 4 }, { 4, 5 });// ell;
    /*std::unique_ptr<Triangle> tri(new Triangle({ 2, 3 }, { 3, 4 }, { 4, 5 }));
    std::unique_ptr<Triangle> tr2(new Triangle({ 2, 3 }, { 3, 4 }, { 4, 5 }));
    std::unique_ptr<Ellipse> ell(new Ellipse({ 2, 3 }, { 3, 4 }, { 4, 5 }));
    std::unique_ptr<Ellipse> ell2(new Ellipse({ 2, 3 }, { 3, 4 }, { 4, 5 }));


    
    tri->Draw();
    tri->Intersect(ell.get());
    ell->Intersect(tri.get());
    tri->Intersect(tr2.get());
    ell->Intersect(ell2.get());
    std::cout << tri->getArea() << std::endl;
    std::cout << ell->getArea() << std::endl;*/
     
    IoRegistryMap io;
    io.RegisterClasses();
    World& instance = World::instance();
    instance.Generate();
    instance.Output();
    std::cout << "-------------------------------------------------\n";
    instance.Input();
    instance.Output();
    

  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "OLOLO!!!!! Leaks.... :(\n";

  return 0;
}