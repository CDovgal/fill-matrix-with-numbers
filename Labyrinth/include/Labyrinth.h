#pragma once

#include <vector>
#include <algorithm>


struct Cell
{
  int x;
  int y;
};

class Wall
{
public:
  Wall() // closed way, can be destroy by default
    : m_is_closed(treu), m_is_border(false)
    {}
  
  bool closed() const;
  bool destroyable() const;
  
  void destroy(); // destroy a wall - make a way
  void restore();
  
  void makeBorder();
  void makeWall();
  
private:
  bool m_is_closed;
  bool m_is_destroyable;
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

  Cell entrance() const;
  Cell exit() const;
  
private:
  Maze m_maze;
};

class Agent
{
public:
  Agent();
  
  void stepLeft() const;
  void stepRight() const;
  void stepUp() const;
  void stepDown() const;

  void setCurrentPosition(const Cell& cell);
  bool isCellVisited(const Cell& cell);
  
private:
  
  void log();
};

class Trace
{
public:
  Trace();
  
  void read(const std::vector<std::string>& route);
  
  void addRecord(const std::string& i_record);
  
  void pushToFile(const std::string& i_filename);
  
  void readFromFile(const std::string& i_filename);
};

Labyrinth::Labyrinth(int i_row, int i_col)
  : m_maze(i_row, std::vector<Wall>(i_col))
{
  for(int i = 0; i < i_row; ++i)
  {
    m_maze[i][0].makeBorder();
    m_maze[i][i_col-1].makeBorder();
  }
  
  for(int j = 0; j < i_col; ++j)
  {
    m_maze[0][j].makeBorder();
    m_maze[i-1][j].makeBorder();
  }
}

  bool Wall::closed() const
  {
    return m_is_closed;
  }
  
  bool Wall::destoyable() const
  {
    return m_is_destroyable;
  }
  
  void Wall::destroy() // destroy a wall - make a way
  {
    m_is_closed = false;
  }
  
  void Wall::restore()
  {
    m_is_closed = true;
  }
  
  void Wall::makeBorder()
  {
    restoreWall();
    m_is_destroyable = false;
  }
  
  void Wall::makeWall()
  {
    restoreWall();
    m_is_destroyable = true;
  }