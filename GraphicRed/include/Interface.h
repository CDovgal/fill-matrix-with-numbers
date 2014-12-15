#include <iostream>

class GraphInterface
{
public:
  virtual ~GraphInterface(){};
  virtual void Draw() = 0;
  virtual void Input() = 0;
  virtual void Output() = 0;
};

class Shape : public GraphInterface
{
public:
  Shape(){};
  ~Shape(){};
  virtual void Draw(){ std::cout << "Shape draw\n"; };
  virtual void Input() { std::cout << "Shape input\n"; }
  virtual void Output(){ std::cout << "Shape output\n"; }
};

class Polyline : public Shape
{
  int m_pointCount;
  Polyline* line;
  Polyline* curve;
public:
  Polyline(){}
  Polyline* Intersect(const Polyline& otherObject);
  virtual void Draw(){ std::cout << "Polyline draw\n"; }
  virtual double getArea(){ return 3.00; }
};

class Triangle : public Polyline
{
  double m_sideA;
  double m_sideB;
  double m_sideC;
public:
  Triangle(Polyline* i_A, Polyline* i_B, Polyline* i_C) : ;
  ~Triangle(){};
  void Draw(){ std::cout << "Triangle draw\n"; };
  double getArea();
};

class Ellipse : public Polyline
{
  double m_sideA;
  double m_sideB;
  double m_sideC;
public:
  Ellipse(double i_A, double i_B, double i_C);
  ~Ellipse(){};
  void Draw(){ std::cout << "Ellipse draw\n"; };
  double getArea();
};



