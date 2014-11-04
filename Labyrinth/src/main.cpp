#include <iostream>
#include "Labyrinth.h"
#include <vector>
#include <time.h>
#include <string>

using namespace std;

typedef vector <vector<string>> Matrix;


void FillMatr()
{
  int rows = 20;
  int cols = 20;
  srand(time(0));
  int enter_point = rand() % rows;
  int out_point = rand() % cols;
  vector<vector<int>> maze(rows, vector<int>(cols));
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      maze[0][j];// = border.closed;
      maze[j][0];// = border.closed;
      maze[rows - 1][i];// = border.closed;
      maze[j][cols - 1];// = border.closed;
      maze[0][rand()];// = Border::is_enter(true);

    }
    cout << endl;
    
  }
}



int main()
{
  FillMatr();
  //PathSearch();
  //OutMatr();
  return 0;
}