#pragma once

#include "iterable.h"
#include "../../algos/generic-node.h"

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