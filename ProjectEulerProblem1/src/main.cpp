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
  long long LPF = 1;
  for (long long i = 2; i <= 600851475143 && number != 1; ++i)
  {
    while (number % i == 0)
    {
      number/= i;
      LPF = i;
    }
      
  }
  std::cout << LPF << std::endl;
}

void LargestPalindromeProduct()
{
  //A palindromic number reads the same both ways. 
  //The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
  //Find the largest palindrome made from the product of two 3 - digit numbers.

}


int main()
{
  //FindSumMultiplies();
  //FibonacciNumbers();
  //PrimeFactor();
  LargestPalindromeProduct();

  return 0;
}