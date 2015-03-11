#ifndef ALIVEINPUT_H
#define ALIVEINPUT_H

#include "BaseInput.h"

class AliveInput : public BaseInput
{
public:
  AliveInput();
  ~AliveInput();
  void Input(std::vector<Product*>& i_prod_vec);
};

#endif //!ALIVEINPUT_H