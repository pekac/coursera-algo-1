#pragma once

#include "generic-node.h"

template<class T>
class Stack {
    private:
        TNode<T>* first;
    public: 
        Stack();

        ~Stack();

        bool isEmpty();        

        void push(T val);

        T pop();
};