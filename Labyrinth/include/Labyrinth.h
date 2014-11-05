#pragma once 
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;


struct Cell
{
  int x;
  int y;
};

class Labyrinth
{
public:
  Labyrinth(){};
  ~Labyrinth(){};
  void FillMatrix();
  void PrintMatrix();
  void FindSolution();
  Matrix maze;
  bool IsCellVisited(const Cell& cell);
  bool IsWall(const Cell& cell);
  bool IsBorder(const Cell& cell);
  bool CanBePulledUp(const Cell& cell);
  void SetEntrance(const Cell& cell);
  void SetExit(const Cell& cell);
  void WriteBackTrack(const Cell& cell); // do we need this?
  void SetCurrentCell(const Cell& cell);
  Cell entrance() const;
  Cell exit() const;
private:
  
};