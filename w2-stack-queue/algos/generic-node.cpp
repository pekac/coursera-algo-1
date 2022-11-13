#include "generic-node.h"

template<typename T>
TNode<T>::TNode(T val) {
    item = val;
    next = NULL;
}

template<typename T>
TNode<T>::~TNode() {
    delete next;
}

template<typename T>
void TNode<T>::linkNext(TNode *node) {
    next = node;
}

template<typename T>
TNode<T>* TNode<T>::getNext() {
    return next;
}

template<typename T>
T TNode<T>::getValue() {
    return item;
}