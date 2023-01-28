#include "binary-search-tree.h"

template<class T>
BinarySearchTree<T>::BinarySearchTree() {};

template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    // iterate & delete all :)
};

template<class T>
BstNode<T>* BinarySearchTree<T>::get(int key) {
    BstNode<T>* x = root;
    while (x != NULL) {
        if (key < x->getKey()) {
            x = x->left;
        } else if (key > x->getKey()) {
            x = x->right;
        } else {
            return x->getValue();
        }
    }
    return NULL;
};

template<class T>
BstNode<T>* BinarySearchTree<T>::put(int key, T value) {
    // iterate and find fucker and assign
    BstNode<T>* x = root;
    BstNode<T>* prev = NULL;
    while (x != NULL) {
        prev = x;
        if (key < x->getKey()) {
            x = x->left;
        } else if (key > x->getKey()) {
            x = x->right;
        } else {
            x->setValue(value);
            return x;
        }
    }

    x = new BstNode<T>(key, value);
    if (prev->getKey() > x->getKey()) {
        prev->left = x;
    } else {
        prev->right = x;
    }
    return x;
};

template<class T>
BstNode<T>* BinarySearchTree<T>::remove(int key) {
    // iterate and find fucker
    return NULL;
};