#ifndef BASEOUTPUT_H
#define BASEOUTPUT_H
#include <vector>
#include "Product.h"

class BaseOutput
{
public:
  BaseOutput();
  virtual ~BaseOutput();
  virtual void Output(std::vector<Product*>& i_prod_vec);
};


#endif //!BASEOUTPUT_H