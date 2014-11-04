#include <iostream>
#include <vector>

using namespace std;

int convertToDecimal(int number)
{
  int dec = 0, pos = 0;
  int factor = 1;

  while (number > 0)
  {
    if ((number % 10) == 1)
    {
      dec += factor;
    }
    number /= 10;
    pos++;
    factor = factor * 2;
  }

  return dec;
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

int decodeNumber(int bin)
{
  int bits_set = 0;

  for (int numb = bin; numb; numb >>= 1)
  {
    bits_set += numb & 1;
  }

  if (bits_set % 2 == 0)
  {
    cout << "Invalid number!!!!\n";
    return 0;
  }
  else
    return  bin >> 1;
}


int main()
{
  int decimal;

  cout << "Please enter encoded decimal number: \n";
  cin >> decimal;
  cout << "Encoded decimal number in binary representation: ";
  int bin = convertToBinary(decimal);
  cout << bin << endl;

  cout << "Decoded decimal number in binary representation: ";
  int decoded = decodeNumber(decimal);
  int dec_bin = convertToBinary(decoded);
  cout << dec_bin << endl;

  cout << "Decoded decimal representation: ";
  cout << decoded << endl;

  return 0;
}