#include "Category.h"
#include "AliveProduct.h"
#include "UnaliveProduct.h"
#include <iostream>


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

Category::Category(const std::string& i_name) : 
m_category_name(i_name)
{

}

std::string& Category::name()
{
  return m_category_name;
}


Category::~Category()
{
  clear_data();
}

void Category::Input()
{
  
  m_base_factory->createInput()->Input();
}

void Category::Output()
{
  m_base_factory->createOutput()->Output();
}

void Category::add_category()
{
  std::cout << "Category added." << std::endl;
}

void Category::Generate() //function for testing workability
{
  AliveProduct *al = new AliveProduct("Rose", 300, 25);
  AliveProduct *al2 = new AliveProduct("Astra", 200, 20);
  AliveProduct *al3 = new AliveProduct("Gvozdika", 500, 15);
  AliveProduct *al4 = new AliveProduct("Liliya", 100, 50);
  m_product_container.push_back(al);
  m_product_container.push_back(al2);
  m_product_container.push_back(al3);
  m_product_container.push_back(al4);

  UnaliveProduct *unal = new UnaliveProduct("Seed", 300, 40);
  UnaliveProduct *unal2 = new UnaliveProduct("Gorshok", 200, 50);
  UnaliveProduct *unal3 = new UnaliveProduct("udobrenie", 500, 50);
  UnaliveProduct *unal4 = new UnaliveProduct("Ololo", 100, 70);
  m_product_container.push_back(unal);
  m_product_container.push_back(unal2);
  m_product_container.push_back(unal3);
  m_product_container.push_back(unal4);
}


