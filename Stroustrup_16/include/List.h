#ifndef LIST_H
#define LIST_H

#include <iostream>

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


#endif // !LIST_H

