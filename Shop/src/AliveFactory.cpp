#include "AliveFactory.h"
#include "AliveIO.h"

BaseInput* AliveFactory::createInput()
{
  return new AliveInput();
}

BaseOutput* AliveFactory::createOutput()
{
  return new AliveOutput();
}