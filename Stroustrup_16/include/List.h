#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Itor.h"

template <class T>
class List
{
public:
  class Link
  {

  };
  List();
  void put(T*);
  T* get();
};

template <class T>
class List_Itor : public Itor<T>
{
  List<T>& lst;
  List<T>::Link p;
public:
  List_Itor(List<T>&);
  T* first();
  T* next();
};



template <class T>
List<T>::List()
{

}

template <class T>
void List<T>::put(T*)
{

}

template <class T>
T* List<T>::get()
{
  return T;
}


template <class T>
List_Itor<T>::List_Itor(List<T>&)
{

}

template <class T>
T* List_Itor<T>::first()
{

}

template <class T>
T* List_Itor<T>::next()
{

}


#endif // !LIST_H

