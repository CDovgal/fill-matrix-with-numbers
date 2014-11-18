#pragma once
#include "Labyrinth.h"

class Agent
{
public:
  Agent(){};
  ~Agent(){};

  void stepLeft() const;
  void stepRight() const;
  void stepUp() const;
  void stepDown() const;

  Cell setAgentStartPosition();
  void FindSolution();
  std::vector<Cell> findOpenedWays(const Cell& i_current_cell);

private:
  void log();
  std::vector<Cell> m_visited_cells;
  std::stack<Cell> m_agent_trace;
};