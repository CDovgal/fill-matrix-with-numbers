#include <iostream>
#include <fstream>
#include "Shop.h"

void Shop::load_db()
{
  std::cout << "Database loaded..." << std::endl;
}

Shop::Shop()
{
  load_db();
}

Shop::~Shop()
{
}

void Shop::set_startup_sun(int i_sum)
{
  m_startup_sum = i_sum;
}

int Shop::start_menu()
{
  std::cout << "Flower Shop\n" << std::endl;
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
    std::cout << "You've not choosen any type." << std::endl;
  }
  return choise;
}


int Shop::admin_menu()
{
  std::cout << "Entered as admin. . .\n" << std::endl;
  std::cout << "1. Enter startup sum." << std::endl;
  std::cout << "2. Show goods(is available)." << std::endl;

  int choise;
  std::cin >> choise;
  switch (choise)
  {
  case 1:
    std::cout << "Please, enter balance: " << std::endl;
    int sum;
    std::cin >> sum;
    Shop::set_startup_sun(sum);
    std::cout << m_startup_sum << std::endl;
    break;
  case 2:
    //std::cout << m_prod_vec.size() << std::endl;
    break;
  }

  return choise;
}