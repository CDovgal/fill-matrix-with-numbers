#include "Agent.h"
#include <vector>
#include "Labyrinth.h"
#include <iostream>


Cell Agent::setAgentStartPosition(const Labyrinth& lab)
{
  Cell agPosition = lab.entrance();
  return agPosition;
}

bool Agent::isVisited(int x, int y) const
{
  Cell i_current_cell(x, y);
  if (std::any_of(begin(m_visited_cells), end(m_visited_cells), [&](const Cell& visited){return i_current_cell == visited; }))
    return true;
  //also we can cut m_visited_cells at all and use Cell variable m_is_visited???? 
}

std::vector<Cell> Agent::findOpenedWays(const Cell& i_current_cell, Labyrinth& lab)
{
  std::vector<Cell> opened_cells;

  if (!lab.isDownWallClosed(i_current_cell.m_x, i_current_cell.m_y) && !isVisited(i_current_cell.m_x, i_current_cell.m_y + 1))
  {
    Cell opened(i_current_cell.m_x, i_current_cell.m_y + 1);
    opened_cells.push_back(opened);
  }

  if (!lab.isRightWallClosed(i_current_cell.m_x, i_current_cell.m_y) && !isVisited(i_current_cell.m_x + 1, i_current_cell.m_y))
  {
    Cell opened(i_current_cell.m_x + 1, i_current_cell.m_y);
    opened_cells.push_back(opened);
  }

  if (!lab.isDownWallClosed(i_current_cell.m_x, i_current_cell.m_y - 1) && !isVisited(i_current_cell.m_x, i_current_cell.m_y - 1))
  {
    Cell opened(i_current_cell.m_x, i_current_cell.m_y - 1);
    opened_cells.push_back(opened);
  }

  if (!lab.isRightWallClosed(i_current_cell.m_x - 1, i_current_cell.m_y) && !isVisited(i_current_cell.m_x - 1, i_current_cell.m_y))
  {
    Cell opened(i_current_cell.m_x - 1, i_current_cell.m_y);
    opened_cells.push_back(opened);
  }

  return opened_cells;
}

void Agent::FindSolution(const Labyrinth& lab)
{
  m_visited_cells.clear();
  int visited_count = 1;
  int total_cells = lab.mazeSize();
  Cell current_cell = setAgentStartPosition(lab);
  m_visited_cells.push_back(current_cell);
  m_agent_trace.push(current_cell);
  Cell exit(lab.exit());

  while (/*visited_count < total_cells*/exit != current_cell) // while !lab.exit()
  {
    auto openedways = findOpenedWays(current_cell, const_cast<Labyrinth&>(lab));

    if (!openedways.empty())
    {
      auto next_cell = openedways.at(rand() % openedways.size());

      m_agent_trace.push(current_cell);
      current_cell = next_cell;
      m_visited_cells.push_back(current_cell);
      ++visited_count;
    }
    else
    {
      current_cell = m_agent_trace.top(); // add check for empty m_agent_trace
      m_agent_trace.pop();
    }
  }
  for (std::stack<Cell> dump = m_agent_trace; !dump.empty(); dump.pop())
    trace_path.push_back(dump.top());
}


//void Agent::printAgent()
//{
//  for (std::stack<Cell> dump = m_agent_trace; !dump.empty(); dump.pop())
//    std::cout << dump.top().m_x << " & " << dump.top().m_y << std::endl;
//}

bool Agent::agentTrace(const Cell& i_cur_cell) const
{
  if (std::any_of(begin(trace_path), end(trace_path), [&](const Cell& visited){return i_cur_cell == visited; }))
    return true;
}


//---------------------------------------for movement

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