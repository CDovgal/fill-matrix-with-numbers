#include "Shop.h"
#include <iostream>


Shop::Shop()
{
  m_category = new Category();
  m_category->Generate();
}

Shop::~Shop()
{

}

void Shop::startup_menu()
{
  /*std::cout << "Flower Shop\n" << std::endl;
  std::cout << "Choose your access type: " << std::endl;
  std::cout << "1. Enter as admin." << std::endl;
  std::cout << "2. Enter as customer." << std::endl;
  std::cout << "3. Exit." << std::endl;
  int choise;
  std::cin >> choise;
  switch (choise)
  {
  case 1:
    std::cout << "Entered as admin." << std::endl;
    system("cls");
    admin_menu();
    break;
  case 2:
    std::cout << "Entered as customer." << std::endl;
    system("cls");
    user_menu();
    break;
  case 3:
    std::cout << "Exiting program..." << std::endl;
    break;
  default:
    std::cout << "You've not choosen any type." << std::endl;
  }*/
}

void Shop::admin_menu()
{

}

void Shop::user_menu()
{

}
