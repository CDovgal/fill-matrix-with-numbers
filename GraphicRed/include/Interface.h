#include <iostream>
#include <vector>

class Point
{
public:
  double m_x;
  double m_y;
  Point(double i_x, double i_y) : 
    m_x(i_x), 
    m_y(i_y){}
};

struct Segment
{
  Point center;
  Point end;
  Segment(const Point& i_cent, const Point& i_end) : 
    center(i_cent), 
    end(i_end){}
};

class Shape
{
public:
  Shape(){};
  virtual ~Shape(){};
  virtual void Draw()   { std::cout << "Shape draw\n"; };
  virtual void Input()  { std::cout << "Shape input\n"; }
  virtual void Output() { std::cout << "Shape output\n"; }
};


class Triangle;
class Ellipse;

class Polyline : public Shape
{
  std::vector<Segment> m_seg_list;
public:
  Polyline(const std::vector<Segment>& i_segment_list);
  virtual void      Draw(){ std::cout << "Polyline draw\n"; }
  virtual double    getArea(){ return 3.00; }
  virtual Polyline* Intersect(Polyline& otherObject);
  virtual Polyline* Intersect(Triangle& i_triangle);
  virtual Polyline* Intersect(Ellipse& i_ellipse);
  static  Polyline* IntersectTriangleWithEllipse(Triangle* i_tr, Ellipse* i_ell)
  {
    std::cout << "Triangle intersects with Ellipse\n";
  }
};

class Triangle : public Polyline
{
  Point m_a;
  Point m_b;
  Point m_c;
public:
  Triangle(const Point& i_a, const Point& i_b, const Point& i_c);
  ~Triangle(){};
  void      Draw(){ std::cout << "Triangle draw\n"; };
  double    getArea();
  Polyline* Intersect(Polyline* pl)
  {
    return pl->Intersect(*this);
  };
  Polyline*        Intersect(Triangle* i_tr);
  Polyline*        Intersect(Ellipse* i_ell);
  static Polyline* IntersectTriangleWithTriangle(Triangle* i_trl, Triangle* i_trr)
  {
    std::cout << "Triangle intersects with triangle\n";
  }
  std::vector<Segment> makeTriangleSegmentList(const Point& i_a, const Point& i_b, const Point& i_c);
};

class Ellipse : public Polyline
{
  Point m_center;
  Point m_a;
  Point m_b;
public:
  Ellipse(const Point& i_center, const Point& i_a, const Point& i_b);
  ~Ellipse(){};
  void      Draw(){ std::cout << "Ellipse draw\n"; };
  double    getArea();
  Polyline* Intersect(Polyline* pl)
  {
    return pl->Intersect(*this);
  };
  Polyline*        Intersect(Triangle* i_tr);
  Polyline*        Intersect(Ellipse* i_ell);
  static Polyline* IntersectEllipseWithEllipse(Ellipse* i_elll, Ellipse* i_ellr)
  {
    std::cout << "Ellipse intersects with Ellipse\n";
  }
  std::vector<Segment> makeEllipseSegmentList(const Point& i_center, const Point& i_a, const Point& i_b);
};




