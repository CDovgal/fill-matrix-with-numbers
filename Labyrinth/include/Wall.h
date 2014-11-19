#pragma once

class Wall
{
public:
  Wall() : 
    m_is_closed(true), // closed way, can be destroy by default
    m_is_destroyable(true), 
    m_down_is_closed(true), 
    m_right_is_closed(true), 
    m_is_entrance(false), 
    m_is_exit(false),
    m_is_visited_by_agent(false)
  {}

  bool closed() const;
  bool destroyable() const;
  bool entrance() const;
  bool exit() const;

  void destroy(); // destroy a wall - make a way
  //-------------------
  bool downWallClosed() const;
  bool rightWallClosed() const;
  void destroyDownWall();
  void destroyRightWall();
  //----------------------
  void restore();

  void makeBorder();
  void makeWall();
  void setEntrance();
  void setExit();
  //------
  void setVisitedByAgent();
  bool isVisitedByAgent() const;
  //------

private:
  bool m_is_visited_by_agent;
  //--------------
  bool m_down_is_closed;
  bool m_right_is_closed;
  //-------------
  bool m_is_closed;
  bool m_is_destroyable;
  bool m_is_entrance;
  bool m_is_exit;
};