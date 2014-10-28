#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;


double rootDiff(double x1, double x2)
{
  return x1 - x2;
}

tuple<double, double> quadraticEq(double a, double b, double c)
{
  if (a == 0)
    return make_tuple(0, 0);

  double x1, x2, realPart, imaginaryPart = 0;
  double discriminant = b*b - 4 * a*c;

  if (a + b + c == 0)
  {
    x1 = 1;
    x2 = c / a;
    return make_tuple(x1,x2);
  }
  else if (discriminant > 0)
  {
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);
    return make_tuple(x1, x2);
  }
  else if (discriminant == 0)
  { 
    x1 = -b / 2 * a;
    return make_tuple(x1, x2);
  }
  else if (discriminant < 0)
  {
    realPart = -b / (2 * a);
    imaginaryPart = sqrt(-discriminant) / (2 * a);
    return make_tuple(x1, x2);
  }
}



int main()
{
  double a, b, c;
  cout << "Please enter the coefficients: \n";
  cin >> a >> b >> c;

  double x1, x2;

  tie(x1, x2) = quadraticEq(a, b, c);

  cout << "Roots are: \n";
  cout << "x1 = " << x1 << endl;
  cout << "x2 = " << x2 << endl;

  cout << "Root difference: " << rootDiff(x1, x2) << endl;
 
  return 0;
}