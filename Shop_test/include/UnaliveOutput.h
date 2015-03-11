#ifndef UNALIVEOUTPUT_H
#define UNALIVEOUTPUT_H

#include "BaseOutput.h"

class UnaliveOutput : public BaseOutput
{
public:
  UnaliveOutput();
  ~UnaliveOutput();
  void Output(std::vector<Product*>& i_prod_vec);
};

#endif //!UNALIVEOUTPUT_H