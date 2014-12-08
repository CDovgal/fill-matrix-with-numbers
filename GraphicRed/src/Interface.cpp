#include "Interface.h"
#include <iostream>

Triangle::Triangle(double i_A, double i_B, double i_C) : m_sideA(i_A), m_sideB(i_B), m_sideC(i_C)
{
  std::cout << "Triangle constr\n";
}

double Triangle::getArea()
{
  double p = (m_sideA + m_sideB + m_sideC) / 2;
  double s = std::sqrt(p*(p-m_sideA)*(p-m_sideB)*(p-m_sideC));
  return s;
}