#include <iostream>
#include <assert.h>

template <typename T>
class List
{
  struct Node
  {
    T m_key;
    Node();
    Node(T i_a);
    Node* m_pPrev;
    Node* m_pNext;
  } *m_pHead;
  //int m_nCount;???
  Node* lastNode()
  {
    for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
    {
      if (iter->m_pNext == nullptr)
        return iter;
    }
    return nullptr;
  };
  Node* endNode()
  {
    for (auto iter = m_pHead;; iter = iter->m_pNext)
    {
      if (iter->m_pNext == nullptr)
        return iter->m_pNext;
    }
    return nullptr;
  };
  void make_head(Node* i_pNewhead);
  void erase_node(Node* i_node);
public:
  List();
  ~List();
  List(const List& rhv);
  List& operator=(const List& rhv);
  void push_back(T i_key);
  void clear();
  void view_list();
  Node* search_node(T i_key)
  {
    for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
    {
      if (iter->m_key == i_key)
        return iter;
    }
    return nullptr;
  };
  Node* first()
  {
    if (m_pHead)
      return m_pHead;
    else
      return nullptr;
  }
  void delete_by_pos(int i_pos);
  void delete_by_key(T i_key);
  void sort();
  void reverse();
  bool is_empty() const;
  bool is_sort() const;
  int size() const;
  void swap(Node* lhv, Node* rhv);
  class iterator
  {
    friend class List<T>;
    Node* iterNode;
    iterator(Node* i_node) : iterNode(i_node){}
  public:
    iterator() : iterNode(nullptr){}
    iterator& operator=(const iterator& rhv)
    {
      iterNode = rhv.iterNode;
      return *this;
    }
    iterator* operator->()
    {
      return this;
    }
    iterator* operator->() const
    {
    return this;
    }
    bool operator==(const iterator& rhv)
    {
      return (this->iterNode == rhv->iterNode);
    }
    bool operator!=(const iterator& rhv)
    {
      return !(this->iterNode == rhv.iterNode);
    }
    iterator operator++()
    {
      if (iterNode)
        iterNode = iterNode->m_pNext;
      return iterNode;
    };
    T operator*() const
    {
      if (iterNode)
        return iterNode->m_key;
    }
  };
  iterator begin()
  {
    return iterator(first());
  }
  iterator end()
  {
    return iterator(endNode());
  }
};



template <typename T>
List<T>::Node::Node(T i_a) : m_key(i_a), m_pPrev(nullptr), m_pNext(nullptr)
{
  //std::cout << "Node constructor  " << this << std::endl;
}

template <typename T>
List<T>::List() : m_pHead(nullptr)
{
  std::cout << "List constructor  " << this << std::endl;
}

template <typename T>
List<T>::~List()
{
  std::cout << "List destructor  " << this << std::endl;
  clear();
}

template <typename T>
List<T>::List(const List& rhv) : m_pHead(rhv.m_pHead)
{
  std::cout << "List copy constructor  " << this << std::endl;
}

template <typename T>
List<T>& List<T>::operator=(const List& rhv)
{
  std::cout << "List copy assignment operator  " << this << std::endl;
  List temp(rhv);
  std::swap(m_pHead, temp.m_pHead);
  return *this;
}

template <typename T>
bool List<T>::is_empty() const
{
  return m_pHead == nullptr;
}

template <typename T>
void List<T>::clear()
{
  if (is_empty())
    return;

  while (!is_empty())
  {
    Node* to_delete = m_pHead;
    if (m_pHead)
      m_pHead = m_pHead->m_pNext;
    else
      delete to_delete;
  }
  //delete temp;
  delete m_pHead;
}

template <typename T>
void List<T>::make_head(Node* i_pNewhead)
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


template <typename T>
void List<T>::erase_node(Node* i_node)
{
  if (is_empty())
    return;

  Node* to_delete = i_node;
  Node* temp = nullptr;
  if (to_delete == m_pHead)
  {
    m_pHead = to_delete->m_pNext;
    m_pHead->m_pPrev = nullptr;
  }
  else if (to_delete == lastNode())
  {
    temp = to_delete->m_pPrev;
    temp->m_pNext = nullptr;
  }
  else
  {
    temp = to_delete->m_pPrev;
    temp->m_pNext = to_delete->m_pNext;
    to_delete->m_pNext->m_pPrev = temp;
  }
}

template <typename T>
void List<T>::push_back(T i_key)
{
  Node *temp = new Node(i_key);

  if (is_empty())
    make_head(temp);
  else
  {
    Node* last = lastNode();
    last->m_pNext = temp;
    temp->m_pPrev = last;
  }
}

template <typename T>
void List<T>::delete_by_pos(int i_pos)
{
  if (is_empty())
    return;
  if (i_pos > size() - 1)
  {
    std::cout << "Could not delete. No such position\n";
    return;
  }

  int count = 0;
  for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
  {
    if (count == i_pos)
    {
      erase_node(iter);
      return;
    }
    ++count;
  }
}

template <typename T>
void List<T>::delete_by_key(T i_key)
{
  for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
  {
    if (iter->m_key = i_key)
    {
      erase_node(iter);
      break;
    }
  }
}

template <typename T>
int List<T>::size() const
{
  int count = 0;
  for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
    ++count;

  return count;
}

template <typename T>
bool List<T>::is_sort() const
{
  if (is_empty())
    return false;

  for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
  {
    if (iter > iter->m_pNext)
      return false;
  }
  return true;
}

template <typename T>
void List<T>::swap(Node* lhv, Node* rhv)
{
  if (!lhv || !rhv)
    return;

  std::swap(lhv->m_key, rhv->m_key);
}

template <typename T>
void List<T>::sort()
{
  if (is_empty())
    std::cout << "List is empty!" << std::endl;

  for (int i = 1; i < size(); ++i)
  {
    for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
    {
      while (iter->m_pPrev && iter->m_key < iter->m_pPrev->m_key)
        swap(iter->m_pPrev, iter);
    }
  }


}

template <typename T>
void List<T>::view_list()
{
  for (auto iter = m_pHead; iter != nullptr; iter = iter->m_pNext)
  {
    std::cout << iter->m_key << " ";
  }
  std::cout << "\n";
}