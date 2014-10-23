#include "SomeHeader.h"

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;


typedef vector <vector<int>> Matrix;

void printMatrix(const Matrix& i_matrix)
{
  int size = i_matrix.size();

  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      cout << i_matrix[i][j] << "\t";
    }
    cout << "\n";
  }
}

void fillMultipliedIndexes(int n) //filled by multiplication of indexes
{
  if (n <= 1)
    return;

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cout << i*j << "\t";
    }
    cout << "\n";
  }
}

void fillSummedIndexes(int n) // filled by sum of matrix cells indexes
{
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cout << i + j << "\t";
    }
    cout << "\n";
  }
}

void fillBottomLeft(int n) // filled by numbers in course from bottom left corbner to top right
{
  vector <vector<int>> bottom_filled(n, vector<int>(n));
  int k = 1;
  int iCol = 0;
  int iRow = n - 1;

  while (iCol < n && iRow >= 0)
  {
    int iRowStep = iRow;
    int iColStep = iCol;

    if (iCol < n - 1)
      iColStep = iCol++;
    else
      iRowStep = iRow--;

    while (iColStep >= 0 && iRowStep >= 0)
      bottom_filled[iRowStep--][iColStep--] = k++;
  }
  printMatrix(bottom_filled);
}




void fillTopRight(int n) // filled by numbers in course from top right corner to left bottom
{
  vector <vector<int>> top_filled(n, vector<int>(n));

  int k = 1;
  int iCol = n - 1;
  int iRow = 0;

  while (iCol >= 0 && iRow < n)
  {
    int iRowStep = iRow;
    int iColStep = iCol;

    if (iCol > 0)
      iColStep = iCol--;
    else
      iRowStep = iRow++;

    while (iColStep < n && iRowStep < n)
      top_filled[iRowStep++][iColStep++] = k++;
  }
  printMatrix(top_filled);
}

vector<int> generateFibonacci(int n)
{
  vector<int> fibo(n);

  for (int c = 0; c < n; ++c)
  {
    if (c <= 1)
      fibo.at(c) = c;
    else
    {
      fibo.at(c) = fibo.at(c - 1) + fibo.at(c);
      fibo.at(c - 1) = fibo.at(c);
      fibo.at(c) = fibo.at(c) + fibo.at(c - 2);
    }
  }
  return fibo;
}


void fillByFibonacciNumb(int n) //filled by Fibonacci number in memory location order
{
  int size = n*n;

  vector <int> fibnumb_filled = generateFibonacci(size);

  for (int i = 0; i < size; ++i)
  {
    cout << fibnumb_filled[i] << "\t";
    if ((i + 1) % n == 0)
      cout << "\n";
  }
}


int main(int argc, char **argv)
{
  /*::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();*/

  cout << "Multiplied matrix\n";
  fillMultipliedIndexes(4);
  cout << "Summed matrix\n";
  fillSummedIndexes(4);
  cout << "Filled bottom left\n";
  fillBottomLeft(4);
  cout << "Filled top right\n";
  fillTopRight(4);
  cout << "Filled by Fibonacci numbers\n";
  fillByFibonacciNumb(4);

  return 0;
}