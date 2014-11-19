#include "Agent.h"

class Renderer
{
public:
  Renderer();
  ~Renderer(){};
  void printMaze(const Labyrinth& i_labyrinth, const Agent& i_agent);
};