#include "Labyrinth.h"
#include "Agent.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <random>
#include <cassert>


bool operator==(const Cell& lhv, const Cell& rhv) { return lhv.m_x == rhv.m_x && lhv.m_y == rhv.m_y; };

bool operator!=(const Cell& lhv, const Cell& rhv) { return !(lhv.m_x == rhv.m_x && lhv.m_y == rhv.m_y); };

Labyrinth::Labyrinth(int i_row, int i_col)
: m_maze(i_row, std::vector<Wall>(i_col)), m_maze_size(i_row*i_col), m_row(i_row), m_col(i_col)
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
}

int Labyrinth::mazeSize() const
{
  return m_maze_size;
}

int Labyrinth::mazeRows() const
{
  return m_row;
}

int Labyrinth::mazeCols() const
{
  return m_col;
}


Direction Labyrinth::checkDirection(const Cell& i_cur_cell, const Cell& i_new_cell)
{
  if (i_cur_cell.m_x < i_new_cell.m_x)
    return step_right;

  if (i_cur_cell.m_x > i_new_cell.m_x)
    return step_left;

  if (i_cur_cell.m_y < i_new_cell.m_y)
    return step_down;

  if (i_cur_cell.m_y > i_new_cell.m_y)
    return step_up;
}


void Labyrinth::generateMaze()
{
  m_visited_cells.clear();
  std::srand((unsigned)time(0));
  int total_cells = mazeSize();
  int visited_count = 1;
  Cell current_cell/*(rand() % mazeRows(), rand() % mazeCols()); */ = entrance();
  m_visited_cells.push_back(current_cell);
  while (visited_count < total_cells)
  {
    auto neighbours = findNeighbours(current_cell);

    if (!neighbours.empty())
    {
      auto new_cell = neighbours.at(rand() % neighbours.size()); //choose one at random // change random !!!!
      //insert checkfunction
      if (checkDirection(current_cell, new_cell) == step_right)
        m_maze[current_cell.m_x][current_cell.m_y].destroyRightWall();
      else if (checkDirection(current_cell, new_cell) == step_left)
        m_maze[new_cell.m_x][new_cell.m_y].destroyRightWall();
      else if (checkDirection(current_cell, new_cell) == step_down)
        m_maze[current_cell.m_x][current_cell.m_y].destroyDownWall();
      else if (checkDirection(current_cell, new_cell) == step_up)
        m_maze[new_cell.m_x][new_cell.m_y].destroyDownWall();
      //m_maze[new_cell.m_x][new_cell.m_y].destroy();
      m_backtrace.push(current_cell);
      //new_cell.m_visited = true;
      current_cell = new_cell; //set this new cell current
      m_visited_cells.push_back(current_cell);
      ++visited_count;
    }
    else
    {
      current_cell = m_backtrace.top();
      m_backtrace.pop();
    }
  }
}


bool Labyrinth::checkNeighbour(int x, int y)
{
  Cell current_neighbour(x, y);

  if (std::any_of(begin(m_visited_cells), end(m_visited_cells), [&](const Cell& visited){return current_neighbour == visited; }))
    return false;
  /*if (current_neighbour.m_visited)
    return false;*/

  if ((current_neighbour.m_x < 0 || current_neighbour.m_y < 0))
    return false;

  if (current_neighbour.m_x >= mazeRows() || current_neighbour.m_y >= mazeCols())
    return false;

  return true;
}

std::vector<Cell> Labyrinth::findNeighbours(const Cell& cur_cell)
{
  std::vector<Cell> neighbour_cells;

  // how to say that we should step in maze and in which direction
  if (checkNeighbour(cur_cell.m_x - 1, cur_cell.m_y))
  {
    Cell for_check(cur_cell.m_x, cur_cell.m_y);
    --for_check.m_x;
    neighbour_cells.push_back(for_check);
  }
  if (checkNeighbour(cur_cell.m_x + 1, cur_cell.m_y))
  {
    Cell for_check(cur_cell.m_x, cur_cell.m_y);
    ++for_check.m_x;
    neighbour_cells.push_back(for_check);
  }
  if (checkNeighbour(cur_cell.m_x, cur_cell.m_y - 1))
  {
    Cell for_check(cur_cell.m_x, cur_cell.m_y);
    --for_check.m_y;
    neighbour_cells.push_back(for_check);
  }
  if (checkNeighbour(cur_cell.m_x, cur_cell.m_y + 1))
  {
    Cell for_check(cur_cell.m_x, cur_cell.m_y);
    ++for_check.m_y;
    neighbour_cells.push_back(for_check);
  }
  return neighbour_cells;
}

void Labyrinth::PrintMaze() const
{
  for (unsigned i = 0; i < mazeRows(); ++i)
  {
    for (unsigned j = 0; j < mazeCols(); ++j)
    {
      if (m_maze[i][j].entrance())
        std::cout << " 0";
      else if (m_maze[i][j].exit())
        std::cout << " 0";
      else if (!m_maze[i][j].destroyable())
        std::cout << " *";
      else if (m_maze[i][j].downWallClosed())
        std::cout << " |";
      else if (m_maze[i][j].rightWallClosed())
        std::cout << "__";
      else if (!m_maze[i][j].downWallClosed())
        std::cout << "  ";
        else if (!m_maze[i][j].rightWallClosed())
        std::cout << "  ";
      if (m_maze[i][j].isVisitedByAgent())
        std::cout << "^";
    }
    std::cout << endl;
  }
  std::cout << endl;
}


bool Labyrinth::isBorder(const Cell& cell) const
{
  if (m_maze[cell.m_x][cell.m_y].destroyable())
    return false;
  else
    return true;
}

bool Labyrinth::isWall(const Cell& cell) const
{
  if (m_maze[cell.m_x][cell.m_y].destroyable())
    return true;
  else
    return false;
}
// FOR AGENT --------------------------------------------------------

bool Labyrinth::isRightWallClosed(int x, int y)
{

  if ((x < 0 || y < 0))
    return true;

  if (x >= mazeRows() || y >= mazeCols())
    return true;

  if (m_maze[x][y].rightWallClosed())
    return true;

  return false;
}

bool Labyrinth::isDownWallClosed(int x, int y)
{

  if ((x < 0 || y < 0))
    return true;

  if (x >= mazeRows() || y >= mazeCols())
    return true;

  if (m_maze[x][y].downWallClosed())
    return true;

  return false;
}

void Labyrinth::setVisitedAg(const Cell& i_visited_cell)
{
  m_maze[i_visited_cell.m_x][i_visited_cell.m_y].setVisitedByAgent();
}
//---------------------------------------------------------------------
Cell Labyrinth::entrance() const
{
  for (unsigned i = 0; i < mazeRows(); ++i)
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
  for (unsigned i = 0; i < mazeRows(); ++i)
  {
    if (m_maze[mazeRows() - 1][i].exit())
    {
      Cell exit_cell(mazeRows() - 1, i);
      return exit_cell;
    }
  }
}



