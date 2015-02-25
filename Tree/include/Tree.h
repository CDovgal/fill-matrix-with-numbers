#include <iostream>
#include <fstream>
#include <vector>

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
    //Node* getLeft() const
    //{
    //  if (this->m_pLeft)
    //    return this->m_pLeft;
    //  else
    //    return nullptr;
    //};
    //Node* getRight() const
    //{
    //  if (this->m_pRight)
    //    return this->m_pRight;
    //  else
    //    return nullptr;
    //};
  } *m_pRoot;
  std::vector<T> tree_data;
  void insert(Node* i_node, T i_value);
  void Show(Node *m_pRoot);
  void destroy_tree(Node* i_node);
  int size(Node* i_node) const;
  int longest_branch(Node* i_node) const;
  void printLevel(Node* i_node, int i_level);
  void BFS(Node *i_node);
  Node* getTop(Node* i_node, T i_value)
  {
    if (i_node->m_pLeft)
      getTop(i_node->m_pLeft, i_value);
    if (i_node->m_pLeft && i_node->m_pLeft->m_pValue == i_value || i_node->m_pRight && i_node->m_pRight->m_pValue == i_value)
      return i_node;
    if (i_node->m_pRight)
      getTop(i_node->m_pRight, i_value);
  }
  Node* find_node(Node* i_node, T i_value)
  {
    if (i_node != nullptr)
    {
      find_node(i_node->m_pLeft, i_value);
      if (i_node->m_pValue == i_value)
      {
        i_node->m_pTop = getTop(m_pRoot, i_value);
        return i_node;
      } 
      find_node(i_node->m_pRight, i_value);
    }
  };
public:
  Tree();
  ~Tree();
  void insert(T i_value);
  void pop(T i_value);
  void Show();
  bool is_empty() const;
  void destroy_tree();
  int size() const;
  int longest_branch() const;
  void BFS();
  void save_tree();
  void load_tree();
  Node* find_node(T i_value)
  {
    if (is_empty())
      return nullptr;
    return find_node(m_pRoot, i_value);
  }
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

template <typename T>
int Tree<T>::size(Node* i_node) const
{
  if (i_node == nullptr)
    return 0;
  else
    return (size(i_node->m_pLeft) + 1 + size(i_node->m_pRight));
}

template <typename T>
int Tree<T>::size() const
{
  if (is_empty())
    return 0;
  else
    return size(m_pRoot);
}


template <typename T>
int Tree<T>::longest_branch(Node* i_node) const
{
  if (!i_node)
    return 0;
  int leftBranchHeight = longest_branch(i_node->m_pLeft);
  int rightBranchHeight = longest_branch(i_node->m_pRight);
  return (leftBranchHeight > rightBranchHeight) ? leftBranchHeight + 1 : rightBranchHeight + 1;
}


template <typename T>
void Tree<T>::printLevel(Node* i_node, int i_level)
{
  if (!i_node)
    return;
  if (i_level == 0)
  {
    std::cout << i_node->m_pValue << " ";
    tree_data.push_back(i_node->m_pValue);
  }
  else 
  {
    printLevel(i_node->m_pLeft, i_level-1);
    printLevel(i_node->m_pRight, i_level-1);
  }
}

template <typename T>
void Tree<T>::BFS(Node* i_node)
{
  int height = longest_branch();
  for (int i = 0; i < height; ++i)
  {
    printLevel(i_node, i);
    std::cout << std::endl;
    tree_data.push_back(0);
  }
}

template <typename T>
void Tree<T>::BFS()
{
  std::cout << "===========BFS===========" << std::endl;
  BFS(m_pRoot);
  std::cout << "===========BFS===========" << std::endl;
}

template <typename T>
int Tree<T>::longest_branch() const
{
  return longest_branch(m_pRoot);
}

template <typename T>
void Tree<T>::destroy_tree()
{
  if (is_empty())
    return;
  else
    destroy_tree(m_pRoot);
}

template <typename T>
void Tree<T>::destroy_tree(Node* i_node)
{
  if (!is_empty())
  {
    if (i_node->m_pLeft)
      destroy_tree(i_node->m_pLeft);
    if (i_node->m_pRight)
      destroy_tree(i_node->m_pRight);
  }
  delete i_node;
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
  if (is_empty())
    return;
  else
  {
    Node* to_delete = find_node(i_value);
    if (to_delete->m_pLeft)
    {
      to_delete->m_pLeft->m_pTop = to_delete->m_pTop;
      to_delete->m_pTop->m_pRight = to_delete->m_pLeft;
      if (to_delete->m_pRight)
        to_delete->m_pLeft->m_pRight = to_delete->m_pRight;
    }
    delete to_delete;
    std::cout << "Popped" << std::endl;
  }
}


template <typename T>
void Tree<T>::Show(Node* m_pRoot)
{
  if (m_pRoot != nullptr)
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
  std::cout << std::endl;
}

template <typename T>
void Tree<T>::save_tree()
{
  std::ofstream tree_file;
  tree_file.open("TreeFile.dat", std::ios::binary);
  if (tree_file.is_open())
  {
    tree_file << tree_data.size() << std::endl;
    for (unsigned i = 0; i < tree_data.size(); ++i)
      tree_file << tree_data.at(i) << " ";
    std::cout << "Tree saved..." << std::endl;
  }
  else
    std::cout << "Couldn't open file." << std::endl;
  tree_file.close();
}


template <typename T>
void Tree<T>::load_tree() //need to rewrite.
{
  tree_data.clear();
  size_t count = 0;
  int data;
  std::ifstream tree_file;
  tree_file.open("TreeFile.dat", std::ios::binary);
  if (tree_file.is_open())
  {
    tree_file >> count;
    for (unsigned i = 0; i < count; ++i)
    {
      tree_file >> data;
      if (data != 0)
        insert(data);
    }
  }
  else
    std::cout << "Couldn't read file." << std::endl;
  tree_file.close();
}








