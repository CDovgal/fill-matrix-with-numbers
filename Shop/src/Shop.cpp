#include <iostream>
#include <fstream>
#include "Shop.h"


std::map<std::string, PF> io_map;

void IoRegistryMap::RegisterClasses()
{
  io_map["class Alive"] = &Alive::new_alive;
  io_map["class Unalive"] = &Unalive::new_unalive;
}

void Shop::load_db()
{
  std::cout << "Database loaded..." << std::endl;
}

void Shop::clear_data()
{
  if (!m_prod_vec.empty())
  for (unsigned i = 0; i < m_prod_vec.size(); ++i)
    delete m_prod_vec.at(i);
  m_prod_vec.clear();
}

Shop::Shop()
{
  load_db();
}

Shop::~Shop()
{
  clear_data();
}

void Shop::Generate()
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

Product* Shop::get_product(std::istream& is)
{
  std::string name;
  std::getline(is, name);
  PF f = io_map[name];
  if (f == 0) return nullptr;//throw not_implemented("no such class");
  return f();
}

void Shop::Input()
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

void Shop::Output()
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

void Shop::set_startup_sun(int i_sum)
{
  m_startup_sum = i_sum;
}

int Shop::start_menu()
{
  std::cout << "Flower Shop\n" << std::endl;
  std::cout << "Choose your access type: " << std::endl;
  std::cout << "1. Enter as admin." << std::endl << "2. Enter as customer." << std::endl;
  int choise;
  std::cin >> choise;
  switch (choise)
  {
  case 1:
    std::cout << "Entered as admin." << std::endl;
    system("cls");
    //admin menu
    break;
  case 2:
    std::cout << "Entered as customer." << std::endl;
    system("cls");
    //customer menu
    break;
  default:
    std::cout << "You've not choosen any type." << std::endl;
  }
  return choise;
}


int Shop::admin_menu()
{
  std::cout << "Entered as admin. . .\n" << std::endl;
  std::cout << "1. Enter startup sum." << std::endl;
  std::cout << "2. Show goods(is available)." << std::endl;

  int choise;
  std::cin >> choise;
  switch (choise)
  {
  case 1:
    std::cout << "Please, enter balance: " << std::endl;
    int sum;
    std::cin >> sum;
    Shop::set_startup_sun(sum);
    std::cout << m_startup_sum << std::endl;
    break;
  case 2:
    //Shop::Generate();
    std::cout << m_prod_vec.size() << std::endl;
    break;
  }

  return choise;
}