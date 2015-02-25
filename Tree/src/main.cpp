#include <iostream>
#include "Tree.h"

int main()
{
  {
    Tree<int> tr;
    tr.insert(5);
    tr.insert(3);
    tr.insert(8);
    tr.insert(6);
    tr.insert(12);
    tr.insert(7);
    tr.insert(10);
    tr.insert(2);
    tr.insert(4);
    tr.insert(21);
    tr.insert(36);
    tr.insert(18);
    tr.insert(13);
    tr.insert(16);
    tr.insert(17);
    //tr.load_tree();
    //tr.BFS();
    tr.Show();
    std::cout << tr.size() << std::endl;
    std::cout << tr.longest_branch() << std::endl;
    //tr.find_node(4);
    tr.delete_by_value(6);
    //tr.BFS();
    //tr.save_tree();
    tr.Show();
    tr.BFS();
  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "MEMORY LEAKS." << std::endl;
  else
    std::cout << "MEMORY OK." << std::endl;
  return 0;
}