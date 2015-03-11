#ifndef UNALIVEINPUT_H
#define UNALIVEINPUT_H

#include "BaseInput.h"

class UnaliveInput : public BaseInput
{
public:
  UnaliveInput();
  ~UnaliveInput();
  void Input(std::vector<Product*>& i_prod_vec);
};

#endif //!UNALIVEINPUT_H