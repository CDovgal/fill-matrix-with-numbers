#include "Interface.h"
#include <iostream>
#include <vector>
#include <exception>
#include <memory>
#include <fstream>
#include <string>

#define PI 3.14159265

Point Point::NA = { DBL_MAX, DBL_MAX };

Polyline::Polyline(const std::vector<Segment>& i_segment_list) :
m_seg_list(i_segment_list)
{
  std::cout << "Polyline constr\n";
}

Polyline* Polyline::Intersect(Polyline* otherObject)
{
  throw not_implemented("Can not intersect polyline with shape!");
  return nullptr;
}

Polyline* Polyline::Intersect(Triangle* i_triangle)
{
  throw not_implemented("Can not intersect polyline with shape!");
  return nullptr;
}

Polyline* Polyline::Intersect(Ellipse* i_ellipse)
{
  throw not_implemented("Can not intersect polyline with shape!");
  return nullptr;
}


std::vector<double> Polyline::Input()
{
  std::vector<double> poly_c;
  std::cout << "Polyline Input\n";
  return poly_c;
}

std::vector<double> Polyline::Output()
{
  std::cout << "Polyline Output\n";
  std::vector<double> poly_coords;

  for (unsigned i = 0; i < m_seg_list.size(); ++i)
  {
    poly_coords.push_back(m_seg_list.at(i).center.getX());
    poly_coords.push_back(m_seg_list.at(i).center.getY());
    poly_coords.push_back(m_seg_list.at(i).end.getX());
    poly_coords.push_back(m_seg_list.at(i).end.getY());
  }
  return poly_coords;
}

Triangle::Triangle(const Point& i_a, const Point& i_b, const Point& i_c) :
Polyline(makeTriangleSegmentList(i_a, i_b, i_c))
{
  std::cout << "Triangle constr\n";
}

std::vector<Segment> Triangle::makeTriangleSegmentList(const Point& i_a,
  const Point& i_b,
  const Point& i_c)
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

std::vector<double> Triangle::Input()
{
  std::vector<double> tr_c;
  std::cout << "Triangle Input\n";
  return tr_c;
}

std::vector<double> Triangle::Output()
{
  std::vector<double> tr_out;
  //for (unsigned i = 0; i < tr_seg_list.size(); ++i)
  //{
  //tr_out.push_back(tr_seg_list.at(i).center.getX());
  //tr_out.push_back(tr_seg_list.at(i).center.getY());
  //tr_out.push_back(tr_seg_list.at(i).end.getX());
  //tr_out.push_back(tr_seg_list.at(i).end.getY());
  //}
  std::cout << "Triangle Output\n";
  return tr_out;
}


Ellipse::Ellipse(const Point& i_center, const Point& i_a, const Point& i_b) :
Polyline(makeEllipseSegmentList(i_center, i_a, i_b))
{
  std::cout << "Ellipse constr\n";
}

std::vector<Segment> Ellipse::makeEllipseSegmentList(const Point& i_center,
  const Point& i_a,
  const Point& i_b)
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

std::vector<double> Ellipse::Input()
{
  std::vector<double> ell_inp;
  std::cout << "Ellipse Input\n";
  return ell_inp;
}

std::vector<double> Ellipse::Output()
{
  std::vector<double> ell_out;
  std::cout << "Ellipse Output\n";
  return ell_out;
}


double Triangle::getArea()
{
  /*double p = (m_a + m_b + m_c) / 2;
  double s = std::sqrt(p*(p-m_sideA)*(p-m_sideB)*(p-m_sideC));*/
  double s = 10;//abs((m_a.getX()*(m_b.getY() - m_c.getY()) + m_b.getX()*
  //(m_c.getY() - m_a.getY()) + m_c.getX()*(m_a.getY() - m_b.getY())) / 2);
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


void World::Generate()
{
  Triangle *tr1 = new Triangle({ 2, 3 }, { 3, 4 }, { 4, 5 });
  m_shapes.push_back(tr1);
  Triangle *tr2 = new Triangle({ 2, 3 }, { 3, 4 }, { 4, 5 });
  m_shapes.push_back(tr2);
  Ellipse *ell1 = new Ellipse({ 2, 3 }, { 3, 4 }, { 4, 5 });
  m_shapes.push_back(ell1);
  Ellipse *ell2 = new Ellipse({ 2, 3 }, { 3, 4 }, { 4, 5 });
  m_shapes.push_back(ell2);

  Polyline *pl1 = tr1->Intersect(ell1);
  Polyline *pl2 = tr2->Intersect(ell2);

  m_shapes.push_back(pl1);
  m_shapes.push_back(pl2);
}

World::~World()
{

}


void World::Input()
{
  m_shapes.clear();
  std::string line;
  std::ifstream myfile("shapes.sd");
  if (myfile.is_open())
  {
    while (std::getline(myfile, line))
    {
      std::cout << line << "\n";
      //m_shapes.push_back(myfile.getline());
    }
  }
  else
    std::cout << "Unable to open file\n";
  myfile.close();
}


void World::Output()
{
  std::ofstream myfile;
  myfile.open("shapes.sd");
  if (myfile.is_open())
  {
    for (unsigned i = 0; i < m_shapes.size(); ++i)
    {
      for (unsigned j = 0; j < m_shapes.at(i)->Output().size(); ++j)
      {
        myfile << m_shapes.at(i)->Output().at(j);
        myfile << "\n";
      }
    }
  }
  else
    std::cout << "Unable to open file\n";
  myfile.close();
}