#include "../../dsa/generic-node.h"
#include "iterable.h"
#include "deque-iterator.h"

#include<iostream>
using namespace std;

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