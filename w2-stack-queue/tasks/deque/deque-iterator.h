#pragma once

#include "iterable.h"
#include "../../algos/generic-node.h"

template<class T>
class DequeIterator: public Iterator<T> {
    private:
        TNode<T>* current;
    public:
        DequeIterator(TNode<T>* first) {}

        ~DequeIterator() {}

        bool hasNext() {}

        T next() {}
};