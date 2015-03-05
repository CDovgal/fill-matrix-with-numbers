#include <iostream>
#include "Shop.h"

int main()
{
  {
    Shop sh;
    sh.startup_menu();
    sh.admin_menu();
  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "MEMORY LEAKS..." << std::endl;
  else
    std::cout << "MEMORY OK..." << std::endl;
  return 0;
}