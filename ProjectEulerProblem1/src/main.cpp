﻿#include <iostream>
#include <vector>

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
      number /= i;
      LPF = i;
    }

  }
  std::cout << LPF << std::endl;
}


bool check_palindromness(int i_numb)
{
  std::vector<int> digits;

  while (i_numb != 0)
  {
    digits.push_back(i_numb % 10);
    i_numb /= 10;
  }

  auto it_begin = digits.cbegin();
  auto it_end = digits.crbegin();
  while (it_begin != digits.cend() && it_end != digits.crend())
  {
    if (*it_begin != *it_end)
      return false;
    ++it_begin;
    ++it_end;
  }
  return true;
}

void LargestPalindromeProduct()
{
  //A palindromic number reads the same both ways. 
  //The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
  //Find the largest palindrome made from the product of two 3 - digit numbers.
  int temp = 0;
  for (int i = 999; i > 99; --i)
  {
    for (int j = 999; j > 99; --j)
    {
      if (check_palindromness(i*j))
      {
        if (i*j > temp)
          temp = i*j;
      }
    }
  }
  std::cout << temp << std::endl;
  //906609 right answer
}


void SmallestMultiple()
{
  //2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
  //What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?
  int number = 1;
  bool passed = true;
  for (;;)
  {
    for (int i = 1; i < 21; ++i)
    {
      passed = true;
      if (number % i != 0)
      {
        passed = false;
        ++number;
        break;
      }
    }
    if (passed)
    {
      std::cout << number << std::endl;
      break;
    }
  }
}


int main()
{
  //FindSumMultiplies();
  //FibonacciNumbers();
  //PrimeFactor();
  //LargestPalindromeProduct();
  SmallestMultiple();

  return 0;
}