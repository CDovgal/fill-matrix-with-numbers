#include <iostream>
#include "Labyrinth.h"
#include <vector>
#include <time.h>
#include <string>

using namespace std;



int main()
{
  Labyrinth lab(10, 10);
  lab.generateMaze();
  lab.PrintMaze();
  return 0;
}