#ifndef GENERIC_STACK_H
#define GENERIC_STACK_H

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

#endif