#include "Interface.h"
#include <iostream>
#include <vector>
#include <exception>
#include <memory>
#include <fstream>
#include <string>
#include <algorithm>
#include <deque>

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

void Polyline::Input(std::istream& str)
{
  std::string line;
  size_t seg_count;
  str >> seg_count;
  m_seg_list.resize(seg_count);
  for (unsigned i = 0; i < seg_count; ++i)
  {
    str >> m_seg_list.at(i);
  }
}

void Polyline::Output(std::ostream& str) const
{
  str << m_seg_list.size() << std::endl;
  for (unsigned i = 0; i < m_seg_list.size(); ++i)
  {
    str << m_seg_list.at(i);
  }
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

void Triangle::Input(std::istream& str)
{
  Polyline::Input(str);
  std::cout << "Triangle Input\n";
}

void Triangle::Output(std::ostream& str) const
{
  Polyline::Output(str);
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

void Ellipse::Input(std::istream& str)
{
  Polyline::Input(str);
  std::cout << "Ellipse Input\n";
}

void Ellipse::Output(std::ostream& str) const
{
  Polyline::Output(str);
}


double Triangle::getArea()
{
  double s = 10;
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


void World::clear_sh()
{
  if (!m_shapes.empty())
  for (unsigned i = 0; i < m_shapes.size(); ++i)
    delete m_shapes.at(i);
  m_shapes.clear();
}

void World::Generate()
{
  Triangle *tr1 = new Triangle({ 2, 3 }, { 3, 4 }, { 4, 5 });
  m_shapes.push_back(tr1);
  Triangle *tr2 = new Triangle({ 7, 2 }, { 4, 8 }, { -4, 3 });
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
  clear_sh();
}

void World::Input()
{
  clear_sh();
  Shape *sh = nullptr;
  std::string line;
  size_t shapes_count;
  std::ifstream myfile("shapes.sd");
  if (myfile.is_open())
  {
    myfile >> shapes_count;
    for (size_t i = 0; i < shapes_count;)
    {
      std::getline(myfile, line);
      if (line == "class Triangle")
        sh = new Triangle();
      else if (line == "class Ellipse")
        sh = new Ellipse();
      else if (line == "class Polyline")
        sh = new Polyline();
      if (sh != nullptr && !line.empty())
      {
        sh->Input(myfile);
        m_shapes.push_back(sh);
        ++i;
      }
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
    myfile << m_shapes.size() << std::endl;
    for (unsigned i = 0; i < m_shapes.size(); ++i)
    {
      myfile << typeid(*m_shapes.at(i)).name() << std::endl;
      m_shapes.at(i)->Output(myfile);
    }
  }
  else
    std::cout << "Unable to open file\n";
  myfile.close();
}