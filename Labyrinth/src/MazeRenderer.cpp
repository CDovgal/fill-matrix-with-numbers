#include "MazeRenderer.h"
#include "Labyrinth.h"
#include <iostream>
#include <cassert>

Renderer::Renderer()
{

}

void Renderer::printMaze(const Labyrinth& i_labyrinth, const Agent& i_agent) const
{
  for (int i = 0; i < i_labyrinth.mazeRows(); ++i)
  {
    for (int j = 0; j < i_labyrinth.mazeCols(); ++j)
    {
      Cell cur_cell(j, i);
      if (i_labyrinth.isEntrance(j, i))
        std::cout << "E ";
      else if (i_labyrinth.isExit(j, i))
        std::cout << "? ";
      else if (i_labyrinth.isBorder(j, i))
        std::cout << "* ";
      //else if (i_agent.agentTrace(cur_cell) && !i_labyrinth.isRightWallClosed(i, j) && !i_labyrinth.isDownWallClosed(i, j))
      //  std::cout << "^  ";
      //else if (i_agent.agentTrace(cur_cell) && i_labyrinth.isRightWallClosed(i, j) && !i_labyrinth.isDownWallClosed(i, j))
      //  std::cout << "^ |";
      //else if (i_agent.agentTrace(cur_cell) && !i_labyrinth.isRightWallClosed(i, j) && i_labyrinth.isDownWallClosed(i, j))
      //  std::cout << "_^ ";
      //else if (i_agent.agentTrace(cur_cell) && i_labyrinth.isRightWallClosed(i, j) && i_labyrinth.isDownWallClosed(i, j))
      //  std::cout << "_^|";
      else if (i_labyrinth.isRightWallClosed(j, i) && !i_labyrinth.isDownWallClosed(j, i))
        std::cout << " |";
      else if (!i_labyrinth.isRightWallClosed(j, i) && i_labyrinth.isDownWallClosed(j, i))
        std::cout << "_ ";
      else if (i_labyrinth.isRightWallClosed(j, i) && i_labyrinth.isDownWallClosed(j, i))
        std::cout << "_|";
      else if (!i_labyrinth.isRightWallClosed(j, i) && !i_labyrinth.isDownWallClosed(j, i))
        std::cout << "  ";

      /*else if (i_agent.agentTrace(cur_cell) && !i_labyrinth.isRightWallClosed(i, j) && !i_labyrinth.isDownWallClosed(i, j))
        std::cout << "^ ";
        else if (i_agent.agkentTrace(cur_cell) && i_labyrinth.isRightWallClosed(i, j) && !i_labyrinth.isDownWallClosed(i, j))
        std::cout << "^|";
        else if (!i_agent.agentTrace(cur_cell) && !i_labyrinth.isRightWallClosed(i, j) && !i_labyrinth.isDownWallClosed(i, j))
        std::cout << "  ";
        else if (!i_agent.agentTrace(cur_cell) && i_labyrinth.isDownWallClosed(i, j) && !i_labyrinth.isRightWallClosed(i, j))
        std::cout << "_ ";
        else if (!i_agent.agentTrace(cur_cell) && i_labyrinth.isRightWallClosed(i, j) && !i_labyrinth.isDownWallClosed(i, j))
        std::cout << " |";
        else if (!i_agent.agentTrace(cur_cell) && i_labyrinth.isDownWallClosed(i, j) && i_labyrinth.isRightWallClosed(i, j))
        std::cout << "_|";*/
    }
    std::cout << endl;
  }
}

void Renderer::printMaze_v2(const Labyrinth& i_labyrinth, const Agent& i_agent) const
{
  static const int M = 6;
  static const int N = 3;

  static const char vertical_closed_wall = '|';
  static const char vertical_opened_wall = ' ';

  static const char horizontal_closed_wall = '_';
  static const char horizontal_opened_wall = ' ';

  static const std::string horizontal_closed_wall_long(M, horizontal_closed_wall); // M times '_'
  static const std::string horizontal_opened_wall_long(M, horizontal_opened_wall); // M times ' '

  static const std::string horizontal_closed_wall_short(M - 1, horizontal_closed_wall); // (M - 1) times '_'
  static const std::string horizontal_opened_wall_short(M - 1, horizontal_opened_wall); // (M - 1) times ' '

  static const std::string vertical_closed_wall_long(vertical_closed_wall + std::string(M - 1, horizontal_opened_wall)); // 1 time '_' & (M - 1) times ' '
  static const std::string vertical_opened_wall_long(horizontal_opened_wall + std::string(M - 1, horizontal_opened_wall)); // 1 time ' ' & (M - 1) times ' '

  int rows = i_labyrinth.mazeRows() - 1;
  assert(rows > 0);
  int columns = i_labyrinth.mazeCols() - 1;
  assert(columns > 0);

  for (unsigned j = 0; j < columns; ++j)
  {
    //std::cout << (i_labyrinth.isRightWallClosed(0, j) ? horizontal_closed_wall_long.c_str() : horizontal_opened_wall_long.c_str());
    std::cout << horizontal_closed_wall_long.c_str();
  }
  std::cout << "\n";
  for (int i = 1; i <= rows; ++i)
  {
    for (unsigned k = 0; k < N; ++k)
    {
      for (int j = 0; j < columns; ++j)
      {
        if ((N - 1) != k)
        {
          std::cout << (i_labyrinth.isRightWallClosed(i, j) ? vertical_closed_wall_long.c_str() : vertical_opened_wall_long.c_str());
        }
        else
        {
          std::cout << (i_labyrinth.isRightWallClosed(i, j) ? vertical_closed_wall : vertical_opened_wall);
          std::cout << (i_labyrinth.isDownWallClosed(i, j) ? horizontal_closed_wall_short.c_str() : horizontal_opened_wall_short.c_str());
        }
      }
      //std::cout << (i_labyrinth.isRightWallClosed(i, columns) ? vertical_closed_wall : vertical_opened_wall);
      std::cout << vertical_closed_wall;
      std::cout << "\n";
    }
  }
  for (unsigned j = 0; j < columns; ++j)
  {
    std::cout << horizontal_closed_wall_long.c_str();
  }
  std::cout << "\n";
}

void Renderer::printLabyrinth() const
{
  Labyrinth lab(10, 10);
  lab.generateMaze();
  Agent age;
  age.FindSolution(lab);
  printMaze(lab, age);
  std::cout << std::endl;
  printMaze_v2(lab, age);
}