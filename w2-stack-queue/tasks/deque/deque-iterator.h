#ifndef DEQUE_ITERATOR_H
#define DEQUE_ITERATOR_H

#include "../../dsa/iterator.h"
#include "../../dsa/generic-node.h"

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