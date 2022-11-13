#include "generic-stack.h"

template<typename T>
Stack<T>::Stack() {
    first = NULL;
}

template<typename T>
Stack<T>::~Stack() {
    delete first;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return first == NULL;
}        

template<typename T>
void Stack<T>::push(T val) {
    TNode<T> *old_first = first;
    first = new TNode<T>(val);
    first->linkNext(old_first);
}

template<typename T>
T Stack<T>::pop() {
    T res = first->getValue();
    first = first->getNext();
    return res;
}