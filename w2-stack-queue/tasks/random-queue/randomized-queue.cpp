#include "randomized-queue.h"

#include <cstddef>

template<class T>
RandomizedQueue<T>::RandomizedQueue() {
    count = 0;
    first = NULL;
    last = NULL;
}

template<class T>
RandomizedQueue<T>::~RandomizedQueue() {
    /* iterate through and delete? */
    delete first;
    delete last;
}

template<class T>
bool RandomizedQueue<T>::isEmpty() {
    return count == 0;
}

template<class T>
int RandomizedQueue<T>::size() {
    return count;
}

template<class T>
void RandomizedQueue<T>::enqueue(T item) {
    if (isEmpty()) {
        first = last = new TNode<T>(item);
        return
    }

    TNode<T>* oldLast = last;
    last = new TNode<T>(item);
    oldLast->linkNext(last);
}

template<class T>
T RandomizedQueue<T>::dequeue() {
    if (isEmpty()) {
        /* Throw e */
    }

    /* shuffle the queue and return and remove first? */
}

template<class T>
T RandomizedQueue<T>::sample() {
    if (isEmpty()) {
        /* Throw e */
    }

    /* shuffle the queue and return first? */
}

template<class T>
T RandomizedQueue<T>::sample() {
    if (isEmpty()) {
        /* Throw e */
    }

    /* shuffle the queue and return first? */
}

template<class T>
Iterator<T>* RandomizedQueue<T>::iterator() {
    /* shuffle the queue and return from first to last? */
}
 
template class RandomizedQueue<int>;