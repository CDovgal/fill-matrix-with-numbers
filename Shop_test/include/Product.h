#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
  std::string m_name;
  int m_count;
  int m_price;
public:
  Product() : m_name("No name"), m_count(0), m_price(0){}
  Product(const std::string& i_name, int count, int i_price);
  virtual ~Product();
  virtual void Input();
  virtual void Output();
};


#endif //!PRODUCT_H