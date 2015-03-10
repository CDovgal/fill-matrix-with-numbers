#include "Shop.h"
#include <iostream>


Shop::Shop() : m_category(new std::vector<Category>)
{
  //parse directory for dll's
  //m_category->push_back(Some_category);
  Category cat1("Alive");
  Category cat2("Unalive");
  //Category cat3("Olololo");
  m_category->push_back(cat1);
  m_category->push_back(cat2);
  //m_category->push_back(cat3);
}

Shop::~Shop()
{
  delete m_category;
}

void Shop::Init()
{
  //for (unsigned i = 0; i < m_category->size(); ++i)
  //{
  //  //m_category->at(i) = new Category();
  //  m_category->at(i).Generate();
  //}
}

void Shop::startup_menu()
{
  /*std::cout << "Flower Shop\n" << std::endl;
  std::cout << "Choose your access type: " << std::endl;
  std::cout << "1. Enter as admin." << std::endl;
  std::cout << "2. Enter as customer." << std::endl;
  std::cout << "3. Exit." << std::endl;
  int choise;
  std::cin >> choise;
  switch (choise)
  {
  case 1:
    std::cout << "Entered as admin." << std::endl;
    system("cls");
    admin_menu();
    break;
  case 2:
    std::cout << "Entered as customer." << std::endl;
    system("cls");
    user_menu();
    break;
  case 3:
    std::cout << "Exiting program..." << std::endl;
    break;
  default:
    std::cout << "You've not choosen any type." << std::endl;
  }*/
}

void Shop::add_category()
{
  std::string name;
  std::cout << "Please, enter name of new category: " << std::endl;
  std::cin >> name;
  Category new_cat(name);
  m_category->push_back(new_cat);
  std::cout << "Category " << name << " added..." << std::endl;
  system("pause");
  admin_menu();
}

void Shop::add_new_product()
{
  if (m_category->empty())
  {
    std::cout << "There are no categories. Do you want to add?     Y/N" << std::endl;
    std::string answer;
    if (answer == "Y" || answer == "y")
      add_category();
    else if (answer == "N" || answer == "n")
      admin_menu();
    else
    {
      std::cout << "Entered wrong answer..." << std::endl;
      admin_menu();
    }
  }
  else
  {
    std::cout << "To which category you want to add product: " << std::endl;
    for (unsigned i = 0; i < m_category->size(); ++i)
    {
      std::cout << i << ". " << m_category->at(i).name() << std::endl;
    }
    int choise;
    std::cin >> choise;
    system("cls");
    m_category->at(choise).Input();
  }
  admin_menu();
}


void Shop::show_products()
{
  if (m_category->empty())
  {
    std::cout << "There are no products..." << std::endl;
    admin_menu();
  }
  else
  {
    std::cout << "Products from which category tou want to see? " << std::endl;
    for (unsigned i = 0; i < m_category->size(); ++i)
    {
      std::cout << i << ". " << m_category->at(i).name() << std::endl;
    }
    int choise;
    std::cin >> choise;
    system("cls");
    m_category->at(choise).Output();
  }
}

void Shop::admin_menu()
{
  system("cls");
  std::cout << "Entered as admin..." << std::endl;
  std::cout << std::endl;
  std::cout << "1. Add new category." << std::endl;
  std::cout << "2. Add new product." << std::endl;
  std::cout << "3. Delete category." << std::endl;
  std::cout << "4. Delete product." << std::endl;
  std::cout << "5. Show all products." << std::endl;
  std::cout << "6. Exit." << std::endl;
  int choise;
  std::cin >> choise;
  switch (choise)
  {
  case 1:
    add_category();
    break;
  case 2:
    add_new_product();
    break;
  case 3:
    break;
  case 4: 
    break;
  case 5:
    show_products();
    break;
  case 6:
    return;
    break;
  }
}

void Shop::user_menu()
{

}
