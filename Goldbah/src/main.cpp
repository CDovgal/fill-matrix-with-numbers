#include <iostream>

int main()
{
  for (int i = 2; i < 25; ++i)
  {
    //std::cin >> number;
    if (i % 2 > 0)
      std::cout << i << " Simple number." << std::endl;
    else
      std::cout << i << " Not simple." << std::endl;
    /*if (number == 0)
      break;*/
  }
  return 0;
}