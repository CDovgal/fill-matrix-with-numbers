#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
  std::string m_name;
  int m_count;
public:
  Product() : m_name("No name"), m_count(0){}
  Product(const std::string& i_name, int count);
  ~Product();
  virtual void Input();
  virtual void Output();
};


#endif //!PRODUCT_H