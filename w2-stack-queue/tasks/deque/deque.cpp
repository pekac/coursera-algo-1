#include "deque.h"
#include "deque-iterator.h"

#include <cstddef>

template<class T>
Deque<T>::Deque() {
    first = NULL;
    last = NULL;
    count = 0;
}

template<class T>
Deque<T>::~Deque() {
    delete first;
    delete last;
}

template<class T>
bool Deque<T>::isEmpty() {
    return count == 0;
}

template<class T>
int Deque<T>::size() {
    return count;
}

template<class T>
void Deque<T>::addFirst(T item) {
    TNode<T> *old_first = first;
    first = new TNode<T>(item);
    first->linkNext(old_first);
    if (isEmpty()) {
        last = first;
    }
    count++;
}

template<class T>
void Deque<T>::addLast(T item) {
    if (isEmpty()) {
        return addFirst(item);
    }

    
    TNode<T> *old_last = last;
    last = new TNode<T>(item);
    old_last->linkNext(last);
    count++; 
}

template<class T>
T Deque<T>::removeFirst() {
    if (isEmpty()) {
        // throw e;
    }
    
    T res = first->getValue();
    first = first->getNext();
    count--;
    return res;
}

template<class T>
T Deque<T>::removeLast() {
    if (isEmpty()) {
        // throw e;
    }

    T res = last->getValue();
    if (first->getNext() == NULL) {
        first = last = NULL;
        count--;
        return res;
    }

    TNode<T>* nextToLast = first;
    while(nextToLast->getNext() != NULL && nextToLast->getNext()->getNext() != NULL) {
        nextToLast = nextToLast->getNext();
    }
    
    nextToLast->linkNext(NULL);
    last = nextToLast;
    count--;

    return res;
}

template<class T>
Iterator<T>* Deque<T>::iterator() {
    return new DequeIterator<T>(first);
}