#include "Category.h"
#include <iostream>
#include <vector>

class Shop
{
  std::vector<Category> *m_category;
public:
  Shop();
  ~Shop();
  void Init();
  void add_category();
  void add_new_product();
  void show_products();
  void startup_menu();
  void admin_menu();
  void user_menu();
};