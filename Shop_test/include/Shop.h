#include "Category.h"
#include <iostream>

class Shop
{
  Category* m_category;
public:
  Shop();
  ~Shop();
  void startup_menu();
  void admin_menu();
  void user_menu();
};