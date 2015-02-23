#ifndef CLASSA_H
#define CLASS_H

template <typename T>
class A
{
  T mt;
public:
  A(T t) : mt(t){ std::cout << "General template" << std::endl; }
  void Show()
  {
    std::cout << mt << std::endl;
  }
};


template <>
class A<char*>
{
  char *m_char;
public:
  //A(char *i_ch) : m_char(i_ch){}
  A(char *i_ch)
  {
    int size = strlen(i_ch) + 1;
    m_char = new char[size];
    memcpy(m_char, i_ch, sizeof(char)*size);    
    std::cout << "CHAR* template" << std::endl;
  }
  ~A()
  {
    if (m_char)
      delete[] m_char;
  }
  void Set()
  {
    if (m_char != nullptr)
      delete[] m_char;
    int size = strlen("Ololo")+1;
    m_char = new char[size];
    memcpy(m_char, "Ololo", sizeof(char)*size);
    
  }
  void Show()
  {
    std::cout << m_char << std::endl;
  }
};

#endif //!CLASSA_H