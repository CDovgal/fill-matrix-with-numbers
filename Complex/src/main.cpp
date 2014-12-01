#include <iostream>
#include "Complex.h"

int main()
{
  Complex a(3.4, 2);
  Complex b(3, 2.6);
  Complex c = a + b;

  std::cout << "Sum: " << c.Real() << " + " << c.Imag() << "i" << std::endl;

  Complex z = a * b;

  std::cout << "Multiplication: " << z.Real() << " + " << z.Imag() << "i" << std::endl;

  //-------------------------------------------------------

  Complex g(5.5, 1);
  Complex d(8, 4.3);

  g++;
  d--;
  std::cout << "Postfix increment " << g.Real() << " and decrement " << d.Real() << " for real part\n";

  //--------------------------------------------------------

  Complex e(6, 2.8);
  Complex f(5.7, 3);

  ++e;
  --f;
  std::cout << "Prefix increment " << e.Imag() << " and decrement " << f.Imag() << " for imaginary part\n";

  //--------------------------------------------------------

  std::cout << e << f << std::endl;

  return 0;
}