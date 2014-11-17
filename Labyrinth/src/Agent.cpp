#include "Agent.h"
#include <vector>
#include "Labyrinth.h"


Cell Agent::setAgentStartPosition()
{
  Cell agPosition = lab.entrance();
  return agPosition;
}


void Agent::FindSolution()
{
  m_visited_cells.clear();
  int visited_count = 1;
  int total_cells = lab.mazeSize();
  Cell current_cell = setAgentStartPosition();
  m_visited_cells.push_back(current_cell);

  while (visited_count < total_cells) // while !lab.exit()
  {
    auto neighbours = lab.findNeighbours(current_cell);

    if (!neighbours.empty())
    {
      auto next_cell = neighbours.at(rand() % neighbours.size());

      if (lab.checkDirection(current_cell, next_cell) == step_right)
        stepRight();
      else if (lab.checkDirection(current_cell, next_cell) == step_left)
        stepLeft();
      else if (lab.checkDirection(current_cell, next_cell) == step_down)
        stepDown();
      else if (lab.checkDirection(current_cell, next_cell) == step_up)
        stepUp();

      m_agent_trace.push(current_cell);
      current_cell = next_cell;
      m_visited_cells.push_back(current_cell);
      ++visited_count;
    }
    else
    {
      current_cell = m_agent_trace.top();
      m_agent_trace.pop();
    }
  }
}


Cell Agent::stepLeft(const Cell& i_current_cell)
{

}

void Agent::stepLeft() const
{

}

Cell Agent::stepRight(const Cell& i_current_cell)
{

}

void Agent::stepRight() const
{

}

Cell Agent::stepUp(const Cell& i_current_cell)
{

}

void Agent::stepUp() const
{

}

Cell Agent::stepDown(const Cell& i_current_cell)
{

}

void Agent::stepDown() const
{

}