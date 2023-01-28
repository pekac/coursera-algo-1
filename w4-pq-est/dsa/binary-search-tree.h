#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "bst-node.h"

template<class T>
class BinarySearchTree {
    private:
        BstNode<T>* root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        BstNode<T>* get(int key);
        BstNode<T>* put(int key, T value);
        BstNode<T>* remove(int key);
};

#endif