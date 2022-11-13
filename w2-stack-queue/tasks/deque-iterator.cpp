#include "deque-iterator.h"

template<typename T>
DequeIterator<T>::DequeIterator(TNode<T>* first) {
    current = first;
}

template<typename T>
DequeIterator<T>::~DequeIterator() {
    delete current;
}

template<typename T>
bool DequeIterator<T>::hasNext() {
    return current != NULL;
}

template<typename T>
T DequeIterator<T>::next() {
    T res = current->getValue();
    current = current->getNext();
    return res;
}