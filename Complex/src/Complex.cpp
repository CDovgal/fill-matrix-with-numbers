#include "Complex.h"


Complex::Complex(double i_r, double i_i) : m_real(i_r), m_imag(i_i)
{

}

Complex Complex::operator+(const Complex& i_complex)
{
  Complex result(m_real, m_imag);
  result.m_real += i_complex.m_real;
  result.m_imag += i_complex.m_imag;
  return result;
}

Complex Complex::operator*(const Complex& i_complex)
{
  Complex result(m_real, m_imag);
  result.m_real *= i_complex.m_real;
  result.m_imag *= i_complex.m_imag;
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