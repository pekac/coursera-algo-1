#ifndef DEQUE_ITERATOR_H
#define DEQUE_ITERATOR_H

#include "iterable.h"
#include "../../dsa/generic-node.h"

#include<iostream>
using namespace std;

template<class T>
class DequeIterator: public Iterator<T> {
    private:
        TNode<T>* current;
    public:
        DequeIterator(TNode<T>* first);

        ~DequeIterator();

        bool hasNext();

        T next();
};

#endif