#include <iostream>
#include "Labyrinth.h"
#include <vector>
#include <time.h>
#include <string>
#include "Agent.h"


int main()
{
  Labyrinth lab(7, 7);
  lab.generateMaze();
  //lab.PrintMaze();
  Agent age;
  age.FindSolution(lab);
  age.printAgent();
  lab.PrintMaze();
  return 0;
}