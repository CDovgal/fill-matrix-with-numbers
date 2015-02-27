#include "Category.h"
#include "AliveProduct.h"
#include "UnaliveProduct.h"


void Category::clear_data()
{
  if (!m_product_container.empty())
  for (unsigned i = 0; i < m_product_container.size(); ++i)
    delete m_product_container.at(i);
  m_product_container.clear();
}

Category::Category()
{

}


Category::~Category()
{
  clear_data();
}

void Category::Input()
{

}

void Category::Output()
{

}

void Category::Generate() //function for testing workability
{
  AliveProduct *al = new AliveProduct("Rose", 300);
  AliveProduct *al2 = new AliveProduct("Astra", 200);
  AliveProduct *al3 = new AliveProduct("Gvozdika", 500);
  AliveProduct *al4 = new AliveProduct("Liliya", 100);
  m_product_container.push_back(al);
  m_product_container.push_back(al2);
  m_product_container.push_back(al3);
  m_product_container.push_back(al4);

  UnaliveProduct *unal = new UnaliveProduct("Seed", 300);
  UnaliveProduct *unal2 = new UnaliveProduct("Gorshok", 200);
  UnaliveProduct *unal3 = new UnaliveProduct("udobrenie", 500);
  UnaliveProduct *unal4 = new UnaliveProduct("Ololo", 100);
  m_product_container.push_back(unal);
  m_product_container.push_back(unal2);
  m_product_container.push_back(unal3);
  m_product_container.push_back(unal4);
}