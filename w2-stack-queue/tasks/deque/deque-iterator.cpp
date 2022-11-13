#include "deque-iterator.h"

template<class T>
DequeIterator<T>::DequeIterator(TNode<T>* first) {
    current = first;
}

template<class T>
DequeIterator<T>::~DequeIterator() {
    delete current;
}

template<class T>
bool DequeIterator<T>::hasNext() {
    return current != NULL;
}

template<class T>
T DequeIterator<T>::next() {
    T res = current->getValue();
    current = current->getNext();
    return res;
}