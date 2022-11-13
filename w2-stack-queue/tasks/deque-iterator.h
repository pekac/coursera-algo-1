#pragma once

#include "../algos/generic-node.h"
#include "../algos/iterable.h"

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