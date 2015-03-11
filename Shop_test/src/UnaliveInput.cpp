#include "UnaliveInput.h"
#include <iostream>
#include <string>
#include "UnaliveProduct.h"
#include "Category.h"

UnaliveInput::UnaliveInput()
{
  //std::cout << "Unalive Input Constructor" << std::endl;
}

UnaliveInput::~UnaliveInput()
{
  //std::cout << "Unalive Input Destructor" << std::endl;
}

void UnaliveInput::Input(std::vector<Product*>& i_prod_vec)
{
  //std::cout << "Unalive Input" << std::endl;
  //BaseInput::Input();
  std::cout << "Enter unalive product properties:\n" << std::endl;
  std::string name;
  std::cout << "Please, enter name of new product: " << std::endl;
  std::cin >> name;
  int count;
  std::cout << "Please, enter amount of new product: " << std::endl;
  std::cin >> count;
  int price;
  std::cout << "Please, enter the price(per unit) of new product: " << std::endl;
  std::cin >> price;
  int weight;
  std::cout << "Please, enter the weight of new product: " << std::endl;
  std::cin >> weight;
  UnaliveProduct *unalive_product = new UnaliveProduct(name, count, price, weight);
  i_prod_vec.push_back(unalive_product);
  //return unalive_product;
}