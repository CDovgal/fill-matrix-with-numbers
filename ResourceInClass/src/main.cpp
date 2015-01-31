#include <iostream>

class really_bad_alloc
{
  const char* m_pWhat;
public:
  really_bad_alloc(const char* text) : m_pWhat(text)
  {
    std::cout << m_pWhat << std::endl;
  }

};


class A
{
  class B
  {
  public:
    int *m_pArr;
  
    B(int m_nSize) : m_pArr(new int(m_nSize))
    {
      if (m_nSize < 0)
        throw really_bad_alloc("Size below zero");
    }
    ~B()
    {
      delete[] m_pArr;
      std::cout << ">> B Destructor " << this << std::endl;
    }
    int* operator->()
    { 
      return m_pArr; 
    }
  };

  B m_B1, m_B2;
public:
  A(int a, int b): m_B1(a), m_B2(b)
  {
    std::cout << ">> A constructor " << this << std::endl;
  }
  ~A()
  {
    std::cout << ">> A destructor " << this << std::endl;
  }
  void Show()
  {
    
    std::cout << *m_B1.m_pArr << std::endl;
    std::cout << *m_B2.m_pArr << std::endl;
  }
};





int main()
{
  
  {
    try
    {
      A a(2, 3);
      a.Show();
      
    }
    catch (std::bad_alloc ba)
    {
      std::cout << ba.what() << std::endl;
    }
  }
  if (_CrtDumpMemoryLeaks())
    std::cout << "Memory Leaks" << std::endl;
  else
    std::cout << "No leaks" << std::endl;
  return 0;
}