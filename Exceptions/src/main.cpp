#include <iostream>
#include <memory>

class Exception
{
  const char* m_pText;
protected:
  Exception *m_pPrev;
public:
  Exception(const char* p_text, const Exception *p_Prev = 0) : m_pText(p_text){ std::cout << "Main exception constructor" << std::endl; };
  virtual ~Exception()
  {
    if (m_pPrev != nullptr)
      delete m_pPrev;
  }
  virtual void Show()
  {
    if (m_pPrev != nullptr)
      m_pPrev->Show();
    std::cout << m_pText << " ";
  }

};

class Child_Exception : public Exception
{
  const char* m_pText;
protected:
  Child_Exception* m_chPrev;
public:
  Child_Exception(const char* p_text, const Exception *m_chPrev = 0) : Exception(p_text), m_pText(p_text){ std::cout << "Child exception constructor" << std::endl; };
  ~Child_Exception()
  {

  }
  virtual void Show()
  {
    if (m_chPrev != nullptr)
      m_chPrev->Show();
    std::cout << m_pText << " ";
  }
};

class GrandChild_Exception : public Child_Exception
{
  const char* m_pText;
  GrandChild_Exception* m_gchPrev;
public:
  GrandChild_Exception(const char* p_text, const Exception *m_chPrev = 0) : Child_Exception(p_text), m_pText(p_text){ std::cout << "Grand exception constructor" << std::endl; };
  ~GrandChild_Exception()
  {

  }
  virtual void Show()
  {
    if (m_gchPrev != nullptr)
      m_gchPrev->Show();
    std::cout << m_pText << " ";
  }
};

class A
{
  int m_a;
public:
  A(int i_a) : m_a(i_a)
  {
    std::cout << "A Constructor" << std::endl;
  }
  ~A()
  {
    std::cout << "A Destructor" << std::endl;
  }
};

int main()
{
  int a;
  std::cin >> a;
  try{
    try{
      try
      {
        Exception *pEx = new Exception("Main Exception");
        if (a == 0) throw pEx;
      }
      catch (Exception* pEx)
      {
        std::cout << "Main Exception catched" << std::endl;
        Child_Exception *pNewChEx = new Child_Exception("Child Exception", pEx);
        throw pNewChEx;
      }
    }
    catch (Child_Exception *pNewChEx)
    {
      std::cout << "Child Exception catched" << std::endl;
      GrandChild_Exception *GrNewChEx = new GrandChild_Exception("GrandChild Exeption", pNewChEx);
      throw GrNewChEx;
    }
  }
  catch (GrandChild_Exception* grch)
  {
    std::cout << "GrandChild Exception catched" << std::endl;
  }
  /*int b;
  std::cin >> b;*/
  //try
  //{
  //  try
  //  {
  //    if (b < 0) throw 1;
  //    else if (b == 0) throw "0";
  //    A a(5);
  //    //std::shared_ptr<A> sh(new A (a));
  //    throw 2;
  //    std::cout << "Task in try..." << std::endl;
  //  }
  //  catch (int a)
  //  {
  //    std::cout << "Inside CATCH" << std::endl;
  //    if (a == 1)
  //      std::cout << "b < 0" << std::endl;
  //    else if (a == 2)
  //      std::cout << "Shared catch" << std::endl;
  //    throw;
  //  }
  //  catch (const char*)
  //  {
  //    std::cout << "Char catch" << std::endl;
  //    throw;
  //  }
  //  catch (...)
  //  {
  //    std::cout << "Unknown error" << std::endl;
  //  }
  //}
  //catch (int f)
  //{
  //  std::cout << "Outer catch" << std::endl;
  //}
  //catch (const char*)
  //{
  //  std::cout << "Outer catch char" << std::endl;
  //}
  return 0;
}