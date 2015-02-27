#ifndef UNALIVEOUTPUT_H
#define UNALIVEOUTPUT_H

#include "BaseOutput.h"

class UnaliveOutput : public BaseOutput
{
public:
  UnaliveOutput();
  ~UnaliveOutput();
  void Output();
};

#endif //!UNALIVEOUTPUT_H