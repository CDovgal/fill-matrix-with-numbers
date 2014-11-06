#include "Labyrinth.h"
#include <vector>


Labyrinth::Labyrinth(int i_row, int i_col)
: m_maze(i_row, std::vector<Wall>(i_col))
{
  for (int i = 0; i < i_row; ++i)
  {
    m_maze[i][0].makeBorder();
    m_maze[i][i_col - 1].makeBorder();
  }

  for (int j = 0; j < i_col; ++j)
  {
    m_maze[0][j].makeBorder();
    m_maze[i_row - 1][j].makeBorder();
  }
}

bool Labyrinth::isBorder(const Cell& cell) const
{
  return true;
}

bool Labyrinth::isWall(const Cell& cell) const
{
  return true;
}

void Labyrinth::setEntrance(const Cell& cell)
{

}

void Labyrinth::setExit(const Cell& cell)
{

}

void Labyrinth::buildMaze(int rows, int cols)
{
  Labyrinth lab(rows, cols);
  Wall wall;

  std::vector<Cell> visited_cells;

  int total_cells = rows*cols;
  int visited_count = 1;

  Cell current_cell = lab.entrance();

  while (visited_count < total_cells)
  {
    auto neighbours = findNeighbours(current_cell);

    if (!neighbours.empty())
    {
      auto cell = neighbours.at(rand() % neighbours.size()); //choose one at random
      wall.destroy(); // and step into new cell ??? how to know which of it should be destroyed???? in which direction it
      visited_cells.push_back(current_cell);
      current_cell = cell;//set this new cell current
      ++visited_count;
    }
    else
    {
      current_cell = visited_cells.back();
    }
  }
}

std::vector<Cell> Labyrinth::findNeighbours(const Cell& cur_cell)
{
  std::vector<Cell> neighbour_cells;
  // how to say that we should step in maze and in which direction
  if (m_maze[cur_cell.x][cur_cell.y].destroyable())
  {
    neighbour_cells.push_back(cur_cell);
  }
  return neighbour_cells;
}

Cell Labyrinth::entrance() const
{
  Cell rand_cell_enter(rand() % (40 / 2), 0);
  return rand_cell_enter;
}