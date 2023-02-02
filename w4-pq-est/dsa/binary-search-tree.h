#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <vector>
using std::vector;

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
        void remove(int key);
        BstNode<T>* removeSubtree(BstNode<T>* node, int key);
        BstNode<T>* min();
        BstNode<T>* subtreeMin(BstNode<T>* node);
        BstNode<T>* max();
        // largest smaller key than arg
        BstNode<T>* floor(int key);
        // smallest bigger key than arg
        BstNode<T>* ceiling(int key);
        // num of keys smaller than arg
        int rank(int key);
        // n-th largest key? or value? or node?
        BstNode<T>* select(int n);
        // traverse inorder
        vector<BstNode<T>*> inorder();
        // inorder helper
        void inorderTraverse(BstNode<T>* node, vector<BstNode<T>*> nodes);
        // delete min in tree
        void removeMin();
        // delete min in subtree
        BstNode<T>* removeSubtreeMin(BstNode<T>* subtreeRoot);
};

#endif