#include <iostream>


class Point
{
public:
  double x;
  double y;
};

class Square;
class Rectangle;
class Triangle;
class Circle;

class GraphInterface
{
public:
  virtual ~GraphInterface(){};
  virtual void Draw() = 0;
  virtual double getArea() = 0;

};

class Shape : public GraphInterface
{
public:
  Shape(){};
  ~Shape(){};
  virtual void Intersect(const Shape& otherObject) = 0;

  virtual void Draw(){ std::cout << "Shape draw\n"; };
  virtual double getArea(){ return 2.34; };
};

class Polygon : public Shape
{
  int m_pointCount;
public:
  Polygon(){}
  virtual void Intersect(const Shape& otherObject);
  virtual void Intersect(const Square& otherObject);
  virtual void Intersect(const Rectangle& otherObject);
  virtual void Intersect(const Triangle& otherObject);
  virtual void Intersect(const Circle& otherObject);
  virtual void Draw(){ std::cout << "Polygon draw\n"; }
  virtual double getArea(){ return 3.00; }
};

class Square : public Shape
{
public:
  Square(){}
  ~Square(){}
  void Draw(){ std::cout << "Square draw\n"; }
  double getArea(){}
};

class Rectangle : public Shape
{
public:
  Rectangle(){};
  ~Rectangle(){};
  void Draw(){ std::cout << "Rectangle draw\n"; }
  double getArea(){ return ; }
};

class Triangle : public Shape
{
  double m_sideA;
  double m_sideB;
  double m_sideC;
public:
  Triangle(double i_A, double i_B, double i_C);
  ~Triangle(){};
  void Draw(){ std::cout << "Triangle draw\n"; };
  double getArea();
};




