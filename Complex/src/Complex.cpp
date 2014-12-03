#include "Complex.h"

Complex::Complex()
{
  std::cout << "DEFAULT CONSTRUCTOR" << std::endl;
}

Complex::Complex(double i_r, double i_i) : m_real(i_r), m_imag(i_i)
{
  std::cout << "Overloaded CONSTRUCTOR" << std::endl;
}

Complex::Complex(const Complex& rhv) : m_real(rhv.m_real), m_imag(rhv.m_imag)
{
  std::cout << "COPY CONSTRUCTOR" << std::endl;
}

Complex::Complex(Complex&& rhv)
{
  m_real = rhv.m_real;
  m_imag = rhv.m_imag;
  rhv.m_real = 0;
  rhv.m_imag = 0;
  std::cout << "MOVE CONSTRUCTOR" << std::endl;
}

Complex& Complex::operator=(Complex&& rhv)
{
  std::cout << "MOVE ASSIGNMENT" << std::endl;
  /*std::swap(m_real, rhv.m_real);
  std::swap(m_imag, rhv.m_imag);*/
  m_real = std::move(rhv.m_real);
  m_imag = std::move(rhv.m_imag);
  return *this; 
}

Complex& Complex::operator=(const Complex& rhv)
{
  std::cout << "COPY ASSIGNMENT" << std::endl;
  m_real = rhv.m_real;
  m_imag = rhv.m_imag;
  return *this;
}

Complex Complex::operator+(const Complex& i_complex)
{
  Complex result(m_real, m_imag);
  result.m_real += i_complex.m_real;
  result.m_imag += i_complex.m_imag;
  return result;
}

Complex Complex::operator-(const Complex& i_complex)
{
  Complex result(m_real, m_imag);
  result.m_real -= i_complex.m_real;
  result.m_imag -= i_complex.m_imag;
  return result;
}

Complex operator-(const Complex& lhv, const Complex& rhv)
{
  Complex result(lhv.m_real-rhv.m_real,lhv.m_imag - rhv.m_imag);
  return result;
}

Complex Complex::operator*(const Complex& i_complex)
{
  Complex result(m_real, m_imag);
  result.m_real *= i_complex.m_real;
  result.m_imag *= i_complex.m_imag;
  return result;
}

Complex Complex::operator/(const Complex& i_complex)
{
  Complex result(m_real, m_imag);
  result.m_real /= i_complex.m_real;
  result.m_imag /= i_complex.m_imag;
  return result;
}

Complex& Complex::operator++()
{
  ++m_imag;
  return *this;
}

Complex& Complex::operator--()
{
  --m_imag;
  return *this;
}

Complex Complex::operator++(int)
{
  Complex incr_result(m_real, m_imag);
  ++m_real;
  return incr_result;
}

Complex Complex::operator--(int)
{
  Complex decr_result(m_real, m_imag);
  --m_real;
  return decr_result;
}


std::ostream& operator<<(std::ostream& output, const Complex& i_complex)
{
  output << i_complex.Real() << " + " << i_complex.Imag() << std::endl;
  return output;
}


double Complex::Real() const
{
  return m_real;
}

double Complex::Imag() const
{
  return m_imag;
}

Complex Complex::Substract(const Complex& lhv, const Complex& rhv)
{
  return lhv - rhv;
}

