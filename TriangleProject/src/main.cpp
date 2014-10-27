#include <iostream>
#include "Triangle.h"

using namespace std;


int main()
{
  Triangle *tri = new Triangle;
  int a, b, c = 0;

  cout << "Enter sides:" << endl;
  cout << "A: ";
  cin >> a;
  cout << "B: ";
  cin >> b;
  cout << "C: ";
  cin >> c;

  tri->checkType(a, b, c);

  delete tri;

  return 0;
}