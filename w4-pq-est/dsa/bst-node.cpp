#include "bst-node.h"

template<class T>
BstNode<T>::BstNode(int k, T val) {
    key = k;
    value = val;
    color = NULL;
}

template<class T>
BstNode<T>::BstNode(int k, T val, bool clr) {
    key = k;
    value = val;
    color = clr;
}        

template<class T>
BstNode<T>::~BstNode() {
    value = NULL;
    left = NULL;
    right = NULL;
}

template<class T>
int BstNode<T>::getKey() {
    return key;
}

template<class T>
T BstNode<T>::getValue() {
    return value;
}

template<class T>
void BstNode<T>::setValue(T val) {
    value = val;
}

template<class T>
int BstNode<T>::getCount() {
    return count;
}

template<class T>
void BstNode<T>::setCount(int val) {
    count = val;
}

template<class T>
bool BstNode<T>::isRed() {
    return color;
}