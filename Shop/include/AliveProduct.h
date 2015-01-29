#ifndef ALIVEPRODUCT_H
#define ALIVEPRODUCT_H

#include <vector>
#include "Product.h"


class Alive : public Product
{
  std::vector<Good> make_alive_list(const Good& good);
public:
  Alive() : Product(make_alive_list({ "", 0 })){};
  Alive(const Good& good) : Product(make_alive_list(good)){};
  void write_to_file(std::ostream& os);
  void read_from_file(std::istream& is);
  static Product* new_alive()
  {
    return new Alive();
  }
};

#endif //ALIVEPRODUCT_H