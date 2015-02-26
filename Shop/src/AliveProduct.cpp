#include "AliveProduct.h"

std::vector<Good> Alive::make_alive_list(const Good& good)
{
  std::vector<Good> alive_vec;
  //Good alive_good = good;
  alive_vec.push_back(good);
  return alive_vec;
}

void Alive::write_to_file(std::ostream& os)
{
  Product::write_to_file(os);
}

void Alive::read_from_file(std::istream& is)
{
  Product::read_from_file(is);
}
