#include "UnaliveFactory.h"

BaseInput* UnaliveFactory::createInput()
{
  return new UnaliveInput();
}

BaseOutput* UnaliveFactory::createOutput()
{
  return new UnaliveOutput();
}