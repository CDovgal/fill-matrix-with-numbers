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

void printOctal(deque<string> oct)
{
  for (unsigned i = 0; i < oct.size(); ++i)
    cout << oct.at(i).c_str();
}

deque<string> octalToBinary(int oct)
{
  deque<int> oct_deq;
  deque<string> octal_out;

  while (oct)
  {
    oct_deq.push_front(oct%10);
    oct/=10;
  }

  unsigned i = 0;

  while (i < oct_deq.size())
  {
    switch (oct_deq.at(i))
    {
    case  0:
      octal_out.push_back("000"); break;
    case  1:
      octal_out.push_back("001"); break;
    case  2:
      octal_out.push_back("010"); break;
    case  3:
      octal_out.push_back("011"); break;
    case  4:
      octal_out.push_back("100"); break;
    case  5:
      octal_out.push_back("101"); break;
    case  6:
      octal_out.push_back("110"); break;
    case  7:
      octal_out.push_back("111"); break;
    default:
      octal_out.clear();
      octal_out.push_back("\n Invalid octal digit ");
      return octal_out;
    }
    i++;
  }
  return octal_out;
}

int main()
{
  int octal;

  cout << "Enter octal number: \n";
  cin >> octal;

  cout << "Octal to decimal: " << octalToDecimal(octal) << endl;

  cout << "Octal to binary: ";
  deque<string> oct = octalToBinary(octal);
  printOctal(oct);
  cout << endl;

  return 0;
}