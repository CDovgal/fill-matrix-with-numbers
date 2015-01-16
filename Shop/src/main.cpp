#include <iostream>
//#include <Input.h>
#include "Shop.h"

int main()
{
  std::cout << "Flower Shop" << std::endl;
  std::cout << "Choose your access type: " << std::endl;
  std::cout << "1. Enter as admin." << std::endl << "2. Enter as customer." << std::endl;
  int choise;
  std::cin >> choise;
  switch (choise)
  {
  case 1:
    std::cout << "Entered as admin." << std::endl;
    system("cls");
    //admin menu
    break;
  case 2:
    std::cout << "Entered as customer." << std::endl;
    system("cls");
    //customer menu
    break;
  default:
    std::cout << "You haven't choosen any type." << std::endl;
  }
  Shop& instance = Shop::instance();
  instance.load_db();
  return 0;
}