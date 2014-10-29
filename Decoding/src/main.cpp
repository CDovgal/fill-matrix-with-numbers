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
  return  bin / 10;
}


int main()
{
  int decimal;

  cout << "Please enter encoded decimal number: \n";
  cin >> decimal;

  int binary = convertToBinary(decimal);

  int decoded = decodeNumber(binary);

  int dec = convertToDecimal(decoded);

  cout << "Decoded decimal representation: ";
  cout << dec << endl;

  return 0;
}