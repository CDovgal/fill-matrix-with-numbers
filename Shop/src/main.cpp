#include <iostream>
#include "Shop.h"
#include "Category.h"


int main()
{
  Shop sh;
  switch (sh.start_menu())
  {
  case 1:
    sh.admin_menu();
    break;
  case 2:
    std::cout << "this is customer menu" << std::endl;
    break;
  }  
  return 0;
}