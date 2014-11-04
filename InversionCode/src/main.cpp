#include <iostream>

using namespace std;

void convertToBinary(int number)
{
  int size = 0;
  for (size_t tmp = number; tmp != 0; tmp >>= 1)
    size++;
  for (int i = size - 1; i >= 0; --i)
    cout << ((number >> i) & 1);
  cout << "\n";
}

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
  {
    bin = (bin << count) | (~bin);
  }
  else
  {
    bin = (bin << count) | bin;
  }

  return bin;
}

int main()
{
  int bin;

  cout << "Enter binary code" << endl;
  cin >> bin;

  int invers = inversionCodeGenerator(bin);

  convertToBinary(invers);
  cout << invers << endl;

  return 0;
}