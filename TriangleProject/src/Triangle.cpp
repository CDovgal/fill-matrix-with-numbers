#include "Triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

double Triangle::triangleArea(const Point& i_A, const Point& i_B, const Point& i_C)
{
  double s = 0;

  s = (i_A.x*(i_B.y - i_C.y) + i_B.x*(i_C.y - i_A.y) + i_C.x*(i_A.y - i_B.y)) / 2;

  return abs(s);
}

TriangleType Triangle::determineTypeByCoords(const Point& A, const Point& B, const Point& C)
{
  TriangleType type;

  double a = sqrt(pow((B.x - A.x),2) + pow((B.y - A.y), 2));//A.y - A.x;
  double b = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
  double c = sqrt(pow((A.x - C.x), 2) + pow((A.y - C.y), 2));

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

void Triangle::checkTypeAndArea(const Point& A, const Point& B, const Point& C)
{
  double s = triangleArea(A, B, C);
  cout << s << endl;

  Triangle *tri = new Triangle;

  TriangleType type = tri->determineTypeByCoords(A, B, C);

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


