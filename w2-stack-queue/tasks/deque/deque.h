#ifndef DEQUE_H
#define DEQUE_H

#include "../../dsa/generic-node.h"
#include "iterator.h"
#include "iterable.h"

template<class T>
class Deque: public Iterable<T> {
    private:
        int count;
        TNode<T>* first;
        TNode<T>* last;
    public:
    // construct an empty deque
    Deque();
    
    ~Deque();

    // is the deque empty?
    bool isEmpty();

    // return the number of items on the deque
    int size();

    // add the item to the front
    void addFirst(T item);

    // add the item to the back
    void addLast(T item);

    // remove and return the item from the front
    T removeFirst();

    // remove and return the item from the back
    T removeLast();

    // return an iterator over items in order from front to back
    Iterator<T>* iterator();
};

#endif