#ifndef RANDOMIZED_QUEUE_H
#define RANDOMIZED_QUEUE_H

#include "../../dsa/generic-node.h"
#include "../deque/iterator.h"
#include "../deque/iterable.h"

template<class T>
class RandomizedQueue: public Iterable<T> {
    private:
        int count;
        TNode<T>* first;
        TNode<T>* last;
    public:
        // construct an empty randomized queue
        RandomizedQueue();
        
        ~RandomizedQueue();

        // is the randomized queue empty?
        bool isEmpty();

        // return the number of items on the randomized queue
        int size();

        // add the item
        void enqueue(T item);

        // remove and return a random item
        T dequeue();

        // return a random item (but do not remove it)
        T sample();

        // return an independent iterator over items in random order
        Iterator<T>* iterator();
};

#endif