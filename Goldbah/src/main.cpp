#include <iostream>

bool isSimple(int i_numb)
{
  for (int i = 2; i < i_numb - 1; ++i)
  {
    if (i_numb % i == 0)
    {
      return false;
    }
    else
      return true;
  }
}

int v()
{
  int m = 0;
  return m++;
}

int main()
{
  int n;
  std::cin >> n;
  for (int i = 1; i < n - 1; ++i)
  {
    int j = n - i;
    if (isSimple(j) && isSimple(i))
    {
      std::cout << i << "+" << j << std::endl;
      break;
    }
  }
  std::cout << 7 / 9 * 9 << std::endl;
  std::cout << v() << std::endl;
  int a = 5;
  int b = 10;
  std::cout << (a>b?a:b) << std::endl;
  return 0;
}