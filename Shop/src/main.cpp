#include <iostream>
#include "Shop.h"


int main()
{
  Shop& instance = Shop::instance();
  
  switch (instance.start_menu())
  {
  case 1:
    instance.admin_menu();
    break;
  case 2:
    std::cout << "this is customer menu" << std::endl;
    break;
  }
  
  std::cout << "End" << std::endl;
  
  return 0;
}