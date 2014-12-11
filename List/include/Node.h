#include <iostream>

class List
{
  struct Node
  {
    int m_a;
    Node();
    Node(int i_a);
    Node* m_pPrev;
    Node* m_pNext;
  } *m_pHead;
  Node* lastNode();
  void make_head(Node* i_pNewhead);
  void erase_node(Node* i_node);
public:
  List();
  ~List();
  List(const List& rhv);
  List& operator=(const List& rhv);
  void push_back(int i_key);
  void clear();
  void view_list();
  Node* search_node(int i_key);
  void delete_by_pos(int i_pos);
  void sort();
  void reverse();
  bool is_empty() const;
};
