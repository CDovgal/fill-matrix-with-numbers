#include "Wall.h"


bool Wall::closed() const
{
  return m_is_closed;
}

bool Wall::destroyable() const
{
  return m_is_destroyable;
}

bool Wall::entrance() const
{
  return m_is_entrance;
}

bool Wall::exit() const
{
  return m_is_exit;
}

void Wall::setEntrance() 
{
  m_is_entrance = true;
}

void Wall::setExit()
{
  m_is_exit = true;
}

void Wall::destroy() // destroy a wall - make a way
{
  m_is_closed = false;
}
//--------------------------------
bool Wall::upWallClosed() const 
{
  return m_up_is_closed;
}

bool Wall::downWallClosed() const
{
  return m_down_is_closed;
}

bool Wall::leftWallClosed() const
{
  return m_left_is_closed;
}

bool Wall::rightWallClosed() const
{
  return m_right_is_closed;
}

void Wall::destroyUpWall()
{
  m_up_is_closed = false;
}
void Wall::destroyDownWall()
{
  m_down_is_closed = false;
}
void Wall::destroyLeftWall()
{
  m_left_is_closed = false;
}
void Wall::destroyRightWall()
{
  m_right_is_closed = false;
}
//--------------------------------
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