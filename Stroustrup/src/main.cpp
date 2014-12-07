
#include <iostream>
#include <string>

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

    return 0;
}