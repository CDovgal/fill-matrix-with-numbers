#pragma once
#include "Labyrinth.h"

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
  void FindSolution();

private:

  void log();
};