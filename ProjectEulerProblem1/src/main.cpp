#include <iostream>
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

void SumSquareDifference()
{
  //The sum of the squares of the first ten natural numbers is,
  //12 + 22 + ... + 102 = 385
  // The square of the sum of the first ten natural numbers is,
  //(1 + 2 + ... + 10)2 = 552 = 3025
  //Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
  //Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
  int sum_of_squares = 0;
  int square_of_the_sum = 0;

  for (int i = 1; i < 101; ++i)
  {
    sum_of_squares += pow(i, 2);
  }
  std::cout << "Sum of squares: " << sum_of_squares << std::endl;

  int temp = 0;
  for (int i = 1; i < 101; ++i)
  {
    temp += i;
  }
  square_of_the_sum = pow(temp, 2);
  std::cout << "Square of the sum: " << square_of_the_sum << std::endl;

  std::cout << "Difference between square of the sum and sum of suares: " << square_of_the_sum - sum_of_squares << std::endl;
}


bool is_prime(int i_numb)
{
  if (i_numb == 1)
    return false;
  for (int d = 2; d*d <= i_numb; ++d){
    if (i_numb % d == 0)
      return false;
  }
  return true;
}

void Prime_10001()
{
  //By listing the first six prime numbers : 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
  //What is the 10 001st prime number ?
  int count = 0;
  for (int i = 2;; ++i)
  {
    if (count == 10001)
    {
      std::cout << i-1 << std::endl;
      break;
    }
    if (is_prime(i))
      ++count;
  }
}


void adjacent_digit_product()
{
  //The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
  //Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
  int temp = 0;
  int result = 0;
  std::string number("7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450");
  while (number.size() != 0)
  {
    temp = number.at(0) - 48;
    for (int i = 1; i < 13 && number.size() >= 13; ++i)
    {
      temp *= number.at(i)-48;
    }
    if (temp > result)
      result = temp;
    number.erase(0, 1);
  }
  std::cout << result << std::endl;
}

int main()
{
  //FindSumMultiplies();
  //FibonacciNumbers();
  //PrimeFactor();
  //LargestPalindromeProduct();
  //SmallestMultiple();
  //SumSquareDifference();
  //Prime_10001();
  adjacent_digit_product();

  return 0;
}