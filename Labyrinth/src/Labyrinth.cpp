#include "Labyrinth.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <functional>
#include <cassert>


Labyrinth::Labyrinth(int i_row, int i_col)
  : m_field(i_row, std::vector<Cell>(i_col))
  , m_maze(i_row + 1, std::vector<Wall>(i_col + 1))
{
  ++i_row;
  ++i_col;

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

  for (int i = 0; i < m_field.size(); ++i)
  for (int j = 0; j < m_field.size(); ++j)
  {
    m_field[i][j].m_x = i;
    m_field[i][j].m_y = j;
  }
}

void Labyrinth::generateMaze()
{
  std::srand((unsigned)time(0));
  int total_cells = m_field.size()*m_field[0].size();
  int visited_count = 0;
  Cell* current_cell = &m_field[0][0]; /*= entrance();*/

  m_backtrace.push(current_cell);
  current_cell->m_visited = true;

  while (visited_count < total_cells)
  {
    PrintMaze();
    auto neighbours = findNeighbours_2(*current_cell);

    if (!neighbours.empty())
    {
      Cell* next_cell = &m_field[1][0];//neighbours.at(rand() % neighbours.size()); //choose one at random
      
      m_maze[next_cell->m_x][next_cell->m_y].destroy(); // or we should destroy at new_cell.m_x && new_cell.m_y ???
      m_backtrace.push(next_cell);
      next_cell->m_visited = true;

      current_cell = next_cell; //set this new cell current
      ++visited_count;
    }
    else
    {
      if (!m_backtrace.empty())
      {
        current_cell = m_backtrace.top();
        m_backtrace.pop();
      }
      else
        break;
    }
  }
}

std::vector<Cell*> Labyrinth::findNeighbours_2(const Cell& cur_cell)
{
  std::vector<Cell*> not_visited;
  
  try
  {
    if (cur_cell.m_x < m_field.size()-1 && !m_field[cur_cell.m_x + 1][cur_cell.m_y].m_visited)
      not_visited.push_back(&m_field[cur_cell.m_x + 1][cur_cell.m_y]);
  }
  catch (...)
  {}

  try
  {
    if (cur_cell.m_y + 1 < m_field[0].size()-1 && !m_field[cur_cell.m_x][cur_cell.m_y + 1].m_visited)
    not_visited.push_back(&m_field[cur_cell.m_x][cur_cell.m_y + 1]);
  }
  catch (...)
  {}

  try
  {
    if (cur_cell.m_x - 1 >= 0 && !m_field[cur_cell.m_x - 1][cur_cell.m_y].m_visited)
    not_visited.push_back(&m_field[cur_cell.m_x - 1][cur_cell.m_y]);
  }
  catch (...)
  {}

  try
  {
    if (cur_cell.m_y - 1 >= 0 && !m_field[cur_cell.m_x][cur_cell.m_y - 1].m_visited)
    not_visited.push_back(&m_field[cur_cell.m_x][cur_cell.m_y - 1]);
  }
  catch (...)
  {}

  return not_visited;
}

bool Labyrinth::checkNeighbour(const Cell& i_cell)
{
  if (i_cell.m_visited)
    return false;

  if (i_cell.m_x < 0 || i_cell.m_y < 0)
    return false;

  if (i_cell.m_x >= m_maze.size()-1 || i_cell.m_y >= m_maze.size()-1)
    return false;

  return true;
}

void Labyrinth::PrintMaze() const
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

  int rows = m_maze.size() - 1;
  assert(rows > 0);
  int columns = m_maze[0].size() - 1;
  assert(columns > 0);

  for (unsigned j = 0; j < columns; ++j)
    //std::cout << (m_maze[0][j].closed() ? horizontal_closed_wall_long.c_str() : horizontal_opened_wall_long.c_str());
    std::cout << horizontal_closed_wall_long.c_str();
  std::cout << "\n";

  for (int i = 1; i <= rows; ++i)  
  {
    for (unsigned k = 0; k < N; ++k)
    {
      for (int j = 0; j < columns; ++j)
      {
        if ((N-1) != k)
        {
          std::cout << (m_maze[i][j].closed() ? vertical_closed_wall_long.c_str() : vertical_opened_wall_long.c_str());
        }
        else
        {
          std::cout << (m_maze[i][j].closed() ? vertical_closed_wall : vertical_opened_wall);
          std::cout << (m_maze[i+1][j].closed() ? horizontal_closed_wall_short.c_str() : horizontal_opened_wall_short.c_str());
        }
      }
      //std::cout << (m_maze[i][columns].closed() ? vertical_closed_wall : vertical_opened_wall);
      std::cout << vertical_closed_wall;
      std::cout << "\n";
    }
  }
  std::cout << "\n";
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

//Cell Labyrinth::entrance() const
//{
//  for (unsigned i = 0; i < m_maze.size(); ++i)
//  {
//    if (m_maze[0][i].entrance())
//    {
//      Cell enter_cell(0, i);
//      return enter_cell;
//    }
//  }
//}

//Cell Labyrinth::exit() const
//{
//  for (unsigned i = 0; i < m_maze.size(); ++i)
//  {
//    if (m_maze[m_maze.size() - 1][i].exit())
//    {
//      Cell exit_cell(m_maze.size() - 1, i);
//      return exit_cell;
//    }
//  }
//}



bool operator==(const Cell& lhv, const Cell& rhv)
{
  return lhv.m_x == rhv.m_x && lhv.m_y == rhv.m_y;
};
