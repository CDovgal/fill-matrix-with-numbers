#ifndef VECTOR_ITOR_H
#define VECTOR_ITOR_H

#include "Itor.h"
#include "Vector.h"

template <class T>
class Vector_Itor : public Itor<T>
{
  Vector<T>& v;
  size_t index;
public:
  Vector_Itor(Vector<T>& vv);
  T* first();
  T* next();
};

template <class T>
Vector_Itor<T>::Vector_Itor(Vector<T>& vv) : v(vv)
{

}

template <class T>
T* Vector_Itor<T>::first()
{
  return (v.size()) ? &v[index = 0] : 0; 
}

template <class T>
T* Vector_Itor<T>::next()
{ 
  return (++index < v.size()) ? &v[index] : 0; 
}


#endif //!VECTOR_ITOR_H