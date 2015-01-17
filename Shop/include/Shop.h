#include <iostream>
#include "BaseFactory.h"
#include <map>
#include <string>

class Shop
{
  Shop();
  ~Shop();
  Shop(const Shop&) = delete;
  Shop& operator=(const Shop&) = delete;
  void load_db();
  int m_startup_sum;
  std::vector<Product*> m_prod_vec;
  void clear_data();
  Product* get_product(std::istream& is);
public:
  static Shop& instance()
  {
    static Shop instance;
    return instance;
  }

  void Generate();
  void Input();
  void Output();
  void set_startup_sun(int i_sum);
  int start_menu();
  int admin_menu();
};


typedef Product* (*PF)();

class IoRegistryMap
{
public:
  void RegisterClasses();
};



