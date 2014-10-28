#include <iostream>
#include <cmath>

using namespace std;


void quadraticEq(float a, float b, float c)
{
  if (a == 0)
    return;
  float x1, x2, realPart, imaginaryPart = 0;
  float discriminant = b*b - 4 * a*c;
  if (a + b + c == 0)
  {
    x1 = 1;
    x2 = c / a;
    cout << "The roots are: \n";
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
  }
  else if (discriminant > 0)
  {
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);
    cout << "The roots are:" << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
  }
  else if (discriminant == 0)
  {
    cout << "The roots are equal: " << endl;
    x1 = -b / 2 * a;
    cout << "x1 = x2 = " << x1 << endl;
  }
  else if (discriminant < 0)
  {
    realPart = -b / (2 * a);
    imaginaryPart = sqrt(-discriminant) / (2 * a);
    cout << "Roots are complex and different." << endl;
    cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
    cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    //cout << "Roots are not available..\n";
  }
}



int main()
{
  float a, b, c;
  cout << "Please enter the coefficients: \n";
  cin >> a >> b >> c;

  quadraticEq(a, b, c);

  return 0;
}