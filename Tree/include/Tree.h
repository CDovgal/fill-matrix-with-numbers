#include <iostream>

template <typename T>
class Tree
{
  struct Node
  {
    Node *m_pLeft;
    Node *m_pRight;
    Node *m_pTop;
    T m_pValue;
    Node(T i_value);
    Node();
    ~Node();
  } *m_pRoot;
  void insert(Node* i_node, T i_value);
  void Show(Node *m_pRoot);
  void destroy_tree(Node* i_node);
  //int size(Node* i_node);
public:
  Tree();
  ~Tree();
  void insert(T i_value);
  void pop(T i_value);
  void Show();
  bool is_empty() const;
  void destroy_tree();
  //int size() const;
};

template <typename T>
Tree<T>::Node::Node() : m_pLeft(nullptr), m_pRight(nullptr), m_pTop(nullptr), m_pValue(NULL)
{

};

template <typename T>
Tree<T>::Node::Node(T i_value) : m_pLeft(nullptr), m_pRight(nullptr), m_pTop(nullptr), m_pValue(i_value)
{

}

template <typename T>
Tree<T>::Node::~Node()
{

}



template <typename T>
Tree<T>::Tree() : m_pRoot(nullptr)
{

}


template <typename T>
Tree<T>::~Tree()
{
  destroy_tree();
}


template <typename T>
bool Tree<T>::is_empty() const
{
  return m_pRoot == nullptr;
}

//template <typename T>
//int Tree<T>::size(Node* i_node)
//{
//  if (is_empty())
//    return 0;
//  else
//    return (size(m_pRoot->m_pLeft) + 1 + size(m_pRoot->m_pRight));
//}

//template <typename T>
//int Tree<T>::size() const 
//{
//  if (is_empty())
//    return 0;
//  else
//    return (size(m_pRoot->m_pLeft) + 1 + size(m_pRoot->m_pRight));
//}

template <typename T>
void Tree<T>::destroy_tree()
{
  if (is_empty())
    return;
  destroy_tree();
}

template <typename T>
void Tree<T>::destroy_tree(Node* i_node)
{
  while (!is_empty())
  {
    Node *to_delete = m_pRoot;
    if (m_pRoot)
      destroy_tree(m_pRoot->m_pLeft);
    delete i_node;
  }

}

template <typename T>
void Tree<T>::insert(Node* i_node, T i_value)
{
  if (i_value < i_node->m_pValue)
  {
    if (i_node->m_pLeft != nullptr)
      insert(i_node->m_pLeft, i_value);
    else
    {
      i_node->m_pLeft = new Node(i_value);
      i_node->m_pLeft->m_pLeft = nullptr;
      i_node->m_pLeft->m_pRight = nullptr;
    }
  }
  else if (i_value >= i_node->m_pValue)
  {
    if (i_node->m_pRight != nullptr)
      insert(i_node->m_pRight, i_value);
    else
    {
      i_node->m_pRight = new Node(i_value);
      i_node->m_pRight->m_pLeft = nullptr;
      i_node->m_pRight->m_pRight = nullptr;
    }
  }
}

template <typename T>
void Tree<T>::insert(T i_value)
{
  //if (is_empty())
  //{
  //  m_pRoot = new Node(i_value);
  //  return;
  //}
  //if (i_value < m_pRoot->m_pValue)
  //{
  //  //m_pRoot->m_pLeft = new Node(i_value);
  //  insert(m_pRoot->m_pLeft, i_value);
  //}
  //else if (i_value > m_pRoot->m_pValue)
  //{
  //  //m_pRoot->m_pRight = new Node(i_value);
  //  insert(m_pRoot->m_pRight, i_value);
  //}
  if (is_empty())
  {
    m_pRoot = new Node(i_value);
    return;
  }
  else
  {
    insert(m_pRoot, i_value);
  }

}


template <typename T>
void Tree<T>::pop(T i_value)
{

}


template <typename T>
void Tree<T>::Show(Node* m_pRoot)
{
  if (m_pRoot != 0)
  {
    Show(m_pRoot->m_pLeft);
    std::cout << m_pRoot->m_pValue << " ";
    Show(m_pRoot->m_pRight);
  }
}

template <typename T>
void Tree<T>::Show()
{
  if (is_empty())
    return;
  else
    Show(m_pRoot);
}







