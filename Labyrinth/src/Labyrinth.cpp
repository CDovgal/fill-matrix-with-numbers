#include "Labyrinth.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>


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

void Labyrinth::generateMaze()
{
  std::vector<Cell> visited_cells;
  std::srand((unsigned)time(0));
  int total_cells = m_maze.size()*m_maze.size();
  int visited_count = 1;

  Cell current_cell(rand() % m_maze.size(), rand() % m_maze.size());//entrance();

  while (visited_count < total_cells)
  {
    auto neighbours = findNeighbours(current_cell);

    if (!neighbours.empty())
    {
      auto new_cell = neighbours.at(rand() % neighbours.size()); //choose one at random
      if (current_cell.x == new_cell.x && current_cell.y == new_cell.y)
        new_cell = neighbours.at(rand() % neighbours.size()); // need to say  that if cell == current_cell? choose another from neighbours

      m_maze[current_cell.x][current_cell.y].destroy(); // or we should destroy at new_cell.x && new_cell.y ???
      visited_cells.push_back(current_cell);
      current_cell = new_cell; //set this new cell current
      ++visited_count;
    }
    else
    {
      current_cell = visited_cells.back();
      visited_cells.pop_back();
    }
    neighbours.clear();
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
      if (m_maze[i][j].closed())
        std::cout << "|";
      if (!m_maze[i][j].closed())
        std::cout << " ";
      if (m_maze[i][j].destroyable())
        std::cout << "^";
      if (!m_maze[i][j].destroyable())
        std::cout << "+";
    }
    std::cout << endl;
  }
}

//Cell Labyrinth::checkRight(int x, int y)
//{
//  Cell cell_right(x, y);
//  if (m_maze[cell_right.x + 1][cell_right.y].closed())
//    ++cell_right.x;
//  return cell_right;
//}
//
//Cell Labyrinth::checkUp(int x, int y)
//{
//  Cell cell_up(x, y);
//  if (m_maze[cell_up.x][cell_up.y - 1].closed())
//    --cell_up.y;
//  return cell_up;
//}
//
//Cell Labyrinth::checkDown(int x, int y)
//{
//  Cell cell_down(x, y);
//  if (m_maze[cell_down.x][cell_down.y + 1].closed())
//    ++cell_down.y;
//  return cell_down;
//}

Cell Labyrinth::entrance() const
{
  Cell rand_cell_enter(rand() % m_maze.size(), 0);
  return rand_cell_enter;
}