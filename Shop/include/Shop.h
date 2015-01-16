#include <iostream>
#include "BaseFactory.h"

class Shop
{
  Shop(){};
  ~Shop(){};
  Shop(const Shop&) = delete;
  Shop& operator=(const Shop&) = delete;
  int m_startup_sum;
public:
  static Shop& instance()
  {
    static Shop instance;
    return instance;
  }
  void load_db()
  {
    std::cout << "Load db" << std::endl;
  };
  void Input();
  void Output();
  void set_startup_sun(int i_sum);
  int start_menu();
  int admin_menu();
};






