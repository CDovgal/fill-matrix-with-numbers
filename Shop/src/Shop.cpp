#include <iostream>
#include <fstream>
#include "Shop.h"
#include "BaseFactory.h"
#include "Category.h"

Category& instance = Category::instance();

void Shop::load_db()
{
  std::cout << "Database loaded..." << std::endl;
}

Shop::Shop()
{
  instance.Generate();
  //instance.write_to_file();
  //instance.read_from_file();
  //instance.write_to_file();
  load_db();
}

Shop::~Shop()
{
}

void Shop::set_startup_sun(int i_sum)
{
  m_startup_sum = i_sum;
}

void Shop::input()
{
  
  system("cls");
  int choise;
  std::cout << "1. Add alive good." << std::endl;
  std::cout << "2. Add unalive good." << std::endl;
  std::cin >> choise;
  switch (choise)
  {
  case 1:
    std::cout << "Alive input" << std::endl;
    instance.Input();
    break;
  case 2:
    std::cout << "Unalive input" << std::endl;
    break;
  }
}


void Shop::output()
{
  system("cls");
  int choise;
  std::cout << "1. Show alive goods." << std::endl;
  std::cout << "2. Show unalive goods." << std::endl;
  std::cin >> choise;
  switch (choise)
  {
  case 1:
    std::cout << "Alive data output" << std::endl;
    break;
  case 2:
    std::cout << "Unalive data output" << std::endl;
    break;
  }
}

int Shop::start_menu()
{
  std::cout << "Flower Shop\n" << std::endl;
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
    //admin menu
    break;
  case 2:
    std::cout << "Entered as customer." << std::endl;
    system("cls");
    //customer menu
    break;
    case 3:
      std::cout << "Exiting program..." << std::endl;
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
  std::cout << "3. Add good." << std::endl;
  std::cout << "4. Delete good." << std::endl;
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
    Shop::output();
    break;
  case 3:
    Shop::input();
    break;
  case 4:
    break;
  }

  return choise;
}