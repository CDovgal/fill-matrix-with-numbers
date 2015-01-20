#include "Product.h"
#include "Category.h"
#include "Shop.h"
#include <fstream>


std::map<std::string, PF> io_map;

void IoRegistryMap::RegisterClasses()
{
  io_map["class Alive"] = &Alive::new_alive;
  io_map["class Unalive"] = &Unalive::new_unalive;
}

std::ostream& operator<<(std::ostream& output, const Good& i_good)
{
  output << i_good.name.c_str() << std::endl << i_good.count << std::endl;
  return output;
}

std::istream& operator>>(std::istream& input, Good& i_good)
{
  input >> i_good.name >> i_good.count;
  return input;
}

Category::Category()
{
  /*bf = new AliveFactory();
  bf->createInput();
  bf->createOutput();
  bf = new UnaliveFactory();
  bf->createInput();
  bf->createOutput();*/
}

Category::~Category()
{
  //delete bf;
  clear_data();
}

void Category::clear_data()
{
  if (!m_prod_vec.empty())
  for (unsigned i = 0; i < m_prod_vec.size(); ++i)
    delete m_prod_vec.at(i);
  m_prod_vec.clear();
}

void Category::Generate()
{
  Alive *al = new Alive(Good("Rose", 300));
  Alive *al2 = new Alive(Good("Astra", 200));
  Alive *al3 = new Alive(Good("Gvozdika", 500));
  Alive *al4 = new Alive(Good("Liliya", 100));
  m_prod_vec.push_back(al);
  m_prod_vec.push_back(al2);
  m_prod_vec.push_back(al3);
  m_prod_vec.push_back(al4);

  Unalive *unal = new Unalive(Good("Seed", 300));
  Unalive *unal2 = new Unalive(Good("Gorshok", 200));
  Unalive *unal3 = new Unalive(Good("udobrenie", 500));
  Unalive *unal4 = new Unalive(Good("Ololo", 100));
  m_prod_vec.push_back(unal);
  m_prod_vec.push_back(unal2);
  m_prod_vec.push_back(unal3);
  m_prod_vec.push_back(unal4);
}

Product* Category::get_product(std::istream& is)
{
  std::string name;
  std::getline(is, name);
  PF f = io_map[name];
  if (f == 0) return nullptr;
  return f();
}

void Category::Input()
{
  clear_data();
  Product *product = nullptr;
  size_t product_count;
  std::ifstream input("Products.dat");
  if (input.is_open())
  {
    input >> product_count;
    for (unsigned i = 0; i < product_count;)
    {
      product = get_product(input);
      if (product != nullptr)
      {
        product->Input(input);
        m_prod_vec.push_back(product);
        ++i;
      }
    }
  }
  else
    std::cout << "Unable to open file\n";
  input.close();
}

void Category::Output()
{
  std::ofstream aliveoutput("Products.dat");
  if (aliveoutput.is_open())
  {
    aliveoutput << m_prod_vec.size() << std::endl;
    for (unsigned i = 0; i < m_prod_vec.size(); ++i)
    {
      aliveoutput << typeid(*m_prod_vec.at(i)).name() << std::endl;
      m_prod_vec.at(i)->Output(aliveoutput);
    }
  }
  else
    std::cout << "Unable to open file\n";
  aliveoutput.close();
}


