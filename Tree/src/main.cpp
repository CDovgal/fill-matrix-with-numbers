#include <iostream>
#include "Tree.h"

int main()
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
  tr.Show();
  return 0;
}