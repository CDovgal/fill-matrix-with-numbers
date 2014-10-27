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

class Triangle
{
public:
  Triangle(){};
  ~Triangle(){};
  void checkType(int a, int b, int c);
private:
  TriangleType determineType(int a, int b, int c);
};