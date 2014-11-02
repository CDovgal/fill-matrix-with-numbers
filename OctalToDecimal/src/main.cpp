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
  int numb = 0;
  while (oct)
  {
    numb = oct; 
    numb %= 10;
    oct_deq.push_front(numb);
    oct/=10;
  }

  int i = 0;

  while (i < oct_deq.size())
  {
    switch (oct_deq.at(i))
    {
    case  0:
      cout << "000"; break;
    case  1:
      cout << "001"; break;
    case  2:
      cout << "010"; break;
    case  3:
      cout << "011"; break;
    case  4:
      cout << "100"; break;
    case  5:
      cout << "101"; break;
    case  6:
      cout << "110"; break;
    case  7:
      cout << "111"; break;
    default:
      cout << "\n Invalid octal digit ", oct_deq.at(i);
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
  cout << endl;

  return 0;
}