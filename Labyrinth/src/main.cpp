#include <iostream>
#include "Labyrinth.h"
#include <vector>
#include <time.h>
#include <string>
#include "Agent.h"


int main()
{
  Labyrinth lab(25, 25);
  lab.generateMaze();
  lab.PrintMaze();
  return 0;
}