#include <iostream>
#include "classA.h"
#include "classB.h"
int main()
{
  A a(5);
  B b;
  b.mpFn = &A::Mult;
  int mult = (a.*b.mpFn)(3, 4);
  std::cout << mult << std::endl;
  b.mpFn = &A::Sum;
  int sum = (a.*b.mpFn)(5, 5);
  std::cout << sum << std::endl;
}