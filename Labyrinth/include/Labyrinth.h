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

bool operator==(const Cell& lhs, const Cell& rhs);

typedef vector<vector<Wall>> Maze;

class Labyrinth
{
public:
  Labyrinth(int i_row, int i_col); 
  ~Labyrinth(){};

  bool isWall(const Cell& cell) const;
  bool isBorder(const Cell& cell) const;  
  bool checkNeighbour(int x, int y);

  void setEntrance(const Cell& cell);
  void setExit(const Cell& cell);
  void generateMaze();
  void PrintMaze() const;

  std::vector<Cell> findNeighbours(const Cell& cur_cell);
  
  Cell entrance() const;
  Cell exit() const;
private:
  Maze m_maze;
  std::vector<Cell> m_visited_cells;
};


  