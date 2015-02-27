#ifndef ALIVEOUTPUT_H
#define ALIVEOUTPUT_H

#include "BaseOutput.h"

class AliveOutput : public BaseOutput
{
public:
  AliveOutput();
  ~AliveOutput();
  void Output();
};

#endif //!ALIVEOUTPUT_H