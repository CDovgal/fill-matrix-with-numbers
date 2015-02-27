#include <iostream>

void FindSumMultiplies()
{
  //Find the sum of all the multiples of 3 or 5 below 1000.
  int sum = 0;
  for (int i = 0; i < 1000; ++i)
  {
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;
  }
  std::cout << sum << std::endl;
}

void FibonacciNumbers()
{
  //Even Fibonacci numbers
  int first = 0, second = 1, sum = 0, even_value_sum = 0;
  while (sum < 4000000)
  {
    if (sum % 2 == 0)
      even_value_sum += sum;
    sum = first + second;
    first = second;
    second = sum;
  }
  std::cout << even_value_sum << std::endl;
}

void PrimeFactor()
{
  //What is the largest prime factor of the number 600851475143 ?
  long long number = 600851475143;
  for (long long i = 600851475143; i > 2; --i)
  {
    if (i % 2 != 0 && number % i == 0)
      std::cout << number << std::endl;
  }
  /*for (long long i = 600851475142; i > 1; --i)
  {
  if (number % i == 0)
  std::cout << i << " ";
  }*/
}

int main()
{
  //FindSumMultiplies();
  //FibonacciNumbers();
  PrimeFactor();

  return 0;
}