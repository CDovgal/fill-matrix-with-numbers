#include <iostream>
#include <deque>

using namespace std;

//bool checkOctalDigits(int octal)
//{
//  return true;
//}

int octalToDecimal(int oct)
{
  int remainder = 0;
  int i = 0;
  int decimal = 0;

  while (oct != 0)
  {
    remainder = oct % 10;
    oct /= 10;
    decimal += remainder * pow(8, i);
    ++i;
  }
  return decimal;
}

void octalToBinary(int oct)
{
  deque<int> oct_deq;
  int i = 0;

  while (oct_deq.at(i))
  {
    switch (oct_deq.at(i))
    {
    case '0':
      printf("000"); break;
    case '1':
      printf("001"); break;
    case '2':
      printf("010"); break;
    case '3':
      printf("011"); break;
    case '4':
      printf("100"); break;
    case '5':
      printf("101"); break;
    case '6':
      printf("110"); break;
    case '7':
      printf("111"); break;
    default:
      printf("\n Invalid octal digit ", oct_deq.at(i));
      return;
    }
    i++;
  }
}

int main()
{
  int octal;

  cout << "Enter octal number: \n";
  cin >> octal;

  cout << "Octal to decimal: " << octalToDecimal(octal) << endl;

  cout << "Octal to binary: "; octalToBinary(octal);

  return 0;
}