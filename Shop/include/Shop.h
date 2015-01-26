#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Shop
{
  Shop(const Shop&) = delete;
  Shop& operator=(const Shop&) = delete;
  void load_db();
  int m_startup_sum;
public:
  Shop();
  ~Shop();
  void set_startup_sun(int i_sum);
  int start_menu();
  int admin_menu();
  void input();
  void output();
};




