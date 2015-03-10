#ifndef ALIVEINPUT_H
#define ALIVEINPUT_H

#include "BaseInput.h"

class AliveInput : public BaseInput
{
public:
  AliveInput();
  ~AliveInput();
  Product* Input();
};

#endif //!ALIVEINPUT_H