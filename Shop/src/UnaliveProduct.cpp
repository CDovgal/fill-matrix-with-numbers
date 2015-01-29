#include "UnaliveProduct.h"

std::vector<Good> Unalive::make_unalive_list(const Good& good)
{
  std::vector<Good> unalive_vec;
  Good unalive_good = good;
  unalive_vec.push_back(unalive_good);
  return unalive_vec;
}

void Unalive::write_to_file(std::ostream& os)
{
  Product::write_to_file(os);
}

void Unalive::read_from_file(std::istream& is)
{
  Product::read_from_file(is);
}