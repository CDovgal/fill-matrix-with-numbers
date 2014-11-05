#include <iostream>
#include "Labyrinth.h"
#include <vector>
#include <time.h>
#include <string>

using namespace std;


bool Labyrinth::IsBorder(const Cell& cell)
{
  return true;
}

bool Labyrinth::IsWall(const Cell& cell)
{
  return true;
}

void Labyrinth::SetEntrance(const Cell& cell)
{

}

void Labyrinth::SetExit(const Cell& cell)
{

}

void Labyrinth::FillMatrix()
{
  int size = 20;

  srand((unsigned)time(0));

  
  Matrix maze(size);

  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      cout << "1";
    }
    cout << endl;
  }
}

void Labyrinth::FindSolution()
{

}



int main()
{
  Labyrinth lab;
  lab.FillMatrix();
  return 0;
}