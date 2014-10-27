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
  Triangle(){};
  ~Triangle(){};
  void checkTypeAndArea(const Point& A, const Point& B, const Point& C);
private:
  double triangleArea(const Point& i_A, const Point& i_B, const Point& i_C);
  TriangleType determineTypeByCoords(const Point& A, const Point& B, const Point& C);
};