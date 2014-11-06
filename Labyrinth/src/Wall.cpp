#include "Wall.h"


bool Wall::closed() const
{
  return m_is_closed;
}

bool Wall::destroyable() const
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
  restore();
  m_is_destroyable = false;
}

void Wall::makeWall()
{
  restore();
  m_is_destroyable = true;
}