#include <iostream>

using namespace std;


bool checkIfLucky(int number)
{
  while (number > 0)
  {
    int digit = number % 10;
    number /= 10;
    
  }

  return true;
}

int main()
{
  int number;

  cout << "Please enter number of ticket: " << endl;

  cin >> number;

  if (checkIfLucky(number))
    cout << "You are lucky today!!!\n";
  cout << "Sorry, another time.. :(\n";


  return 0;
}