#include "Agent.h"

class Renderer
{
  void printMaze(const Labyrinth& i_labyrinth, const Agent& i_agent) const;
public:
  Renderer();
  ~Renderer(){};

  void printLabyrinth() const;
};