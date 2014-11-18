#pragma once

#include <vector>
#include <algorithm>
#include "Wall.h"
#include <stack>

using namespace std;

enum Direction
{
  step_up,
  step_down,
  step_left,
  step_right
};

struct Cell
{
  Cell(int i_x = 0, int i_y = 0) :m_x(i_x), m_y(i_y), m_visited(false){};
  
  int m_x;
  int m_y;
  bool m_visited;
};

bool operator==(const Cell& lhv, const Cell& rhv);

typedef vector<vector<Wall>> Maze;

class Labyrinth
{
public:
  Labyrinth(int i_row, int i_col); 
  ~Labyrinth(){};
  bool isWall(const Cell& cell) const;
  bool isBorder(const Cell& cell) const; 
  // agent
  bool isRightWallClosed(int x, int y);
  bool isDownWallClosed(int x, int y);
  // agent ^
  bool checkNeighbour(int x, int y);
  void generateMaze();
  void PrintMaze() const;
  int mazeSize() const;
  int mazeRows() const;
  int mazeCols() const;
  Direction checkDirection(const Cell& i_cur_cell, const Cell& i_new_cell);
  std::vector<Cell> findNeighbours(const Cell& cur_cell);
  Cell entrance() const;
  Cell exit() const;
private:
  Maze m_maze;
  std::vector<Cell> m_visited_cells;
  std::stack<Cell> m_backtrace;
  int m_maze_size;
  int m_row;
  int m_col;
};


  