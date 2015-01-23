#include <iostream>
#include <string>

int main()
{
  std::string input;

  for (;;)
  {
    std::cin >> input;
    if (input == "Quit")
    {
      std::cout << "Exiting program..." << std::endl;
      break;
    } 
    
    std::cout << input << std::endl;
  }
  return 0;
}