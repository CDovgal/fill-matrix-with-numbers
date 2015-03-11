#ifndef ALIVEOUTPUT_H
#define ALIVEOUTPUT_H

#include "BaseOutput.h"

class AliveOutput : public BaseOutput
{
public:
  AliveOutput();
  ~AliveOutput();
  void Output(std::vector<Product*>& i_prod_vec);
};

#endif //!ALIVEOUTPUT_H