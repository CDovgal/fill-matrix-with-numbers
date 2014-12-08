
#include <iostream>
#include <string>
#include <limits>

int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa = 3;

enum En
{
  a,
  b,
  c,
  d,
  e
};

enum En2
{
  
};

enum En3
{
  one,
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  eleven,
  twelwe,
  thirteen,
  fourteen,
  fifteen,
  sixteen,
  seventeen,
  eighteen,
  nineteen,
  twenty
};

int main()
{
    std::cout << "Hello World!!!" << std::endl;

    char ch = 's';
    std::string s = "sadklasdlkad";
    int count;
    count = 1;
    const double pi = 3.14;
    extern int error_number;
    //error_number = 3;
    const char* name;
    name = "Njalsda";
    const char* season[] = { "dsada", "sdadsa" };

    std::cout << ch << " " << s << " " << std::endl;

    std::cout << "\nInt: " << sizeof(int) 
      << "\nShort: " << sizeof(short int) 
      << "\nLong: " << sizeof(long) 
      << "\nDouble: " << sizeof(double) 
      << "\nChar: " << sizeof(char) 
      << "\nString: " << sizeof(std::string)
      << "\nString s: " << sizeof(s)
      << "\nFloat: " << sizeof(float)
      << "\nBool: " << sizeof(bool)
      << "\nChar*: " << sizeof(char*)
      << "\nInt*: " << sizeof(int*)
      << "\nString*: " << sizeof(std::string*)
      << "\nEnum: " << sizeof(En)
      << "\nEnum2: " << sizeof(En2)
      << "\nEnum3: " << sizeof(En3)

      << "\n";

    for (char i = 97; i < 123; ++i)
    {
      std::cout << i << " ";
    }
    std::cout << "\n";

    for (char i = 48; i < 58; ++i)
    {
      std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Int min: " << std::numeric_limits<int>::min() <<
      "\n" << "Int max: " << std::numeric_limits<int>::max() <<
      "\n" << "Char min: " << std::numeric_limits<char>::min() <<
      "\n" << "Char max: " << std::numeric_limits<char>::max() <<
      "\n" << "Short min: " << std::numeric_limits<short>::min() <<
      "\n" << "Short max: " << std::numeric_limits<short>::max() <<
      "\n" << "Long min: " << std::numeric_limits<long>::min() <<
      "\n" << "Long max: " << std::numeric_limits<long>::max() <<
      "\n" << "Float min: " << std::numeric_limits<float>::min() <<
      "\n" << "Float max: " << std::numeric_limits<float>::max() <<
      "\n" << "Double min: " << std::numeric_limits<double>::min() <<
      "\n" << "Double max: " << std::numeric_limits<double>::max() <<
      "\n" << "Long double min: " << std::numeric_limits<long double>::min() <<
      "\n" << "Long double max: " << std::numeric_limits<long double>::max() <<
      "\n" << "Unsigned min: " << std::numeric_limits<unsigned>::min() <<
      "\n" << "Unsigned max: " << std::numeric_limits<unsigned>::max() << "\n";

    


    return 0;
}