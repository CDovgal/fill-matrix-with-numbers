#pragma once
#include <iostream>
#include <Input.h>
#include <fstream>
#include <string>


void BaseInput::Input()
{
  std::cout << "Please enter name of a good: " << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << "Please enter amount of a good: " << std::endl;
  int amount;
  std::cin >> amount;
  std::cout << "Alive good added..." << std::endl;
  std::cout << "Base Input Function" << std::endl;
}

void BaseOutput::Output()
{
  std::cout << "Base Output Function" << std::endl;
}

void AliveInput::Input()
{
  BaseInput::Input();
}

void AliveOutput::Output()
{
  BaseOutput::Output();
}

void UnaliveInput::Input()
{
  BaseInput::Input();
}

void UnaliveOutput::Output()
{
  BaseOutput::Output();
}



