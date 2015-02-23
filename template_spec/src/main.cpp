#include <iostream>
#include "classA.h"

int main()
{
  {
    A<int> a(5);
    a.Show();

    A<char*> b("Abcd");
    b.Show();
    b.Set();
    b.Show();
  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "Leaks" << std::endl;
  else
    std::cout << "No leaks" << std::endl;
}