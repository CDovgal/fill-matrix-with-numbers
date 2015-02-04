#include <iostream>
#include <vector>
#include "Linked_List.h"
#include <string>

int main()
{
  {
    /*List<int> lst;
    lst.push_back(5);
    lst.push_back(4);
    lst.push_back(3);
    lst.push_back(2);
    lst.push_back(1);*/
    //std::cout << lst.search_node(2) << std::endl;
    //lst.delete_by_pos(5);
    //lst.delete_by_key(3);
    //lst.view_list();
    /*if (!lst.is_sort())
      lst.sort();
    lst.view_list();
    std::cout << lst.size() << std::endl;

    List<int> lst2(lst);
    lst2.view_list();
    List<int> lst3;
    for (int i = 0; i < 5; ++i)
      lst3.push_back(i);
    lst3.view_list();
    lst2 = lst3;
    lst2.view_list();*/

    /*List<int> lst;
    lst.push_back(5);
    lst.push_back(4);
    lst.push_back(3);
    lst.push_back(2);
    lst.push_back(1);

    for (List<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
      std::cout << *iter << std::endl;*/

    List<std::string> lst2;
    //lst2.push_back("a");
    /*lst2.push_back("b");
    lst2.push_back("c");
    lst2.push_back("d");*/

    for (List<std::string>::iterator iter = lst2.begin(); iter != lst2.end(); ++iter)
      std::cout << *iter << std::endl;


    //std::cout << "Lst " << &lst << std::endl << "Lst2 " << &lst2 << std::endl << "Lst3 " << &lst3 << std::endl;
  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "Oooooopsssss..." << std::endl;
  else
    std::cout << "No leaks :)" << std::endl;


  return 0;
}