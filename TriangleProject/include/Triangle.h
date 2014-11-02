#pragma once

enum TriangleType
{
  acute_angled, // ostrougolniy    +
  obtuse,       // tupougolniy     +
  right_angled, // pryamougolniy   +
  scalene,      // raznostoronniy  +
  isosceles,    // ravnobedrennuy  +
  equilateral   // ravnostoronniy  +
};

struct Point
{
  int x;
  int y;
};

class Triangle
{
public:
  Triangle();
  Triangle(const Point& i_A, const Point& i_B, const Point& i_C) :m_A(i_A), m_B(i_B), m_C(i_C){};
  ~Triangle(){};
  void checkType();
  void checkArea();
  void setCoords(const Point& A, const Point& B, const Point& C);
  double triangleArea() const;
private:
  TriangleType determineTypeByCoords() const;
  TriangleType determineType(int a, int b, int c) const;
  Point m_A;
  Point m_B;
  Point m_C;
};