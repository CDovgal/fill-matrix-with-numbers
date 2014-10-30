#include <iostream>

using namespace std;

int inversionCodeGenerator(int bin)
{
  int numb = bin;
  int bits_set = 0;
  int count = 0;

  for (; numb; numb >>= 1)
  {
    bits_set += numb & 1;
    count++;
  }

  if (bits_set % 2)
    return bin = (bin << count) | ~bin;
  else
    return bin = (bin << count) | bin;
}

int convertToBinary(int number)
{
  int bin = 0, pos = 1;
  while (number > 0)
  {
    bin = bin + (number % 2) * pos;
    number = number / 2;
    pos *= 10;
  }
  return bin;
}

int main()
{
  int bin;

  cout << "Enter binary code" << endl;
  cin >> bin;

  int invers = inversionCodeGenerator(bin);

  cout << convertToBinary(invers) << endl;
  cout << invers << endl;


  return 0;
}