#include <iostream>
#include "Triangle.h"

using namespace std;


int main()
{
  Triangle *tri = new Triangle;

  Point A = { 1, 3 };
  Point B = { -2, -2 };
  Point C = { 3, -1 };

  tri->checkTypeAndArea(A, B, C);

  delete tri;

  return 0;
}