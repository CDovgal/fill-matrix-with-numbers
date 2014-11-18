#include "Agent.h"
#include <vector>
#include "Labyrinth.h"


Cell Agent::setAgentStartPosition()
{
  Cell agPosition = lab.entrance();
  return agPosition;
}


std::vector<Cell> Agent::findOpenedWays(const Cell& i_current_cell)
{
  std::vector<Cell> opened_cells;

  if (!isDownWallClosed(i_current_cell.m_x, i_current_cell.m_y))
  {
    Cell opened(i_current_cell.m_x, i_current_cell.m_y + 1);
    opened_cells.push_back(opened);
  }

  if (!isRightWallClosed(i_current_cell.m_x, i_current_cell.m_y))
  {
    Cell opened(i_current_cell.m_x + 1, i_current_cell.m_y);
    opened_cells.push_back(opened);
  }

  if (!isDownWallClosed(i_current_cell.m_x, i_current_cell.m_y - 1))
  {
    Cell opened(i_current_cell.m_x, i_current_cell.m_y - 1);
    opened_cells.push_back(opened);
  }

  if (!isRightWallClosed(i_current_cell.m_x - 1, i_current_cell.m_y))
  {
    Cell opened(i_current_cell.m_x - 1, i_current_cell.m_y);
    opened_cells.push_back(opened);
  }

  return opened_cells;
}

void Agent::FindSolution()
{
  m_visited_cells.clear();
  int visited_count = 1;
  int total_cells = mazeSize();
  Cell current_cell = setAgentStartPosition();
  m_visited_cells.push_back(current_cell);

  while (visited_count < total_cells) // while !lab.exit()
  {
    auto openedways = findOpenedWays(current_cell);

    if (!openedways.empty())
    {
      auto next_cell = openedways.at(rand() % openedways.size());

      /*if (lab.checkDirection(current_cell, next_cell) == step_right)
        stepRight();
      else if (lab.checkDirection(current_cell, next_cell) == step_left)
        stepLeft();
      else if (lab.checkDirection(current_cell, next_cell) == step_down)
        stepDown();
      else if (lab.checkDirection(current_cell, next_cell) == step_up)
        stepUp();*/

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


void Agent::stepLeft() const
{

}

void Agent::stepRight() const
{

}

void Agent::stepUp() const
{

}

void Agent::stepDown() const
{

}