#include "Interface.h"
#include <iostream>
#include <vector>
#include <exception>

#define PI 3.14159265

Point Point::NA = { DBL_MAX, DBL_MAX };

Polyline::Polyline(const std::vector<Segment>& i_segment_list) :
m_seg_list(i_segment_list)
{
  std::cout << "Polyline constr\n";
}

Polyline* Polyline::Intersect(Polyline* otherObject)
{
  /*ry
  {
    otherObject->Intersect(this);
  }
  catch (std::exception& pl_exc)
  {
    std::cerr << "Exception caught: " << pl_exc.what() << std::endl;
  }*/
  return nullptr;
}

Polyline* Polyline::Intersect(Triangle* i_triangle)
{
  try
  {
    i_triangle->Intersect(this);
  }
  catch (std::exception& tr_exc)
  {
    std::cerr << "Exception caught: " << tr_exc.what() << std::endl;
  }
  return nullptr;
}

Polyline* Polyline::Intersect(Ellipse* i_ellipse)
{
  return nullptr;
}

Triangle::Triangle(const Point& i_a, const Point& i_b, const Point& i_c) :
Polyline(makeTriangleSegmentList(i_a, i_b, i_c))
{
  std::cout << "Triangle constr\n";
}

std::vector<Segment> Triangle::makeTriangleSegmentList(const Point& i_a, const Point& i_b, const Point& i_c)
{
  std::vector<Segment> tr_seg_list;
  Segment a(Point::NA, i_a);
  Segment b(Point::NA, i_b);
  Segment c(Point::NA, i_c);
  tr_seg_list.push_back(a);
  tr_seg_list.push_back(b);
  tr_seg_list.push_back(c);
  return tr_seg_list;
}

Ellipse::Ellipse(const Point& i_center, const Point& i_a, const Point& i_b) :
Polyline(makeEllipseSegmentList(i_center, i_a, i_b))
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
  double s = 10;//abs((m_a.getX()*(m_b.getY() - m_c.getY()) + m_b.getX()*(m_c.getY() - m_a.getY()) + m_c.getX()*(m_a.getY() - m_b.getY())) / 2);
  return s;
}

double Ellipse::getArea()
{
  double s = 5;
  return s;
}


Polyline* Triangle::Intersect(Triangle* i_triangle)
{
  std::cout << "Triangle intersects with triangle (Triangle func)\n";
  return IntersectTriangleWithTriangle(this, i_triangle);
}

Polyline* Triangle::Intersect(Ellipse* i_ellipse)
{
  std::cout << "Triangle intersects with ellipse (Triangle func)\n";
  return IntersectTriangleWithEllipse(this, i_ellipse);
};


Polyline* Ellipse::Intersect(Triangle* i_triangle)
{
  std::cout << "Ellipse intersects with triangle (Ellipse func)\n";
  return IntersectTriangleWithEllipse(i_triangle, this);
};

Polyline* Ellipse::Intersect(Ellipse* i_ellipse)
{
  std::cout << "Ellipse intersects with ellipse (Ellipse func)\n";
  return IntersectEllipseWithEllipse(this, i_ellipse);
};