#include <iostream>
#include "Node.h"

int main()
{
  {
    List lst;
    lst.push_back(5);
    lst.push_back(4);
    lst.push_back(3);
    lst.push_back(2);
    lst.push_back(1);
    lst.view_list();
    std::cout << lst.search_node(3) << std::endl;
    lst.delete_by_pos(1);
    lst.view_list();
  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "Oooooopsssss..." << std::endl;
  else
    std::cout << "No leaks :)" << std::endl;


  return 0;
}