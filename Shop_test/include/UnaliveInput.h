#ifndef UNALIVEINPUT_H
#define UNALIVEINPUT_H

#include "BaseInput.h"

class UnaliveInput : public BaseInput
{
public:
  UnaliveInput();
  ~UnaliveInput();
  Product* Input();
};

#endif //!UNALIVEINPUT_H