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


void fillMatrixDiagonallyByOne(int n) // fill diagonally by 1
{
  vector <vector<int>> diagonally_filled_by_one(n, vector<int>(n));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i == j)
        diagonally_filled_by_one[i][j] = 1;
      else if (i + j == n - 1)
        diagonally_filled_by_one[i][j] = 2;
    }
  }
  printMatrix(diagonally_filled_by_one);

}


void fillMatrixDiagonallyByZero(int n) // fill diagonally by ZEROs
{
  vector <vector<int>> diagonally_filled_by_zero(n, vector<int>(n));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i == j)
        diagonally_filled_by_zero[i][j] = 0;
      else if (i - j == 1)
        diagonally_filled_by_zero[i][j] = 1;
      else if (j - i == 1)
        diagonally_filled_by_zero[i][j] = 2;
    }
  }
  printMatrix(diagonally_filled_by_zero);

}


void fillTopLeft(int n) // Fill matrix by numbers in order from top left bottom right.
{
  vector <vector<int>> topleft_filled(n, vector<int>(n));
  int k = 1;
  int iCol = 0;
  int iRow = 0;

  while (iCol < n && iRow < n)
  {
    int iRowStep = iRow;
    int iColStep = iCol;

    if (iCol < n - 1)
      iColStep = iCol++;
    else
      iRowStep = iRow++;


    while (iColStep >= 0 && iRowStep < n)
      topleft_filled[iRowStep++][iColStep--] = k++;
  }
  printMatrix(topleft_filled);
}


void fillBottomRight(int n) // Fill matrix by numbers in order from bottom right to top left.
{
  vector <vector<int>> bottomright_filled(n, vector<int>(n));
  int k = 1;
  int iCol = n - 1;
  int iRow = n - 1;

  while (iCol >= 0 && iRow >= 0)
  {
    int iRowStep = iRow;
    int iColStep = iCol;

    if (iCol > 0)
      iColStep = iCol--;
    else
      iRowStep = iRow--;


    while (iColStep < n  && iRowStep >= 0)
      bottomright_filled[iRowStep--][iColStep++] = k++;
  }
  printMatrix(bottomright_filled);
}

void fillSpirallyInOrder(int n) // fill matrix in in-spiral order
{
  vector <vector<int>> spiral_in(n, vector<int>(n));
  int number = 1;
  int size = static_cast< int >(ceil(static_cast<double>(n) / 2.0));
  int len = n;
  int j;

  for (int i = 0; i < size; ++i)
  {
    for (j = 0; j < len; ++j)
      spiral_in[i][i + j] = number++;
    for (j = 1; j < len; ++j)
      spiral_in[i + j][n - 1 - i] = number++;
    for (j = len - 2; j > -1; --j)
      spiral_in[n - 1 - i][i + j] = number++;
    for (j = len - 2; j > 0; --j)
      spiral_in[i + j][i] = number++;

    len -= 2;
  }

  printMatrix(spiral_in);
}

void fillSpirallyOut(int n) // fill matrix in out-spiral order
{
  vector <vector<int>> spiral_in(n, vector<int>(n));
 
  int i = n / 2;
  int j = n % 2 == 0 ? (n / 2) - 1 : (n / 2); 

  int direction = 0; 
  int stepsCount = 1; 
  int stepPosition = 0; 
  int stepChange = 0; 

  for (int k = 1; k <= n * n; k++)
  {
    spiral_in[i][j] = k;

    if (stepPosition < stepsCount)
    {
      stepPosition++;
    }
    else
    {
      stepPosition = 1;
      if (stepChange == 1)
      {
        stepsCount++;
      }
      stepChange = (stepChange + 1) % 2;
      direction = (direction + 1) % 4;
    }
    switch (direction)
    {
    case 0:
      j++;
      break;
    case 1:
      i--;
      break;
    case 2:
      j--;
      break;
    case 3:
      i++;
      break;
    }
  }

  printMatrix(spiral_in);
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
  cout << "Filled diagonally by 1\n";
  fillMatrixDiagonallyByOne(4);
  cout << "Filled diagonally by ZEROs\n";
  fillMatrixDiagonallyByZero(4);
  cout << "Filled matrix diagonally by numbers in order from left top\n";
  fillTopLeft(4);
  cout << "Filled matrix diagonally by numbers in order from right bottom\n";
  fillBottomRight(4);
  cout << "Filled matrix spirally by numbers in order\n";
  fillSpirallyInOrder(4);
  cout << "Filled matrix spirally(reversed) by numbers in order\n";
  fillSpirallyOut(4);

  return 0;
}