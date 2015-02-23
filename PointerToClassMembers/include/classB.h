#ifndef CLASSB_H
#define CLASSB_H

#include "classA.h"

class B
{

public:
  B(){}
  ~B(){}
  int (A::*mpFn)(int, int);
};

#endif //!CLASSB_H