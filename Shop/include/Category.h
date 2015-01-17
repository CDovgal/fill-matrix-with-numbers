#include <iostream>
#include <vector>
#include <string>

class Good
{
  std::string name;
  int count;
public:
  Good(){}
  Good(const std::string i_name, int i_count): name(i_name), count(i_count){}
  friend std::ostream& operator<<(std::ostream& output, const Good& i_good)
  {
    output << i_good.name.c_str() << std::endl << i_good.count << std::endl;
    return output;
  }
  friend std::istream& operator>>(std::istream& input, Good& i_good)
  {
    input >> i_good.name >> i_good.count;
    return input;
  }
};

class Product;

class Category
{
  std::vector<Product*> m_product;
  std::string m_category_name;
public:
  Category(){};
};

class Product : public Category
{
  std::vector<Good> m_products;
public:
  Product() : m_products(0){};
  Product(const std::vector<Good>& i_products);
  virtual void Output(std::ostream& os);
  virtual void Input(std::istream& is);
};

class Alive : public Product
{
  std::vector<Good> make_alive_list(const Good& good)
  {
    std::vector<Good> alive_vec;
    Good alive_good = good;
    alive_vec.push_back(alive_good);
    return alive_vec;
  };
public:
  Alive() : Product(make_alive_list({ "", 0 })){};
  Alive(const Good& good) : Product(make_alive_list(good)){};
  void Output(std::ostream& os);
  void Input(std::istream& is);
  static Product* new_alive()
  {
    return new Alive();
  }
};

class Unalive : public Product
{
  std::vector<Good> make_unalive_list(const Good& good)
  {
    std::vector<Good> unalive_vec;
    Good alive_good = good;
    unalive_vec.push_back(alive_good);
    return unalive_vec;
  };
public:
  Unalive() : Product(make_unalive_list({ "", 0 })){};
  Unalive(const Good& good) : Product(make_unalive_list(good)){}
  void Output(std::ostream& os);
  void Input(std::istream& is);
  static Product* new_unalive()
  {
    return new Unalive();
  }
};