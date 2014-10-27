#include "Triangle.h"
#include <iostream>

using namespace std;

TriangleType Triangle::determineType(int a, int b, int c)
{
  TriangleType type;

  if (a*a + b*b > c*c)
    type = acute_angled;

  if (a*a + b*b < c*c)
    type = obtuse;

  if (a != b && b != c)
    type = scalene;

  if (a == b || b == c || c == a)
    type = isosceles;

  if (a == b && b == c)
    type = equilateral;

  if (a*a + b*b == c*c)
    type = right_angled;
  
  return type;
}


void Triangle::checkType(int a, int b, int c)
{
  if (a == 0 || b == 0 || c == 0)
    return;

  Triangle *tri = new Triangle;

  TriangleType type = tri->determineType(a, b, c);

  switch (type)
  {
  case equilateral: cout << "Ravnostoronniy\n";
    break;
  case acute_angled: cout << "Ostrougolniy\n";
    break;
  case obtuse: cout << "Tupougolniy\n";
    break;
  case scalene: cout << "Raznosotoronniy\n";
    break;
  case isosceles: cout << "Ravnobedrennuy\n";
    break;
  case right_angled: cout << "Pryamougolniy\n";
    break;
  }
}