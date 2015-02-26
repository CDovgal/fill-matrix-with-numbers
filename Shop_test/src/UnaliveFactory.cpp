#include "UnaliveFactory.h"
#include "UnaliveInput.h"
#include "UnaliveOutput.h"


UnaliveFactory::UnaliveFactory()
{

}

UnaliveFactory::~UnaliveFactory()
{

}

BaseInput* UnaliveFactory::createInput()
{
  return new UnaliveInput();
}

BaseOutput* UnaliveFactory::createOutput()
{
  return new UnaliveOutput();
}