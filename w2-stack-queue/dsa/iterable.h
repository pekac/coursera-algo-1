#ifndef ITERABLE_H
#define ITERABLE_H

#include "iterator.h"

template<class T>
class Iterable {
    public:
        virtual Iterator<T>* iterator() = 0;
        virtual ~Iterable();
};

#endif