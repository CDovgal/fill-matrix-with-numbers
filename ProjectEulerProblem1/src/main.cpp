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
    if (is_prime(i))
      ++count;
    if (count == 10001)
    {
      std::cout << i << std::endl;
      break;
    }
  }
}


void adjacent_digit_product()
{
  //The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
  //Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
  long long temp = 0;
  long long result = 0;
  std::string number("7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450");
  while (number.size() > 12)
  {
    temp = number.at(0) - 48;
    for (int i = 1; i < 13; ++i)
    {
      temp *= number.at(i) - 48;
    }
    if (temp > result)
      result = temp;
    number.erase(0, 1);
  }
  std::cout << result << std::endl;
}


void PythagoreanTriplet()
{
  //There exists exactly one Pythagorean triplet for which a + b + c = 1000.
  //Find the product abc.
  for (int a = 0; a < 1001; ++a)
  {
    for (int b = 0; b < 1001; ++b)
    {
      int c = 1000 - (a + b);
      if (a < b && b < c && (a*a + b*b == c*c) && (a + b + c) == 1000)
      {
        std::cout << a << " " << b << " " << c << std::endl;
        std::cout << a*b*c << std::endl;
      }
    }
  }
}


void SummationPrimes()
{
  long long sum = 0;
  for (int i = 1; i < 2000001; ++i)
  {
    if (is_prime(i))
      sum += i;
  }
  std::cout << sum << std::endl;
}


void LargestProductInAGrid()
{
  //The product of these numbers is 26 × 63 × 78 × 14 = 1788696. 
  //What is the greatest product of four adjacent numbers in the same 
  //direction(up, down, left, right, or diagonally) in the 20×20 grid ?

  int Matrix[20][20] = {
    8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8,
    49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 0,
    81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65,
    52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91,
    22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
    24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
    32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
    67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
    24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
    21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95,
    78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14, 9, 53, 56, 92,
    16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57,
    86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
    19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40,
    4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
    88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
    4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36,
    20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16,
    20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54,
    1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48
  };

  long long h_result = 0;
  int h_n = 4;
  int h_first = 0;
  for (int i = 0; i < 20;)
  {
    long long temp = 1;
    for (int j = h_first; j < h_n && j < 20; ++j)
    {
      if (Matrix[i][j] == 0)
        break;
      temp *= Matrix[i][j];
      if (temp > h_result)
        h_result = temp;
    }
    ++h_first;
    ++h_n;
    if (h_n == 19)
    {
      ++i;
      h_first = 0;
      h_n = 4;
    }
  }
  std::cout << "Horizontal Product: " << h_result << std::endl;


  long long v_result = 0;
  int v_n = 4;
  int v_first = 0;
  for (int j = 0; j < 20;)
  {
    long long temp = 1;
    for (int i = v_first; i < v_n && i < 20; ++i) // v_n < 20
    {
      if (Matrix[i][j] == 0)
        break;
      temp *= Matrix[i][j];
      if (temp > v_result)
        v_result = temp;
    }
    ++v_first;
    ++v_n;
    if (v_n == 19)
    {
      ++j;
      v_first = 0;
      v_n = 4;
    }
  }
  std::cout << "Vertical Product: " << v_result << std::endl;

  int Test_Matrix[6][6] =
  {
    52, 12, 50, 77, 91, 8,
    69, 48, 4, 56, 62, 0,
    30, 3, 49, 13, 36, 65,
    56, 71, 37, 2, 36, 91,
    40, 28, 66, 33, 13, 80,
    84, 20, 35, 17, 12, 50
  };

  long long dl_result = 0;
  int dl_first = 0;
  int dl_last = 4;
  int dl_current = 0;
  for (int i = 0; i < 17;)
  {
    long long temp = 1;
    for (int j = dl_first; j < dl_last && j < 20; ++j) // dl_last < 20
    {
      temp *= Matrix[i][j];
      ++i;
    }
    if (temp > dl_result)
      dl_result = temp;
    ++dl_first;
    ++dl_last;
    i = dl_current;
    if (dl_last == 21)
    {
      ++dl_current;
      i = dl_current;
      dl_first = 0;
      dl_last = 4;
    }
  }
  std::cout << "Left diagonal !/ Product: " << dl_result << std::endl;


  long long dr_result = 0;
  int dr_first = 19;
  int dr_last = 15;
  int dr_current = 0;
  for (int i = 0; i < 17;)
  {
    long long temp = 1;
    for (int j = dr_first; j > dr_last; --j)
    {
      temp *= Matrix[i][j];
      ++i;
    }
    if (temp > dr_result)
      dr_result = temp;
    --dr_first;
    --dr_last;
    i = dr_current;
    if (dr_last == 0)
    {
      ++dr_current;
      i = dr_current;
      dr_first = 19;
      dr_last = 15;
    }
  }

  std::cout << "Right diagonal / Product: " << dr_result << std::endl;

}


//int check_for_divisors(long long i_numb)
//{
//  int count = 0;
//  for (long long i = 1; i < i_numb; ++i)
//  {
//    if (i_numb % i == 0)
//      ++count;
//  }
//  return count;
//}

void DivisibleTriangularNumber()
{
  //What is the value of the first triangle number to have over five hundred divisors?

  /*int num_of_divisors = 0;
  long long sum = 1;
  long long cur_numb = 2;
  while (num_of_divisors < 501)
  {
    num_of_divisors = check_for_divisors(sum);
    sum += cur_numb;
    ++cur_numb;
  }
  std::cout << sum << std::endl;*/


  long long int i = 1;
  long long int sum = 0;

  while (true) {
    int number = 2;
    sum += i;
    for (long long int n = 2; n < sqrt(sum); ++n)
    if (sum % n == 0)
      number += 2;

    if (number > 500) {
      std::cout << sum << std::endl;
      break;
    }

    ++i;

  }
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
  //adjacent_digit_product();
  //PythagoreanTriplet();
  //SummationPrimes();
  //LargestProductInAGrid();
  //DivisibleTriangularNumber();


  return 0;
}