#include "Interface.h"
#include <iostream>
#include <vector>
#define PI 3.14159265
Point Point::NA = { DBL_MAX, DBL_MAX };

Polyline::Polyline(const std::vector<Segment>& i_segment_list) :
m_seg_list(i_segment_list)
{
  std::cout << "Polyline constr\n";
}

Triangle::Triangle(const Point& i_a, const Point& i_b, const Point& i_c) :
Polyline(makeTriangleSegmentList(i_a, i_b, i_c)),
m_a(i_a),
m_b(i_b),
m_c(i_c)
{
  std::cout << "Triangle constr\n";
}

std::vector<Segment> Triangle::makeTriangleSegmentList(const Point& i_a, const Point& i_b, const Point& i_c)
{
  std::vector<Segment> tr_seg_list;
  Segment a({ 0, 0 }, i_a);
  Segment b({ 0, 0 }, i_b);
  Segment c({ 0, 0 }, i_c);
  tr_seg_list.push_back(a);
  tr_seg_list.push_back(b);
  tr_seg_list.push_back(c);
  return tr_seg_list;
}

Ellipse::Ellipse(const Point& i_center, const Point& i_a, const Point& i_b) :
Polyline(makeEllipseSegmentList(i_center, i_a, i_b)),
m_center(i_center),
m_a(i_a),
m_b(i_b)
{
  std::cout << "Ellipse constr\n";
}

std::vector<Segment> Ellipse::makeEllipseSegmentList(const Point& i_center, const Point& i_a, const Point& i_b)
{
  std::vector<Segment> ell_seg_list;
  Segment arc({ 0, 0 }, i_center);
  Segment a({ 0, 0 }, i_a);
  Segment b({ 0, 0 }, i_b);
  ell_seg_list.push_back(arc);
  ell_seg_list.push_back(a);
  ell_seg_list.push_back(b);
  return ell_seg_list;
}

double Triangle::getArea()
{
  /*double p = (m_a + m_b + m_c) / 2;
  double s = std::sqrt(p*(p-m_sideA)*(p-m_sideB)*(p-m_sideC));*/
  double s = abs((m_a.m_x*(m_b.m_y - m_c.m_y) + m_b.m_x*(m_c.m_y - m_a.m_y) + m_c.m_x*(m_a.m_y - m_b.m_y)) / 2);
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