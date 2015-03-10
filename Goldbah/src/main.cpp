#include <iostream>

bool isSimple(int i_numb)
{
  for (int i = 2; i < i_numb - 1; ++i)
  {
    if (i_numb % i == 0)
    {
      return false;
    }
  }
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
  return 0;
}