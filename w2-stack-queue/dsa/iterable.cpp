#include "iterable.h"

template<class T>
Iterable<T>::~Iterable() {}

/* undefined ref fix - not sure if valid */
template class Iterable<int>;