#include <iostream>
#include "Complex.h"

int main()
{
  //Complex a(3.4, 2);
  //Complex b(3, 2.6);
  //Complex c = a + b;

  //std::cout << "Sum: " << c.Real() << " + " << c.Imag() << "i" << std::endl;

  //Complex z = a * b;

  //std::cout << "Multiplication: " << z.Real() << " + " << z.Imag() << "i" << std::endl;

  ////-------------------------------------------------------

  //Complex g(5.5, 1);
  //Complex d(8, 4.3);

  //g++;
  //d--;
  //std::cout << "Postfix increment " << g.Real() << " and decrement " << d.Real() << " for real part\n";

  ////--------------------------------------------------------

  //Complex e(6, 2.8);
  //Complex f(5.7, 3);

  //++e;
  //--f;
  //std::cout << "Prefix increment " << e.Imag() << " and decrement " << f.Imag() << " for imaginary part\n";

  ////--------------------------------------------------------

  //std::cout << e << f << std::endl;

  ////--------COPY CONSTRUCTOR AND COPY ASSIGNMENT OPERATOR------------------------------------------------

  //Complex r(e);
  //std::cout << r << std::endl;
  //Complex o(f);
  //std::cout << o << std::endl;

  //r = o;

  //std::cout << r << std::endl;

  ////-----------------------OPERATOR - ------------------------

  //Complex y(r);
  //Complex x(g);

  //Complex k = x - y;

  //std::cout << k << std::endl;

  ////---------------operator / --------------------------------

  //std::cout << k / x << std::endl;

  ////---------------------substraction function-------------------
  {
    Complex v(5.6, 3);
    Complex s(3.4, 2);
    Complex result = Complex::Substract(v, s);
    v = s;
    v = std::move(s);
    std::cout << result << std::endl;
  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "oops!" << std::endl;
  std::cout << "nope" << std::endl;

  return 0;
}