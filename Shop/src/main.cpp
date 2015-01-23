#include <iostream>
#include "Shop.h"
#include "Category.h"


int main()
{
  Shop sh;
  IoRegistryMap io;
  io.RegisterClasses();
  Category& instance = Category::instance();
  instance.Generate();
  instance.write_to_file();
  instance.read_from_file();
  instance.write_to_file();
  
  switch (sh.start_menu())
  {
  case 1:
    sh.admin_menu();
    break;
  case 2:
    std::cout << "this is customer menu" << std::endl;
    break;
  }
  
  std::cout << "End" << std::endl;
  
  return 0;
}