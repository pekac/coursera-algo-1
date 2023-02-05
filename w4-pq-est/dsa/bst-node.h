#ifndef BST_NODE_H
#define BST_NODE_H

#include <string>

using std::string;

template<class T>
class BstNode {
    private:
        int key;
        T value;
        int count;
    public:
        bool color;
        BstNode<T>* left;
        BstNode<T>* right;
        BstNode(int key, T value);
        BstNode(int key, T value, bool color);
        ~BstNode();
        int getKey();
        T getValue();
        void setValue(T value);
        int getCount();
        void setCount(int val);
        bool isRed();
};

#endif