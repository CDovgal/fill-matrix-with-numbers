#include "AliveFactory.h"

BaseInput* AliveFactory::createInput()
{
  return new AliveInput();
}

BaseOutput* AliveFactory::createOutput()
{
  return new AliveOutput();
}