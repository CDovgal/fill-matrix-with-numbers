#include <iostream>
#include "Labyrinth.h"
#include <vector>
#include <time.h>
#include <string>

using namespace std;



int main()
{
  Labyrinth lab(25, 25);
  lab.generateMaze();
  lab.PrintMaze();
  return 0;
}