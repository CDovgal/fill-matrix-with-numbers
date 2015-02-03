#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "Vector_Itor.h"

template <class T>
class Vector
{
public:
  explicit Vector(size_t n);
  T& operator[](size_t);
  size_t size();
};


template <class T>
Vector<T>::Vector(size_t n)
{
  
}

template <class T>
T& Vector<T>::operator[](size_t)
{
  return this[];
}


template <class T>
size_t Vector<T>::size()
{
  int count = 0;
  Vector_Itor<T> v(this);
  for (auto iter = v.first(); iter; iter = v.next())
  {
    ++count;
  }
  return count;
}

#endif //!VECTOR_H