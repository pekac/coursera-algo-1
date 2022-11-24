#include "iterator.h"

template<class T>
Iterator<T>::~Iterator() {}

/* undefined ref fix - not sure if valid */
template class Iterator<int>;