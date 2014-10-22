#include "SomeHeader.h"

#include <iostream>
#include <vector>
//#include <gtest/gtest.h>

using namespace std;


void fillMultipliedIndexes(int n) //filled by multiplication of indexes
{
  if (n <= 1)
    return;
  vector <vector<int>> multi(n, vector<int>(n));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      multi[i][j] = i*j;
      cout << multi[i][j] << "\t";
    }
    cout << "\n";
  }
}

void fillSummedIndexes(int n) // filled by sum of matrix cells indexes
{
  vector <vector<int>> summ(n, vector<int>(n));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      summ[i][j] = i + j;
      cout << summ[i][j] << "\t";
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

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cout << bottom_filled[i][j] << "\t";
    }
    cout << "\n";
  }

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

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cout << top_filled[i][j] << "\t";
    }
    cout << "\n";
  }
}

vector<int> generateFibonacci(int n)
{
  int first = 0, second = 1;

  vector<int> fibo;

  for (int c = 0; c < n; ++c)
  {
    if (c < 1)
      fibo.push_back(first);
    else if (c == 1)
      fibo.push_back(first + second);
    else
    {
      fibo.push_back(first + second);
      first = second;
      second = fibo.at(c);
    }
  }
  return fibo;
}


void fillByFibonacciNumb(int n) //filled by Fibonacci number in memory location order
{
  int k = 0;

  vector <int> fibnumb_filled(n*n);
  fibnumb_filled = generateFibonacci(n*n);

  for (int i = 0; i < n*n; ++i)
  {
      cout << fibnumb_filled[i] << "\t";
      if ((i+1)%(n) == 0)
        cout << "\n";
  }
}


int main(int argc, char **argv)
{
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