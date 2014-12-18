#include "Interface.h"
#include <iostream>
#define PI 3.14159265

Polyline::Polyline(const Point& i_a, const Point& i_b)
{
  std::cout << "Polyline constr\n";
}

Triangle::Triangle(const Point& i_A, const Point& i_B, const Point& i_C) : Polyline(i_A, i_B), m_a(i_A), m_b(i_B), m_c(i_C)
{
  std::cout << "Triangle constr\n";
}

Ellipse::Ellipse(const Point& i_center, const Point& i_a, const Point& i_b) : Polyline(i_a, i_b), m_center(i_center), m_a(i_a), m_b(i_b)
{
  std::cout << "Ellipse constr\n";
}

double Triangle::getArea()
{
  /*double p = (m_a + m_b + m_c) / 2;
  double s = std::sqrt(p*(p-m_sideA)*(p-m_sideB)*(p-m_sideC));*/
  double s = abs((m_a.m_x*(m_b.m_y - m_c.m_y)+ m_b.m_x*(m_c.m_y-m_a.m_y)+m_c.m_x*(m_a.m_y-m_b.m_y))/2);
  return s;
}

double Ellipse::getArea()
{
  double s = 5;
  return s;
}


Polyline* Triangle::Intersect(Triangle* i_tr)
{
  std::cout << "Triangle intersects with triangle\n";
  return IntersectTriangleWithTriangle(this, i_tr);
}

Polyline* Triangle::Intersect(Ellipse* i_ell)
{
  std::cout << "Triangle intersects with ellipse\n";
  return IntersectTriangleWithEllipse(this, i_ell);
};


Polyline* Ellipse::Intersect(Triangle* i_tr)
{
  std::cout << "Ellipse intersects with triangle\n";
  return IntersectTriangleWithEllipse(i_tr, this);
};

Polyline* Ellipse::Intersect(Ellipse* i_ell)
{
  std::cout << "Ellipse intersects with ellipse\n";
  return IntersectEllipseWithEllipse(this, i_ell);
};