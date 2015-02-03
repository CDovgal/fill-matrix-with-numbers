#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "Itor.h"

template <class T>
class Vector
{
  T* m_vec;
public:
  explicit Vector(size_t n);
  T& operator[](size_t n);
  size_t size();
  T* first();
  T* next();
};

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
Vector<T>::Vector(size_t n)
{
  m_vec = new T(n);
}

template <class T> 
T* Vector<T>::first()
{
  return m_vec[0];
}

template <class T>
T* Vector<T>::next()
{
  return m_vec[0];
}

template <class T>
T& Vector<T>::operator[](size_t n)
{
  return m_vec[n];
}


template <class T>
size_t Vector<T>::size()
{
  int count = 0;
  Vector_Itor<T> v(*this);
  for (v = m_vec.first(); v; v = m_vec.next())
  {
    ++count;
  }
  return count;
}

std::vector<int> vec;

std::vector<int>::iterator iter = vec.begin();

template <class T>
Vector_Itor<T>::Vector_Itor(Vector<T>& vv) : v(vv), index(0)
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

#endif //VECTOR_H