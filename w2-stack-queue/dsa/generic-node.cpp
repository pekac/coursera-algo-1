#include "generic-node.h"
#include<iostream>
using namespace std;

template<class T>
TNode<T>::TNode(T val) {
    item = val;
    next = NULL;
}

template<class T>
TNode<T>::~TNode() {
    delete next;
}

template<class T>
void TNode<T>::linkNext(TNode *node) {
    next = node;
}

template<class T>
TNode<T>* TNode<T>::getNext() {
    return next;
}

template<class T>
T TNode<T>::getValue() {
    return item;
}
/* undefined ref fix - not sure if valid */
template class TNode<int>;