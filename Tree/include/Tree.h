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
public:
  Tree();
  ~Tree();
  void insert(T i_value);
  void pop(T i_value);
  void Show();
};

template <typename T>
Tree<T>::Node::Node() : m_pLeft(nullptr), m_pRight(nullptr), m_pTop(nullptr), m_pValue(0)
{

};

template <typename T>
Tree<T>::Node::Node(T i_value) : m_pValue(i_value)
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

}

template <typename T>
void Tree<T>::insert(Node* i_node, T i_value)
{

}

template <typename T>
void Tree<T>::insert(T i_value)
{
  if (m_pRoot == 0)
  {
    m_pRoot = new Node(i_value);
    return;
  }
  if (m_pRoot->m_pLeft > i_value)
  {
    m_pRoot->m_pLeft = new Node(i_value);
  }
  else
    insert(m_pRoot->m_pLeft, i_value);
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
 
}







