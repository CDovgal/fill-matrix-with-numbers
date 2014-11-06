#pragma once

#include <vector>
#include <algorithm>
#include "Wall.h"

using namespace std;

struct Cell
{
  Cell(int i_x, int i_y) :x(i_x), y(i_y){};
  int x;
  int y;
};

typedef vector<vector<Wall>> Maze;

class Labyrinth
{
public:
  Labyrinth(int i_row, int i_col);
  
  ~Labyrinth(){};
  
  void PrintMatrix() const;

  bool isWall(const Cell& cell) const;
  bool isBorder(const Cell& cell) const;  
  bool canBeDestroy(const Cell& cell) const;
  
  void setEntrance(const Cell& cell);
  void setExit(const Cell& cell);

  void buildMaze(int rows, int cols);

  std::vector<Cell> findNeighbours(const Cell& cur_cell);

  Cell entrance() const;
  Cell exit() const;
  
private:
  Maze m_maze;
};


  