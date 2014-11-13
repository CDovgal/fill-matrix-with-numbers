#pragma once

#include <vector>
#include <algorithm>
#include "Wall.h"
#include <stack>

using namespace std;

struct Cell
{
  Cell(int i_x = 0, int i_y = 0)
    : m_x(i_x), m_y(i_y)
    , m_visited(false)
  {}
  
  int m_x;
  int m_y;
  bool m_visited;
};


bool operator==(const Cell& lhv, const Cell& rhv);

typedef vector<vector<Wall>> Maze;

/*       
      <--M-->

      ___0_______0_____0____
      |      |      |      |          ^
      0      1      2      3          N
      |__1___|___1__|__1___|          ^
      |      |      |      |
      0      1      2      3
      |__2___|___2__|__2___|
      |      |      |      |
      0      1      2      3
      |__3___|___3__|__3___|

      rule for walls numeration
      M = 6, N = 3
*/

class Labyrinth
{
public:
  Labyrinth(int i_row, int i_col);
  
  ~Labyrinth(){};
  
  void PrintMaze() const;

  bool isWall(const Cell& cell) const;
  bool isBorder(const Cell& cell) const;  
  
  void setEntrance(const Cell& cell);
  void setExit(const Cell& cell);

  void generateMaze();

  //std::vector<Cell> findNeighbours(const Cell& cur_cell);

  std::vector<Cell*> findNeighbours_2(const Cell& i_cell);

  bool checkNeighbour(const Cell& i_cell);

  //Cell entrance() const;
  //Cell exit() const;
  
private:
  Maze m_maze;
  std::vector<Cell> m_visited_cells;

  std::stack<Cell*> m_backtrace;
  std::vector<std::vector<Cell>> m_field;
};
