#include <iostream>

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
  virtual void Draw(){ std::cout << "Shape draw\n"; };
  virtual double getArea(){ return 2.34; };
};

class Rectangle :public Shape
{
public:
  Rectangle(){};
  ~Rectangle(){};
  void Draw(){ std::cout << "Rectangle draw\n"; };
  double getArea();
};

class Triangle : public Shape
{
public:
  Triangle(){};
  ~Triangle(){};
  void Draw(){ std::cout << "Triangle draw\n"; };
  double getArea();
};