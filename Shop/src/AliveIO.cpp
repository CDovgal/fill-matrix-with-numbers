#include "AliveIO.h"
#include <iostream>
#include <string>

void AliveInput::Input()
{
  std::cout << "Please enter name of alive good: " << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << "Please enter amount of a good: " << std::endl;
  int amount;
  std::cin >> amount;
  std::cout << "Alive good added..." << std::endl;
  //BaseInput::Input();
}

void AliveOutput::Output()
{
  BaseOutput::Output();
}