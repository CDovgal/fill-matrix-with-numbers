#pragma once
#include <iostream>
#include <Input.h>
#include <fstream>


void BaseInput::Input(std::istream& is)
{
  std::cout << "Base Input" << std::endl;
}

void BaseOutput::Output(std::ostream& os)
{
  std::cout << "Base Output" << std::endl;
}

void AliveInput::Input(std::istream& is)
{
  BaseInput::Input(is);
}

void AliveOutput::Output(std::ostream& os)
{
  BaseOutput::Output(os);
}

void UnaliveInput::Input(std::istream& is)
{
  BaseInput::Input(is);
}

void UnaliveOutput::Output(std::ostream& os)
{
  BaseOutput::Output(os);
}



