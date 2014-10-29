#include <iostream>
#include <cmath>
#include <tuple>
#include <complex>


using namespace std;


double rootDiff(double x1, double x2)
{
  return x1 - x2;
}

bool isSolutionReal(double a, double b, double c)
{
  double discriminant = b*b - 4 * a*c;

  if (discriminant >= 0)
    return true;
  else
    return false;
}

tuple<double, double> realSolution(double a, double b, double c)
{
  if (a == 0)
    return make_tuple(0, 0);

  double discriminant = b*b - 4 * a*c;

  if (a + b + c == 0)
  {
    double x1 = 1;
    double x2 = c / a;
    return make_tuple(x1, x2);
  }
  else if (discriminant > 0)
  {
    double x1 = (-b + sqrt(discriminant)) / (2 * a);
    double x2 = (-b - sqrt(discriminant)) / (2 * a);
    return make_tuple(x1, x2);
  }
  else if (discriminant == 0)
  {
    double x1 = -b / 2 * a;
    return make_tuple(x1, x1);
  }
}


tuple<complex<double>, complex<double>> generalSolution(double a, double b, double c)
{
  double discriminant = b*b - 4 * a*c;
  double realPart = -b / (2 * a);
  double imaginaryPart = sqrt(-discriminant) / (2 * a);
  complex<double> x1(realPart, imaginaryPart), x2(realPart, -imaginaryPart);
  return make_tuple(x1, x2);
}



int main()
{
  double a, b, c;
  cout << "Please enter the coefficients: \n";
  cin >> a >> b >> c;

  if (isSolutionReal(a, b, c))
  {
    double x1, x2;

    tie(x1, x2) = realSolution(a, b, c);

    cout << "Roots are: \n";
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
  }
  else
  {
    complex<double> x1, x2;

    tie(x1, x2) = generalSolution(a, b, c);

    cout << "Roots are(complex): \n";
    cout << "x1 = " << x1.real() << "+" << x1.imag() <<  endl;
    cout << "x2 = " << x2.real() << x2.imag() << endl;
  }

  //cout << "Root difference: " << rootDiff(x1, x2) << endl;

  return 0;
}