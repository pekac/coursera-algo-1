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

    int leftCount = x->left != NULL ? x->left->getCount() : 0;
    int rightCount = x->right != NULL ? x->right->getCount() : 0;

    x->setCount(1 + leftCount + rightCount);
    
    if (prev != NULL && prev->getKey() > x->getKey()) {
        prev->left = x;
    } else {
        prev->right = x;
    }
    
    return x;
};

template<class T>
void BinarySearchTree<T>::remove(int key) {
    root = removeSubtree(root, key);
};

template<class T>
BstNode<T>* BinarySearchTree<T>::removeSubtree(BstNode<T>* x, int key) {
    if (x == NULL) return NULL;

    if (key > x->getKey()) {
        x->right = removeSubtree(x->right, key);
    } else (key < x->getKey()) {
        x->left = removeSubtree(x->left, key);
    } 

    if (x->left == NULL) return x->right;
    if (x->right == NULL) return x->left;

    BstNode<T>* temp = x;
    x = subtreeMin(temp->right);
    x->right = removeMin(temp->right);
    x->left = temp->left;

    x->setCount(x->left->getCount() + x->right->getCount() + 1);
    return x;
};

template<class T>
BstNode<T>* BinarySearchTree<T>::min() {
    return subtreeMin(root);
};

template<class T>
BstNode<T>* BinarySearchTree<T>::subtreeMin(BstNode<T>* node) {
    BstNode<T>* x = node;
    BstNode<T>* prev = NULL;
    while (x != NULL) {
        prev = x;
        x = x->left;
    }

    return prev;
};

template<class T>
BstNode<T>* BinarySearchTree<T>::max() {
    BstNode<T>* x = root;
    BstNode<T>* prev = NULL;
    while (x != NULL) {
        prev = x;
        x = x->right;
    }

    return prev;
};

template<class T>
BstNode<T>* BinarySearchTree<T>::floor(int key) {
    BstNode<T>* x = root;
    BstNode<T>* result = NULL;
    while (x != NULL) {
        if (x->getKey() == key) {
            return x;
        } 
        
        if (x->getKey() < key) {
            if (result == NULL || x->getKey() > result->getKey()) {
                result = x;
            }
            x = x->right;
        } 

        x = x->left;
    }

    return result;
};

template<class T>
BstNode<T>* BinarySearchTree<T>::ceiling(int key) {
    BstNode<T>* x = root;
    BstNode<T>* result = NULL;
    while (x != NULL) {
        if (x->getKey() == key) {
            return x;
        } 
        
        if (x->getKey() > key) {
            if (result == NULL || x->getKey() < result->getKey()) {
                result = x;
            }
            x = x->left;
        } 

        x = x->right;
    }

    return result;
};

template<class T>
int BinarySearchTree<T>::rank(int key) {
    BstNode<T>* x = root;
    int result = 0;

    while (x != NULL) {
        if (key > x->getKey()) {
            int leftCount = x->left != NULL ? x->left->getCount() : 0;
            result += leftCount + 1;
            x = x->right;
            continue;
        }

        if (key < x->getKey()) {
            x = x->left;
            continue;
        }

        if (key == x->getKey()) {
            result += x->getCount();
            return result;
        }
    }

    return result;
};

template<class T>
BstNode<T>* BinarySearchTree<T>::select(int n) {
    BstNode<T>* x = root;
    int rank = x->getCount() - n + 1;

    while (x != NULL) {
        int xRank = rank(x->getKey());
        if (rank == xRank) {
            return x;
        } else if (rank > xRank) {
            x = x->right;
        } else {
            x = x->left;
        }
    }

    return x;
};

template<class T>
vector<BstNode<T>*> BinarySearchTree<T>::inorder() {
    vector<BstNode<T>*> nodes; 
    inorderTraverse(root, nodes);
    return nodes;
};

template<class T>
void BinarySearchTree<T>::inorderTraverse(BstNode<T>* node, vector<BstNode<T>*> nodes) {
    if (node == NULL) return;

    inorderTraverse(node->left, nodes);
    nodes.push_back(node);
    inorderTraverse(node->right, nodes);
};

template<class T>
void BinarySearchTree<T>::removeMin() {
    root = removeSubtreeMin(root);
}

template<class T>
BstNode<T>* BinarySearchTree<T>::removeSubtreeMin(BstNode<T>* subtreeRoot) {
    BstNode<T>* x = subtreeRoot;
    BstNode<T>* prev = NULL;
    while (x->left != NULL) {
        prev = x;
        x = x->left;
    }

    prev->left = x->right;
    int prevCountRight = prev->right != NULL ? prev->right->getCount() : 0;
    int xCountRight = x->right != NULL ? x->right->getCount() : 0;
    prev->setCount(1 + prevCountRight + xCountRight);
    return x;
}