#ifndef ITOR_H
#define ITOR_H

template <class T>
class Itor
{
public:
  virtual T* first() = 0;
  virtual T* next() = 0;
  virtual size_t size() = 0;
};
#endif //!ITOR_H