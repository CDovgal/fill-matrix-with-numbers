#pragma once
#include <iostream>
#include <Input.h>
#include <fstream>

BaseInput::BaseInput()
{
  std::cout << "Base Input" << std::endl;
}

BaseOutput::BaseOutput()
{
  std::cout << "Base Output" << std::endl;
}


AliveOutput::AliveOutput()
{
  std::ofstream aliveoutput("AliveOutput.dat");
  if (aliveoutput.is_open())
  {
    aliveoutput << "Alive Output!" << std::endl;
  }
  aliveoutput.close();
}

UnaliveOutput::UnaliveOutput()
{
  std::ofstream unaliveoutput("UnaliveOutput.dat");
  if (unaliveoutput.is_open())
  {
    unaliveoutput << "Unalive Output!" << std::endl;
  }
  unaliveoutput.close();
}