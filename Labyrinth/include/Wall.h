#pragma once

class Wall
{
public:
  Wall() // closed way, can be destroy by default
    : m_is_closed(true), m_is_destroyable(false), m_is_entrance(false), m_is_exit(false)
  {}

  bool closed() const;
  bool destroyable() const;
  bool entrance() const;
  bool exit() const;

  void destroy(); // destroy a wall - make a way
  void restore();

  void makeBorder();
  void makeWall();
  void setEntrance();
  void setExit();

private:
  bool m_is_closed;
  bool m_is_destroyable;
  bool m_is_entrance;
  bool m_is_exit;
};