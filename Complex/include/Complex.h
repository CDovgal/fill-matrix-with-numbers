#include <iostream>

class Complex
{
  double m_real;
  double m_imag;
public:
  double Real() const;
  double Imag() const;
  Complex(double i_r, double i_i);
  Complex operator+(const Complex& i_complex);
  Complex operator*(const Complex& i_complex);
  Complex& operator++();
  Complex& operator--();

  Complex operator++(int);
  Complex operator--(int);

  friend std::ostream& operator<<(std::ostream& output, const Complex& i_complex);
};