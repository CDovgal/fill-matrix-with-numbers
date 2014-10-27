#include <iostream>

using namespace std;


int digit_sum(int number)
{
  unsigned sum = 0;

  while (number > 0)
  {
    int digit = number % 10;
    number /= 10;
    sum+=digit;
  }

  return sum;
}


bool checkIfLucky(int number)
{
  int sum_left = 0;
  int sum_right = 0;
  int left = number % 1000; 
  int right = number / 1000;

  if (digit_sum(left) == digit_sum(right))
    return true;

  return false;
}




int main()
{
  int number;

  cout << "Please enter number of ticket: " << endl;

  cin >> number;

  if (checkIfLucky(number))
    cout << "You are lucky today!!!\n";
  else
    cout << "Sorry, another time.. :(\n";


  return 0;
}