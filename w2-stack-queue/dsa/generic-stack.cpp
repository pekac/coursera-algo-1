#include "generic-node.h"
#include "generic-stack.h"

template<class T>
Stack<T>::Stack() {
    first = NULL;
}

template<class T>
Stack<T>::~Stack() {
    delete first;
}

template<class T>
bool Stack<T>::isEmpty() {
    return first == NULL;
}        

template<class T>
void Stack<T>::push(T val) {
    TNode<T> *oldFirst = first;
    first = new TNode<T>(val);
    first->linkNext(oldFirst);
}

template<class T>
T Stack<T>::pop() {
    T res = first->getValue();
    first = first->getNext();
    return res;
}