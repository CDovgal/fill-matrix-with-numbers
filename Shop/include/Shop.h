#include <iostream>
#include "BaseFactory.h"

class Shop
{
  Shop(){};
  ~Shop(){};
  Shop(const Shop&) = delete;
  Shop& operator=(const Shop&) = delete;
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
};






