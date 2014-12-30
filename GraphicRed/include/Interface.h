#include <iostream>
#include <vector>
#include <limits.h>
#include <memory>


class not_implemented : public std::exception
{
  std::string m_msg;
public:
  not_implemented(const std::string& msg) : m_msg(msg){}
  const char* what() const throw()
  {
    return m_msg.c_str();
  }
};

class Point
{
  double m_x;
  double m_y;
public:
  static Point NA;
  Point(double i_x, double i_y) :
    m_x(i_x),
    m_y(i_y){}
  double getX() const{ return m_x; };
  double getY() const{ return m_y; };
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
  virtual ~Shape(){};
  virtual void Draw() = 0;
  virtual std::vector<double> Input() = 0;
  virtual std::vector<double> Output() = 0;
};


class Triangle;
class Ellipse;

class Polyline : public Shape
{
  std::vector<Segment> m_seg_list;
public:
  Polyline(){}
  Polyline(const std::vector<Segment>& i_segment_list);
  virtual void      Draw(){ std::cout << "Polyline draw\n"; }
  virtual std::vector<double> Input();
  virtual std::vector<double> Output();
  virtual double    getArea(){ return 3.00; }
  virtual Polyline* Intersect(Polyline* otherObject);
  virtual Polyline* Intersect(Triangle* i_triangle);
  virtual Polyline* Intersect(Ellipse* i_ellipse);
  static  Polyline* IntersectTriangleWithEllipse(Triangle* i_tr, Ellipse* i_ell)
  {
    std::cout << "Triangle intersects with Ellipse(Polyline func)\n";
    //intersecting of triangle and ellipse will give us vector<Segment> of 
    //4 points that we will put in poly
    std::vector<Segment> tr_ell_seg_list;
    Segment a(Point::NA, { 3, 4 });
    Segment b(Point::NA, { 3, 4 });
    Segment c({ 0, 0 }, { 3, 4 });
    tr_ell_seg_list.push_back(a);
    tr_ell_seg_list.push_back(b);
    tr_ell_seg_list.push_back(c);
    Polyline *poly = new Polyline(tr_ell_seg_list);
    return poly;
  }
};

class Triangle : public Polyline
{
  std::vector<Segment> makeTriangleSegmentList(const Point& i_a,
  const Point& i_b,
  const Point& i_c);
  //std::vector<Segment> tr_seg_list; //&&&&&&&???????
public:
  Triangle(const Point& i_a, const Point& i_b, const Point& i_c);
  ~Triangle(){};
  void      Draw(){ std::cout << "Triangle draw\n"; };
  std::vector<double> Input();
  std::vector<double> Output();
  double    getArea();
  Polyline* Intersect(Polyline* otherObject)
  {
    return otherObject->Intersect(this);
  };
  Polyline*        Intersect(Triangle* i_triangle);
  Polyline*        Intersect(Ellipse* i_ellipse);
  static Polyline* IntersectTriangleWithTriangle(Triangle* i_trl, Triangle* i_trr)
  {
    std::cout << "Triangle intersects with triangle (Triangle func)\n";
    std::vector<Segment> tr_tr_seg_list;
    Polyline *poly = new Polyline(tr_tr_seg_list);
    return poly;
  }
};

class Ellipse : public Polyline
{
  std::vector<Segment> makeEllipseSegmentList(const Point& i_center,
  const Point& i_a,
  const Point& i_b);
public:
  Ellipse(const Point& i_center, const Point& i_a, const Point& i_b);
  ~Ellipse(){};
  void      Draw(){ std::cout << "Ellipse draw\n"; };
  std::vector<double> Input();
  std::vector<double> Output();
  double    getArea();
  Polyline* Intersect(Polyline* otherObject)
  {
    return otherObject->Intersect(this);
  };
  Polyline*        Intersect(Triangle* i_tr);
  Polyline*        Intersect(Ellipse* i_ell);
  static Polyline* IntersectEllipseWithEllipse(Ellipse* i_elll, Ellipse* i_ellr)
  {
    std::cout << "Ellipse intersects with Ellipse(Ellipse func)\n";
    std::vector<Segment> el_el_seg_list;
    Polyline *poly = new Polyline(el_el_seg_list);
    return poly;
  }
};

class World
{
  std::vector<Shape*> m_shapes;
  World(){};
  ~World();
  World(const World& rhv) = delete;
  World& operator=(const World&) = delete;
public:
  static World& instance()
  {
    static World instance;
    return instance;
  }
  void Generate();
  void Input();
  void Output();
  void Draw(){};
};





