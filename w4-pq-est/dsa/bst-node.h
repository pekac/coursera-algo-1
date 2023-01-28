#ifndef BST_NODE_H
#define BST_NODE_H

#include <string>

using std::string;

template<class T>
class BstNode {
    private:
        int key;
        T value;
    public:
        BstNode<T>* left;
        BstNode<T>* right;

        BstNode(int key, T value);
        ~BstNode();
        int getKey();
        T getValue();
        void setValue(T value);
};

#endif