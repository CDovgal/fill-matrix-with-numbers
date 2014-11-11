#include "Labyrinth.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>


Labyrinth::Labyrinth(int i_row, int i_col)
: m_maze(i_row, std::vector<Wall>(i_col))
{
  std::srand((unsigned)time(0));

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

  m_maze[0][rand() % i_col].setEntrance();

  m_maze[i_col - 1][rand() % i_row].setExit();

  PrintMaze();
}

void Labyrinth::generateMaze()
{
  std::vector<Cell> visited_cells;
  std::srand((unsigned)time(0));
  int total_cells = m_maze.size()*m_maze.size();
  int visited_count = 1;
  Cell current_cell(rand() % m_maze.size(), rand() % m_maze.size()); /*= entrance();*/

  while (visited_count < total_cells)
  {
    auto neighbours = findNeighbours(current_cell);

    if (!neighbours.empty())
    {
      auto new_cell = neighbours.at(rand() % neighbours.size()); //choose one at random
      m_maze[new_cell.x][new_cell.y].destroy(); // or we should destroy at new_cell.x && new_cell.y ???
      visited_cells.push_back(current_cell);
      current_cell = new_cell; //set this new cell current
      ++visited_count;
    }
    else
    {
      current_cell = visited_cells.back();
      visited_cells.pop_back();
    }
  }
}

std::vector<Cell> Labyrinth::findNeighbours(const Cell& cur_cell)
{
  std::vector<Cell> neighbour_cells;

  // how to say that we should step in maze and in which direction
  if (checkNeighbour(cur_cell.x - 1, cur_cell.y))
  {
    Cell for_check(cur_cell.x, cur_cell.y);
    --for_check.x;
    neighbour_cells.push_back(for_check);
  }
  if (checkNeighbour(cur_cell.x + 1, cur_cell.y))
  {
    Cell for_check(cur_cell.x, cur_cell.y);
    ++for_check.x;
    neighbour_cells.push_back(for_check);
  }
  if (checkNeighbour(cur_cell.x, cur_cell.y - 1))
  {
    Cell for_check(cur_cell.x, cur_cell.y);
    --for_check.y;
    neighbour_cells.push_back(for_check);
  }
  if (checkNeighbour(cur_cell.x, cur_cell.y + 1))
  {
    Cell for_check(cur_cell.x, cur_cell.y);
    ++for_check.y;
    neighbour_cells.push_back(for_check);
  }
  return neighbour_cells;
}

bool Labyrinth::checkNeighbour(int x, int y)
{
  if ((x < 0 || y < 0))
    return false;
  if (x >= m_maze.size() || y >= m_maze.size())
    return false;
  if (m_maze[x][y].closed())
    return true;
  else
    return false;
}

void Labyrinth::PrintMaze() const
{
  for (unsigned i = 0; i < m_maze.size(); ++i)
  {
    for (unsigned j = 0; j < m_maze.size(); ++j)
    {
      if (!m_maze[i][j].destroyable())
        std::cout << "*";
      else
      if (m_maze[i][j].closed())
        std::cout << "_";
      if (m_maze[i][j].closed())
        std::cout << "|";
      if (!m_maze[i][j].closed())
        std::cout << "&";
    }
    std::cout << endl;
  }
}


bool Labyrinth::isBorder(const Cell& cell) const
{
  if (m_maze[cell.x][cell.y].destroyable())
    return false;
  else
    return true;
}

bool Labyrinth::isWall(const Cell& cell) const
{
  if (m_maze[cell.x][cell.y].destroyable())
    return true;
  else
    return false;
}

Cell Labyrinth::entrance() const
{
  for (unsigned i = 0; i < m_maze.size(); ++i)
  {
    if (m_maze[0][i].entrance())
    {
      Cell enter_cell(0, i);
      return enter_cell;
    }
  }
}

Cell Labyrinth::exit() const
{
  for (unsigned i = 0; i < m_maze.size(); ++i)
  {
    if (m_maze[m_maze.size() - 1][i].exit())
    {
      Cell exit_cell(m_maze.size() - 1, i);
      return exit_cell;
    }
  }
}



