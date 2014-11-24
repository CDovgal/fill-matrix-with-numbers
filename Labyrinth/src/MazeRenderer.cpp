#include "MazeRenderer.h"
#include "Labyrinth.h"
#include <iostream>

Renderer::Renderer()
{

}

void Renderer::printMaze(const Labyrinth& i_labyrinth, const Agent& i_agent) const
{
  for (int i = 0; i < i_labyrinth.mazeRows(); ++i)
  {
    for (int j = 0; j < i_labyrinth.mazeCols(); ++j)
    {
      Cell cur_cell(i, j);
      if (i_labyrinth.isEntrance(cur_cell))
        std::cout << "E ";
      else if (i_labyrinth.isExit(cur_cell))
        std::cout << "? ";
      else if (i_labyrinth.isBorder(cur_cell))
        std::cout << "* ";
      else if (i_agent.agentTrace(cur_cell) && !i_labyrinth.isRightWallClosed(i, j))
        std::cout << "^ ";
      else if (i_agent.agentTrace(cur_cell) && !i_labyrinth.isRightWallClosed(i, j) && !i_labyrinth.isDownWallClosed(i, j))
        std::cout << "^ ";
      else if (i_agent.agentTrace(cur_cell) && !i_labyrinth.isDownWallClosed(i, j))
        std::cout << "2 ";
      else if (i_labyrinth.isDownWallClosed(i, j) && !i_labyrinth.isRightWallClosed(i, j))
        std::cout << "_ ";
      else if (!i_labyrinth.isDownWallClosed(i, j) && i_labyrinth.isRightWallClosed(i, j))
        std::cout << " |";
      else if (i_labyrinth.isDownWallClosed(i, j) && i_labyrinth.isRightWallClosed(i, j))
        std::cout << "_|";
      else if (!i_labyrinth.isDownWallClosed(i, j) && !i_labyrinth.isRightWallClosed(i, j))
        std::cout << "  ";
    }
    std::cout << endl;
  }
}

void Renderer::printLabyrinth() const
{
  Labyrinth lab(20, 20);
  lab.generateMaze();
  Agent age;
  age.FindSolution(lab);
  printMaze(lab, age);
}