#include "Node.h"
#include <iostream>

List::Node::Node(int i_a) : m_a(i_a), m_pPrev(nullptr), m_pNext(nullptr)
{

}

List::List() : m_pHead(nullptr)
{
  std::cout << "List constructor  " << this << std::endl;
}

List::~List()
{
  std::cout << "List destructor  " << this << std::endl;
  //delete temp;
  void clear();
}

//List::List(const List& rhv)
//{
//  std::cout << "List copy constructor  " << this << std::endl;
//}
//
//List& List::operator=(const List& rhv)
//{
//  std::cout << "List copy assignment operator  " << this << std::endl;
//  List lst;
//  return lst;
//}

bool List::is_empty() const
{
  return m_pHead == nullptr;
}

void List::clear()
{
  if (is_empty())
    return;
  int count;
  for (count = 0; !is_empty(); ++count)
  {
    Node* to_delete = m_pHead;
    m_pHead = m_pHead->m_pNext;
    delete to_delete;
  }
  delete m_pHead;
}

List::Node* List::lastNode()
{
  for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
  {
    if (iter->m_pNext == nullptr)
      return iter;
  }
  return nullptr;
}

void List::make_head(Node* i_pNewhead)
{
  if (!is_empty())
  {
    i_pNewhead->m_pNext = m_pHead;
    m_pHead->m_pPrev = i_pNewhead;
    m_pHead = i_pNewhead;
  }
  else
    m_pHead = i_pNewhead;
}

void List::erase_node(Node* i_node)
{
  if (is_empty())
    return;

  Node* to_delete = i_node;
  Node* prev = nullptr;
  if (to_delete == m_pHead)
    m_pHead = to_delete->m_pNext;
  else
  {
    prev = m_pHead->m_pNext;
    while (prev->m_pNext != to_delete && prev->m_pNext != nullptr)
      prev = prev->m_pNext;
    to_delete->m_pPrev->m_pNext = to_delete->m_pNext;
  }
  to_delete = to_delete->m_pNext;
}

void List::push_back(int i_key)
{
  Node* temp = new Node(i_key);

  if (is_empty())
    make_head(temp);
  else
  {
    Node* last = lastNode();
    last->m_pNext = temp;
    temp->m_pPrev = last;
  }
  //delete temp;
}

List::Node* List::search_node(int i_key)
{
  for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
  {
    if (iter->m_a == i_key)
      return iter;
  }
  return nullptr;
}

void List::delete_by_pos(int i_pos)
{
  if (is_empty())
    return;

  int count = 0;
  for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
  {
    if (count == i_pos)
      erase_node(iter);
  }
}

void List::view_list()
{
  for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
  {
    std::cout << iter->m_a << " ";
  }
  std::cout << "\n";
}