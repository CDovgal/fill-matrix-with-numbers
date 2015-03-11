#include "Category.h"
#include "AliveProduct.h"
#include "UnaliveProduct.h"
#include "AliveFactory.h"
#include "UnaliveFactory.h"
#include <iostream>
#include <map>

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
  Generate();
}

std::string& Category::name()
{
  return m_category_name;
}


Category::~Category()
{
  delete m_base_factory;
  //clear_data();
}

void Category::Input()
{
  if (m_category_name == "Alive")
  {
    m_base_factory = new AliveFactory();
    m_base_factory->createInput()->Input(m_product_container);
  }
  else if (m_category_name == "Unalive")
  {
    m_base_factory = new UnaliveFactory();
    m_base_factory->createInput()->Input(m_product_container);
  }
}

void Category::show_product()
{
  if (!m_product_container.empty())
  for (unsigned i = 0; i < m_product_container.size(); ++i)
  {
    m_product_container.at(i)->Output();
  }
}

void Category::Output()
{
  if (m_category_name == "Alive")
  {
    m_base_factory = new AliveFactory();
    m_base_factory->createOutput()->Output(m_product_container);
  }
  else if (m_category_name == "Unalive")
  {
    m_base_factory = new UnaliveFactory();
    m_base_factory->createOutput()->Output(m_product_container);
  }
}


void Category::write_to_file()
{

}


void Category::read_from_file()
{

}

void Category::Generate() //function for testing workability
{
  AliveProduct *al = new AliveProduct("Rose", 300, 25, 7);
  AliveProduct *al2 = new AliveProduct("Astra", 200, 20, 9);
  AliveProduct *al3 = new AliveProduct("Gvozdika", 500, 15, 13);
  AliveProduct *al4 = new AliveProduct("Liliya", 100, 50, 5);
  m_product_container.push_back(al);
  m_product_container.push_back(al2);
  m_product_container.push_back(al3);
  m_product_container.push_back(al4);

  UnaliveProduct *unal = new UnaliveProduct("Seed", 300, 40, 10);
  UnaliveProduct *unal2 = new UnaliveProduct("Gorshok", 200, 50, 20);
  UnaliveProduct *unal3 = new UnaliveProduct("udobrenie", 500, 50, 50);
  UnaliveProduct *unal4 = new UnaliveProduct("Lopata", 100, 70, 7);
  m_product_container.push_back(unal);
  m_product_container.push_back(unal2);
  m_product_container.push_back(unal3);
  m_product_container.push_back(unal4);
}


