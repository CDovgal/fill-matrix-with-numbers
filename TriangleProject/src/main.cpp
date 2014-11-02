#include <iostream>
#include "Triangle.h"

using namespace std;


int main()
{
  Point A = { 1, 3 };
  Point B = { -2, -2 };
  Point C = { 3, -1 };

  Triangle tri(A, B, C);

  tri.checkType();
  tri.checkArea();

  return 0;
}