#pragma once
#include <iostream>
#include <Input.h>
#include <fstream>


void BaseInput::Input()
{
  std::cout << "Base Input" << std::endl;
}

void BaseOutput::Output()
{
  std::cout << "Base Output" << std::endl;
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



