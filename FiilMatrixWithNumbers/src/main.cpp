#include "SomeHeader.h"

#include <iostream>
#include <vector>

using namespace std;


void multipliedMatrix(int n)
{
	vector <vector<int>> multi(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			multi[i][j] = i*j;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << multi[i][j] << "\t";
		}
		cout << "\n";
	}
}

void summedMatrix(int n)
{
	vector <vector<int>> summ(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			summ[i][j] = i + j;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << summ[i][j] << "\t";
		}
		cout << "\n";
	}
}

void fillBottomLeft(int n)
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

void fillTopRight(int n)
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


int main()
{
	cout << "Multiplied matrix\n";
	multipliedMatrix(4);
	cout << "Summed matrix\n";
	summedMatrix(4);
	cout << "Filled bottom left\n";
	fillBottomLeft(4);
	cout << "Filled top right\n";
	fillTopRight(4);
}