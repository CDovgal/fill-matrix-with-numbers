#include <iostream>
#include <iostream>

class Complex
{
  double m_real;
  double m_imag;
  
public:
  Complex();
  Complex(double i_r, double i_i);
  Complex(const Complex& rhv);
  Complex(Complex&& rhv);
  ~Complex(){ std::cout << "COMPLEX DESTRUCTOR" << std::endl; };

  Complex& operator=(Complex&& rhv);
  Complex& operator=(const Complex& rhv);

  Complex operator+(const Complex& i_complex);
  Complex operator*(const Complex& i_complex);
  Complex operator-(const Complex& i_complex);
  Complex operator/(const Complex& i_complex);

  Complex& operator++();
  Complex& operator--();

  Complex operator++(int);
  Complex operator--(int);

  double Real() const;
  double Imag() const;

  static Complex Substract(const Complex& lhv, const Complex& rhv);

  friend std::ostream& operator<<(std::ostream& output, const Complex& i_complex);
  friend Complex operator-(const Complex& lhv, const Complex& rhv);
};