#include <iostream>
#include <vector>

using namespace std;


int converToBinary(int number)
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

bool checkForPair(int binary)
{
  return true;
}

int encodeNumber(int bin)
{
  int count = 0;
  int numb = bin;

  while (numb)
  {
    numb &= (numb - 1);
    count++;
  }

  cout << "COUNT " << count << endl;

  return count % 2 == 0 ? bin <<= 1 : bin ^= 0;
}

int main()
{
  int decimal;

  cout << "Please enter decimal number: \n";
  cin >> decimal;
  cout << "Binary representation: ";

  int bin = converToBinary(decimal);
  cout << bin << endl;

  cout << "Encoded binary representation: ";

  int enc = encodeNumber(bin);
  cout << enc << endl;

  cout << "Encoded decimal representation: ";

  cout << convertToDecimal(enc) << endl;

  return 0;
}