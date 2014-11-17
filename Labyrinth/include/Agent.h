#pragma once
#include "Labyrinth.h"

class Agent
{
public:
  Agent();

  void stepLeft() const;
  Cell stepLeft(const Cell& i_current_cell);
  void stepRight() const;
  Cell stepRight(const Cell& i_current_cell);
  void stepUp() const;
  Cell stepUp(const Cell& i_current_cell);
  void stepDown() const;
  Cell stepDown(const Cell& i_current_cell);

  Cell setAgentStartPosition();
  //bool isCellVisited(const Cell& i_cell);
  void FindSolution();

private:
  Labyrinth lab;
  void log();
  std::vector<Cell> m_visited_cells;
  std::stack<Cell> m_agent_trace;
};