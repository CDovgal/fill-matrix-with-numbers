#include "UnaliveIO.h"
#include <iostream>
#include <string>

void UnaliveInput::Input()
{
  std::cout << "Please enter name of uanlive good: " << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << "Please enter amount of a good: " << std::endl;
  int amount;
  std::cin >> amount;
  std::cout << "Unalive good added..." << std::endl;
 // BaseInput::Input();
}

void UnaliveOutput::Output()
{
  BaseOutput::Output();
}