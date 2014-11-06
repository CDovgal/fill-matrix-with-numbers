#pragma once

class Wall
{
public:
  Wall() // closed way, can be destroy by default
    : m_is_closed(true), m_is_destroyable(false)
  {}

  bool closed() const;
  bool destroyable() const;

  void destroy(); // destroy a wall - make a way
  void restore();

  void makeBorder();
  void makeWall();

private:
  bool m_is_closed;
  bool m_is_destroyable;
};