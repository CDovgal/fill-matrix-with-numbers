#ifndef UNALIVEPRODUCT_H
#define UNALIVEPRODUCT_H

#include <vector>
#include "Product.h"

class Unalive : public Product
{
  std::vector<Good> make_unalive_list(const Good& good);
public:
  Unalive() : Product(make_unalive_list({ "", 0 })){};
  Unalive(const Good& good) : Product(make_unalive_list(good)){}
  void write_to_file(std::ostream& os);
  void read_from_file(std::istream& is);
  static Product* new_unalive()
  {
    return new Unalive();
  }
};

#endif UNALIVEPRODUCT_H