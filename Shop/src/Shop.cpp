#include <iostream>
#include "Shop.h"

void Shop::Input()
{
  std::cout << "Input" << std::endl;
}

void Shop::Output()
{
  std::cout << "Output" << std::endl;
}

void Shop::set_startup_sun(int i_sum)
{
  m_startup_sum = i_sum;
}

int Shop::start_menu()
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
    std::cout << "You've not choosen any type." << std::endl;
  }
  return choise;
}


int Shop::admin_menu()
{
  std::cout << "Entered as admin. . .\n\n" << std::endl;
  std::cout << "1. Enter startup sum." << std::endl;
  std::cout << "2. Load database." << std::endl;
  std::cout << "3. Enter startup sum." << std::endl;
  std::cout << "4. Enter startup sum." << std::endl;
  std::cout << "5. Enter startup sum." << std::endl;

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
    std::cout << "Load database." << std::endl;
    break;
  }

  return 0;
}