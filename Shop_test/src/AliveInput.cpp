#include "AliveInput.h"
#include <iostream>
#include <string>
#include "AliveProduct.h"
#include "Category.h"

AliveInput::AliveInput()
{
  //std::cout << "Alive Input Constructor" << std::endl;
}

AliveInput::~AliveInput()
{
  //std::cout << "Alive Input Destructor" << std::endl;
}

Product* AliveInput::Input()
{
  std::cout << "Enter alive product properties:\n" << std::endl;
  std::string name;
  std::cout << "Please, enter name of new product: " << std::endl;
  std::cin >> name;
  int count;
  std::cout << "Please, enter amount of new product: " << std::endl;
  std::cin >> count;
  int price;
  std::cout << "Please, enter the price(per unit) of new product: " << std::endl;
  std::cin >> price;
  int suitability;
  std::cout << "Please, enter the suitability days count of new product: " << std::endl;
  std::cin >> suitability;
  AliveProduct *alive_product = new AliveProduct(name, count, price, suitability);
  return alive_product;
}