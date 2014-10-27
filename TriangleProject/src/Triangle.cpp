#include "Triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

void Triangle::setCoords(const Point& A, const Point& B, const Point& C)
{
  m_A = A;
  m_B = B;
  m_C = C;
}

double Triangle::triangleArea() const
{
  double s = 0;

  s = (m_A.x*(m_B.y - m_C.y) + m_B.x*(m_C.y - m_A.y) + m_C.x*(m_A.y - m_B.y)) / 2;

  return abs(s);
}

TriangleType Triangle::determineTypeByCoords() const
{
  double a = sqrt(pow((m_B.x - m_A.x),2) + pow((m_B.y - m_A.y), 2));
  double b = sqrt(pow((m_C.x - m_B.x), 2) + pow((m_C.y - m_B.y), 2));
  double c = sqrt(pow((m_A.x - m_C.x), 2) + pow((m_A.y - m_C.y), 2)); 

  return determineType(a, b, c);
}

TriangleType Triangle::determineType(int a, int b, int c) const // maybe double?????????????
{
  if (a*a + b*b > c*c)
    return acute_angled;

  if (a*a + b*b < c*c)
    return obtuse;

  if (a != b && b != c)
    return scalene;

  if (a == b || b == c || c == a)
    return isosceles;

  if (a == b && b == c)
    return equilateral;

  if (a*a + b*b == c*c)
    return right_angled;
}


void Triangle::checkType()
{
  TriangleType type = determineTypeByCoords();

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

void Triangle::checkArea()
{
  double s = triangleArea();
  cout << s << endl;
}


